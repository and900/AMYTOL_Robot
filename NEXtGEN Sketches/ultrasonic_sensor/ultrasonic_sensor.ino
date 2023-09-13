#include "Ultrasonic.h"   // Make sure the Grove Ultrasonic Ranger library by Seeed Studio is installed

Ultrasonic ultrasonic(7);
void setup() {
 Serial.begin(9600);
}

void loop() {
 long RangeInInches;
 long RangeInCentimeters;

 RangeInCentimeters = ultrasonic.MeasureInCentimeters(); // two measurements should keep an interval
 Serial.print(RangeInCentimeters);//0~400cm
 Serial.println(" cm");
 delay(750);
}