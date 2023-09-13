#include <QTRSensors.h>

QTRSensors qtr;

void setup() {
  Serial.begin(9600);
  // Optional: wait for some input from the user, such as a button press.
  // Initialize the sensors.
  // In this example we have three sensors on pins A0 - A2.
  qtr.setTypeRC(); // or setTypeAnalog()
  qtr.setSensorPins((const uint8_t[]){A3,A1}, 2);
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
  // Get calibrated sensor values returned in the sensors array, along with the
  // line position, which will range from 0 to 2000, with 1000 corresponding to
  // a position under the middle sensor.
  qtr.readCalibrated(sensors);
  Serial.print("value left: "); Serial.println(sensors[0]);
  Serial.print("value right: "); Serial.println(sensors[1]);
  // If all three sensors see very low reflectance, take some appropriate action
  // for this  situation.
  // if (sensors[0]) {
  //   // Do something. Maybe this means we're at the edge of a course or about to
  //   // fall off a table, in which case we might want to stop moving, back up,
  //   // and turn around.
  //   //Serial.println("LOW reflectance...");
  //   return;
  // }
  // Compute our "error" from the line position. We will make it so that the
  // error is zero when the middle sensor is over the line, because this is our
  // goal. Error will range from -1000 to +1000. If we have sensor 0 on the left
  // and sensor 2 on the right,  a reading of -1000 means that we see the line
  // on the left and a reading of +1000 means we see the line on the right.
  // int16_t error = position - 1000;
  // int16_t leftMotorSpeed = 100;
  // int16_t rightMotorSpeed = 100;
  // if (error < -500) {
  //   // the line is on the left
  //   leftMotorSpeed = 0;  // turn left
  // }
  // if (error > 500) {
  //   // the line is on the right
  //   rightMotorSpeed = 0;  // turn right
  // }
  // set motor speeds using the two motor speed variables above

  delay(100);
}