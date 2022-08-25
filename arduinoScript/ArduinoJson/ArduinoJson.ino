#include <Arduino_JSON.h>
#include <DHT.h>

#define DHTPIN 3
#define resPin 4
#define humPin 5
#define v1Pin 6
#define v2Pin 7
#define freq 115200
#define DHTTYPE DHT11

String inputString; 
DHT dht(DHTPIN, DHTTYPE);
JSONVar myObject;

void blink(int, int);
void getData();
void SerialEvent();

void setup() {
    
    Serial.begin(freq);
    
    pinMode(LED_BUILTIN, OUTPUT);
    pinMode(resPin, OUTPUT);
    pinMode(humPin, OUTPUT);
    pinMode(v1Pin,  OUTPUT);
    pinMode(v2Pin,  OUTPUT);

    dht.begin();
    while (!Serial);
}

void loop() {
    blink(v1Pin,1);
    SerialEvent();
}

void getData() {

    float h = dht.readHumidity();
    float t = dht.readTemperature();
    
    myObject["temperatura"] = t;
    myObject["humedad"] = h;

    String jsonString = JSON.stringify(myObject);

    Serial.println(jsonString);

}

void blink(int pin,int dt){
    digitalWrite(pin, HIGH);
    delay(dt*1000);
    digitalWrite(pin, LOW);
}

void SerialEvent(){
  while(Serial.available()){
    char inputChar = Serial.read();
    inputString += inputChar;
    }

    if(inputString.indexOf("getValue")>=0){
        getData();
    }

    if(inputString.indexOf("T") >= 0){
        blink(resPin,1);
    } 

    if(inputString.indexOf("H") >= 0){
        blink(humPin,1);
    }

    inputString = "";
}