#include <QTRSensors.h>

QTRSensors qtr;

void setup() {
  Serial.begin(9600);
  // Optional: wait for some input from the user, such as a button press.
  // Initialize the sensors.
  // In this example we have three sensors on pins A0 - A2.
  qtr.setTypeRC(); // or setTypeAnalog()
  qtr.setSensorPins((const uint8_t[]){A1, A2, A3}, 3);
  // Optional: change parameters like RC timeout, set an emitter control pin...
  // Then start the calibration phase and move the sensors over both reflectance
  // extremes they will encounter in your application. This calibration should
  // take about 5 seconds (250 iterations * 20 ms per iteration).
  //
  // Passing a QTRReadMode to calibrate() is optional; it should match the mode
  // you plan to use when reading the sensors.
  Serial.println("###");
  Serial.println("### STARTED CALIBRATION ###");
  Serial.println("###");
  
  for (uint8_t i = 0; i < 250; i++) {
    qtr.calibrate();
    delay(20);
  }
  
  // Optional: signal that the calibration phase is now over and wait for
  // further input from the user, such as a button press.
  Serial.println("###");
  Serial.println("### FINISHED CALIBRATION ###");
  Serial.println("###");
}

void loop() {
  uint16_t sensors[1];
  // Get calibrated sensor values returned in the sensors array
  qtr.readCalibrated(sensors);
  Serial.print("value left: "); Serial.println(sensors[0]);
  Serial.print("value middle: "); Serial.println(sensors[1]);
  Serial.print("value right: "); Serial.println(sensors[2]);

  delay(100);
}