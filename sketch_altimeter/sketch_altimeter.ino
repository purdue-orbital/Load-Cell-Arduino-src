#include <Wire.h>
#include "SparkFunMPL3115A2.h"

MPL3115A2 altimeterSensor;

void setup() {
  Wire.begin();
  Serial.begin(9600);

  altimeterSensor.begin();
  altimeterSensor.setModeAltimeter();
  altimeterSensor.setOversampleRate(7); //value between 0 to 7
  altimeterSensor.enableEventFlags();
}

void loop() {
  float alt = altimeterSensor.readAltitudeFt();
  float temp = altimeterSensor.readTempF();
  Serial.print("Altitude: ");
  Serial.print(alt, 2);
  Serial.print(" feet");
  Serial.print(" Temperature: ");
  Serial.print(temp, 2);
  Serial.print(" F");
  Serial.println();
}


