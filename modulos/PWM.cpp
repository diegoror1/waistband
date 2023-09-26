#include <Arduino.h>
const int temPin = 32;
const int vibPin = 34;

const int frecuencia = 5000;
const int canal = 0;
const int resolucion = 8;

void setup() {
  ledcSetup(canal, frecuencia, resolucion);
  ledcAttachPin(temPin, canal);
}

void loop() {
  for (int dutyCycle = 0; dutyCycle <=255; dutyCycle++){
    ledcWrite(canal, dutyCycle);
    delay(15);
  }
  for (int dutyCycle = 255; dutyCycle >=0; dutyCycle--){
    ledcWrite(canal, dutyCycle);
    delay(15);
  }

}