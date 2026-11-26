# Documentación Técnica: Sistema de Control de Acceso ISTAE

## 1. Arquitectura

Modelo cliente-servidor con dos tipos de cliente: navegador web (administradores y docentes) y hardware IoT (NodeMCU ESP8266).

```
Hikvision DS-K1T8003EF ──ISAPI/Digest──▶ NodeMCU ESP8266 ──HTTPS──▶ Nginx ──▶ Gunicorn (Flask) ──▶ MySQL
   (huella, Ethernet)    (alertStream)     (relé de puerta)  (polling)            app.py
```

- **Frontend web:** Jinja2 (renderizado en servidor) + Bootstrap 5 + JavaScript. El dashboard se actualiza por AJAX y la asistencia remota usa face-api.js en el navegador.
  - **Navegación:** un único menú lateral (`templates/includes/sidebar.html`) que `base.html` incluye según el rol, con la opción activa resaltada. En escritorio el botón ☰ lo contrae a íconos (estado guardado en `localStorage`); en celular y tablet (< 992 px) es un panel deslizable que se cierra con la X, tocando fuera, deslizando, con Esc o al elegir una opción. El título de cada página sale de `{% block title %}` o del diccionario `titulos` de `base.html`. La confirmación de apertura forzada está en `templates/includes/modal_apertura.html`.
- **Backend:** aplicación Flask monolítica (`app.py`). Corre en **Gunicorn** (3 workers) administrado por **systemd** (`biometrico.service`), detrás de **Nginx** con SSL.
- **Persistencia:** MySQL con SQLAlchemy. Las vistas pesadas usan `.paginate()` (20–30 registros por página).
- **Configuración:** `config.py` lee los secretos de `instance/.env` o de variables de entorno (ver §6).
- **Hardware:** NodeMCU ESP8266 conectado por WiFi; biométrico Hikvision por Ethernet en la red local (IP fija `192.168.1.22`).

---

## 2. Modelos de datos (SQLAlchemy)

| Modelo (tabla) | Campos principales | Notas |
|---|---|---|
| `User` (`usuarios`) | `biometric_id` (único), `nombre`, `username` (único), `password` (hash pbkdf2), `rol` (`admin`/`docente`), `acceso_puerta` (0/1), `face_descriptor` (JSON, 128 valores) | Al eliminar un docente se eliminan sus permisos (cascade). |
| `Log` (`logs`) | `fecha` (naive, hora Ecuador), `usuario_id` (= `biometric_id`), `tipo_evento`, `origen`, `latitud`, `longitud`, `descripcion`, `foto_path` | `tipo_evento`: `Asistencia + puerta`, `Asistencia` o `Apertura Remota`. `origen`: `Huella`, `Asistencia remota` o `Panel Control`. |
| `Comando` (`comandos`) | `instruccion`, `estado` (`PENDIENTE`/`ENVIADO`/`EXPIRADO`), `creado` | `creado` se agrega automáticamente al iniciar la app si no existe. |
| `Permiso` (`permisos`) | `user_id` (FK `usuarios.id`), `fecha_permiso`, `observacion` | Se muestran en el reporte matricial. |
| `ConfigSistema` (`config_sistema`) | `asistencia_remota_activa`, `requiere_face_id`, `ar_fecha_inicio/fin`, `ar_hora_inicio/fin` | Tabla de una sola fila. |

Todas las fechas se guardan sin zona horaria, en hora de Ecuador (`America/Guayaquil`).

---

## 3. API del hardware

Cada llamada del NodeMCU a cualquiera de estos endpoints actualiza `last_seen.txt`, que el panel usa para mostrar el estado "en línea" (umbral de 60 s).

### `GET /api/sincronizar`
- **Uso:** el NodeMCU descarga la lista blanca cada 10 minutos.
- **Autenticación:** cabecera `X-Token: <TOKEN_NODE>` (o `?token=`), exigida solo si `EXIGIR_TOKEN_HARDWARE=true`. Sin token válido responde `403`.
- **Respuesta:** `biometric_id` de los usuarios con `acceso_puerta=1`, separados por comas. Ej.: `999,1,4,5`.

### `GET /api/check_comando`
- **Uso:** polling cada 3 segundos.
- **Autenticación:** igual que `/api/sincronizar`.
- **Comportamiento:**
  1. Marca como `EXPIRADO` todo comando `PENDIENTE` con más de 60 s (o sin fecha de creación).
  2. Devuelve el comando pendiente más antiguo y lo marca como `ENVIADO`.
- **Respuesta:** `ABRIR`, `SET_TIME|YYYY-MM-DDTHH:MM:SS` o `NADA`. El firmware también entiende `REBOOT`, pero el panel no tiene opción para enviarlo.

