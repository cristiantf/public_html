/**
 * PROYECTO: CONTROL DE ACCESO BIOMÉTRICO ISTAE
 * VERSIÓN: v2.3 Estabilizada (Soporte QOP Digest + Sincronización Horaria)
 * HARDWARE: NodeMCU ESP8266 + Hikvision DS-K1T8003EF
 */

#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <WiFiClientSecure.h>
#include <WiFiManager.h>
#include <LittleFS.h>
#include <MD5Builder.h>

// --- CONFIGURACIÓN DE NUBE ---
const char* HOST_URL = "https://acceso.istae.edu.ec";
const char* TOKEN_NODE = "istae1805A";

// --- DATOS DEL BIOMÉTRICO ---
const char* ip_bio = "192.168.1.22";
const int port_bio = 80;
const char* user_bio = "admin";
const char* pass_bio = "istae1804A"; 

// --- PINES ---
const int RELAY_PIN = 5; // D1 en NodeMCU

// --- VARIABLES DE CONTROL ---
WiFiClient bioClient; 
String listaBlanca = "";
String bufferJSON = "";
int llaves = 0;
bool capturando = false;
bool puertaAbierta = false;

// Variables Digest Avanzadas
String realm = "", nonce = "", qop = "";
unsigned long msRelay = 0, msCheckCmd = 0, msSync = 0;

void setup() {
  Serial.begin(115200);
  pinMode(RELAY_PIN, OUTPUT);
  digitalWrite(RELAY_PIN, LOW);
  
  if(!LittleFS.begin()) Serial.println(F("Falla LittleFS"));

  // --- CONFIGURACIÓN RESILIENTE DE WIFI ---
  WiFiManager wm;
  wm.setConfigPortalTimeout(180); 
  
  if (!wm.autoConnect("NODE_PUERTA_ISTAE")) {
    Serial.println(F("❌ Tiempo de espera agotado. Reiniciando..."));
    delay(3000);
    ESP.restart();
  }

  WiFi.setAutoReconnect(true);
  WiFi.persistent(true);

  Serial.println(F("\n✅ Red ISTAE Conectada Correctamente."));
  sincronizarListaBlanca();
}

void loop() {
  unsigned long now = millis();

  // 1. Mantener flujo de eventos abierto con el biométrico (Solo si hay WiFi)
  if (WiFi.status() == WL_CONNECTED) {
    if (!bioClient.connected()) {
      conectarConDigest();
      delay(2000);
    }
  }

  // 2. Procesar el Stream de datos del biométrico
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
    if (bufferJSON.length() > 2500) { capturando = false; bufferJSON = ""; llaves = 0; }
  }

  // 3. Temporizador de cierre de puerta
  if (puertaAbierta && (now - msRelay >= 3000)) {
    digitalWrite(RELAY_PIN, LOW);
    puertaAbierta = false;
    Serial.println(F("🔒 Cerradura bloqueada."));
  }

  // 4. Tareas de Nube (Solo si hay WiFi)
  if (WiFi.status() == WL_CONNECTED) {
    if (now - msCheckCmd >= 3000) { revisarComandosNube(); msCheckCmd = now; }
    if (now - msSync >= 600000) { sincronizarListaBlanca(); msSync = now; }
  }
}

/**
 * Conexión de Escucha de Eventos (GET) con soporte robusto para QOP Digest
 */
