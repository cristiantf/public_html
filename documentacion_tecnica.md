# Documentación Técnica: Sistema de Control de Acceso ISTAE

## 1. Arquitectura del Sistema
El sistema sigue un modelo Cliente-Servidor (con clientes tanto Web como de Hardware IoT), desarrollado en la pila tecnológica de **Python/Flask, MySQL y C++ (ESP8266)**.

- **Frontend Web:** Jinja2 (server-side rendering) enriquecido con JavaScript para peticiones AJAX. Utiliza **Paginación dinámica** en vistas pesadas (como Historial de Asistencias y Permisos) para alivianar la carga del DOM y memoria.
- **Backend Servidor:** Flask centralizado (`app.py`), encargado de despachar vistas y APIs. Los procesos de formularios (Creación de Usuarios, Permisos, Sincronización) se procesan en rutas HTTP independientes con métodos `GET` y `POST` tradicionales. El servicio corre sobre **Gunicorn** (3 workers) administrado por **systemd** (`biometrico.service`), detrás de un proxy inverso **Nginx** con SSL.
- **Capa de Persistencia:** Base de datos MySQL con ORM **SQLAlchemy**. Se emplea `.paginate()` nativo de Flask-SQLAlchemy para limitar la extracción de memoria a "chunks" de 20 o 30 registros.
- **Hardware Periférico:** Placa de desarrollo NodeMCU ESP8266 conectada al biométrico Hikvision DS-K1T8003EF vía red local (IP fija `192.168.1.22`).

---

## 2. Modelos de Base de Datos (ORM SQLAlchemy)

1. **`User` (`usuarios`):** Atributos como `biometric_id`, `nombre`, `rol`, `acceso_puerta`, etc.
2. **`Log` (`logs`):** Guarda la historia (asistencia y apertura). Posee campos para soporte remoto como `latitud`, `foto_path`, etc. El campo `tipo_evento` distingue entre `Asistencia + puerta` (acceso con apertura de puerta) y `Asistencia` (marcación sin apertura de puerta).
3. **`Comando` (`comandos`):** Tabla de encolamiento de órdenes (Ej. `ABRIR` o `SET_TIME|2026-06-29T14:30:00`).
4. **`Permiso` (`permisos`):** Registro de ausencias justificadas y permisos administrativos.
5. **`ConfigSistema` (`config_sistema`):** Tabla Singleton (1 sola fila) para variables de entorno lógicas, como habilitar o deshabilitar (o programar) la asistencia remota desde la web.

---

## 3. Especificación de la API (Hardware - Servidor)

El sistema provee endpoints específicos, y cada vez que el NodeMCU los toca, el servidor actualiza internamente un registro (`last_seen.txt`) para medir su "Estado En Línea".

### `GET /api/sincronizar`
- **Uso:** El NodeMCU descarga periódicamente (cada 10 minutos) la lista de IDs de usuarios autorizados. Actualiza el estado online.
- **Respuesta:** Lista de `biometric_id` separados por comas. Ej: `999,1,4,5,6,7`

### `GET /api/check_comando`
- **Uso:** Polling constante (cada 3 segundos) desde el hardware. Actualiza el estado online.
- **Respuesta:** Retorna la instrucción pendiente (`ABRIR`, `SET_TIME|<iso_time>`) o `NADA`. El estado del comando se marca como `ENVIADO` al ser consultado.

### `POST /api/recibir_log`
- **Uso:** Almacena registros capturados por la huella. Actualiza el estado online.
- **Payload JSON:**
  ```json
  {
    "id": "1",
    "estado": "EXITO",
    "fecha_dispositivo": "2026-06-29T14:43:19",
    "token": "istae1805A",
    "origen": "Huella"
  }
  ```
- **Campos:**
  - `id`: El `employeeNoString` del biométrico Hikvision (equivale a `biometric_id` en la BD).
  - `estado`: `EXITO` cuando el usuario está en la lista blanca (se abre la puerta), `DENEGADO` cuando no lo está (solo registra asistencia). Si es `EXITO`, se registra como `Asistencia + puerta`; si es `DENEGADO`, se registra como `Asistencia`. Ambos tipos son incluidos en los reportes Excel.
  - `fecha_dispositivo`: Fecha y hora del biométrico en formato ISO 8601. El servidor toma los primeros 19 caracteres (`YYYY-MM-DD HH:MM:SS`) descartando cualquier sufijo de zona horaria, ya que la hora del Hikvision ya está configurada en hora Ecuador.
  - `token`: Token de seguridad que debe coincidir con `config.TOKEN_NODE`.

