#include <ArduinoJson.h>

long randNumber;
String inputString;

StaticJsonDocument<200> doc;

void setup(){
  Serial.begin(115200);
  randomSeed(analogRead(0));
  }

void loop(){
  delay(100);
  SerialEvent();
}

void SerialEvent(){
  while(Serial.available()){
    char inputChar = Serial.read();
    inputString += inputChar;
    }
    if(inputString.indexOf("getValue")>=0){
      randNumber = random(100);
      
      doc["temperatura"] = randNumber;
      doc["humedad"] = randNumber;
      
      serializeJson(doc, Serial);
      Serial.println(); 
    } 
    inputString = "";
  }
