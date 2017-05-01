/*
Custom Weight Program for Hybrid Motor Load Cell
By: Ken Sodetz
Created for Purdue Orbital Hybrid Motro Team
Portions borrowd from Nathan Seidle at Sparkfun Electronics
*/

#include "HX711.h"

#define calibration_factor 1040 //from calibration  

#define DAT  5 //data pin 5
#define CLK  4 //data pin 4
#define SER 9600 //serial port

HX711 scale(DAT, CLK); //corresponds to the respective pins on the board

void setup() {
  Serial.begin(SER);
  Serial.println("Load Cell Start");

  scale.set_scale(calibration_factor); 
  scale.tare(); 
  Serial.println("Readings:");
}

void loop() {
  Serial.print("Reading: ");
  Serial.print(scale.get_units(), 1); 
  Serial.print(" Newtons"); 
  Serial.println();
}
