# Sistema de Control de Acceso Biométrico - ISTAE

Este proyecto es un sistema de control de acceso biométrico basado en la web, desarrollado para el ISTAE. Gestiona el acceso de usuarios a través de una interfaz web y un componente de hardware (ESP8266 con sensor biométrico Hikvision DS-K1T8003EF). El sistema registra cada intento de acceso y proporciona un panel de control avanzado para administradores.

## Características Actualizadas

- **Autenticación de usuarios:** Roles separados para administradores y docentes.
- **Panel de control Interactivo (Dashboard):** Muestra el estado del hardware (En línea/Desconectado) en tiempo real y el volumen exacto de asistencias procesadas en el día, usando AJAX.
- **Módulos Administrativos Independientes:** La creación de docentes, el registro de permisos, reportes Excel y sincronización horaria operan en sus propias páginas para una experiencia más inmersiva y tradicional.
- **Gestión Paginada de Datos:** La revisión de asistencias y permisos cuenta con Paginación inteligente en el servidor (mostrando bloques de 20-30 registros a la vez), lo cual protege al servidor de quedarse sin memoria cuando el sistema escala.
- **Apertura remota de la puerta:** Vía asincrónica a través de la interfaz web.
- **Registro diferenciado de eventos:** El sistema distingue entre accesos exitosos (`Asistencia + puerta`) y accesos denegados (`Acceso Denegado`) según el estado reportado por el hardware.
- **Estética Corporativa:** Integración del logotipo e imagen institucional del ISTAE en todas las vistas (Login, Dashboard, Favicon).

## Pila Tecnológica

- **Backend:** Flask, Flask-SQLAlchemy, Flask-Login. (Uso intensivo del plugin nativo `.paginate()`).
- **Base de datos:** MySQL (vía ORM SQLAlchemy).
- **Frontend:** Bootstrap 5, Jinja2, JavaScript.
- **Hardware:** NodeMCU ESP8266 + Relé + Hikvision DS-K1T8003EF (Sensor biométrico de huella dactilar).

## Flujo de Datos del Hardware (`nodered5.ino`)

El firmware del NodeMCU se comunica con el biométrico Hikvision vía protocolo **ISAPI con autenticación Digest (QOP)**, escuchando eventos en streaming. Cada marcación de huella detectada se reenvía inmediatamente al backend en la nube.

- El hardware efectúa polling constante con el backend web.
- Cada petición realizada (asistencia, check de comando o sincronización de lista blanca) actualiza una estampa de tiempo en el servidor, lo cual permite al panel central conocer de inmediato si el dispositivo sigue activo y con energía.
- La sincronización de la hora del biométrico se realiza bajo demanda desde el panel admin usando comandos `SET_TIME` a través de la API ISAPI (PUT con Digest Auth).

## Configuración e Instalación

1.  **Clonar el repositorio y entorno:**
    ```bash
    git clone <url>
    python -m venv venv
    source venv/bin/activate
    pip install -r requirements.txt
    ```

2.  **Configurar la aplicación:**
    - Edita el fichero `config.py` con credenciales de DB.
    - Asegura que `TOKEN_NODE` coincide con el del ESP8266.

3.  **Ejecución:**
    Para producción, usar Gunicorn y reiniciar el demonio en systemd:
    ```bash
    sudo systemctl restart biometrico.service
    ```

## Endpoints de la API Central (ESP8266)

- `GET /api/sincronizar`: Devuelve IDs biométricos autorizados (lista blanca separada por comas).
- `POST /api/recibir_log`: Recibe logs presenciales. Acepta JSON con campos `id`, `estado` (`EXITO`/`DENEGADO`), `fecha_dispositivo` (ISO 8601), `token` y `origen`.
- `GET /api/check_comando`: Comprueba si hay comandos remotos pendientes (`ABRIR`, `SET_TIME|<iso_time>`, `NADA`).
*(Cualquiera de los tres endpoints actualiza el estado "Online" del Hardware).*

## Modelos de la Base de Datos

- **User:** Maneja usuarios y privilegios.
- **Log:** Historial de accesos, asistencias y eventos remotos.
- **Comando:** Puente asincrónico para enviar órdenes (abrir puerta, sincronizar hora) desde la Web hacia el hardware.
- **Permiso:** Manejo de excepciones, ausencias y permisos administrativos.

## Troubleshooting

### El biométrico marca pero no registra en la nube
1. **Verificar conexión física:** Asegurar que el cable de red del biométrico Hikvision (IP `192.168.1.22`) esté conectado y que el dispositivo sea accesible desde la red local del NodeMCU.
2. **Verificar Gunicorn:** `sudo systemctl status biometrico.service` — debe estar `active (running)`.
3. **Reiniciar servicio:** `sudo systemctl restart biometrico.service` — necesario después de cada cambio en `app.py`.
4. **Monitor Serie del NodeMCU:** Conectar por USB y abrir Monitor Serie a 115200 baudios para ver si el ESP8266 recibe eventos del biométrico y si logra enviarlos al servidor.