# Sistema de Control de Acceso Biométrico - ISTAE

Este proyecto es un sistema de control de acceso biométrico basado en la web, desarrollado para el ISTAE. Gestiona el acceso de usuarios a través de una interfaz web y un componente de hardware (ESP8266 con sensor biométrico). El sistema registra cada intento de acceso y proporciona un panel de control web para administradores y docentes.

## Características

- **Autenticación de usuarios:** Roles separados para administradores y docentes.
- **Panel de administración:** Permite la gestión completa de los usuarios docentes (crear, editar, eliminar).
- **Panel de docente:** Permite a los docentes ver sus registros de acceso y abrir la puerta de forma remota.
- **Monitorización en tiempo real:** Muestra los últimos eventos de acceso en el panel de administración.
- **Informes de asistencia:** Genera informes de asistencia en formato Excel, con filtros por fecha y docente.
- **Apertura remota de la puerta:** Permite a los administradores y docentes autorizados abrir la puerta desde la interfaz web.
- **Integración de hardware:** Se integra con un dispositivo ESP8266 para el escaneo biométrico y el control de la puerta.
- **Capacidad sin conexión:** El ESP8266 almacena los registros de acceso si el servidor no está disponible y los envía más tarde.

## Pila Tecnológica

- **Backend:** Flask, Flask-SQLAlchemy, Flask-Login
- **Base de datos:** MySQL (inicialmente configurado para SQLite)
- **Frontend:** Bootstrap 5, Jinja2, JavaScript (con AJAX para actualizaciones en tiempo real)
- **Hardware:** ESP8266 (NodeMCU)
- **Librerías Python:** `openpyxl` para la generación de informes en Excel.

## Hardware (`node.ino`)

El sketch `node.ino` está diseñado para un dispositivo ESP8266/NodeMCU conectado a un sensor biométrico y un relé.

- Se conecta a la red WiFi local mediante WiFiManager para una fácil configuración.
- Sincroniza una "lista blanca" de IDs de usuario autorizados desde el servidor Flask.
- Cuando se escanea una huella digital, comprueba el ID con la lista blanca.
- Si el ID está autorizado, activa un relé para abrir la puerta.
- Envía los registros de acceso al servidor en tiempo real.
- Si el servidor no está disponible, almacena los registros localmente en LittleFS y los envía cuando se restablece la conexión.
- Comprueba periódicamente si hay comandos remotos pendientes en el servidor (como abrir la puerta).

## Configuración e Instalación

1.  **Clonar el repositorio:**
    ```bash
    git clone <url-del-repositorio>
    cd <directorio-del-repositorio>
    ```

2.  **Crear un entorno virtual:**
    ```bash
    python -m venv venv
    source venv/bin/activate  # En Windows: venv\Scripts\activate
    ```

3.  **Instalar las dependencias:**
    ```bash
    pip install -r requirements.txt
    ```

4.  **Configurar la aplicación:**
    - Edita el fichero `config.py` para establecer la `SECRET_KEY` y la `SQLALCHEMY_DATABASE_URI`.
    - El `TOKEN_NODE` en `config.py` debe coincidir con el `TOKEN_NODE` en el fichero `node.ino`.

5.  **Inicializar la base de datos:**
    La base de datos se inicializa automáticamente en la primera ejecución. Se crea un usuario administrador por defecto:
    - **Usuario:** `admin`
    - **Contraseña:** `istae123A*`

6.  **Ejecutar la aplicación:**
    Para desarrollo:
    ```bash
    flask run
    ```
    Para producción, se recomienda usar un servidor WSGI como Gunicorn:
    ```bash
    gunicorn --bind 0.0.0.0:5000 app:app
    ```

## Endpoints de la API (para el ESP8266)

- `GET /api/sincronizar`: Devuelve una cadena de texto separada por comas con los IDs biométricos autorizados.

- `POST /api/recibir_log`: Recibe una entrada de registro desde el ESP8266. Requiere un `TOKEN_NODE` válido.
  - **Payload (JSON):** `{"id": "...", "estado": "...", "fecha_dispositivo": "...", "token": "..."}`

- `GET /api/check_comando`: Comprueba si hay comandos remotos pendientes (por ejemplo, "ABRIR").

## Modelos de la Base de Datos

- **User:** Almacena la información de los usuarios.
  - `id`: Clave primaria.
  - `biometric_id`: El ID del sensor biométrico.
  - `nombre`: Nombre completo del usuario.
  - `username`: Nombre de usuario para el inicio de sesión.
  - `password`: Contraseña hasheada.
  - `rol`: `'admin'` o `'docente'`.
  - `acceso_puerta`: `1` si el usuario puede abrir la puerta con su huella, `0` en caso contrario.

- **Log:** Almacena los registros de acceso.
  - `id`: Clave primaria.
  - `fecha`: Marca de tiempo del evento.
  - `usuario_id`: El ID biométrico del usuario.
  - `tipo_evento`: Por ejemplo, "Asistencia + puerta", "Apertura Remota".
  - `origen`: Por ejemplo, "Huella", "Panel Control".

- **Comando:** Almacena los comandos que debe ejecutar el ESP8266.
  - `id`: Clave primaria.
  - `instruccion`: El comando (por ejemplo, "ABRIR").
  - `estado`: `'PENDIENTE'` o `'LISTO'`.

## Configuración (`config.py`)

- `SECRET_KEY`: Clave secreta para la gestión de sesiones.
- `SQLALCHEMY_DATABASE_URI`: Cadena de conexión a la base de datos.
- `TOKEN_NODE`: Token secreto para autenticar las peticiones del ESP8266. Debe ser el mismo que en el fichero `node.ino`.