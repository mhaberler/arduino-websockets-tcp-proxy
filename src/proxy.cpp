
#include <ProxyWebSocketsServer.h>

#ifndef WIFI_SSID
    #define WIFI_SSID "WiFi SSID"
#endif

#ifndef WIFI_PASSWORD
    #define WIFI_PASSWORD "password"
#endif


ProxyWebSocketsServer *webSocket;

void setup() {
    delay(3000);
    Serial.begin(115200);

    Serial.printf("Connecting to WiFi %s\n", WIFI_SSID);
    WiFi.mode(WIFI_STA);
    WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
    while (WiFi.status() != WL_CONNECTED) {
        delay(1000);
    }
    Serial.printf("WiFi connected, IP: %s\n", WiFi.localIP().toString().c_str());

    webSocket = new ProxyWebSocketsServer(8883, PROXY_DEST, 1883, 2000);
}

void loop() {
    if (webSocket)
        webSocket->loop();
    delay(1);
}
