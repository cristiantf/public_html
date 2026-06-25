# Estado Actual del Proyecto: Sistema de Control de Acceso ISTAE

## 1. Resumen de Madurez
El proyecto es una solución funcional e integral de extremo a extremo que involucra **hardware IoT (ESP8266/NodeMCU)** y un **backend web (Python/Flask)**. Actualmente, el proyecto cuenta con un estado de desarrollo maduro, abordando tanto los casos de uso principales como escenarios secundarios (por ejemplo, pérdida de conectividad en el hardware o asistencias remotas).

## 2. Componentes y su Estado

### 2.1 Backend Web (Flask)
- **Estado:** Completamente implementado y en funcionamiento.
- **Funcionalidades:** 
  - Gestión de sesiones y roles de usuario (`admin`, `docente`).
  - Creación, edición y eliminación de docentes.
  - Registro de logs (presenciales y remotos).
  - API REST para la comunicación con el dispositivo NodeMCU.
  - Generación de reportes dinámicos en Excel mediante `openpyxl`.
- **Estructura del Código:** El backend se encuentra en su mayoría centralizado en un único archivo (`app.py`), el cual contiene cerca de 800 líneas. Gestiona modelos de base de datos, inicialización, vistas, API REST y reportes.

### 2.2 Hardware / Firmware IoT (C++ NodeMCU)
- **Estado:** Desarrollado y configurado (`node.ino`).
- **Funcionalidades:**
  - Configuración automática de WiFi vía `WiFiManager`.
  - Captura y validación de usuarios mediante listas blancas, activando un relé si hay coincidencias.
  - Sincronización en la nube mediante solicitudes HTTP regulares (`/api/sincronizar` y `/api/check_comando`).
  - Resiliencia offline: Almacena logs de acceso fallidos localmente en `LittleFS` y los encola cuando vuelve el WiFi.

### 2.3 Base de Datos (MySQL)
- **Estado:** Esquema relacional implementado con SQLAlchemy.
- **Modelos Principales:** `User` (credenciales y configuración del docente), `Log` (eventos de acceso), `Comando` (órdenes encoladas para el NodeMCU) y `Permiso` (permisos de inasistencias o especiales).

### 2.4 Interfaz de Usuario (Frontend)
- **Estado:** Completado, usando plantillas Jinja2 y Bootstrap 5.
- **Funcionalidades:** Modal con uso de API de Geolocalización y captura de cámara para las "asistencias remotas", adaptabilidad móvil.

## 3. Puntos Fuertes del Sistema
1. **Resiliencia ante caídas de red:** La implementación de memoria local en el hardware (LittleFS) previene pérdida de datos.
2. **Sistema Híbrido:** Proporciona un mecanismo presencial (Biométrico) y un mecanismo remoto seguro (Geolocalización + Foto).
3. **Control Desacoplado de Puerta:** El hardware hace polling (sondeo) constante, lo que permite abrir la puerta a distancia sin necesidad de configuraciones complicadas de reenvío de puertos.

## 4. Áreas de Mejora y Deuda Técnica
1. **Refactorización de `app.py`:** A medida que creció el sistema, el enrutamiento, la configuración y los modelos se mantuvieron en `app.py`. Es muy recomendable usar **Flask Blueprints** para separar:
   - `auth/` (Login y usuarios)
   - `api/` (Endpoints para el NodeMCU)
   - `admin/` (Panel y reportes de administrador)
   - `docente/` (Vistas para los usuarios estándar)
2. **Seguridad del Token IoT:** Actualmente, `TOKEN_NODE` se envía estáticamente. Si la red no utiliza HTTPS, esto podría ser propenso a interceptación. El hardware usa `client.setInsecure()`, lo que invalida la validación de certificados SSL.
3. **Zona Horaria y Geolocalización:** Aunque el servidor implementa la corrección a la zona `America/Guayaquil`, la validación de coordenadas (geocercas) es muy permisiva y queda a juicio del revisor (admin).
4. **Testing Automático:** No hay un conjunto definido de tests unitarios automáticos (`pytest` o similar). Las pruebas se realizan por scripts manuales (`biometrico_driver.py`).
