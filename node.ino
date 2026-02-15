#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <WiFiClientSecure.h>
#include <WiFiManager.h>
#include <ESP8266WebServer.h>
#include <LittleFS.h>

// --- CONFIGURACIÓN ---
const char* HOST_URL = "https://acceso.istae.edu.ec";
const char* TOKEN_NODE = "istae1805A";
const char* BACKUP_PATH = "/respaldo_logs.txt";
const int RELAY_PIN = 5; // Pin D1

// --- TEMPORIZADORES (NO BLOQUEANTES) ---
unsigned long msRelay = 0, msSync = 0, msCheckCmd = 0, msWiFiCheck = 0;
const long duracionApertura = 3000;
const long intervaloSync = 600000;
const long intervaloCheckCmd = 3000;
const long intervaloWiFi = 30000;

bool puertaAbierta = false;
String listaBlanca = "";
ESP8266WebServer server(80);

void setup() {
  Serial.begin(115200);
  pinMode(RELAY_PIN, OUTPUT);
  digitalWrite(RELAY_PIN, LOW);

  if (!LittleFS.begin()) Serial.println("❌ Error LittleFS");

  WiFiManager wm;
  if (!wm.autoConnect("NODE_PUERTA_ISTAE")) ESP.restart();

  Serial.println("✅ Red ISTAE conectada.");
  server.onNotFound(manejarEventoBiometrico);
  server.begin();
  sincronizarListaBlanca();
}

void loop() {
  server.handleClient();
  unsigned long now = millis();

  // Gestión de WiFi y Respaldo
  if (now - msWiFiCheck >= intervaloWiFi) {
    if (WiFi.status() != WL_CONNECTED) WiFi.reconnect();
    else procesarPendientesLittleFS();
    msWiFiCheck = now;
  }

  // Cierre de puerta automático
  if (puertaAbierta && (now - msRelay >= duracionApertura)) {
    digitalWrite(RELAY_PIN, LOW);
    puertaAbierta = false;
    Serial.println("🔒 Puerta cerrada físicamente.");
  }

  // Tareas de red
  if (now - msCheckCmd >= intervaloCheckCmd) { revisarComandosNube(); msCheckCmd = now; }
  if (now - msSync >= intervaloSync) { sincronizarListaBlanca(); msSync = now; }
}

// --- PROCESAMIENTO XML DE FÁBRICA ---
void manejarEventoBiometrico() {
  if (server.method() == HTTP_POST) {
    String body = "";
    if (server.hasArg("plain")) body = server.arg("plain");
    else while (server.client().available()) body += (char)server.client().read();

    if (body.length() > 0) {
      // Extracción entre etiquetas XML de fábrica <tag>DATO</tag>
      String id = extraerEntreEtiquetas(body, "<employeeNoString>", "</employeeNoString>");
      String fecha = extraerEntreEtiquetas(body, "<time>", "</time>");

      if (id != "") {
        Serial.printf("\n👤 ID Detectado: %s | 🕒 Hora: %s\n", id.c_str(), fecha.c_str());
        
        String estado = (listaBlanca.indexOf(id) != -1) ? "EXITO" : "DENEGADO";
        if (estado == "EXITO") activarRele();
        
        if (!enviarLogNube(id, estado, fecha)) {
          guardarEnLittleFS(id, estado, fecha);
        }
      }
    }
    server.send(200, "text/plain", "OK");
  }
}

String extraerEntreEtiquetas(String fuente, String inicio, String fin) {
  int posInicio = fuente.indexOf(inicio);
  if (posInicio == -1) return "";
  posInicio += inicio.length();
  int posFin = fuente.indexOf(fin, posInicio);
  if (posFin == -1) return "";
  return fuente.substring(posInicio, posFin);
}

// --- COMUNICACIÓN Y PERSISTENCIA ---
void guardarEnLittleFS(String id, String estado, String fecha) {
  File f = LittleFS.open(BACKUP_PATH, "a");
  if (f) {
    f.printf("%s,%s,%s\n", id.c_str(), estado.c_str(), fecha.c_str());
    f.close();
    Serial.println("💾 Falló red. Log guardado en memoria interna.");
  }
}

void procesarPendientesLittleFS() {
  if (!LittleFS.exists(BACKUP_PATH)) return;
  File f = LittleFS.open(BACKUP_PATH, "r");
  String buffer = "";
  while (f.available()) buffer += (char)f.read();
  f.close();
  LittleFS.remove(BACKUP_PATH);

  int pos = 0;
  while ((pos = buffer.indexOf('\n')) != -1) {
    String linea = buffer.substring(0, pos);
    buffer.remove(0, pos + 1);
    int c1 = linea.indexOf(',');
    int c2 = linea.lastIndexOf(',');
    if (c1 != -1 && c2 != -1) {
      String id = linea.substring(0, c1);
      String est = linea.substring(c1 + 1, c2);
      String fec = linea.substring(c2 + 1);
      if (!enviarLogNube(id, est, fec)) {
        guardarEnLittleFS(id, est, fec); // Re-guardar si la nube sigue caída
        break;
      }
      Serial.println("🔄 Log de respaldo enviado con éxito.");
    }
  }
}

bool enviarLogNube(String id, String estado, String fecha) {
  if (WiFi.status() != WL_CONNECTED) return false;
  WiFiClientSecure client; client.setInsecure();
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
  Serial.println("🔓 Apertura autorizada.");
}

void sincronizarListaBlanca() {
  if (WiFi.status() != WL_CONNECTED) return;
  WiFiClientSecure client; client.setInsecure(); HTTPClient http;
  if (http.begin(client, String(HOST_URL) + "/api/sincronizar")) {
    if (http.GET() == 200) {
      listaBlanca = http.getString();
      Serial.println("☁️ Usuarios sincronizados desde la nube.");
    }
    http.end();
  }
}

void revisarComandosNube() {
  if (WiFi.status() != WL_CONNECTED) return;
  WiFiClientSecure client; client.setInsecure(); HTTPClient http;
  if (http.begin(client, String(HOST_URL) + "/api/check_comando")) {
    if (http.GET() == 200 && http.getString() == "ABRIR") {
      activarRele();
      Serial.println("🌐 Orden remota detectada: ABRIR");
    }
    http.end();
  }
}