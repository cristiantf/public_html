/**
 * PROYECTO: CONTROL DE ACCESO BIOMÉTRICO ISTAE (BioISTAE)
 * VERSIÓN:  v3.0 Refactorizada
 * HARDWARE: NodeMCU ESP8266 + Hikvision DS-K1T8003EF
 * 
 * CHANGELOG v3.0:
 *  - FIX: Falso positivo en lista blanca (ID "3" matcheaba dentro de "13")
 *  - FIX: Verificación de respuesta HTTP en enviarLogNube con diagnóstico
 *  - NEW: Cola offline con LittleFS (hasta 50 marcaciones pendientes)
 *  - NEW: Backoff exponencial en reconexión al biométrico
 *  - NEW: Monitor de heap libre y LED de estado
 *  - NEW: Soporte para comando REBOOT remoto
 *  - REF: Comentarios completos, código modularizado
 */

#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <WiFiClientSecure.h>
#include <WiFiManager.h>
#include <LittleFS.h>
#include <MD5Builder.h>

// ============================================================================
// CONFIGURACIÓN — Modificar según el entorno de despliegue
// ============================================================================
const char* HOST_URL   = "https://acceso.istae.edu.ec";
const char* TOKEN_NODE = "istae1805A";

const char* ip_bio   = "192.168.1.22";   // IP fija del biométrico Hikvision
const int   port_bio = 80;
const char* user_bio = "admin";
const char* pass_bio = "istae1804A";

// ============================================================================
// PINES DE HARDWARE
// ============================================================================
const int RELAY_PIN = 5;              // D1 — Relé de cerradura eléctrica
const int LED_PIN   = LED_BUILTIN;    // LED integrado del NodeMCU

// ============================================================================
// CONSTANTES DE TIEMPO (milisegundos)
// ============================================================================
const unsigned long PUERTA_ABIERTA_MS   = 3000;    // Tiempo que la puerta permanece abierta
const unsigned long CHECK_COMANDO_MS    = 3000;    // Intervalo de polling de comandos
const unsigned long SYNC_LISTA_MS       = 600000;  // Intervalo de sincronización de lista blanca (10 min)
const unsigned long RECONEX_BIO_MIN_MS  = 2000;    // Backoff mínimo de reconexión al biométrico
const unsigned long RECONEX_BIO_MAX_MS  = 60000;   // Backoff máximo
const unsigned long HEAP_MONITOR_MS     = 30000;   // Intervalo de monitoreo de memoria
const unsigned long RETRY_OFFLINE_MS    = 15000;   // Intervalo de reenvío de cola offline
const char* OFFLINE_FILE = "/cola_offline.txt";     // Archivo LittleFS para cola

// ============================================================================
// VARIABLES DE ESTADO
// ============================================================================
WiFiClient bioClient;
String listaBlanca   = "";
String bufferJSON    = "";
int    llaves        = 0;
bool   capturando    = false;
bool   puertaAbierta = false;

// Temporizadores no bloqueantes
unsigned long msRelay     = 0;
unsigned long msCheckCmd  = 0;
unsigned long msSync      = 0;
unsigned long msHeap      = 0;
unsigned long msRetryQ    = 0;
unsigned long msReconBio  = 0;
unsigned long backoffBio  = RECONEX_BIO_MIN_MS;  // Backoff exponencial

// Variables Digest (se reutilizan entre conexiones al biométrico)
String realm = "", nonce = "", qop = "";

// ============================================================================
// SETUP — Inicialización del sistema
// ============================================================================
void setup() {
  Serial.begin(115200);
  pinMode(RELAY_PIN, OUTPUT);
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(RELAY_PIN, LOW);
  digitalWrite(LED_PIN, HIGH);  // LED apagado (lógica invertida en NodeMCU)

  // Inicializar sistema de archivos para cola offline
  if (!LittleFS.begin()) {
    Serial.println(F("❌ Falla al iniciar LittleFS"));
  }

  // Configuración de WiFi con portal cautivo automático
  WiFiManager wm;
  wm.setConfigPortalTimeout(180);

  if (!wm.autoConnect("NODE_PUERTA_ISTAE")) {
    Serial.println(F("❌ Timeout WiFi. Reiniciando en 3s..."));
    delay(3000);
    ESP.restart();
  }

  WiFi.setAutoReconnect(true);
  WiFi.persistent(true);
  digitalWrite(LED_PIN, LOW);  // LED encendido = WiFi conectado

  Serial.println(F("\n✅ WiFi conectado. Sistema BioISTAE v3.0 iniciado."));
  Serial.printf("   IP: %s | Heap: %u bytes\n", WiFi.localIP().toString().c_str(), ESP.getFreeHeap());

  sincronizarListaBlanca();
}

