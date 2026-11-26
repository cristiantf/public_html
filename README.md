# Sistema de Control de Acceso Biométrico - ISTAE

Sistema web de control de acceso y asistencia docente del ISTAE. Integra un biométrico de huella Hikvision DS-K1T8003EF, un NodeMCU ESP8266 que controla la cerradura y un backend Flask con panel administrativo, asistencia remota (GPS, foto y reconocimiento facial) y reportes Excel.

## Características

- **Roles:** administrador y docente, con verificación de rol en cada ruta administrativa.
- **Dashboard en tiempo real (AJAX):** últimas marcaciones, total de asistencias del día y estado del hardware (en línea/desconectado).
- **Gestión de docentes, asistencias y permisos:** vistas dedicadas con paginación en el servidor (20–30 registros por página).
- **Apertura remota de la puerta:** mediante una cola de comandos que el NodeMCU consulta; los comandos caducan a los 60 s.
- **Registro diferenciado de eventos:** `Asistencia + puerta` (usuario en lista blanca) y `Asistencia` (marcación sin apertura).
- **Asistencia remota configurable:** el admin la activa, desactiva o programa por rango de fechas y horas. Exige GPS, admite foto de evidencia y, opcionalmente, verificación facial (Face ID con face-api.js).
- **Reportes Excel:** reporte matricial de asistencia (mañana/tarde, con permisos) y reporte de permisos.
- **Sincronización horaria** del biométrico desde el panel.
- **Términos, Política de Uso y Protección de Datos (LOPDP):** aceptación obligatoria y versionada, con constancia en la base de datos (fecha, IP, navegador y hash del texto) y vista de control para el administrador.
- **Cámara frontal o trasera** en el registro de rostro, la verificación y la foto de evidencia.
- **Seguridad:** protección CSRF, secretos fuera del código, token del hardware, validación de archivos subidos (ver [documentacion_tecnica.md](documentacion_tecnica.md#5-seguridad)).

## Pila tecnológica

- **Backend:** Flask 3, Flask-SQLAlchemy, Flask-Login, openpyxl, Pillow.
- **Base de datos:** MySQL (PyMySQL) vía SQLAlchemy.
- **Frontend:** Jinja2, Bootstrap 5, JavaScript, face-api.js (modelos locales en `static/models/`).
- **Hardware:** NodeMCU ESP8266 + relé + Hikvision DS-K1T8003EF (ISAPI con Digest Auth). Firmware: [nodered5.ino](nodered5.ino) v3.0.
- **Producción:** Nginx (SSL) → Gunicorn (3 workers) administrado por systemd (`biometrico.service`).

## Instalación rápida

```bash
git clone <url>
cd <directorio>
python3 -m venv venv
source venv/bin/activate
pip install -r requirements.txt
```

Cree `instance/.env` con las credenciales (ver [GUIA_IMPLEMENTACION.md](GUIA_IMPLEMENTACION.md), Parte 1, Paso 4). `config.py` no contiene secretos y `instance/` está excluida de git.

En producción, después de cualquier cambio en el código:

```bash
sudo systemctl restart biometrico.service
```

## API del hardware (NodeMCU)

| Endpoint | Uso | Autenticación |
|---|---|---|
| `GET /api/sincronizar` | Lista blanca de `biometric_id` con acceso a puerta, separados por comas | Cabecera `X-Token` (si `EXIGIR_TOKEN_HARDWARE=true`) |
| `GET /api/check_comando` | Devuelve el comando pendiente más antiguo (`ABRIR`, `SET_TIME\|<iso>`) o `NADA` | Cabecera `X-Token` (si `EXIGIR_TOKEN_HARDWARE=true`) |
| `POST /api/recibir_log` | Registra una marcación de huella | Campo `token` en el JSON (siempre) |

Cualquiera de los tres actualiza el estado "en línea" del hardware. Los comandos que no se entregan en 60 s pasan a `EXPIRADO`. Detalle completo en [documentacion_tecnica.md](documentacion_tecnica.md#3-api-del-hardware).

## Modelos de datos

- **User** (`usuarios`): usuarios, rol, acceso a puerta y descriptor facial.
- **Log** (`logs`): marcaciones (huella y remotas) y aperturas remotas, con GPS y foto.
- **Comando** (`comandos`): cola de órdenes hacia el hardware, con fecha de creación para su caducidad.
- **Permiso** (`permisos`): ausencias justificadas por docente y fecha.
- **ConfigSistema** (`config_sistema`): configuración global (asistencia remota, Face ID).
- **AceptacionLegal** (`aceptaciones_legales`): constancias de aceptación de los documentos legales.

## Documentación

| Documento | Contenido |
|---|---|
| [documentacion_tecnica.md](documentacion_tecnica.md) | Arquitectura, modelos, API, rutas web, flujos y seguridad |
| [GUIA_IMPLEMENTACION.md](GUIA_IMPLEMENTACION.md) | Instalación desde cero, actualización y verificación del hardware |
| [FLUJO_ASISTENCIA_REMOTA.md](FLUJO_ASISTENCIA_REMOTA.md) | Flujo completo de la asistencia remota y Face ID |
| [estadoactual.md](estadoactual.md) | Estado del proyecto, incidencias y deuda técnica |
| `files/`, `isapi.pdf` | Manual de referencia ISAPI de Hikvision |

## Solución de problemas

### El biométrico marca pero no se registra en el sistema
1. **Conexión física:** el cable de red del Hikvision (IP `192.168.1.22`) debe estar conectado y el equipo accesible desde la red del NodeMCU.
2. **Servicio:** `sudo systemctl status biometrico.service` debe mostrar `active (running)`.
3. **Token:** si `EXIGIR_TOKEN_HARDWARE=true`, el firmware cargado debe enviar `X-Token` con el mismo `TOKEN_NODE` de `instance/.env`.
4. **Monitor Serie:** conecte el NodeMCU por USB a 115200 baudios para ver si recibe eventos del biométrico y si el servidor responde.

### El panel muestra el hardware "Desconectado"
El estado se calcula con la última consulta del NodeMCU (archivo `last_seen.txt`, umbral de 60 s). Revise WiFi del NodeMCU (portal `NODE_PUERTA_ISTAE`) y que el servidor no responda `403` al token.
