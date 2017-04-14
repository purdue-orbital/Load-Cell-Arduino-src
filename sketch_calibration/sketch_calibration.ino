/*
Custom Calibration Program for Hybrid Motor Load Cell
By: Ken Sodetz
4/12/2017
Created for Purdue Orbital Hybrid Motor Team
Portions borrowed from Nathan Seidle at SparkFun Electronics
*/

#include "HX711.h"

#define DAT  5 //pin 5 on the arduino
#define CLK  4 //pin 4 on the arduino 
#define NEWTON 4.44822162

HX711 scale(DAT, CLK); //corresponds to the respective pins on the arduino board

float factor =  350;
float weight;
float force;
void setup() {
  Serial.begin(9600);
  Serial.println("HX711 calibration");
  Serial.println("Press a to increase calibration factor by 100");
  Serial.println("Press z to decrease calibration factor by 100");
  Serial.println("Press s to increase calibration factor by 10");
  Serial.println("Press x to decrease calibration factor by 10");
  Serial.println("Press d to increase calibration factor by 1");
  Serial.println("Press c to decrease calibration factor by 1");

  scale.set_scale();
  scale.tare(); //Reset to 0

  long zero_reading = scale.read_average(); //Get a base reading
  Serial.print("Zero reading: ");
  Serial.println(zero_reading);
}

void loop() {

  if(Serial.available()){
    char temp = Serial.read();
    if(temp == 'a')
      factor += 100;
    else if(temp == 'z')
      factor -= 100;
    else if(temp == 's')
      factor +=10;
    else if(temp == 'x')
      factor -=10;
     else if(temp == 'd')
      factor +=1;
     else if(temp == 'c')
      factor -= 1;
  }
  scale.set_scale(factor);
  weight = scale.get_units();
  Serial.print("Reading: ");
  Serial.print(weight, 1);
  Serial.print(" lbs ---- ");
  Serial.print(weight*NEWTON, 1);
  Serial.print(" Newtons ");
  Serial.print(" Calibration factor: ");
  Serial.print(factor);
  Serial.println();

  
}