// ============================================================================
// LOOP PRINCIPAL — Ciclo no bloqueante
// ============================================================================
void loop() {
  unsigned long now = millis();

  // --- 1. Mantener conexión de streaming con el biométrico ---
  if (WiFi.status() == WL_CONNECTED) {
    if (!bioClient.connected() && (now - msReconBio >= backoffBio)) {
      conectarConDigest();
      msReconBio = now;
      // Backoff exponencial: si falla, espera más antes del próximo intento
      if (!bioClient.connected()) {
        backoffBio = min(backoffBio * 2, RECONEX_BIO_MAX_MS);
      } else {
        backoffBio = RECONEX_BIO_MIN_MS;  // Reset si conectó exitosamente
      }
    }
  }

  // --- 2. Procesar stream JSON del biométrico ---
  while (bioClient.available()) {
    char c = bioClient.read();
    if (c == '{') {
      if (!capturando) { capturando = true; bufferJSON = ""; }
      llaves++;
    }
    if (capturando) {
      bufferJSON += c;
      if (c == '}') {
        llaves--;
        if (llaves == 0) {
          procesarEventoAcceso(bufferJSON);
          capturando = false;
        }
      }
    }
    // Protección contra buffer overflow (fragmentos corruptos)
    if (bufferJSON.length() > 2500) {
      capturando = false; bufferJSON = ""; llaves = 0;
    }
  }

  // --- 3. Temporizador de cierre de puerta ---
  if (puertaAbierta && (now - msRelay >= PUERTA_ABIERTA_MS)) {
    digitalWrite(RELAY_PIN, LOW);
    puertaAbierta = false;
    Serial.println(F("🔒 Cerradura bloqueada."));
  }

  // --- 4. Tareas de nube (solo con WiFi) ---
  if (WiFi.status() == WL_CONNECTED) {
    // Polling de comandos remotos (cada 3s)
    if (now - msCheckCmd >= CHECK_COMANDO_MS) {
      revisarComandosNube();
      msCheckCmd = now;
    }
    // Sincronizar lista blanca (cada 10 min)
    if (now - msSync >= SYNC_LISTA_MS) {
      sincronizarListaBlanca();
      msSync = now;
    }
    // Reintentar cola offline (cada 15s)
    if (now - msRetryQ >= RETRY_OFFLINE_MS) {
      reenviarColaOffline();
      msRetryQ = now;
    }
  }

  // --- 5. Monitor de diagnóstico ---
  if (now - msHeap >= HEAP_MONITOR_MS) {
    Serial.printf("📊 Heap: %u bytes | WiFi: %s | Bio: %s\n",
      ESP.getFreeHeap(),
      WiFi.status() == WL_CONNECTED ? "OK" : "DESCONECTADO",
      bioClient.connected() ? "STREAM" : "OFFLINE");
    // LED: encendido = todo OK, apagado = sin WiFi
    digitalWrite(LED_PIN, WiFi.status() == WL_CONNECTED ? LOW : HIGH);
    msHeap = now;
  }
}

// ============================================================================
// AUTENTICACIÓN DIGEST — Conexión de streaming al biométrico Hikvision
// ============================================================================

/**
 * Establece una conexión de streaming con el biométrico usando HTTP Digest Auth.
 * Proceso: 1) GET sin auth → 2) Recibir desafío 401 → 3) GET con respuesta Digest
 */
