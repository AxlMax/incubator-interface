#include <Arduino_JSON.h>

void setup() {
  Serial.begin(9600);
  while (!Serial);

  getData();
}

void loop() {
}

void getData() {

  JSONVar myObject;

  myObject["temperatura"] = 10;
  myObject["humedad"] = 10;

  String jsonString = JSON.stringify(myObject);

  Serial.println(jsonString);

}