### `POST /api/recibir_log`
- **Uso:** registra una marcación de huella. Exento de CSRF (no usa sesión de navegador).
- **Payload JSON:**
  ```json
  {
    "id": "1",
    "estado": "EXITO",
    "fecha_dispositivo": "2026-06-29T14:43:19",
    "token": "<TOKEN_NODE>",
    "origen": "Huella"
  }
  ```
- **Campos:**
  - `id`: `employeeNoString` del Hikvision (= `biometric_id`).
  - `estado`: `EXITO` (usuario en lista blanca, se abrió la puerta) → `Asistencia + puerta`; `DENEGADO` → `Asistencia`. Ambos cuentan en los reportes.
  - `fecha_dispositivo`: ISO 8601. Se toman los primeros 19 caracteres (`YYYY-MM-DD HH:MM:SS`); si falta o es inválida se usa la hora del servidor en Ecuador.
  - `token`: debe coincidir con `TOKEN_NODE`; si no, responde `403`.

---

## 4. Rutas web

Todas requieren sesión iniciada salvo `/login`. Las marcadas **admin** redirigen al inicio (o responden `403` en JSON) si el usuario no es administrador. Todos los `POST` exigen token CSRF.

| Ruta | Método | Rol | Función |
|---|---|---|---|
| `/login`, `/logout` | GET/POST, GET | — | Inicio y cierre de sesión |
| `/admin/dashboard` | GET | admin | Panel con métricas y monitor AJAX |
| `/api/logs_admin` | GET | admin | JSON del monitor: últimos 20 logs, cola de comandos, asistencias de hoy, estado del hardware |
| `/admin/abrir` | POST | admin | Encola `ABRIR` y registra `Apertura Remota` |
| `/admin/sincronizar_hora` | GET/POST | admin | Encola `SET_TIME` con la hora de Ecuador o una hora manual |
| `/admin/config_asistencia_remota` | GET/POST | admin | Configura asistencia remota y Face ID |
| `/admin/gestion_asistencia` | GET | admin | Historial filtrable y paginado |
| `/admin/asistencia/editar/<id>`, `/admin/asistencia/actualizar` | GET, POST | admin | Edición de una marcación |
| `/admin/asistencia/eliminar/<id>` | POST | admin | Elimina la marcación y su foto |
| `/admin/gestion_permisos`, `/admin/nuevo_permiso` | GET, GET/POST | admin | Listado y alta de permisos |
| `/admin/permiso/editar/<id>`, `/admin/permiso/actualizar`, `/admin/permiso/eliminar/<id>` | GET, POST, POST | admin | Edición y baja de permisos |
| `/admin/nuevo_docente`, `/editar_docente/<id>`, `/actualizar_docente`, `/eliminar_docente/<id>` | GET/POST, GET, POST, POST | admin | Gestión de docentes (valida username e ID biométrico únicos) |
| `/admin/docente/<id>/restablecer_rostro` | POST | admin | Borra el rostro registrado del docente |
| `/toggle_permiso/<id>` | POST (JSON) | admin | Activa o quita el acceso a puerta |
| `/admin/reportes`, `/descargar_reporte_matricial`, `/descargar_reporte_permisos` | GET | admin | Reportes Excel |
| `/docente/dashboard` | GET | todos | Panel del docente |
| `/docente/marcar_web` | POST | todos | Asistencia remota (ver [FLUJO_ASISTENCIA_REMOTA.md](FLUJO_ASISTENCIA_REMOTA.md)) |
| `/docente/abrir_puerta` | POST | con `acceso_puerta=1` | Apertura remota desde el panel docente |
| `/perfil`, `/actualizar_password` | GET, POST | todos | Perfil, cambio de contraseña y registro de rostro |
| `/docente/registrar_rostro` | POST (JSON) | todos | Guarda el descriptor facial (solo si no hay uno; el admin puede re-registrar el suyo) |
| `/uploads/<archivo>` | GET | admin, o docente dueño | Evidencias fotográficas |

---

## 5. Seguridad