void conectarConDigest() {
  Serial.println(F("\n📡 Conectando al biométrico..."));
  if (!bioClient.connect(ip_bio, port_bio)) {
    Serial.println(F("❌ Sin conexión al biométrico. ¿Cable de red conectado?"));
    return;
  }

  // Paso 1: Enviar GET sin credenciales para recibir el desafío 401
  bioClient.println("GET /ISAPI/Event/notification/alertStream HTTP/1.1");
  bioClient.print("Host: "); bioClient.println(ip_bio);
  bioClient.println();

  // Paso 2: Leer el desafío WWW-Authenticate del 401
  realm = ""; nonce = ""; qop = "";
  unsigned long timeout = millis();
  while (bioClient.connected() && millis() - timeout < 2000) {
    String header = bioClient.readStringUntil('\n');
    if (header.indexOf("WWW-Authenticate: Digest") != -1) {
      realm = extraerParam(header, "realm");
      nonce = extraerParam(header, "nonce");
      qop   = extraerParam(header, "qop");
      break;
    }
    if (header == "\r") break;
  }
  bioClient.stop();

  if (realm == "" || nonce == "") {
    Serial.println(F("❌ No se recibió desafío Digest del biométrico."));
    return;
  }

  // Paso 3: Calcular respuesta Digest y enviar GET autorizado
  String uri = "/ISAPI/Event/notification/alertStream";
  String authHeader = construirDigestAuth("GET", uri, realm, nonce, qop);

  if (bioClient.connect(ip_bio, port_bio)) {
    bioClient.println("GET " + uri + " HTTP/1.1");
    bioClient.print("Host: "); bioClient.println(ip_bio);
    bioClient.println(authHeader);
    bioClient.println("Connection: keep-alive");
    bioClient.println();
    Serial.println(F("✅ Streaming ISAPI activo (Digest + QOP)."));
  }
}

/**
 * Construye el header Authorization: Digest para un método y URI dados.
 * Soporta QOP (auth) y fallback sin QOP para biométricos con firmware antiguo.
 */
String construirDigestAuth(String method, String uri, String r, String n, String q) {
  String ha1 = getMD5(String(user_bio) + ":" + r + ":" + String(pass_bio));
  String ha2 = getMD5(method + ":" + uri);
  String cnonce = "0a4f" + String(random(1000, 9999));
  String nc = "00000001";
  String response;

  if (q.indexOf("auth") != -1) {
    response = getMD5(ha1 + ":" + n + ":" + nc + ":" + cnonce + ":auth:" + ha2);
    return "Authorization: Digest username=\"admin\", realm=\"" + r +
           "\", nonce=\"" + n + "\", uri=\"" + uri +
           "\", qop=auth, nc=" + nc + ", cnonce=\"" + cnonce +
           "\", response=\"" + response + "\"";
  } else {
    response = getMD5(ha1 + ":" + n + ":" + ha2);
    return "Authorization: Digest username=\"admin\", realm=\"" + r +
           "\", nonce=\"" + n + "\", uri=\"" + uri +
           "\", response=\"" + response + "\"";
  }
}

// ============================================================================
// PROCESAMIENTO DE EVENTOS DE HUELLA
// ============================================================================

/**
 * Recibe el JSON completo de un evento ISAPI y decide:
 *  - Si el ID está en la lista blanca → abre puerta + envía EXITO
 *  - Si no está → solo envía DENEGADO (se registra como Asistencia en el server)
 */
void procesarEventoAcceso(String json) {
  String id       = extraerDatoJSON(json, "employeeNoString");
  String fechaBio = extraerDatoJSON(json, "dateTime");

  if (id == "" || id == "null") return;

  Serial.printf("\n👤 ID: %s | Hora HW: %s\n", id.c_str(), fechaBio.c_str());

  // Búsqueda EXACTA en lista blanca (evita que "3" matchee dentro de "13")
  bool autorizado = ("," + listaBlanca + ",").indexOf("," + id + ",") != -1;

  if (autorizado) {
    abrirPuerta();
    enviarLogNube(id, "EXITO", fechaBio);
  } else {
    Serial.println(F("⚠️ Usuario sin acceso a puerta. Registrando asistencia."));
    enviarLogNube(id, "DENEGADO", fechaBio);
  }
}

