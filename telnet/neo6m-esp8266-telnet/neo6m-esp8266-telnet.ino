#include <ESP8266WiFi.h>


char ssid[] = "WIFI_SSID";
char password[] = "WIFI_PASSWORD";


char host[] = "Server_IP";
const uint16_t port = 17; //Server Port

void setup() {
  Serial.begin(115200);
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}

void loop() {
  Serial.print("connecting to ");
  Serial.print(host);
  Serial.print(':');
  Serial.println(port);

  WiFiClient client;
  if (!client.connect(host, port)) {
    Serial.println("connection failed");
    delay(5000);
    return;
  }


  Serial.println("sending data to server");
  if (client.connected()) {
    client.println("test");
  }


  Serial.println("closing connection");
  client.stop();

}