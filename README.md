# Sistema de Control de Acceso y Asistencia Biométrico

## 1. Descripción General

Este proyecto es un sistema de control de acceso y registro de asistencia automatizado basado en la web. Centraliza la gestión de un biométrico Hikvision en un servidor web, eliminando la necesidad de una PC dedicada en el punto de acceso.

El sistema permite la gestión de usuarios (docentes), el control de acceso a través de una puerta, el monitoreo de eventos en tiempo real y la generación de reportes de asistencia.

## 2. Arquitectura

El proyecto se compone de tres elementos principales:

*   **Backend (Aplicación Flask):** El cerebro del sistema, escrito en Python con el framework Flask. Gestiona la lógica de negocio, la autenticación, la comunicación con la base de datos y expone una API para el hardware.
*   **Frontend:** Una interfaz web responsiva construida con **Bootstrap 5** y **JavaScript**, que permite la administración del sistema y la visualización de datos en tiempo real.
*   **Hardware (NodeMCU):** Un microcontrolador NodeMCU (ESP8266) actúa como un puente IoT. Se comunica con el biométrico, valida localmente los permisos de acceso, activa el relé de la puerta y reporta los eventos al servidor central.

## 3. Funcionalidades Principales

*   **Autenticación de Usuarios:** Roles diferenciados para `admin` y `docente`.
*   **Gestión de Docentes:** Creación, edición y eliminación de usuarios.
*   **Control de Acceso por Huella:** Asignación de permisos individuales para que un usuario pueda abrir la puerta con su huella.
*   **Apertura Remota:** Los administradores y docentes con permiso pueden abrir la puerta desde la interfaz web.
*   **Monitor de Eventos en Tiempo Real:** El panel de administrador muestra las asistencias y los intentos de acceso fallidos sin necesidad de recargar la página.
*   **Reportes de Asistencia:** Generación de reportes de asistencia en formato Excel, con filtrado por fecha y docente.
*   **Sincronización Offline:** El NodeMCU descarga periódicamente la lista de usuarios autorizados para poder operar incluso si pierde la conexión a internet temporalmente.

## 4. API para NodeMCU

La aplicación expone los siguientes endpoints para la comunicación con el hardware:

*   #### `GET /api/sincronizar`
    El NodeMCU utiliza este endpoint para descargar la "lista blanca" de IDs de usuarios que tienen permiso para abrir la puerta.
    *   **Respuesta Exitosa (200):** Una cadena de texto con los IDs biométricos separados por comas (ej: `999,5,9,12`).

*   #### `POST /api/recibir_log`
    El NodeMCU envía un reporte a este endpoint cada vez que se produce un evento en el biométrico.
    *   **Cuerpo de la Petición (JSON):**
        ```json
        {
          "id": "123",
          "estado": "ASISTENCIA_EXITO",
          "token": "istae1805A"
        }
        ```
    *   **Respuesta Exitosa (200):** `{"status": "success"}`

*   #### `GET /api/check_comando`
    El NodeMCU sondea este endpoint periódicamente (cada 2 segundos) para verificar si hay una orden de apertura remota enviada desde la aplicación web.
    *   **Respuesta (200):**
        *   `ABRIR`: Si hay una orden de apertura pendiente.
        *   `NADA`: Si no hay órdenes pendientes.

## 5. Instalación y Puesta en Marcha

1.  **Clonar el Repositorio:**
    ```bash
    git clone <URL_DEL_REPOSITORIO>
    cd <NOMBRE_DEL_PROYECTO>
    ```
2.  **Crear y Activar Entorno Virtual:**
    ```bash
    python3 -m venv venv
    source venv/bin/activate
    ```
3.  **Instalar Dependencias:**
    ```bash
    pip install -r requirements.txt
    ```
4.  **Configurar la Aplicación:**
    Revisa el archivo `config.py` para ajustar la `SECRET_KEY` si es necesario.
5.  **Ejecutar la Aplicación:**
    *   Para desarrollo:
        ```bash
        flask run
        ```
    *   Para producción, se recomienda usar un servidor WSGI como Gunicorn:
        ```bash
        gunicorn --bind 0.0.0.0:5000 app:app
        ```

## 6. Migración de SQLite a MySQL/MariaDB

Para entornos de producción, es altamente recomendable migrar de SQLite a un sistema de base de datos más robusto como MySQL o MariaDB.

### Paso 1: Exportar los Datos de SQLite

Ya hemos realizado este paso y guardado el resultado en `backup_sqlite.sql`. Este archivo contiene los comandos SQL para recrear la estructura y los datos.

### Paso 2: Ajustar el Archivo de Volcado (`.sql`)

Deberás abrir `backup_sqlite.sql` y hacer pequeños cambios de sintaxis en las sentencias `CREATE TABLE` para que sean compatibles con MySQL.

*   **Ejemplo de cambio:**

    **Sintaxis de SQLite:**
    ```sql
    CREATE TABLE usuarios (
        id INTEGER PRIMARY KEY AUTOINCREMENT,
        nombre TEXT NOT NULL,
        ...
    );
    ```

    **Sintaxis equivalente en MySQL/MariaDB:**
    ```sql
    CREATE TABLE usuarios (
        id INT PRIMARY KEY AUTO_INCREMENT,
        nombre VARCHAR(100) NOT NULL,
        ...
    );
    ```
*   **Cambios comunes:**
    *   `INTEGER PRIMARY KEY AUTOINCREMENT` -> `INT PRIMARY KEY AUTO_INCREMENT`
    *   `TEXT` (para campos cortos) -> `VARCHAR(255)`
    *   `TEXT` (para campos largos) -> `TEXT`
    *   `DATETIME` -> `DATETIME` (generalmente compatible)
    *   `INTEGER` -> `INT`
    *   Las sentencias `INSERT INTO ...` son compatibles y no necesitan cambios.
    *   Puedes eliminar las líneas `PRAGMA`, `BEGIN TRANSACTION;` y `COMMIT;` del archivo.

### Paso 3: Instalar el Driver de Python para MySQL

La aplicación necesita un "conector" para hablar con MySQL. Instálalo con pip:

```bash
# Opción 1: mysqlclient (más rápido, pero a veces requiere compilación)
pip install mysqlclient

# Opción 2: PyMySQL (más fácil de instalar, puro Python)
pip install PyMySQL
```

### Paso 4: Cambiar la Configuración en `app.py`

Modifica la línea `SQLALCHEMY_DATABASE_URI` para que apunte a tu nueva base de datos.

*   **Si instalaste `PyMySQL`:**
    ```python
    # La URI debe empezar con 'mysql+pymysql://'
    app.config['SQLALCHEMY_DATABASE_URI'] = 'mysql+pymysql://<user>:<password>@<host>/<database_name>'
    ```
*   **Si instalaste `mysqlclient`:**
    ```python
    # La URI debe empezar con 'mysql://'
    app.config['SQLALCHEMY_DATABASE_URI'] = 'mysql://<user>:<password>@<host>/<database_name>'
    ```
    Reemplaza `<user>`, `<password>`, `<host>` y `<database_name>` con tus credenciales.

### Paso 5: Importar los Datos

Finalmente, crea una base de datos vacía en tu servidor MySQL/MariaDB y luego importa el archivo `backup_sqlite.sql` (ya modificado) usando la línea de comandos de `mysql`:

```bash
mysql -u <user> -p <database_name> < backup_sqlite.sql
```

Después de estos pasos, al reiniciar tu aplicación Flask, se conectará a la nueva base de datos MySQL/MariaDB con todos tus datos migrados.
