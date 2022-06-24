#include <ESP8266WiFi.h>
#include <WiFiUdp.h>
#include <OSCMessage.h>

char ssid[] = "WIFI_SSID";
char password[] = "WIFI_PASSWORD";

WiFiUDP Udp;

const IPAddress outIp(192,168,0,25); //IP address of the OSC server
const unsigned int outPort = 1234; //Port of the OSC server
const unsigned int localPort = 1235; //Local port

void setup() {
  Serial.begin(115200);
  Serial.print("Connecting to ");Serial.println(ssid);
  
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println(".");

  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());

  Serial.println("Starting UDP Communication");
  Udp.begin(localPort);
}

void loop() {
  OSCMessage msg("/message");
  msg.add("test");
  Udp.beginPacket(outIp, outPort);
  msg.send(Udp);
  Udp.endPacket();
  msg.empty();
}