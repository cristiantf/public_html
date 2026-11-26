# Guía de Implementación y Mantenimiento

Pasos para desplegar el Sistema de Control de Acceso desde cero, actualizar una instalación existente y verificar el hardware.

---

## Parte 1: Implementación inicial (desde cero)

### Paso 1: Entorno del servidor

1. Acceda al servidor por SSH.
2. Clone el repositorio:
   ```bash
   git clone <URL_DEL_REPOSITORIO>
   cd <NOMBRE_DEL_DIRECTORIO>
   ```
3. Cree el entorno virtual. Use el nombre `venv`, que es el que espera el servicio systemd:
   ```bash
   python3 -m venv venv
   source venv/bin/activate
   pip install -r requirements.txt
   ```

### Paso 2: Base de datos MySQL

En el panel del servidor (HestiaCP o cPanel):

1. Cree una base de datos (por ejemplo `user1_biom`).
2. Cree un usuario con contraseña segura y dele todos los privilegios sobre esa base.
3. Si MySQL está en otro servidor, autorice la IP del servidor de la aplicación como host remoto y use esa dirección en `DB_HOST`.

### Paso 3: Generar secretos

Genere valores aleatorios para `SECRET_KEY` y `TOKEN_NODE`:

```bash
python3 -c "import secrets; print(secrets.token_urlsafe(48))"   # SECRET_KEY
python3 -c "import secrets; print(secrets.token_urlsafe(24))"   # TOKEN_NODE
```

### Paso 4: Configuración de la aplicación (`instance/.env`)

`config.py` no contiene secretos: los lee de **`instance/.env`**. Créelo con este contenido:

```ini
SECRET_KEY=<cadena aleatoria larga>
DB_USER=<usuario MySQL>
DB_PASS=<contraseña MySQL>
DB_HOST=localhost
DB_NAME=<base de datos>
TOKEN_NODE=<token aleatorio, el mismo que en nodered5.ino>
EXIGIR_TOKEN_HARDWARE=true
ADMIN_INITIAL_PASSWORD=<contraseña del primer admin>
HIKVISION_USER=admin
HIKVISION_PASS=<contraseña del biométrico>
```

```bash
chmod 600 instance/.env
```

