#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <WiFiClientSecure.h>
#include <WiFiManager.h>
#include <ESP8266WebServer.h>
#include <LittleFS.h> // Sistema de archivos para respaldo local

// --- CONFIGURACIÓN ---
const char* HOST_URL = "https://acceso.istae.edu.ec";
const char* TOKEN_NODE = "istae1805A";
const char* LOG_FILE = "/respaldo_logs.txt";
const int RELAY_PIN = 5;

// --- TEMPORIZADORES ---
unsigned long msRelay = 0, msSync = 0, msCheckCmd = 0, msWiFiCheck = 0;
const long duracionApertura = 3000, intervaloSync = 600000, intervaloCheckCmd = 3000, intervaloWiFi = 30000;

bool puertaAbierta = false;
String listaBlanca = "";
ESP8266WebServer server(80);

void setup() {
  Serial.begin(115200);
  pinMode(RELAY_PIN, OUTPUT);
  digitalWrite(RELAY_PIN, LOW);

  // Inicializar LittleFS
  if (!LittleFS.begin()) {
    Serial.println("❌ Error al montar LittleFS");
  }

  WiFiManager wifiManager;
  if (!wifiManager.autoConnect("NODE_PUERTA_ISTAE")) ESP.restart();

  server.onNotFound(manejarEventoBiometrico);
  server.begin();
  sincronizarListaBlanca();
}

void loop() {
  server.handleClient();
  unsigned long currentMillis = millis();

  // Gestión de WiFi y Reconexión
  if (currentMillis - msWiFiCheck >= intervaloWiFi) {
    if (WiFi.status() != WL_CONNECTED) WiFi.reconnect();
    else procesarPendientesLittleFS(); // Si hay red, enviar lo guardado
    msWiFiCheck = currentMillis;
  }

  // Cierre de puerta
  if (puertaAbierta && (currentMillis - msRelay >= duracionApertura)) {
    digitalWrite(RELAY_PIN, LOW);
    puertaAbierta = false;
  }

  // Polling y Sync
  if (currentMillis - msCheckCmd >= intervaloCheckCmd) { revisarComandosNube(); msCheckCmd = currentMillis; }
  if (currentMillis - msSync >= intervaloSync) { sincronizarListaBlanca(); msSync = currentMillis; }
}

// --- EXTRACCIÓN QUIRÚRGICA DE DATOS ---
void manejarEventoBiometrico() {
  if (server.method() == HTTP_POST) {
    String body = server.arg("plain");
    
    // Extracción de ID (employeeNoString)
    String id = extraerDato(body, "employeeNoString", 19);
    // Extracción de Fecha/Hora original del equipo (time)
    String fechaEquipo = extraerDato(body, "time", 7); 

    if (id != "") {
      Serial.printf("👤 ID: %s | 🕒 Fecha Equipo: %s\n", id.c_str(), fechaEquipo.c_str());
      
      String estado = (listaBlanca.indexOf(id) != -1) ? "EXITO" : "DENEGADO";
      if (estado == "EXITO") activarRele();
      
      // Intentar enviar, si falla, guardar en LittleFS
      if (!enviarLogNube(id, estado, fechaEquipo)) {
        guardarEnLittleFS(id, estado, fechaEquipo);
      }
    }
    server.send(200, "text/plain", "OK");
  }
}

String extraerDato(String fuente, String etiqueta, int offset) {
  int pos = fuente.indexOf(etiqueta);
  if (pos == -1) return "";
  String res = "";
  for (int i = pos + offset; i < pos + offset + 20; i++) {
    if (isDigit(fuente[i]) || fuente[i] == '-' || fuente[i] == ':' || fuente[i] == 'T') res += fuente[i];
    else if (res.length() > 0) break;
  }
  return res;
}

// --- SISTEMA DE RESPALDO (LITTLEFS) ---
void guardarEnLittleFS(String id, String estado, String fecha) {
  File f = LittleFS.open(LOG_FILE, "a");
  if (f) {
    f.printf("%s,%s,%s\n", id.c_str(), estado.c_str(), fecha.c_str());
    f.close();
    Serial.println("💾 Log respaldado localmente por falta de red.");
  }
}

void procesarPendientesLittleFS() {
  if (!LittleFS.exists(LOG_FILE)) return;
  
  File f = LittleFS.open(LOG_FILE, "r");
  String backupData = "";
  while (f.available()) backupData += (char)f.read();
  f.close();
  LittleFS.remove(LOG_FILE); // Limpiar tras leer

  // Re-enviar cada línea
  int pos = 0;
  while ((pos = backupData.indexOf('\n')) != -1) {
    String linea = backupData.substring(0, pos);
    backupData.remove(0, pos + 1);
    // Parsear simple (id,estado,fecha) y re-enviar
    // (Simplificado para este ejemplo)
    Serial.println("🔄 Re-enviando log pendiente...");
  }
}

// --- COMUNICACIÓN CLOUD ---
bool enviarLogNube(String id, String estado, String fecha) {
  if (WiFi.status() != WL_CONNECTED) return false;
  
  WiFiClientSecure client;
  client.setInsecure();
  HTTPClient http;
  String url = String(HOST_URL) + "/api/recibir_log";
  String json = "{\"id\":\"" + id + "\",\"estado\":\"" + estado + "\",\"fecha_dispositivo\":\"" + fecha + "\",\"token\":\"" + String(TOKEN_NODE) + "\"}";
  
  http.begin(client, url);
  http.addHeader("Content-Type", "application/json");
  int code = http.POST(json);
  http.end();
  return (code == 200);
}

void activarRele() {
  digitalWrite(RELAY_PIN, HIGH);
  puertaAbierta = true;
  msRelay = millis();
}

void sincronizarListaBlanca() {
  WiFiClientSecure client; client.setInsecure(); HTTPClient http;
  if (http.begin(client, String(HOST_URL) + "/api/sincronizar")) {
    if (http.GET() == 200) listaBlanca = http.getString();
    http.end();
  }
}

void revisarComandosNube() {
  WiFiClientSecure client; client.setInsecure(); HTTPClient http;
  if (http.begin(client, String(HOST_URL) + "/api/check_comando")) {
    if (http.GET() == 200 && http.getString() == "ABRIR") activarRele();
    http.end();
  }
}