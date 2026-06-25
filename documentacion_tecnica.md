# Documentación Técnica: Sistema de Control de Acceso ISTAE

## 1. Arquitectura del Sistema
El sistema sigue un modelo Cliente-Servidor (con clientes tanto Web como de Hardware IoT), desarrollado en la pila tecnológica de **Python/Flask, MySQL y C++ (ESP8266)**.

- **Frontend Web:** Jinja2 (server-side rendering) enriquecido con JavaScript para peticiones AJAX y captura de periféricos (cámara, GPS). Usa Bootstrap 5 para el diseño de interfaces responsivas.
- **Backend Servidor:** Flask centralizado (`app.py`), corriendo detrás de WSGI y encargado tanto de servir las vistas Web como de exponer una API RESTful privada para el dispositivo biométrico.
- **Capa de Persistencia:** Base de datos MySQL con ORM **SQLAlchemy**.
- **Hardware Periférico:** Placa de desarrollo NodeMCU (ESP8266) conectada a un lector biométrico (presumiblemente por comunicación serial) y un relé para el acceso a la cerradura electromagnética de una puerta.

---

## 2. Modelos de Base de Datos (ORM SQLAlchemy)

1. **`User` (`usuarios`):**
   - Atributos: `id`, `biometric_id` (identificador único del biométrico), `nombre`, `username`, `password` (hash pbkdf2), `rol` (`admin` o `docente`), `acceso_puerta` (booleano).
2. **`Log` (`logs`):**
   - Atributos: `id`, `fecha` (hora del evento), `usuario_id`, `tipo_evento` (Asistencia, Apertura Remota), `origen` (Huella, Asistencia Remota, Panel Control). 
   - Soporte remoto: `latitud`, `longitud`, `descripcion`, `foto_path` (enlace al nombre del archivo de la foto cargada).
3. **`Comando` (`comandos`):**
   - Atributos: `id`, `instruccion` (Ej. `ABRIR` o `SET_TIME`), `estado` (`PENDIENTE` o `ENVIADO`). Sirve de cola para comunicarse de vuelta con el NodeMCU.
4. **`Permiso` (`permisos`):**
   - Atributos: `id`, `user_id` (Foráneo hacia `User`), `fecha_permiso`, `observacion`.

---

## 3. Especificación de la API (Hardware - Servidor)
El NodeMCU interactúa con la plataforma mediante peticiones HTTP(S) periódicas. Se aseguran mediante la validación del constante `TOKEN_NODE`.

### `GET /api/sincronizar`
- **Uso:** El NodeMCU descarga periódicamente (cada 10 min) la lista de IDs de usuarios autorizados.
- **Respuesta:** Una cadena plana separada por comas (Ej. `1,4,12,999`).

### `GET /api/check_comando`
- **Uso:** Polling constante (cada 3 segundos) desde el hardware para detectar eventos de "abrir puerta" generados de manera asincrónica en la Web.
- **Respuesta:** Retorna el texto del comando pendiente (Ej. `ABRIR` o `SET_TIME|2023-08-15T08:00:00`) o `NADA` en su defecto. Automáticamente cambia el comando a `ENVIADO`.

### `POST /api/recibir_log`
- **Uso:** Almacena de manera permanente un registro capturado por la huella.
- **Payload:** `{ "id": "1", "estado": "EXITO", "fecha_dispositivo": "2023-10-15 08:00:00", "token": "istae1805A" }`
- **Respuesta:** JSON indicando `{"status": "success"}`.

---

## 4. Flujos Clave del Sistema

### 4.1. Flujo de Acceso Local (ESP8266 -> Servidor)
1. El usuario coloca la huella en el lector.
2. El NodeMCU lee el ID y lo contrasta con la variable global en memoria `listaBlanca`.
3. Si existe, enciende el Pin de relé (`RELAY_PIN = 5`) por 3 segundos.
4. Intenta emitir un POST a `/api/recibir_log`.
5. **Fallo de red:** Si no hay respuesta satisfactoria, el registro en texto plano se escribe en `/respaldo_logs.txt` en el FileSystem del chip (`LittleFS`). Cada 30 segundos, si se recupera la conexión, procesa las líneas pendientes y las emite vía POST.

### 4.2. Flujo de Asistencia Remota (Navegador -> Servidor)
1. El docente entra al sistema e interactúa con el botón de asistir remoto (`/docente/dashboard`).
2. Se ejecuta un Javascript del navegador que invoca a la API nativa de `geolocation` y rellena `input`s ocultos del formulario.
3. Se selecciona o captura en el acto una foto mediante un `input file` ajustado.
4. Se emite un `POST` Multipart hacia `/docente/marcar_web`.
5. El servidor recupera la información, sanitiza y guarda la foto con `secure_filename` en el directorio de `uploads` con sufijos únicos, guardando la ubicación y el estado en el modelo `Log`.

### 4.3. Flujo de Comando de Apertura Asincrónica
1. Un Admin o Docente (autorizado) presiona el botón en la web `/admin/abrir` o `/docente/abrir_puerta`.
2. El backend añade una fila al modelo `Comando` con la directiva `ABRIR` y guarda un registro de auditoría en la tabla `Log`.
3. En su ciclo habitual, el NodeMCU pregunta en `/api/check_comando` y el servidor le suministra la fila más antigua. El hardware lee `ABRIR` e instantáneamente activa el relé.

---

## 5. Implementación de Seguridad
- **Sistema de Archivos:** Las fotos de evidencia (`uploads/`) se sirven a través de Flask `send_from_directory` mediante la ruta `/uploads/<filename>`, la cual incluye el decorador `@login_required` para impedir accesos anónimos a fotos privadas.
- **Contraseñas:** Hasheadas en base de datos bajo el algoritmo PBKDF2 (SHA-256).
- **Protección API Hardware:** Todo endpoint con método `POST` verifica un Token Pre-Compartido (`TOKEN_NODE`), evitando inyecciones de logs basura en caso de que se descubra la URL de la API.