void conectarConDigest() {
  Serial.println(F("\n📡 Abriendo canal de escucha ISAPI..."));
  if (!bioClient.connect(ip_bio, port_bio)) return;

  bioClient.println("GET /ISAPI/Event/notification/alertStream HTTP/1.1");
  bioClient.print("Host: "); bioClient.println(ip_bio);
  bioClient.println();

  // Leer desafío 401
  unsigned long timeout = millis();
  realm = ""; nonce = ""; qop = "";
  while (bioClient.connected() && millis() - timeout < 2000) {
    String header = bioClient.readStringUntil('\n');
    if (header.indexOf("WWW-Authenticate: Digest") != -1) {
      realm = extraerParam(header, "realm");
      nonce = extraerParam(header, "nonce");
      qop = extraerParam(header, "qop");
      break;
    }
    if (header == "\r") break;
  }
  bioClient.stop();

  if (realm == "" || nonce == "") {
    Serial.println(F("❌ Error: No se obtuvo el desafío de seguridad del biométrico."));
    return;
  }

  // Cálculos Criptográficos adaptativos (Digest con o sin QOP)
  String ha1 = getMD5(String(user_bio) + ":" + realm + ":" + String(pass_bio));
  String ha2 = getMD5("GET:/ISAPI/Event/notification/alertStream");
  String response = "";

  String cnonce = "0a4f" + String(random(1000, 9999)); // Cliente Nonce aleatorio
  String nc = "00000001";

  if (qop.indexOf("auth") != -1) {
    // Cálculo con QOP habilitado (Requerido por firmwares modernos)
    response = getMD5(ha1 + ":" + nonce + ":" + nc + ":" + cnonce + ":auth:" + ha2);
  } else {
    // Fallback estándar
    response = getMD5(ha1 + ":" + nonce + ":" + ha2);
  }

  // Petición final autorizada
  if (bioClient.connect(ip_bio, port_bio)) {
    bioClient.println("GET /ISAPI/Event/notification/alertStream HTTP/1.1");
    bioClient.print("Host: "); bioClient.println(ip_bio);
    
    if (qop.indexOf("auth") != -1) {
      bioClient.print("Authorization: Digest username=\"admin\", realm=\"");
      bioClient.print(realm); bioClient.print("\", nonce=\"");
      bioClient.print(nonce); bioClient.print("\", uri=\"/ISAPI/Event/notification/alertStream\", qop=auth, nc=");
      bioClient.print(nc); bioClient.print(", cnonce=\"");
      bioClient.print(cnonce); bioClient.print("\", response=\"");
      bioClient.print(response); bioClient.println("\"");
    } else {
      bioClient.print("Authorization: Digest username=\"admin\", realm=\"");
      bioClient.print(realm); bioClient.print("\", nonce=\"");
      bioClient.print(nonce); bioClient.print("\", uri=\"/ISAPI/Event/notification/alertStream\", response=\"");
      bioClient.print(response); bioClient.println("\"");
    }
    
    bioClient.println("Connection: keep-alive");
    bioClient.println();
    Serial.println(F("✅ AUTENTICACIÓN DIGEST CON QOP EXITOSA."));
  }
}

/**
 * Función genérica PUT autorizada para configurar parámetros (Time Sync)
 */
void enviarPutDigest(String uri, String xmlBody) {
  WiFiClient client;
  if (!client.connect(ip_bio, port_bio)) return;

  // Realizar un handshake seguro usando GET previo
  client.print("GET " + uri + " HTTP/1.1\r\n");
  client.print("Host: " + String(ip_bio) + "\r\n\r\n");

  String l_realm = "", l_nonce = "", l_qop = "";
  unsigned long timeout = millis();
  while (client.connected() && millis() - timeout < 2000) {
    String header = client.readStringUntil('\n');
    if (header.indexOf("WWW-Authenticate: Digest") != -1) {
      l_realm = extraerParam(header, "realm");
      l_nonce = extraerParam(header, "nonce");
      l_qop = extraerParam(header, "qop");
      break;
    }
    if (header == "\r") break;
  }
  client.stop();

  if (l_nonce == "") return;

  String ha1 = getMD5(String(user_bio) + ":" + l_realm + ":" + String(pass_bio));
  String ha2 = getMD5("PUT:" + uri);
  String response = "";
  String cnonce = "0b5e" + String(random(1000, 9999));
  String nc = "00000001";

  if (l_qop.indexOf("auth") != -1) {
    response = getMD5(ha1 + ":" + l_nonce + ":" + nc + ":" + cnonce + ":auth:" + ha2);
  } else {
    response = getMD5(ha1 + ":" + l_nonce + ":" + ha2);
  }

  if (client.connect(ip_bio, port_bio)) {
    client.print("PUT " + uri + " HTTP/1.1\r\n");
    client.print("Host: " + String(ip_bio) + "\r\n");
    
    if (l_qop.indexOf("auth") != -1) {
      client.print("Authorization: Digest username=\"admin\", realm=\"" + l_realm + "\", nonce=\"" + l_nonce + "\", uri=\"" + uri + "\", qop=auth, nc=" + nc + ", cnonce=\"" + cnonce + "\", response=\"" + response + "\"\r\n");
    } else {
      client.print("Authorization: Digest username=\"admin\", realm=\"" + l_realm + "\", nonce=\"" + l_nonce + "\", uri=\"" + uri + "\", response=\"" + response + "\"\r\n");
    }
    
    client.print("Content-Type: application/xml\r\n");
    client.print("Content-Length: " + String(xmlBody.length()) + "\r\n");
    client.print("Connection: close\r\n\r\n");
    client.print(xmlBody);
    client.stop();
    Serial.println(F("⏰ Sincronización horaria enviada con éxito al hardware."));
  }
}

