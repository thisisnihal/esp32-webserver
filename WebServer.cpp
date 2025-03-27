#include "WebServer.h"

WebServer::WebServer(const char* ssid, const char* password, int sdCsPin)
    : server(80), ssid(ssid), password(password), sdCsPin(sdCsPin) {}

void WebServer::begin() {
    Serial.begin(115200);

    // Connect to WiFi
    WiFi.begin(ssid, password);
    while (WiFi.status() != WL_CONNECTED) {
        delay(1000);
        Serial.println("Connecting to WiFi...");
    }
    Serial.println("Connected! IP: " + WiFi.localIP().toString());

    // Initialize SD card
    if (!SD.begin(sdCsPin)) {
        Serial.println("SD Card Mount Failed!");
        return;
    }

    // Serve index.html
    server.on("/", HTTP_GET, [](AsyncWebServerRequest *request) {
        request->send(SD, "/index.html", "text/html");
    });

    // Serve other files dynamically
    server.onNotFound([](AsyncWebServerRequest *request) {
        String path = request->url();
        if (SD.exists(path)) {
            request->send(SD, path, "text/plain");
        } else {
            request->send(404, "text/plain", "File Not Found");
        }
    });

    server.begin();
}
