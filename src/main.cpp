#include <Arduino.h>
// configuracion de pines de salida PWM

const int temPin = 15;
const int vibPin = 2;
// configuracion de parametros de PWM
const int frecuencia = 5000;
const int canal0 = 0;
const int canal1 = 1;
const int resolucion = 8;
const int resolucion2 = 9;
// configuracion de pines de entrada analogica 
const int temSen = 32;
const int vibSen = 33;
// Variables de captacion de datos
int vib = 0;
int tem = 0;
float dutyCycle1 = 0;
float dutyCycle2 = 0;

void setup() {
  ledcSetup(canal0, frecuencia, resolucion);
  ledcAttachPin(temPin, canal0);
  ledcSetup(canal1, frecuencia, resolucion);
  ledcAttachPin(vibPin, canal1);
  analogReadResolution(resolucion2);
  Serial.begin(9600);
}

void loop() {
  
  vib = analogRead(vibSen);
  tem = analogRead(temSen);
  dutyCycle1 = (0.499)*vib; 
  ledcWrite(canal0, int(dutyCycle1));
  delay(15);
  dutyCycle2 = (0.499)*tem; 
  ledcWrite(canal1, int(dutyCycle2));
  delay(15);
  Serial.println(int(dutyCycle2));
  Serial.println(int(dutyCycle1));
  delay(500);
}


