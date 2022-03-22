/******************************************************/
//       THIS IS A GENERATED FILE - DO NOT EDIT       //
/******************************************************/

#include "Particle.h"
#line 1 "c:/Users/reed_/Documents/IoT/PredictiveWateringSystem/DustSensorTest/src/DustSensorTest.ino"
/*
 * Project       DustSensorTest
 * Description:  Test the interface to the dust sensor
 * Author:       Reed Searle
 * Date:         18 March 2022
 */

#include <math.h>
void setup();
void loop();
#line 9 "c:/Users/reed_/Documents/IoT/PredictiveWateringSystem/DustSensorTest/src/DustSensorTest.ino"
SYSTEM_MODE(SEMI_AUTOMATIC);
const int DUSTPIN    = D5;      // Dust sensor Pin
const int SAMPLETIME = 30000;   // sample time of 30 sec

float duration;                 // duration that the sensor pin is low during a given sample - uS
float lowPulseOccupancy;        // Duration the pin is low for the sample time of 30 sec - uS
float sampleStart;              // Timer for sample
float ratio;                    // Ration of LPO time to total time
float concentration;            // Concentration of dut in sample


void setup() {
  Serial.begin(9600);
  sampleStart = millis();

  pinMode(DUSTPIN, INPUT);

  lowPulseOccupancy = 0;        //  Initialize all variables
  ratio             = 0;
  concentration     = 0;  
}

void loop() {
  duration = pulseIn(DUSTPIN, LOW);  //  Read the input pin for low pulses
  lowPulseOccupancy += duration;     //  summ the total amount of low time

  if (millis() - sampleStart > SAMPLETIME) {   //  Once the air has been samples for 30 sec
    ratio = lowPulseOccupancy / (SAMPLETIME * 10.0);   // calculate the ratio
    concentration = 1.1 * pow(ratio, 3) - 3.8 * pow(ratio, 2) +520.0 * ratio + 0.62;  //  Calculate the concentration
    Serial.printf("LPO %0.0f, concen %0.2f, ratio %0.2f\n", lowPulseOccupancy, concentration, ratio);
    lowPulseOccupancy = 0;  // reset the LPO
    sampleStart = millis(); // Reset the timer
  }
}