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
void validationTemp();
void validationHum();

unsigned int tempActual = 0;
unsigned int humActual  = 0;

unsigned int tempAmbiente = 0;
unsigned int humAmbiente  = 0;

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
    SerialEvent();

    if(tempActual != 0){
        tempAmbiente = dht.readTemperature();
        validationTemp()
    }

    if(humActual != 0){
        humAmbiente = dht.readHumidity();
        validationHum();
    }
    
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

    int limitSup = 0;
    int limitInf = 0;

    if(inputString.indexOf("getValue")>=0){
        getData();
    }

    if(inputString.indexOf("T") >= 0){
        limitSup = inputString.indexOf(":") + 1;
        limitInf = inputString.length();

        tempActual = inputString.substring(limitSup, limitInf).toFloat();
    } 

    if(inputString.indexOf("H") >= 0){
        limitSup = inputString.indexOf(":") + 1;
        limitInf = inputString.length();

        humActual = inputString.substring(limitSup, limitInf).toFloat();
    }

    inputString = "";
}

void validationTemp(){
    if(tempActual > tempAmbiente){
        digitalWrite(v1Pin, HIGH);
        digitalWrite(v2Pin, LOW);
    }else{
        digitalWrite(v1Pin, HIGH);
        digitalWrite(v2Pin, HIGH);
        digitalWrite(resPin, LOW);
    }
}

void validationHum(){
        if(HumActual > HumAmbiente){
        digitalWrite(v1Pin, HIGH);
        digitalWrite(v2Pin, LOW);
    }else{
        digitalWrite(v1Pin, HIGH);
        digitalWrite(v2Pin, HIGH);
        digitalWrite(humPin, LOW);
    }
}