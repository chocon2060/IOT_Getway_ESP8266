#include <ESP8266WiFi.h>
#include <PubSubClient.h>
#include <ArduinoJson.h>
#include "CRC32.h"
#include "configuration.h"
#include "ProtocolConvert.h"

// Update these with values suitable for your network.

crc32 crc;

WiFiClient espClient;
PubSubClient client(espClient);
ProtocolConvert converter;
bool uart_rxDone = false;
bool uartStart = false;
String RxBuffer = "";
String MainBuffer = "";
String modeData = "";
String Data = "";
uint16_t lastPoint;
uint16_t nextPoint;
int lastTime = 0;
void setup_wifi() {

  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    digitalWrite(BUILTIN_LED,LOW);
    delay(250);
    digitalWrite(BUILTIN_LED,HIGH);
    delay(250);
  }
  digitalWrite(BUILTIN_LED,LOW);
  randomSeed(micros());
}

void callback(char* topic, byte* payload, unsigned int length) {
  String strmsg = (char*)payload;
  if(crc.strCheckCrc(strmsg)){
    converter.Convert(crc.getStrmsg());
  }else{
    Serial.println("CRC ERROR");
  }
  crc.deleteStrmsg();
}

void reconnect() {
  while (!client.connected()) {
    String clientId = "ESP8266Client-";
    clientId += String(random(0xffff), HEX);
    if (client.connect(clientId.c_str())) {
      client.publish(topic_pub, "Client-Online");
      client.subscribe(topic_sub);
    } else {
      delay(5000);
    }
  }
}

void setup() {
  pinMode(BUILTIN_LED, OUTPUT);     // Initialize the BUILTIN_LED pin as an output
  Serial.begin(9600);
  setup_wifi();
  client.setServer(mqtt_server, port);
  client.setCallback(callback);
  crc.setPolynomial(Polynomial);
}

void loop() {
if (WiFi.status() != WL_CONNECTED){
  setup_wifi();
}else{
  if (!client.connected()) {
    reconnect();
  }
}
  client.loop();
  
  if(Serial.available()>0){
    uartStart = true;
    lastTime = millis();
    char data = Serial.read();
    RxBuffer += data;
    if(data == '}'){
      lastPoint = RxBuffer.indexOf('{');
      nextPoint = RxBuffer.indexOf('}');
      MainBuffer = RxBuffer.substring(lastPoint, nextPoint+1);
      // Serial.write(MainBuffer.c_str());
      RxBuffer = "";
      uart_rxDone = true;
    }
  }
  if(uartStart){
		if(millis() - lastTime > 500){
			RxBuffer = "";
			uartStart = false;
		}
	}
  if(uart_rxDone){
    client.publish(topic_pub, MainBuffer.c_str());
    MainBuffer = "";
    uart_rxDone = false;
  }
}