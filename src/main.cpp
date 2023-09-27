#include <Arduino.h>

#include <TFT_ILI9163C.h>
#include <SPI.h>
#include "Imagen1.h"
#include "Imagen2.h"

#define CS 5
#define DC 3 
#define MOSI 23
#define SCK 18

TFT_ILI9163C tft=TFT_ILI9163C(CS,DC);

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
const int batSen = 25;
// Variables de captacion de datos
int vib = 0;
int tem = 0;
int bat = 0;
int threshold = 40;
float dutyCycle1 = 0;
float dutyCycle2 = 0;
void touchInterrupt(void){
  Serial.println("tocado");

}
void setup() {
  ledcSetup(canal0, frecuencia, resolucion);
  ledcAttachPin(temPin, canal0);
  ledcSetup(canal1, frecuencia, resolucion);
  ledcAttachPin(vibPin, canal1);
  analogReadResolution(resolucion2);
  // Configuracion de sensores touch
  touchAttachInterrupt(T7, touchInterrupt, threshold);
  touchAttachInterrupt(T6, touchInterrupt, threshold);
  touchAttachInterrupt(T5, touchInterrupt, threshold);
  touchAttachInterrupt(T4, touchInterrupt, threshold);
  Serial.begin(9600);
}

void loop() {
  
  vib = analogRead(vibSen);
  tem = analogRead(temSen);
  bat = analogRead(batSen);

  dutyCycle1 = (0.499)*vib; 
  ledcWrite(canal0, int(dutyCycle1));
  delay(15);
  dutyCycle2 = (0.499)*tem; 
  ledcWrite(canal1, int(dutyCycle2));
  delay(15);
  Serial.print("PWM1 = ");
  Serial.println(int(dutyCycle2));
  Serial.print("PWM2 = ");
  Serial.println(int(dutyCycle1));
  Serial.print("batt = ");
  Serial.println(int(0.499*bat));

  delay(500);
}