---

## 4. Flujos Clave del Sistema

### 4.1. Monitorización en Tiempo Real (AJAX)
1. El Dashboard principal (`/admin/dashboard`) renderiza una tabla vacía y tarjetas de métricas.
2. Un script en JS solicita `/api/logs_admin` cada 3.5 segundos.
3. El backend realiza tres operaciones críticas: 
   - Devuelve los últimos 20 logs.
   - Suma explícitamente y de manera absoluta todas las marcaciones del día actual con consultas directas a BD.
   - Lee la última estampa de tiempo del Hardware para determinar si el NodeMCU está conectado (`True`) o desconectado (`False`).
4. El Frontend actualiza los números, iconos de WiFi y la tabla HTML instantáneamente sin requerir que la página se recargue.

### 4.2. Paginación de Registros Administrativos
1. Cuando el administrador entra a "Gestión de Asistencias" o "Gestión de Permisos", Flask recibe el parámetro de página (`?page=1`).
2. Mediante SQLAlchemy `.paginate(page=X, per_page=30)`, el servidor extrae estrictamente lo que se necesita mostrar, devolviendo un objeto `Pagination`.
3. Esto evita la caída del sistema por desbordamiento de memoria cuando la base de datos supera miles de entradas.

### 4.3. Flujo de Marcación Biométrica (Hardware → Nube)
1. El biométrico Hikvision DS-K1T8003EF detecta una huella y genera un evento ISAPI con el `employeeNoString` y `dateTime`.
2. El NodeMCU, que mantiene una conexión abierta de streaming al endpoint `/ISAPI/Event/notification/alertStream` con autenticación Digest (incluyendo soporte QOP), recibe el JSON del evento.
3. El firmware extrae el `employeeNoString` (ID del usuario) y `dateTime` (fecha/hora del biométrico).
4. Si el ID está en la lista blanca local, activa el relé (abre la puerta por 3 segundos) y envía el log a la nube con estado `EXITO` (se registra como `Asistencia + puerta`). Si no está en la lista blanca, envía con estado `DENEGADO` (se registra como `Asistencia`, sin apertura de puerta).
5. El backend Flask recibe el POST, parsea la fecha (tomando los primeros 19 caracteres del ISO 8601), y lo guarda en MySQL como un `Log` naive (sin timezone).

### 4.4. Sincronización de Hora del Biométrico
1. El administrador puede enviar un comando de sincronización horaria desde el panel web.
2. El comando `SET_TIME|<iso_time>` se encola en la tabla `Comando`.
3. El NodeMCU lo detecta en su próximo polling a `/api/check_comando`.
4. El firmware construye un XML ISAPI y lo envía al biométrico mediante un PUT con autenticación Digest al endpoint `/ISAPI/System/time`.

### 4.5. Apertura Remota y Resiliencia
- Continúa el flujo asincrónico a través de la tabla de "Comandos", permitiendo aperturas sin conexión entrante abierta en el firewall del hardware local.

---

## 5. Implementación de Seguridad
- Las rutas sensibles están separadas físicamente a lo largo de diversas vistas con decoradores unificados de roles.
- `TOKEN_NODE` protege contra inyección de falsas lecturas biométricas.
- Las peticiones en masa están mitigadas por los esquemas de paginación y limitadores `LIMIT` en SQL, resguardando al servidor contra vulnerabilidades de "Denegación de Servicio (DoS)" accidentales por consumo de RAM.

---

## 6. Infraestructura de Producción

| Componente | Detalle |
|---|---|
| **Servidor Web** | Nginx (proxy inverso SSL) → Gunicorn (3 workers, puerto 5000) |
| **Servicio systemd** | `biometrico.service` — reiniciar con `sudo systemctl restart biometrico.service` |
| **Base de Datos** | MySQL (`user1_biom`) vía SQLAlchemy |
| **Certificado SSL** | Gestionado por HestiaCP / Let's Encrypt |
| **Red IoT** | NodeMCU (WiFi) ↔ Hikvision (Ethernet, IP `192.168.1.22`, puerto 80) |
