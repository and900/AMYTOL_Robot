#include <Servo.h>
#include "Ultrasonic.h" //Grove Ultrasonic Ranger by Seed
#include "pitches.h"

#define BATTERY_PIN A0 //A1
#define FORWARD 1
#define BACKWARD -1

// PINS
int motorLPin = 5; // PWM output pin connected to the motor
int dirLPin = 6; // direction pin connected to the motor
int motorRPin = 2; // PWM output pin connected to the motor
int dirRPin = 3 ; // direction pin connected to the motor
int ultrasonicPin = 7;
int buzzerPin = 8;
int touchSensorPin = 9;
int buzzer = 8;

Servo servo;
Ultrasonic ultrasonic(ultrasonicPin);

int speed = 0; // speed value between 0 and 255
int forward_speed = 150;
int backward_speed = 150;
int speed_increment = 5;
int direction = FORWARD;

int num_times_to_repeat = 1;
boolean isMoving = false;

const int DISTANCE_TO_STOP_AT = 30;

// Next, we need to set up the pins as outputs:

void setup() {
  Serial.begin(9600);
  pinMode(motorLPin, OUTPUT);
  pinMode(dirLPin, OUTPUT);
  pinMode(motorRPin, OUTPUT);
  pinMode(dirRPin, OUTPUT);

  // Setup servo
  servo.attach(4);

  // Delay the motion for 2 seconds
  delay(2000);

  // Set servo to front
  servo.write(90);
  // Play initialised tone
  tone(buzzerPin, 262, 1000);

  Serial.println("Rover v3 initialised...");

  // Wait for 2 seconds before drive
  delay(2000);
}

// Now we can write the main loop of the program. 
// We will use the analogWrite() function to send a PWM signal to the motor pin, and digitalWrite() to set the direction pin:

void loop() {
  // CHECK BATTERY!
  if(checkBattery() == -1){
    // alert with buzzer!
    tone(buzzer, NOTE_C4, 500);
    tone(buzzer, NOTE_C5, 500);
    tone(buzzer, NOTE_C6, 500);
    return;
  }

  // Point 'eyes' forward and check distance
  if(scanForward() > DISTANCE_TO_STOP_AT) {
    if(!isMoving) {
      // Move forward if not already moving and set moving to TRUE
      forward(forward_speed);
      isMoving = true;
    }
  }
  else {
    // distance is less then 30cm so brake, backup and turn left OR right
    brake(1000);
    isMoving = false;
    backwardFor(backward_speed, 500);

    int leftDistance = scanLeft();
    int rightDistance = scanRight();

    // Turn whichever direction has a greater distance to travel
    if(leftDistance > rightDistance){
      turnLeft();
    }
    else {
      turnRight();
    }
  }
  delay(500);
}

void setSpeed(int s) {
  // set the motor speed to a value between 0 and 255
  analogWrite(motorLPin, s);
  analogWrite(motorRPin, s);
}

void turnLeft() {
  Serial.println("turn left...");
    // Both motors spin forward
    digitalWrite(dirLPin, LOW);
    digitalWrite(dirRPin, HIGH);

    // Left motor much slower than right
    analogWrite(motorLPin, 50);
    analogWrite(motorRPin, 200);

    delay(1000); // allow the motors to turn for 1 second
    brake(1000);
}

void turnRight() {
  Serial.println("turn right...");
    // Both motors spin forward
    digitalWrite(dirLPin, HIGH);
    digitalWrite(dirRPin, LOW);

    // Left motor much slower than right
    analogWrite(motorLPin, 200);
    analogWrite(motorRPin, 50);

    delay(1000);
    brake(1000);
}

void forward(int s) {
  Serial.println("forward...");
  digitalWrite(dirLPin, HIGH);
  digitalWrite(dirRPin, HIGH);

  setSpeed(s);
}

void backward(int s) {
  Serial.println("backward...");
  digitalWrite(dirLPin, LOW);
  digitalWrite(dirRPin, LOW);

  setSpeed(s);
}

void forwardFor(int s, int t) {
  Serial.println("forward for...");
    digitalWrite(dirLPin, HIGH);
    digitalWrite(dirRPin, HIGH);

    setSpeed(s);

    delay(t);
    brake(1000);
}

void backwardFor(int s, int t) {
  Serial.println("bacward for...");
    digitalWrite(dirLPin, LOW);
    digitalWrite(dirRPin, LOW);

    setSpeed(s);
    
    delay(t);
    brake(1000);
}

void brake(int ms) {
  Serial.println("braking....");
  while (speed > 0) {
    speed -= 75;
    setSpeed(speed);
  }
  speed = max(speed, 0);
  setSpeed(speed);

  delay(ms);
}

long getDistance() {
  long rangeInCentimeters;

  rangeInCentimeters = ultrasonic.MeasureInCentimeters(); // two measurements should keep an interval
  Serial.print(rangeInCentimeters);//0~400cm
  Serial.println(" cm");
  return rangeInCentimeters;
}

long scanForward() {
  servo.write(90);
  return getDistance(); 
}

long scanLeft() {
  servo.write(180);
  Serial.print("left distance: ");
  delay(2000);
  long distance = getDistance();
  scanForward();
  return distance;
}

long scanRight() {
  servo.write(0);
  Serial.print("right distance: ");
  delay(2000);
  long distance = getDistance();
  scanForward();
  return distance;
}

int checkBattery() {
  float vRef = 5; 
  float maxVoltage = 8.4; // Vmax
  float minVoltage = 6.5; // Vmin
  float ResistorUp = 100000; //100K
  float ResistorDown = 33000; //33K

  float analogVal = analogRead(BATTERY_PIN); 
  //Serial.print("analogVal = ");Serial.println(analogVal);
  float proportionalVoltage = analogVal * vRef / 1024.0;
  //Serial.print("proportionalVoltage = ");Serial.println(proportionalVoltage);

  // Gives us the proportional voltage of the voltage divider
  // Rearranging the resistance equation, we can say final voltage is:
  float totalBatteryVoltage = proportionalVoltage * (ResistorUp / ResistorDown + 1);

  // Get battery percentage using the min/max limits
  float batteryPercentage = (totalBatteryVoltage - minVoltage) / (maxVoltage - minVoltage) * 100;

  // Confine the values to between 0-100
  if (batteryPercentage > 100) batteryPercentage = 100;
  else if (batteryPercentage < 0) batteryPercentage = 0;

  // Need some code to alert user or take action when voltage drops below 10.4v (to be safe)
  if (totalBatteryVoltage <= minVoltage) {
    // ###########
    // TAKE ACTION !!!
    // ###########

    Serial.println("### WARNING: BATTERY LOW - PLEASE CHARGE ###");
    return -1;
  }

  Serial.print("BATTERY VOLTAGE: ");Serial.println(totalBatteryVoltage); 
  //Serial.print("CAPACITY: "); Serial.print(batteryPercentage); Serial.println("%");

  return 1;

}