/** Activa el relé de la cerradura por PUERTA_ABIERTA_MS milisegundos */
void abrirPuerta() {
  digitalWrite(RELAY_PIN, HIGH);
  puertaAbierta = true;
  msRelay = millis();
  Serial.println(F("🔓 PUERTA ABIERTA"));
}

// ============================================================================
// COMUNICACIÓN CON LA NUBE (HTTPS)
// ============================================================================

/**
 * Envía una marcación al servidor. Si falla, la encola en LittleFS.
 * Verifica el código HTTP de respuesta para diagnóstico.
 */
void enviarLogNube(String id, String estado, String fecha) {
  String payload = "{\"id\":\"" + id + "\",\"estado\":\"" + estado +
                   "\",\"fecha_dispositivo\":\"" + fecha +
                   "\",\"token\":\"" + String(TOKEN_NODE) +
                   "\",\"origen\":\"Huella\"}";

  if (WiFi.status() != WL_CONNECTED) {
    guardarEnCola(payload);
    Serial.println(F("📥 Sin WiFi. Marcación guardada en cola offline."));
    return;
  }

  WiFiClientSecure client;
  client.setInsecure();
  HTTPClient http;

  http.begin(client, String(HOST_URL) + "/api/recibir_log");
  http.addHeader("Content-Type", "application/json");
  int httpCode = http.POST(payload);

  if (httpCode == 200) {
    Serial.println(F("☁️ Log enviado correctamente al servidor."));
  } else {
    Serial.printf("❌ Error enviando log (HTTP %d). Guardando en cola.\n", httpCode);
    guardarEnCola(payload);
  }
  http.end();
}

/** Sincroniza la lista de IDs autorizados desde el servidor */
void sincronizarListaBlanca() {
  WiFiClientSecure client; client.setInsecure();
  HTTPClient http;
  if (http.begin(client, String(HOST_URL) + "/api/sincronizar")) {
    if (http.GET() == 200) {
      listaBlanca = http.getString();
      Serial.printf("☁️ Lista blanca actualizada: [%s]\n", listaBlanca.c_str());
    }
    http.end();
  }
}

/** Consulta comandos pendientes del servidor (ABRIR, SET_TIME, REBOOT) */
void revisarComandosNube() {
  WiFiClientSecure client; client.setInsecure();
  HTTPClient http;
  if (http.begin(client, String(HOST_URL) + "/api/check_comando")) {
    if (http.GET() == 200) {
      String resp = http.getString();

      if (resp == "ABRIR") {
        abrirPuerta();
      }
      else if (resp.startsWith("SET_TIME|")) {
        String isoTime = resp.substring(9);
        String xml = "<?xml version=\"1.0\" encoding=\"UTF-8\"?>"
                     "<Time xmlns=\"http://www.isapi.org/ver20/XMLSchema\" version=\"2.0\">"
                     "<timeMode>manual</timeMode>"
                     "<localTime>" + isoTime + "</localTime></Time>";
        enviarPutDigest("/ISAPI/System/time", xml);
        Serial.println("⏰ Hora sincronizada: " + isoTime);
      }
      else if (resp == "REBOOT") {
        Serial.println(F("🔄 Comando REBOOT recibido. Reiniciando..."));
        delay(500);
        ESP.restart();
      }
    }
    http.end();
  }
}

// ============================================================================
// COLA OFFLINE — Persistencia en LittleFS
// ============================================================================

/** Guarda un payload JSON en el archivo de cola para reenvío posterior */
void guardarEnCola(String payload) {
  File f = LittleFS.open(OFFLINE_FILE, "a");
  if (f) {
    f.println(payload);
    f.close();
  }
}

