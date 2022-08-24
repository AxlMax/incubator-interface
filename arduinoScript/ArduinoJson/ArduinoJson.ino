#include <Arduino_JSON.h>
#include <DHT.h>

#define DHTPIN 3
#define resPin 4
#define humPin 5
#define v1Pin 6
#define v2Pin 7
#define freq 115200

#define DHTTYPE DHT11
 
DHT dht(DHTPIN, DHTTYPE);

void setup() {
    
    Serial.begin(freq);
    
    pinMode(LED_BUILTIN, OUTPUT);
    pinMode(resPin, OUTPUT);
    pinMode(humPin, OUTPUT);
    pinMode(v1Pin,  OUTPUT);
    pinMode(v2Pin,  OUTPUT);

    dht.begin();
    while (!Serial);

    getData();
}

void loop() {
}

void getData() {

    float h = dht.readHumidity();
    float t = dht.readTemperature();
    JSONVar myObject;

    myObject["temperatura"] = h;
    myObject["humedad"] = t;

    String jsonString = JSON.stringify(myObject);

    Serial.println(jsonString);
    
}


