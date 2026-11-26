# Estado Actual del Proyecto: Sistema de Control de Acceso ISTAE

**Última actualización:** 26 de noviembre de 2026.

## 1. Resumen

Solución funcional de extremo a extremo: biométrico Hikvision DS-K1T8003EF, NodeMCU ESP8266 (firmware v3.0) y backend Flask en producción. En noviembre de 2026 se hizo una revisión de seguridad que corrigió fallos de autorización, Face ID, subida de archivos, comandos remotos, CSRF y manejo de secretos (ver §4).

## 2. Componentes

### 2.1 Backend web (Flask)
- **Estado:** ✅ En producción. Gunicorn (3 workers) con systemd (`biometrico.service`) detrás de Nginx con SSL.
- **Funcionalidades:**
  - Roles `admin` y `docente`, con verificación de rol en todas las rutas administrativas.
  - Gestión de docentes, asistencias y permisos con paginación en el servidor.
  - Asistencia remota configurable por fechas y horas, con GPS, foto validada y Face ID opcional (face-api.js con `tiny_face_detector`).
  - Restablecimiento del rostro de un docente por el administrador.
  - Reportes Excel: matricial (mañana/tarde, huella o web, con permisos) y de permisos.
  - Dashboard AJAX con asistencias del día y estado del hardware.
  - Cola de comandos (`ABRIR`, `SET_TIME`) con caducidad de 60 s.
  - Protección CSRF, secretos en `instance/.env` y token del hardware.

### 2.2 Firmware IoT (`nodered5.ino`, v3.0)
- **Estado:** ✅ En producción. La versión del repositorio envía la cabecera `X-Token`; **debe flashearse** antes de activar `EXIGIR_TOKEN_HARDWARE`.
- **Funcionalidades:**
  - WiFi con `WiFiManager` (portal `NODE_PUERTA_ISTAE`).
  - Streaming ISAPI con Digest Auth (QOP) y reconexión con backoff exponencial.
  - Lista blanca descargada cada 10 min; apertura de puerta por 3 s.
  - Envío de marcaciones `EXITO`/`DENEGADO` con **cola offline en LittleFS** (hasta 50, reintento cada 15 s).
  - Polling de comandos cada 3 s (`ABRIR`, `SET_TIME`, `REBOOT`).
  - Monitor de memoria y LED de estado.

### 2.3 Base de datos (MySQL)
- **Estado:** ✅ Modelos `User`, `Log`, `Comando`, `Permiso`, `ConfigSistema`. La columna `comandos.creado` se agrega automáticamente al iniciar.

### 2.4 Frontend
- **Estado:** ✅ Jinja2 + Bootstrap 5 con logotipo institucional. Acciones destructivas mediante formularios `POST` con token CSRF.

## 3. Puntos fuertes
1. Integración robusta con Hikvision (Digest con QOP) y tolerancia a cortes de red gracias a la cola offline.
2. Control de puerta sin abrir puertos en la red local (polling) y con caducidad de comandos.
3. Paginación y límites de consulta que protegen la memoria del servidor.
4. Configuración sin secretos en el código.

## 4. Incidencias resueltas

| Fecha | Incidencia | Causa raíz | Resolución |
|---|---|---|---|
| 2026-06-29 | Las marcaciones de huella no se registraban ni abrían la puerta | Cable de red del Hikvision (`192.168.1.22`) desconectado | Reconexión del cable Ethernet |
| 2026-06-29 | El parseo de fecha descartaba la hora | Se dividía la fecha ISO 8601 por `-` | Usar `fecha_str[:19]` |
| 2026-07-09 | Los reportes no incluían marcaciones de docentes sin acceso a puerta | El evento `Acceso Denegado` no contenía "Asistencia" | Cambio a `Asistencia` y migración de 255 registros |
| 2026-11-26 | Un docente podía cambiar la contraseña del admin, abrir la puerta o eliminar docentes | Rutas sin verificación de rol | Verificación de rol admin en todas las rutas administrativas |
| 2026-11-26 | Face ID se podía saltar con un descriptor vacío | La comparación no validaba la longitud | Exigir 128 valores numéricos |
| 2026-11-26 | Se podían subir archivos HTML como evidencia (XSS) y de cualquier tamaño | Sin validación de tipo ni tamaño | Solo imágenes verificadas con Pillow, límite de 16 MB, acceso a evidencias por dueño |
| 2026-11-26 | Un `ABRIR` enviado con el hardware desconectado abría la puerta horas después | Comandos sin caducidad | Caducidad de 60 s y aviso al admin |
| 2026-11-26 | Acciones ejecutables desde enlaces externos (CSRF) | Sin token CSRF y acciones por `GET` | Token CSRF en todos los `POST` y acciones destructivas solo por `POST` |
| 2026-11-26 | Credenciales y fotos de docentes publicadas en el repositorio | Secretos en `config.py`/firmware; `uploads/`, `venv/` y BD versionados | Secretos en `instance/.env`; archivos locales fuera de git |
| 2026-11-26 | Errores 500 con fechas inválidas, duplicados, GPS no numérico o al eliminar docentes con permisos | Falta de validación | Validaciones y eliminación en cascada de permisos |
| 2026-11-26 | Face ID fallaba en instalaciones nuevas | Modelos `tiny_face_detector` no estaban en git | Modelos agregados al repositorio |

## 5. Pendientes operativos

1. **Rotar las credenciales** que estuvieron publicadas en GitHub (MySQL, `SECRET_KEY`, `TOKEN_NODE`, contraseña del Hikvision y del admin). Ver [GUIA_IMPLEMENTACION.md](GUIA_IMPLEMENTACION.md), Parte 3.
2. **Flashear el firmware** con `X-Token` y activar `EXIGIR_TOKEN_HARDWARE=true`.
3. Evaluar la limpieza del historial de git (contiene credenciales y fotos antiguas).
4. Revisar la conexión del NodeMCU: el último contacto registrado con el servidor fue el 10 de noviembre de 2026.

## 6. Deuda técnica
1. **Blueprints:** todas las rutas siguen en `app.py`; conviene dividirlas en módulos.
2. **Pruebas automáticas:** no hay suite de `pytest`; las verificaciones de noviembre se hicieron con scripts sobre SQLite.
3. **Migraciones:** adoptar Flask-Migrate (Alembic) en lugar de `ALTER TABLE` manuales o automáticos.
4. **Prueba de vida de Face ID** validada en el servidor; hoy se hace solo en el navegador.
5. **Límite de intentos de inicio de sesión** (rate limiting).
6. **Caché** del conteo diario si el volumen de datos crece (por ejemplo, Redis).
