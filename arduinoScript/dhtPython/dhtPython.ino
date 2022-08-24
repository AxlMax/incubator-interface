
#include <DHT.h>
 
#define DHTPIN 3
#define resPin 4
#define humPin 5
#define v1Pin 6
#define v2Pin 7
#define freq 115200

#define DHTTYPE DHT11
 
DHT dht(DHTPIN, DHTTYPE);

void blink(int);

void setup(){
    Serial.begin(freq);
    
    pinMode(LED_BUILDIN, OUTPUT);
    pinMode(resPin, OUTPUT);
    pinMode(humPin, OUTPUT);
    pinMode(v1Pin,  OUTPUT);
    pinMode(v2Pin,  OUTPUT);

    dht.begin();
}

void loop(){
    blink(2);
    Serial.Println("hola como estas");
}

void blink(int dt){
    digitalWrite(LED_BUILDIN, HIGH);
    delay(dt*1000);
    digitalWrite(LED_BUILDIN, LOW);
}

