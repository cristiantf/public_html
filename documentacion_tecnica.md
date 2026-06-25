# Documentación Técnica: Sistema de Control de Acceso ISTAE

## 1. Arquitectura del Sistema
El sistema sigue un modelo Cliente-Servidor (con clientes tanto Web como de Hardware IoT), desarrollado en la pila tecnológica de **Python/Flask, MySQL y C++ (ESP8266)**.

- **Frontend Web:** Jinja2 (server-side rendering) enriquecido con JavaScript para peticiones AJAX. Utiliza **Paginación dinámica** en vistas pesadas (como Historial de Asistencias y Permisos) para alivianar la carga del DOM y memoria.
- **Backend Servidor:** Flask centralizado (`app.py`), encargado de despachar vistas y APIs. Los procesos de formularios (Creación de Usuarios, Permisos, Sincronización) se procesan en rutas HTTP independientes con métodos `GET` y `POST` tradicionales.
- **Capa de Persistencia:** Base de datos MySQL con ORM **SQLAlchemy**. Se emplea `.paginate()` nativo de Flask-SQLAlchemy para limitar la extracción de memoria a "chunks" de 20 o 30 registros.
- **Hardware Periférico:** Placa de desarrollo NodeMCU.

---

## 2. Modelos de Base de Datos (ORM SQLAlchemy)

1. **`User` (`usuarios`):** Atributos como `biometric_id`, `nombre`, `rol`, etc.
2. **`Log` (`logs`):** Guarda la historia (asistencia y apertura). Posee campos para soporte remoto como `latitud`, `foto_path`, etc.
3. **`Comando` (`comandos`):** Tabla de encolamiento de órdenes (Ej. `ABRIR` o `SET_TIME`).
4. **`Permiso` (`permisos`):** Registro de ausencias justificadas y permisos administrativos.

---

## 3. Especificación de la API (Hardware - Servidor)

El sistema provee endpoints específicos, y cada vez que el NodeMCU los toca, el servidor actualiza internamente un registro (`last_seen.txt`) para medir su "Estado En Línea".

### `GET /api/sincronizar`
- **Uso:** El NodeMCU descarga periódicamente la lista de IDs de usuarios autorizados. Actualiza el estado online.

### `GET /api/check_comando`
- **Uso:** Polling constante (cada 3 segundos) desde el hardware. Actualiza el estado online.
- **Respuesta:** Retorna el comando (`ABRIR`) o `NADA`.

### `POST /api/recibir_log`
- **Uso:** Almacena registros capturados por la huella. Actualiza el estado online.

---

## 4. Flujos Clave del Sistema

### 4.1. Monitorización en Tiempo Real (AJAX)
1. El Dashboard principal (`/admin/dashboard`) renderiza una tabla vacía y tarjetas de métricas.
2. Un script en JS solicita `/api/logs_admin` cada 3.5 segundos.
3. El backend realiza tres operaciones críticas: 
   - Devuelve los últimos 20 logs.
   - Suma explícitamente y de manera absoluta todas las marcaciones del día actual con consultas directas a BD.
   - Lee la última estampa de tiempo del Hardware para determinar si el NodeMCU está conectado (`True`) o desconectado (`False`).
4. El Frontend actualiza los números, iconos de WiFi y la tabla HTML instantáneamente sin requerir que la página se recargue.

### 4.2. Paginación de Registros Administrativos
1. Cuando el administrador entra a "Gestión de Asistencias" o "Gestión de Permisos", Flask recibe el parámetro de página (`?page=1`).
2. Mediante SQLAlchemy `.paginate(page=X, per_page=30)`, el servidor extrae estrictamente lo que se necesita mostrar, devolviendo un objeto `Pagination`.
3. Esto evita la caída del sistema por desbordamiento de memoria cuando la base de datos supera miles de entradas.

### 4.3. Apertura Remota y Resiliencia
- Continúa el flujo asincrónico a través de la tabla de "Comandos", permitiendo aperturas sin conexión entrante abierta en el firewall del hardware local. El sistema tolera caídas y respalda asincrónicamente mediante `LittleFS`.

---

## 5. Implementación de Seguridad
- Las rutas sensibles ahora están separadas físicamente a lo largo de diversas vistas con decoradores unificados de roles.
- `TOKEN_NODE` protege contra inyección de falsas lecturas.
- Las peticiones en masa están mitigadas por los esquemas de paginación y limitadores `LIMIT` en SQL, resguardando al servidor contra vulnerabilidades de "Denegación de Servicio (DoS)" accidentales por consumo de RAM.
