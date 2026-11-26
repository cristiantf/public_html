# Flujo de Asistencia Remota

Proceso completo de una asistencia remota de un docente: desde la interfaz del navegador hasta el registro en la base de datos.

## Resumen

1. **Disponibilidad:** el administrador decide cuándo está permitida (`ConfigSistema`).
2. **Registro de rostro (si se exige Face ID):** el docente registra su rostro una vez desde su perfil.
3. **Frontend:** el navegador obtiene el GPS, verifica el rostro (si aplica) y envía el formulario con la foto opcional.
4. **Backend:** Flask valida disponibilidad, CSRF, rostro, GPS y foto, y registra el `Log`.

---

## 1. Configuración (administrador)

Ruta `/admin/config_asistencia_remota`, guardada en la tabla `config_sistema`:

| Campo | Efecto |
|---|---|
| `asistencia_remota_activa` | Interruptor general. |
| `ar_fecha_inicio`, `ar_fecha_fin` | Rango de fechas permitido (opcional). |
| `ar_hora_inicio`, `ar_hora_fin` | Rango horario diario permitido (opcional; se aplica solo si ambos están definidos). |
| `requiere_face_id` | Exige verificación facial para marcar. |

La función `asistencia_remota_permitida()` evalúa estas reglas en hora de Ecuador. Si no hay configuración guardada, la asistencia remota está permitida.

---

## 2. Registro del rostro (`templates/perfil.html`)

1. El docente pulsa **Registrar Rostro**. Se cargan los modelos de face-api.js desde `static/models/` (`tiny_face_detector`, `face_landmark_68`, `face_recognition`).
2. Durante unos 4 segundos se capturan 20 fotogramas con una sola cara detectada; se piden movimientos de cabeza como prueba de vida básica.
3. Se promedian los descriptores (128 valores) y se envían a `POST /docente/registrar_rostro` como JSON, con la cabecera `X-CSRFToken`.
4. El servidor exige exactamente 128 números finitos y guarda el descriptor en `usuarios.face_descriptor`.
5. **Un docente no puede reemplazar su rostro.** Si necesita cambiarlo, el administrador lo restablece desde **Editar docente → Restablecer Rostro** (`POST /admin/docente/<id>/restablecer_rostro`) y el docente lo registra de nuevo. El botón **Cancelar** detiene la cámara durante el registro.

---

## 3. Frontend: marcación (`templates/docente.html`)

La marcación ocurre en un modal que se abre con **Marcar Asistencia Remota** (solo visible si la asistencia remota está permitida).

### 3.1. GPS
`navigator.geolocation.getCurrentPosition()` solicita la ubicación. Si el docente la concede, la latitud y longitud se guardan en los campos ocultos `latitud` y `longitud`. Sin GPS el botón **CONFIRMAR** no se habilita.

### 3.2. Verificación facial (si `requiere_face_id`)
1. Se activa la cámara frontal y se analizan fotogramas cada 300 ms con `TinyFaceDetector`.
2. Cuando hay exactamente una cara con confianza > 0,70, su descriptor se guarda en el campo oculto `live_face_descriptor` y se apaga la cámara.
3. La decisión final la toma el servidor (§4.3), no el navegador.

### 3.3. Datos del formulario

| Campo | Tipo | Obligatorio |
|---|---|---|
| `csrf_token` | oculto | Sí |
| `latitud`, `longitud` | ocultos | Sí |
| `live_face_descriptor` | oculto | Solo con Face ID |
| `descripcion` | texto | No |
| `foto` | archivo (`accept="image/*" capture="environment"`) | No |

El formulario se envía por `POST` a `/docente/marcar_web` con `enctype="multipart/form-data"`.

---

## 4. Backend: `docente_marcar()` en `app.py`

### 4.1. Disponibilidad y CSRF
- `verificar_csrf()` (antes de cada `POST`) rechaza la petición si el token no coincide con el de la sesión.
- Si `asistencia_remota_permitida()` es falso, se rechaza con el aviso "La asistencia remota no está habilitada en este momento".

### 4.2. Autenticación
`@login_required` garantiza un usuario autenticado; el registro se asocia a `current_user.biometric_id`.

### 4.3. Verificación facial
Si `requiere_face_id` está activo:
1. El docente debe tener un rostro registrado y haber enviado `live_face_descriptor`.
2. Ambos descriptores deben ser listas de 128 números (`descriptor_valido()`); un descriptor vacío o incompleto se rechaza.
3. Se calcula la distancia euclidiana; si es mayor que **0,55**, la marcación se rechaza.

### 4.4. GPS
Latitud y longitud deben ser números dentro de los rangos válidos (−90…90 y −180…180). Si no, se pide repetir.

### 4.5. Foto de evidencia
1. Extensión permitida: `.jpg`, `.jpeg`, `.png` o `.webp`.
2. El contenido se verifica con Pillow (`es_imagen_valida()`); un archivo disfrazado de imagen se rechaza.
3. Tamaño máximo de la petición: 16 MB; si se supera, se muestra un aviso.
4. Nombre del archivo: `<user_id>_<YYYYMMDDHHMMSS><ext>` en hora de Ecuador, guardado en `uploads/`.

### 4.6. Registro en la base de datos
Se crea un `Log` con:
- `fecha`: hora actual de Ecuador.
- `usuario_id`: `current_user.biometric_id`.
- `tipo_evento`: `Asistencia`; `origen`: `Asistencia remota`.
- `latitud`, `longitud`, `descripcion`, `foto_path`.

### 4.7. Respuesta
Mensaje flash de éxito y redirección al panel del docente.

---

## 5. Consulta de la evidencia (administrador)

En el dashboard y en **Gestión de Asistencias**, las marcaciones remotas muestran un botón que abre el modal `templates/includes/evidence_modal.html` con la descripción, un enlace a Google Maps y la foto. Las fotos se sirven por `/uploads/<archivo>`: el administrador puede ver todas; cada docente solo las suyas.

---

## 6. Limitaciones

- La prueba de vida se hace solo en el navegador; el servidor solo compara descriptores.
- Las coordenadas GPS las proporciona el navegador y pueden falsearse.
