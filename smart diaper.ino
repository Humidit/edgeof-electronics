#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char auth[] = "6d2de121dc234ef88413b003825c5258";
const int sensorPin = 4; 
int sensorState = 0;
int lastState = 0;


void setup()
{
  Serial.begin(9600);
  Blynk.begin(auth, "connection error", "jarvis123");
  pinMode(sensorPin, INPUT);
}

void loop()
{ 
  Blynk.run();

  sensorState = digitalRead(sensorPin);
Serial.println(sensorState);

if (sensorState == 1 && lastState == 0) {
  Serial.println("diaper is dry");
   
  lastState = 1;
  delay(1000);

    
  } 
  else if (sensorState == 1 && lastState == 1) {
  Serial.println("diaper is dry");
 
  delay(1000);
  }
  else {
    //st
    Serial.println("diaper is wet");
    Blynk.notify("diaper is wet change it");
    lastState = 0;
    delay(1000);
  }
  
  delay(100);
}