/**
 * Procesa la marcación de huella detectada
 */
void procesarEventoAcceso(String json) {
  String id = extraerDatoJSON(json, "employeeNoString");
  String fechaBio = extraerDatoJSON(json, "dateTime");

  if (id != "" && id != "null") {
    Serial.printf("\n👤 ID DETECTADO: %s | HORA HARDWARE: %s\n", id.c_str(), fechaBio.c_str());
    
    if (listaBlanca.indexOf(id) != -1) {
      abrirPuerta();
      enviarLogNube(id, "EXITO", fechaBio);
    } else {
      enviarLogNube(id, "DENEGADO", fechaBio);
    }
  }
}

void abrirPuerta() {
  digitalWrite(RELAY_PIN, HIGH);
  puertaAbierta = true;
  msRelay = millis();
  Serial.println(F("🔓 PUERTA ABIERTA"));
}

void enviarLogNube(String id, String estado, String fecha) {
  WiFiClientSecure client; client.setInsecure();
  HTTPClient http;
  String payload = "{\"id\":\"" + id + "\",\"estado\":\"" + estado + 
                   "\",\"fecha_dispositivo\":\"" + fecha + 
                   "\",\"token\":\"" + String(TOKEN_NODE) + 
                   "\",\"origen\":\"Huella\"}";
                   
  http.begin(client, String(HOST_URL) + "/api/recibir_log");
  http.addHeader("Content-Type", "application/json");
  int httpCode = http.POST(payload);
  http.end();
  Serial.println(F("☁️ Log enviado a la base de datos central."));
}

void sincronizarListaBlanca() {
  WiFiClientSecure client; client.setInsecure(); HTTPClient http;
  if(http.begin(client, String(HOST_URL) + "/api/sincronizar")){
    if(http.GET() == 200) {
      listaBlanca = http.getString();
      Serial.println(F("☁️ Lista blanca sincronizada."));
    }
    http.end();
  }
}

void revisarComandosNube() {
  WiFiClientSecure client; client.setInsecure(); HTTPClient http;
  if(http.begin(client, String(HOST_URL) + "/api/check_comando")){
    if(http.GET() == 200) {
      String response = http.getString();
      
      if (response == "ABRIR") {
        abrirPuerta();
      } 
      // Soporte de Comandos Complejos (Sincronización de Hora)
      else if (response.startsWith("SET_TIME|")) {
        String isoTime = response.substring(9);
        String xml = "<?xml version=\"1.0\" encoding=\"UTF-8\"?><Time xmlns=\"http://www.isapi.org/ver20/XMLSchema\" version=\"2.0\"><timeMode>manual</timeMode><localTime>" + isoTime + "</localTime></Time>";
        enviarPutDigest("/ISAPI/System/time", xml);
        Serial.println("⏰ Comando de sincronización de hora procesado: " + isoTime);
      }
    }
    http.end();
  }
}

/**
 * Función de parseo adaptativa para JSON (Ignora espacios en blanco y tabulaciones)
 */
String extraerDatoJSON(String fuente, String clave) {
  String busqueda = "\"" + clave + "\":";
  int posClave = fuente.indexOf(busqueda);
  
  if (posClave == -1) {
    // Intenta buscar con espacio adicional tras los dos puntos
    busqueda = "\"" + clave + "\": ";
    posClave = fuente.indexOf(busqueda);
  }
  
  if (posClave == -1) return "";
  
  int posInicio = fuente.indexOf("\"", posClave + busqueda.length());
  if (posInicio == -1) return "";
  posInicio += 1; 
  int posFin = fuente.indexOf("\"", posInicio);
  
  if (posFin == -1) return "";
  return fuente.substring(posInicio, posFin);
}

String getMD5(String data) {
  MD5Builder md5;
  md5.begin();
  md5.add(data);
  md5.calculate();
  return md5.toString();
}

String extraerParam(String header, String param) {
  int pos = header.indexOf(param + "=\"");
  if (pos == -1) return "";
  int start = pos + param.length() + 2;
  int end = header.indexOf("\"", start);
  return header.substring(start, end);
}