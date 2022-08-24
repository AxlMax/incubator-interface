
#include <DHT.h>
#include <ArduinoJson.h>

#define DHTPIN 3
#define resPin 4
#define humPin 5
#define v1Pin 6
#define v2Pin 7
#define freq 115200

#define DHTTYPE DHT11
 
DHT dht(DHTPIN, DHTTYPE);
StaticJsonDocument<200> doc;

void blink(int);

void setup(){
    Serial.begin(freq);
    
    pinMode(LED_BUILTIN, OUTPUT);
    pinMode(resPin, OUTPUT);
    pinMode(humPin, OUTPUT);
    pinMode(v1Pin,  OUTPUT);
    pinMode(v2Pin,  OUTPUT);

    dht.begin();
}

void loop(){
    blink(1);
    float h = dht.readHumidity();
    float t = dht.readTemperature();

    doc["temperatura"] = randNumber;
    doc["humedad"] = randNumber;
      
    serializeJson(doc, Serial);
    Serial.println(); 
}

void blink(int dt){
    digitalWrite(resPin, HIGH);
    delay(dt*1000);
    digitalWrite(resPin, LOW);
}

