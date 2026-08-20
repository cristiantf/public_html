# Estado Actual del Proyecto: Sistema de Control de Acceso ISTAE

## 1. Resumen de Madurez
El proyecto es una solución funcional e integral de extremo a extremo que involucra **hardware IoT (ESP8266/NodeMCU + Hikvision DS-K1T8003EF)** y un **backend web (Python/Flask)**. Tras una intensiva refactorización y estabilización, el proyecto cuenta con una arquitectura web escalable, firmware robusto con autenticación Digest QOP para comunicación con el biométrico, y un pipeline de datos confiable desde la huella hasta la base de datos en la nube.

**Última actualización:** 29 de junio de 2026.

## 2. Componentes y su Estado

### 2.1 Backend Web (Flask)
- **Estado:** ✅ Completamente implementado, estabilizado y en producción.
- **Servicio:** Gunicorn (3 workers) administrado por systemd (`biometrico.service`), detrás de proxy inverso Nginx con SSL.
- **Funcionalidades:** 
  - Gestión de sesiones y roles de usuario (`admin`, `docente`).
  - Creación, edición y eliminación de docentes a través de vistas dedicadas.
  - Gestión de logs de asistencias y permisos **con paginación del lado del servidor** (ej: últimas 30 asistencias por página) para prevenir el agotamiento de memoria del servidor al escalar la base de datos.
  - Vistas administrativas completamente modularizadas (`/admin/nuevo_docente`, `/admin/reportes`, `/admin/sincronizar_hora`, `/admin/config_asistencia_remota`, etc.) con métodos GET/POST limpios.
  - **Asistencia Remota Configurable:** Control granular con panel dedicado para que el administrador decida (incluso con rangos de fechas y horas) cuándo los docentes pueden marcar su asistencia web.
  - Generación de reportes dinámicos en Excel mediante `openpyxl`.
  - Panel de control (Dashboard) con cálculo de métricas reales (Total de marcaciones diarias) y visualización del estado de conexión del Hardware (Online/Offline) basado en su último ping al servidor.
  - **Diferenciación de eventos:** El endpoint `/api/recibir_log` procesa el campo `estado` enviado por el hardware para registrar marcaciones con apertura de puerta (`Asistencia + puerta`) y marcaciones sin apertura (`Asistencia`) por separado. Ambos tipos se incluyen en los reportes Excel.
  - **Parseo robusto de fecha:** El servidor toma únicamente los primeros 19 caracteres de la fecha ISO 8601 recibida del hardware, descartando sufijos de zona horaria de forma segura para evitar incompatibilidades con MySQL.

### 2.2 Hardware / Firmware IoT (C++ NodeMCU)
- **Estado:** ✅ Desarrollado, estabilizado y en producción (`nodered5.ino`, versión v2.3).
- **Funcionalidades:**
  - Configuración automática de WiFi vía `WiFiManager` (portal cautivo `NODE_PUERTA_ISTAE`).
  - **Comunicación ISAPI con autenticación Digest QOP:** Conexión de streaming persistente al biométrico Hikvision para recibir eventos de huella en tiempo real.
  - Validación de usuarios mediante listas blancas descargadas del servidor, activando relé (apertura de puerta por 3 segundos).
  - Envío de marcaciones al servidor con estado diferenciado (`EXITO`/`DENEGADO`). Ambos se registran como asistencia válida en la BD (`Asistencia + puerta` o `Asistencia`).
  - Sincronización de hora del biométrico bajo demanda vía comandos `SET_TIME` desde el panel admin, usando PUT con Digest Auth al ISAPI del Hikvision.
  - Polling constante con los endpoints (`/api/check_comando` cada 3s, `/api/sincronizar` cada 10 min) que permiten al servidor medir su conectividad en tiempo real (umbral de 60 segundos).

### 2.3 Base de Datos (MySQL)
- **Estado:** ✅ Esquema relacional implementado con SQLAlchemy.
- **Modelos Principales:** `User`, `Log`, `Comando` y `Permiso`.

### 2.4 Interfaz de Usuario (Frontend)
- **Estado:** ✅ Completado, usando plantillas Jinja2 y Bootstrap 5.
- **Funcionalidades:** 
  - Dashboard central con monitor asíncrono (AJAX) que actualiza tabla de logs, conteo diario y estado del NodeMCU cada 3.5 segundos.
  - Diseño unificado y elegante incluyendo el logotipo institucional en Favicon, Panel y Login.
  - Barra lateral de navegación adaptativa que unifica todas las sub-vistas del administrador.

## 3. Puntos Fuertes del Sistema
1. **Integración robusta con hardware Hikvision:** El firmware soporta autenticación Digest con QOP, garantizando compatibilidad con firmwares modernos del biométrico.
2. **Parseo de fecha estabilizado:** El procesamiento de la fecha del hardware se realiza de forma segura tomando solo los 19 caracteres relevantes del ISO 8601.
3. **Escalabilidad Visual y de Memoria:** El desacoplamiento de formularios a vistas independientes y la inclusión de paginación preparan al sistema para soportar millones de registros sin penalizaciones de RAM.
4. **Control Desacoplado de Puerta:** El hardware hace polling constante sin necesitar apertura de puertos en el router local.

## 4. Incidencias Resueltas

| Fecha | Incidencia | Causa Raíz | Resolución |
|---|---|---|---|
| 2026-06-29 | Las marcaciones de huella no se registraban en la BD ni abrían la puerta | Cable de red del biométrico Hikvision (IP 192.168.1.22) desconectado. Sin conexión física, el biométrico no puede enviar eventos ISAPI al NodeMCU. | Reconexión del cable de red Ethernet al biométrico. |
| 2026-06-29 | Bug en parseo de fecha que descartaba la hora | El código anterior dividía la fecha por el carácter `-`, lo cual cortaba el año de la cadena ISO 8601. | Corrección: tomar solo `fecha_str[:19]` en lugar de hacer `split('-')`. |
| 2026-07-09 | Los reportes Excel no incluían marcaciones de docentes sin acceso a puerta | El tipo de evento `Acceso Denegado` no contenía la palabra "Asistencia" que los reportes usan como filtro. | Cambio de `Acceso Denegado` → `Asistencia` en el código y migración de 255 registros históricos en la BD. |

## 5. Áreas de Mejora y Deuda Técnica
1. **Refactorización de `app.py` mediante Blueprints:** Aunque las rutas se desacoplaron lógicamente a vistas dedicadas en el HTML, todas las funciones siguen en el archivo maestro `app.py`. En el futuro, se recomienda estructurar mediante Flask Blueprints.
2. **Testing Automático:** Las pruebas actuales son mayoritariamente manuales; implementar `pytest` para las APIs críticas sería ideal.
3. **Caché en BD:** Si los datos siguen creciendo, la cuenta de marcaciones diarias en tiempo real en SQL podría causar un cuello de botella. Se sugiere el uso futuro de una capa de Redis.
4. **Resiliencia offline en firmware:** Implementar cola de reintentos con `LittleFS` en el NodeMCU para marcaciones que no pudieron enviarse a la nube por fallas de WiFi.