| Control | Implementación |
|---|---|
| Autorización por rol | Cada ruta administrativa comprueba `current_user.rol == 'admin'`. |
| CSRF | Token por sesión (`csrf_token()` en Jinja). Los formularios lo envían como campo `csrf_token` y las llamadas `fetch` como cabecera `X-CSRFToken` (leída de `<meta name="csrf-token">` en `base.html`). Solo `/api/recibir_log` está exento. Las acciones destructivas solo aceptan `POST`. |
| Secretos | Fuera del código, en `instance/.env` (permisos `600`, excluido de git). El firmware tiene marcadores `CAMBIAR_*` que se reemplazan al flashear. |
| Token del hardware | `TOKEN_NODE` en `/api/recibir_log` (siempre) y cabecera `X-Token` en `/api/sincronizar` y `/api/check_comando` (con `EXIGIR_TOKEN_HARDWARE=true`). |
| Caducidad de comandos | 60 s (`COMANDO_TTL_SEGUNDOS`): un `ABRIR` enviado con el hardware desconectado no abre la puerta más tarde. El admin recibe un aviso si el hardware está offline. |
| Archivos subidos | Solo `.jpg`, `.jpeg`, `.png`, `.webp`, verificados con Pillow; máximo 16 MB (`MAX_CONTENT_LENGTH`). Cada docente solo accede a sus evidencias; los archivos que no son imagen se sirven como descarga. |
| Face ID | El servidor exige descriptores de exactamente 128 números y compara con distancia euclidiana (umbral 0,55). El docente no puede reemplazar su rostro: lo restablece el admin. |
| Contraseñas | Hash pbkdf2:sha256 (Werkzeug). La contraseña del admin inicial sale de `ADMIN_INITIAL_PASSWORD` o se genera al azar. |
| Consumo de memoria | Paginación y `LIMIT` en las consultas; reporte matricial limitado a un año. |

**Limitaciones conocidas:** la prueba de vida de Face ID se hace solo en el navegador; las coordenadas GPS las envía el cliente y pueden falsearse; no hay límite de intentos de inicio de sesión.

---

## 6. Configuración (`instance/.env`)

| Variable | Obligatoria | Descripción |
|---|---|---|
| `SECRET_KEY` | Sí | Clave de firma de sesiones y CSRF. Cambiarla cierra todas las sesiones. |
| `DB_USER`, `DB_PASS`, `DB_NAME` | Sí | Credenciales de MySQL. |
| `DB_HOST` | No (`localhost`) | Servidor MySQL. |
| `TOKEN_NODE` | Sí | Token compartido con el firmware. |
| `EXIGIR_TOKEN_HARDWARE` | No (`false`) | `true` exige `X-Token` en la API de polling. Activar solo con el firmware que lo envía. |
| `ADMIN_INITIAL_PASSWORD` | No | Contraseña del admin al crearlo por primera vez. |
| `HIKVISION_USER`, `HIKVISION_PASS` | No | Referencia para flashear el firmware (la app no las usa). |

Las variables de entorno del sistema tienen prioridad sobre el archivo. Si falta una obligatoria, la app no arranca y el error indica cuál.

---

## 7. Flujos clave

### 7.1. Monitor en tiempo real
1. `/admin/dashboard` renderiza la tabla y las tarjetas de métricas.
2. Un script consulta `/api/logs_admin` cada 3,5 s.
3. El backend expira comandos vencidos y devuelve los últimos 20 logs, el tamaño de la cola, las **asistencias** del día (sin contar aperturas remotas) y el estado del hardware.

### 7.2. Marcación biométrica (hardware → nube)
1. El Hikvision detecta una huella y emite un evento ISAPI con `employeeNoString` y `dateTime`.
2. El NodeMCU mantiene un streaming a `/ISAPI/Event/notification/alertStream` con Digest Auth (QOP) y recibe el evento.
3. Si el ID está en la lista blanca, activa el relé 3 s y envía `EXITO`; si no, envía `DENEGADO`.
4. Si el envío falla, la marcación se guarda en la cola offline de LittleFS (hasta 50) y se reintenta cada 15 s.
5. Flask guarda el `Log` con la fecha del dispositivo.

### 7.3. Comandos remotos (apertura y hora)
1. El admin (o un docente con acceso a puerta) encola el comando desde el panel.
2. El NodeMCU lo recoge en su siguiente consulta a `/api/check_comando` (cada 3 s).
3. `ABRIR` activa el relé 3 s; `SET_TIME` se aplica al Hikvision con un `PUT` ISAPI a `/ISAPI/System/time`.
4. Si el comando no se recoge en 60 s, expira.

### 7.4. Reporte matricial
Por docente y día muestra la primera y última marcación de la mañana y de la tarde (rangos configurables), con prefijo `(H)` huella o `(W)` web, y `PERMISO: <observación>` cuando hay un permiso registrado.

### 7.5. Paginación
`gestion_asistencia` (30 por página) y `gestion_permisos` (20 por página) usan `.paginate()`; los filtros de fecha inválidos se ignoran en lugar de producir error.

---

## 8. Infraestructura de producción

| Componente | Detalle |
|---|---|
| Servidor web | Nginx (proxy inverso SSL) → Gunicorn (3 workers, puerto 5000) |
| Servicio systemd | `biometrico.service`, usuario `aenriquez2`, directorio del proyecto como `WorkingDirectory`. Reiniciar tras cada cambio de código. |
| Base de datos | MySQL (`user1_biom`) |
| Certificado SSL | HestiaCP / Let's Encrypt |
| Red IoT | NodeMCU (WiFi) ↔ Hikvision (Ethernet, `192.168.1.22:80`) |