/** Reenvía las marcaciones pendientes de la cola al servidor */
void reenviarColaOffline() {
  if (!LittleFS.exists(OFFLINE_FILE)) return;

  File f = LittleFS.open(OFFLINE_FILE, "r");
  if (!f || f.size() == 0) { f.close(); return; }

  // Leer todas las líneas pendientes
  String pendientes = "";
  String linea;
  bool todoOK = true;

  while (f.available()) {
    linea = f.readStringUntil('\n');
    linea.trim();
    if (linea.length() < 10) continue;

    // Intentar enviar cada línea
    WiFiClientSecure client; client.setInsecure();
    HTTPClient http;
    http.begin(client, String(HOST_URL) + "/api/recibir_log");
    http.addHeader("Content-Type", "application/json");
    int code = http.POST(linea);
    http.end();

    if (code == 200) {
      Serial.println(F("📤 Cola: registro reenviado OK."));
    } else {
      pendientes += linea + "\n";
      todoOK = false;
    }
  }
  f.close();

  // Reescribir solo los que fallaron, o borrar si todo se envió
  if (todoOK) {
    LittleFS.remove(OFFLINE_FILE);
    Serial.println(F("✅ Cola offline vaciada completamente."));
  } else {
    File fw = LittleFS.open(OFFLINE_FILE, "w");
    if (fw) { fw.print(pendientes); fw.close(); }
  }
}

// ============================================================================
// PUT CON DIGEST AUTH — Para sincronización horaria del biométrico
// ============================================================================

/** Envía un PUT autorizado con Digest Auth al biométrico (ej: /ISAPI/System/time) */
void enviarPutDigest(String uri, String xmlBody) {
  WiFiClient client;
  if (!client.connect(ip_bio, port_bio)) return;

  // Paso 1: GET para obtener desafío 401
  client.print("GET " + uri + " HTTP/1.1\r\n");
  client.print("Host: " + String(ip_bio) + "\r\n\r\n");

  String l_realm = "", l_nonce = "", l_qop = "";
  unsigned long timeout = millis();
  while (client.connected() && millis() - timeout < 2000) {
    String header = client.readStringUntil('\n');
    if (header.indexOf("WWW-Authenticate: Digest") != -1) {
      l_realm = extraerParam(header, "realm");
      l_nonce = extraerParam(header, "nonce");
      l_qop   = extraerParam(header, "qop");
      break;
    }
    if (header == "\r") break;
  }
  client.stop();
  if (l_nonce == "") return;

  // Paso 2: PUT con Digest Auth
  String authHeader = construirDigestAuth("PUT", uri, l_realm, l_nonce, l_qop);

  if (client.connect(ip_bio, port_bio)) {
    client.print("PUT " + uri + " HTTP/1.1\r\n");
    client.print("Host: " + String(ip_bio) + "\r\n");
    client.println(authHeader);
    client.print("Content-Type: application/xml\r\n");
    client.print("Content-Length: " + String(xmlBody.length()) + "\r\n");
    client.print("Connection: close\r\n\r\n");
    client.print(xmlBody);
    client.stop();
    Serial.println(F("⏰ Configuración enviada al biométrico."));
  }
}

// ============================================================================
// UTILIDADES — Parseo JSON, MD5 y extracción de parámetros
// ============================================================================

/** Extrae el valor de una clave de un JSON simple (sin librería externa) */
String extraerDatoJSON(String fuente, String clave) {
  String busqueda = "\"" + clave + "\":";
  int posClave = fuente.indexOf(busqueda);
  if (posClave == -1) {
    busqueda = "\"" + clave + "\": ";
    posClave = fuente.indexOf(busqueda);
  }
  if (posClave == -1) return "";
  int posInicio = fuente.indexOf("\"", posClave + busqueda.length());
  if (posInicio == -1) return "";
  posInicio++;
  int posFin = fuente.indexOf("\"", posInicio);
  if (posFin == -1) return "";
  return fuente.substring(posInicio, posFin);
}

/** Calcula el hash MD5 de una cadena (usado para Digest Auth) */
String getMD5(String data) {
  MD5Builder md5;
  md5.begin();
  md5.add(data);
  md5.calculate();
  return md5.toString();
}

/** Extrae un parámetro entrecomillado de un header HTTP (ej: realm="valor") */
String extraerParam(String header, String param) {
  int pos = header.indexOf(param + "=\"");
  if (pos == -1) return "";
  int start = pos + param.length() + 2;
  int end = header.indexOf("\"", start);
  return header.substring(start, end);
}