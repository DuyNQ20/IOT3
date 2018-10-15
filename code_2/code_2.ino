#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include "index.h"
// Thong so WiFi 
const char* ssid = "Ank";
const char* password = "1234567890";

// Tao server
ESP8266WebServer server(80);

// Pin
int output_pin = D1;

void setup() {

  // Khoi dong Serial
  Serial.begin(115200);
  delay(10);

  // Khai bao GPIO5
  pinMode(output_pin, OUTPUT);
  digitalWrite(output_pin, 0);

  // Ket noi toi mang WiFi 
  Serial.println();
  Serial.println();
  Serial.print("Dang ket noi toi mang ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("Da ket noi WiFi");

  server.on("/", handleRoot);
  server.on("/led", ledControl);
  // Khoi dong server
  server.begin();
  Serial.println("Khoi dong Server");

  // In dia chi IP
  Serial.println(WiFi.localIP());
  
}

void loop() {
  server.handleClient();  
}

void handleRoot()
{
  String s = MAIN_page; //Doc trang HTML
  server.send(200, "text/html", s); // Gui HTML den client
}
void ledControl()
{
    String tus = server.arg("status_led");
    if(tus=="1")
    {
      digitalWrite(output_pin, 1);
    }
    else
    {
      digitalWrite(output_pin, 0);
    }
}
