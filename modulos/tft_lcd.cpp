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

void setup() {
  tft.begin();
}

void loop() {
  uint16_t dato=0;
  for(uint8_t y=0;y<128;y++){
    for(uint8_t x=0;x<128;x++){
      tft.drawPixel(x,y,LogoParsek[dato]);
      dato++;
    }
  }

delay(3000);

dato=0;

  for(uint8_t y=0;y<128;y++){
    for(uint8_t x=0;x<128;x++){
      tft.drawPixel(x,y,Parsek[dato]);
      dato++;
    }
  }

delay(3000);

}
