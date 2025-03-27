#ifndef WEBSERVER_H
#define WEBSERVER_H

#include <WiFi.h>
#include <ESPAsyncWebServer.h>
#include <SD.h>
#include <SPI.h>

class WebServer {
private:
    AsyncWebServer server;
    const char* ssid;
    const char* password;
    int sdCsPin;

public:
    WebServer(const char* ssid, const char* password, int sdCsPin);
    void begin();
};

#endif
