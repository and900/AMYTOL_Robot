#include <Amytol.h>
#include <Servo.h>  //Arduino IDE included Servo motor library
#define NEXTGEN     // NextGen CodeCamp Specifics
// PINS to set up the pins as outputs:
Rbt rbt (007); //Secret Agent Pin Declaration 
//Ultrasonic sensor pins J8 Nexgen Rover v3
//#define trig_pin A1 //analog input 1
//#define echo_pin A1 //analog input 2 if Grove one pin use same pin
//Ultrasonic sensor pins J3 Nexgen Rover v3
int trig_pin = 7; 
int echo_pin = 7; 
//Ultrasonic sensor pins J10 Nexgen Rover v3
//int trig_pin = A5; //analog input 1
//int echo_pin = A5; //analog input 2 if Grove one pin use same pin
#define maximum_distance 200
boolean goesForward = false;
int distance = 100;

NewPing sonar(trig_pin, echo_pin, maximum_distance); //sensor function
Servo servo_motor; //Name for our servo motor

void setup()        // Where we setup the initalising code which run one
{
  rbt.begin();      // Initalise the Workspace
  servo_motor.attach(4); // Setup servo
  delay(500);  // Give Time ot initalise Delay the motion
  servo_motor.write(90);
  delay(2000);
  distance = readPing();
  delay(100);
}
void loop() {         // Continualy repeats unless told to stop  
  int distanceRight = 0;
  int distanceLeft = 0;
  delay(50);

  if (distance <= 40){
    rbt.stopCoast(250); //     rbt.stopHard();
    delay(300);
    rbt.backward(fast_speed, 400);
    delay(400);
    rbt.stopCoast(fast_speed); //  rbt.stopHard();
    delay(300);
    distanceRight =  lookRight();
    delay(300);
    distanceLeft = lookLeft();
    delay(300);
    if (distance >= distanceLeft){
    rbt.turnRight(140,400);
    rbt.stopHard();
    }
    else{
    rbt.turnLeft(140,400);
    rbt.stopHard();
    }
  }
  else{
    rbt.forward(255);   //rbt.frwrdSpedVar(220, 220, medLow_speed);
  }
    distance = readPing();
}

//=====================================================
//=== ************* Functions ********************* ===
//=====================================================
int lookRight(){ 
  servo_motor.write(20);
  delay(500);
  int distance = readPing();
  delay(100);
  servo_motor.write(90);
  return distance;
}
int lookLeft(){
  servo_motor.write(160);
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





