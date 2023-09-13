#include <Servo.h>

Servo myservo;

void setup() {
  Serial.begin(9600);
  myservo.attach(4); // attach servo to digital pin 4 (D4)

  myservo.write(0); 
  Serial.println("Initialised At 0 degrees");
  delay(5000);

  myservo.write(90); // move to 90 degrees (left)
  Serial.println("Moved to 90 degrees");
  delay(2000);       // wait for 2 seconds

  myservo.write(180); // move to 180 degrees (left)
  Serial.println("Moved to 180 degrees"); 
  delay(2000);

  myservo.write(90); // Finish forward at 90 degrees (left)
  Serial.println("Moved to 90 degrees"); 
}

void loop() {
  // nothing here !!
}
