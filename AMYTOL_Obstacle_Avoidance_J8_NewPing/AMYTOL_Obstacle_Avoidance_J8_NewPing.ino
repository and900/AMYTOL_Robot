#include <Amytol.h>
#include <Servo.h>  //Arduino IDE included Servo motor library
#include <NewPing.h>  //Ultrasonic sensor function manually installed library 
#define NEXTGEN     // NextGen CodeCamp Specifics
// PINS to set up the pins as outputs:
Rbt rbt (007); //Secret Agent Pin Declaration 
//sensor pins J8 Nextgen Rover v3
#define trig_pin A1 //analog input 1
#define echo_pin A1 //analog input 2 if Grove one pin use same pin

#define maximum_distance 200
boolean goesForward = false;
int distance = 100;

NewPing sonar(trig_pin, echo_pin, maximum_distance); //sensor function
Servo servo_motor; //Name for our servo motor

void setup()        // Where we setup the initalising code which run one
{
  rbt.begin();      // Initalise the Workspace
  //servo.attach(4);   // Setup servo
  servo_motor.attach(4);
  delay(500);  // Give Time ot initalise Delay the motion
  servo_motor.write(90);
  delay(2000);
  distance = readPing();
  delay(100);
  distance = readPing();
  delay(100);
  distance = readPing();
  delay(100);
  distance = readPing();
  delay(100);
// servo.write(90);  // Set servo to front
//  delay(2000);
}
void loop() {         // Continualy repeats unless told to stop  
  int distanceRight = 0;
  int distanceLeft = 0;
  delay(50);

  if (distance <= 30){
    rbt.stopHard();
    delay(300);
    rbt.backward(fast_speed, 400);
    delay(400);
    rbt.stopHard();
    delay(300);
    distanceRight = lookRight();
    delay(300);
    distanceLeft = lookLeft();
    delay(300);
    if (distance >= distanceLeft){
    rbt.backward(fast_speed, 400);
    rbt.turnRight(140,400);
    rbt.stopHard();
    }
    else{
    rbt.backward(fast_speed, 400);
    rbt.turnLeft(140,400);
    rbt.stopHard();
    }
  }
  else{
    rbt.forward(medLow_speed);
  }
    distance = readPing();
}

//=====================================================
//=== ************* Functions ********************* ===
//=====================================================
int lookRight(){ 
  servo_motor.write(50);
  delay(500);
  int distance = readPing();
  delay(100);
  servo_motor.write(90);
  return distance;
}
int lookLeft(){
  servo_motor.write(170);
  delay(500);
  int distance = readPing();
  delay(100);
  servo_motor.write(90);
  return distance;
  delay(100);
}
int readPing(){
  delay(70);
  int cm = sonar.ping_cm();
  if (cm==0){
    cm=250;
  }
  return cm;
}