- La carpeta `instance/` está en `.gitignore`: **nunca** suba este archivo a git.
- Las mismas claves pueden definirse como variables de entorno; tienen prioridad sobre el archivo.
- Si falta una variable obligatoria, la aplicación no arranca y el error indica cuál.
- La descripción de cada variable está en [documentacion_tecnica.md §6](documentacion_tecnica.md#6-configuración-instanceenv).

### Paso 5: Primer arranque

1. Ejecute la aplicación. SQLAlchemy crea las tablas y el usuario `admin`:
   ```bash
   flask run --host=0.0.0.0 --port=5000
   ```
2. Inicie sesión como `admin` con la contraseña de `ADMIN_INITIAL_PASSWORD`. Si la dejó vacía, la contraseña generada se imprime en el log del primer arranque. Cámbiela desde **Perfil**.

### Paso 6: Servicio en producción (systemd + Gunicorn)

Archivo `/etc/systemd/system/biometrico.service`:

```ini
[Unit]
Description=Gunicorn instance to serve Acceso Biometrico
After=network.target

[Service]
User=<usuario>
Group=www-data
WorkingDirectory=<ruta del proyecto>
Environment="PATH=<ruta del proyecto>/venv/bin"
ExecStart=<ruta del proyecto>/venv/bin/gunicorn --workers 3 --bind 0.0.0.0:5000 app:app

[Install]
WantedBy=multi-user.target
```

```bash
sudo systemctl daemon-reload
sudo systemctl enable --now biometrico.service
```

El usuario del servicio debe poder leer `instance/.env` y escribir en `uploads/` y en `last_seen.txt`. Configure Nginx como proxy inverso con SSL hacia el puerto 5000.

### Paso 7: Firmware del NodeMCU

1. Abra [nodered5.ino](nodered5.ino) en Arduino IDE (placa NodeMCU 1.0, librerías `WiFiManager` y `LittleFS`).
2. Reemplace los marcadores **solo en su copia local**:
   - `CAMBIAR_TOKEN_NODE` → valor de `TOKEN_NODE`.
   - `CAMBIAR_PASS_HIKVISION` → contraseña del biométrico.
   - Revise `HOST_URL` e `ip_bio`.
3. Flashee el NodeMCU. **No haga commit** del archivo con los valores reales.
4. En el primer arranque, conéctese a la red WiFi `NODE_PUERTA_ISTAE` para configurar la red del instituto.

---

## Parte 2: Actualización de una instalación existente

### Paso 1: Respaldo

Antes de actualizar, respalde los datos que no están en git:

```bash
tar czf ~/respaldo_istae_$(date +%Y%m%d).tgz instance/ uploads/
```

> **Importante (actualización a la versión con `.gitignore` nuevo):** versiones anteriores versionaban `venv/`, `uploads/` y la base SQLite. Al actualizar desde una de ellas, `git pull` **borra esas carpetas del disco**. Antes del pull, quítelas del índice:
> ```bash
> git rm -r -q --cached venv __pycache__ instance uploads app_resp.py
> git commit -m "chore: dejar de versionar archivos locales"
> ```
> o restaure `uploads/` desde el respaldo y recree `venv/` (`python3 -m venv venv && venv/bin/pip install -r requirements.txt`) después del pull.

### Paso 2: Actualizar el código

```bash
cd <NOMBRE_DEL_DIRECTORIO>
git pull
source venv/bin/activate
pip install -r requirements.txt
```

Si la actualización mueve los secretos a `instance/.env` y el archivo aún no existe, créelo (Parte 1, Paso 4) **antes** de reiniciar, o la aplicación no arrancará.

### Paso 3: Migraciones de base de datos

`db.create_all()` crea tablas nuevas pero no agrega columnas a tablas existentes.

- **Automáticas:** al arrancar, la app agrega `comandos.creado` si falta.
- **Manuales:** instalaciones muy antiguas sin las columnas de asistencia remota en `logs` necesitan este SQL (phpMyAdmin o cliente MySQL):
  ```sql
  ALTER TABLE `logs`
  ADD COLUMN `latitud` FLOAT NULL DEFAULT NULL AFTER `origen`,
  ADD COLUMN `longitud` FLOAT NULL DEFAULT NULL AFTER `latitud`,
  ADD COLUMN `descripcion` TEXT NULL DEFAULT NULL AFTER `longitud`,
  ADD COLUMN `foto_path` VARCHAR(255) NULL DEFAULT NULL AFTER `descripcion`;
  ```
  Las columnas `usuarios.face_descriptor` y la tabla `config_sistema` también deben existir; la tabla se crea sola, la columna se agrega con:
  ```sql
  ALTER TABLE `usuarios` ADD COLUMN `face_descriptor` TEXT NULL;
  ```

### Paso 4: Reiniciar la aplicación

```bash
sudo systemctl restart biometrico.service
sudo systemctl status biometrico.service
```

Es obligatorio reiniciar después de cualquier cambio en el código: Gunicorn no recarga los módulos solo. Tras el reinicio, los usuarios con una página abierta verán una vez el aviso "La sesión del formulario expiró" si la versión anterior no tenía CSRF.

### Paso 5: Activar el token del hardware

Si `EXIGIR_TOKEN_HARDWARE` está en `false`:

1. Flashee el firmware que envía `X-Token` (Parte 1, Paso 7).
2. Compruebe en el panel que el hardware aparece "en línea".
3. Cambie `EXIGIR_TOKEN_HARDWARE=true` en `instance/.env` y reinicie el servicio.

Si activa el token antes de flashear, el NodeMCU deja de recibir comandos y de actualizar la lista blanca.

---

## Parte 3: Rotación de credenciales

Si alguna credencial se expuso (por ejemplo, en el historial de git):

| Credencial | Dónde cambiarla | Efecto |
|---|---|---|
| Contraseña MySQL | Panel del servidor + `DB_PASS` | Reiniciar servicio |
| `SECRET_KEY` | `instance/.env` | Cierra todas las sesiones |
| `TOKEN_NODE` | `instance/.env` + reflashear firmware | El hardware falla hasta reflashear |
| Contraseña Hikvision | Interfaz del biométrico + reflashear firmware | — |
| Contraseña `admin` | Perfil del admin en la web | — |

---

## Parte 4: Verificación del hardware biométrico

Si las marcaciones de huella no aparecen en el sistema, revise en orden:

1. **Cable de red del biométrico:** el Hikvision DS-K1T8003EF (IP fija `192.168.1.22`) debe estar conectado por Ethernet.
2. **Conectividad:** desde la red local, `ping 192.168.1.22`.
3. **WiFi del NodeMCU:** si no se conecta, crea el portal `NODE_PUERTA_ISTAE` para configurarlo.
4. **Monitor Serie:** NodeMCU por USB a 115200 baudios; muestra eventos recibidos, respuestas del servidor y la cola offline.
5. **Token:** un `403` en el Monitor Serie indica que el `TOKEN_NODE` del firmware no coincide con el del servidor.
6. **Servicio:** `sudo systemctl status biometrico.service` debe estar activo.
7. **Estado en el panel:** se basa en `last_seen.txt` (última consulta del NodeMCU, umbral 60 s).
