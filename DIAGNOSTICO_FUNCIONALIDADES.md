# Diagnóstico de Funcionalidades — Sistema de Control de Acceso ISTAE

**Fecha:** 26 de noviembre de 2026
**Commit analizado:** `e34c62c` (más cambios locales en `app.py` y `templates/perfil.html`)

## 1. Resumen

El sistema es funcional de extremo a extremo: Huella → NodeMCU → Flask → MySQL, con panel web, reportes Excel y asistencia remota con GPS y Face ID. El área más débil es la **seguridad**: existen fallos de autorización que permiten a un docente autenticado escalar privilegios o abrir la puerta. Los fallos funcionales son menores.

## 2. Estado por módulo

| Módulo | Estado |
|---|---|
| Login y roles (admin/docente) | ✅ Funciona |
| API de hardware: `/api/recibir_log` (con token) | ✅ |
| API de hardware: lista blanca, cola de comandos (ABRIR, SET_TIME), estado online | ✅ Funciona, con riesgos (ver §3) |
| CRUD de docentes y permisos, gestión de asistencias paginada | ✅ Funciona, con bugs (ver §4) |
| Reportes Excel (matricial y de permisos) | ✅ |
| Asistencia remota configurable (rango de fechas y horas) + GPS + foto | ✅ |
| Registro de rostro y Face ID | ⚠️ Funciona, pero es eludible |
| Cambios locales sin commit (fix JSON en `registrar_rostro`, botón Cancelar) | ✅ Correctos |

## 3. Hallazgos críticos (seguridad)

1. **Rutas sin verificación de rol admin.** Cualquier usuario autenticado puede usarlas:
   - `/actualizar_docente`: permite modificar a cualquier usuario, incluida la contraseña del admin (escalada de privilegios).
   - `/eliminar_docente/<id>`, `/editar_docente/<id>`, `/toggle_permiso/<id>`.
   - `/admin/abrir`: cualquier docente puede abrir la puerta.
2. **Face ID eludible.** En `docente_marcar`, la distancia euclidiana se calcula con `zip()` sin validar la longitud del descriptor recibido. Un descriptor vacío o corto produce una distancia cercana a 0. **Corrección:** exigir exactamente 128 valores numéricos.
3. **Credenciales en el repositorio.** `config.py` contiene la contraseña de MySQL, el `SECRET_KEY` y el token del NodeMCU. El token también aparece en `nodered5.ino` y en `biometrico_driver.py`, y la contraseña inicial del admin está en `app.py`. Como ya constan en el historial de git, **hay que rotarlas**, no basta con borrarlas.
4. **Subida de archivos sin restricción.** La foto de evidencia acepta cualquier extensión (por ejemplo `.html` o `.svg`, lo que permite XSS almacenado cuando el admin la abre) y no tiene límite de tamaño (`MAX_CONTENT_LENGTH`). Además, `/uploads/<filename>` es accesible para cualquier usuario autenticado y los nombres de archivo son predecibles.
5. **APIs de hardware sin token.** `/api/check_comando` y `/api/sincronizar` son públicas: un tercero puede consumir comandos pendientes, leer los IDs autorizados y falsear el estado "online".
6. **Sin protección CSRF.** Además, varias acciones que modifican datos se ejecutan por GET (abrir puerta, eliminar asistencia, eliminar permiso, eliminar docente).

## 4. Bugs funcionales

- **Comandos sin caducidad.** Un ABRIR enviado con el hardware offline se ejecuta cuando el NodeMCU se reconecta, aunque sea horas después. Los comandos deben expirar a los 30–60 s. Además, se marcan como `ENVIADO` sin confirmación del hardware.
- **Errores 500 no controlados:**
  - Eliminar un docente que tiene permisos (la relación no tiene `cascade` y `user_id` no admite NULL).
  - `username` o `biometric_id` duplicados al crear o editar un docente.
  - Fechas inválidas en los filtros de búsqueda.
  - Valores de latitud o longitud no numéricos.
- **Reporte matricial:** no considera los permisos; un docente con permiso aparece como "Sin registros".
- **Zona horaria inconsistente:** el nombre de la foto y las fechas por defecto del reporte usan `datetime.now()` sin la zona de Ecuador.
- **Contador "marcaciones hoy":** incluye las aperturas remotas.
- **Re-registro de rostro:** el docente puede reemplazar su rostro sin aprobación del admin, y la prueba de vida (liveness) se valida solo en el navegador.

## 5. Higiene del repositorio

- Se versionan `venv/`, `__pycache__/`, `instance/sistema_tesis.db` y fotos de docentes en `uploads/` (datos personales).
- Los modelos `static/models/tiny_face_detector_*` **no están en git**, pero las plantillas los usan: un despliegue limpio desde el repositorio deja Face ID sin funcionar.
- Archivos o dependencias sobrantes: `app_resp.py` (copia de respaldo) y `pandas`/`numpy` en `requirements.txt` (no se usan en `app.py`).
- `import time` (línea 128 de `app.py`) oculta el `time` de `datetime`.
- No hay pruebas automatizadas.

## 6. Plan de corrección priorizado

1. Agregar la verificación de rol admin a las rutas listadas en §3.1 y validar la longitud del descriptor facial.
2. Restringir las subidas a extensiones de imagen y fijar `MAX_CONTENT_LENGTH`; exigir el token en las APIs de hardware; agregar caducidad a los comandos.
3. Mover las credenciales a variables de entorno (`.env`), rotar todas las credenciales expuestas y retirar `venv/`, `uploads/` y la base de datos del repositorio.
4. Incorporar CSRF (Flask-WTF) y migrar las acciones destructivas a POST.
5. Manejar los errores 500 y unificar la zona horaria.
