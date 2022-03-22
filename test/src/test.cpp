/******************************************************/
//       THIS IS A GENERATED FILE - DO NOT EDIT       //
/******************************************************/

#include "Particle.h"
#line 1 "c:/Users/reed_/Documents/IoT/PredictiveWateringSystem/test/src/test.ino"
/*
 * Project test
 * Description:
 * Author:
 * Date:
 */
#include "neopixel.h"
void setup();
void loop();
#line 8 "c:/Users/reed_/Documents/IoT/PredictiveWateringSystem/test/src/test.ino"
const int PIXELPIN    = D6;  //  First NeoPixel on pin D6
const int PIXELNUM    = 1;   //  1 pixel in string

SYSTEM_MODE(SEMI_AUTOMATIC);
Adafruit_NeoPixel waterPixel(PIXELNUM, PIXELPIN, WS2812B);

void setup() {
  Serial.begin(9600);
  Serial.println("Setup");
  waterPixel.begin();
  waterPixel.show();               // Initialize all pixels to 'off'

}

// loop() runs over and over again, as quickly as it can execute.
void loop() {
  Serial.print(".");
    waterPixel.setPixelColor(0,0,255,0);            //  Set pixel color GREEN
    waterPixel.show();
delay(100);
    waterPixel.setPixelColor(0,255,0,0);            //  Set pixel color RED
    waterPixel.show();
delay(100);

}