#define FORWARD 1
#define BACKWARD -1

const int touchSensorPin = 9;
int motorLPin = 5; // PWM output pin connected to the motor
int dirLPin = 6; // direction pin connected to the motor
int motorRPin = 2; // PWM output pin connected to the motor
int dirRPin = 3 ; // direction pin connected to the motor
int speed = 0; // speed value between 0 and 255
int forward_speed = 255;
int backward_speed = 150;
int speed_increment = 5;

int num_times_to_repeat = 1;
boolean stopped = false;

// Next, we need to set up the pins as outputs:

void setup() {
  Serial.begin(9600);
  pinMode(touchSensorPin, INPUT);
  pinMode(motorLPin, OUTPUT);
  pinMode(dirLPin, OUTPUT);
  pinMode(motorRPin, OUTPUT);
  pinMode(dirRPin, OUTPUT);

  // Delay the motion for 2 seconds
  delay(2000);
}

void loop() {
  // Here is some example code to help you
 // if (stopped == true) return;

   if(num_times_to_repeat < 5) {             // When num_times_to_repeat reaches 2, the code inside the 'if' won't run
   Serial.println(num_times_to_repeat);
  
  forward(forward_speed, 400); // Moves forward for 1 second

 // brake(1000); // Brakes then waits for 1000ms

  turnRight(140,400); // Turns right for 750msSpeed,Time

     forward(forward_speed, 400);            // Drive forward for 750 milliseconds
     
     // brake(1000); 

turnRight(140,400); // Turns right for 750msSpeed,Time

 // brake(1000); 
      forward(forward_speed, 400);            // Drive forward for 750 milliseconds
   turnRight(140,400); // Turns right Speed,Time Delay

     forward(forward_speed, 400);            // Drive forward for 750 milliseconds
     // brake(1000); 
  
 turnRight(140,400); // Turns right for 750msSpeed,Time

 // brake(1000); 

    forward(forward_speed, 400);            // Drive forward for 750 milliseconds
     brake(1000); 

//    brake();                                // Brake to a halt

    //backward(backward_speed, 750);          // Drive backward for 750 milliseconds

   //brake();                                // Brake to a halt

    num_times_to_repeat++;                  // Add 1 to num_times_to_repeat
  }


  /*** YOUR CODE STARTS HERE ***/


  /*** YOUR CODE ENDS HERE ***/

 // stopped = true;
}

void setSpeed(int ms) {
  // set the motor speed to a value between 0 and 255
  analogWrite(motorLPin, ms);
  analogWrite(motorRPin, ms);
}

void setSpeedLeft(int ms) {
  // set the motor speed to a value between 0 and 255
  analogWrite(motorLPin, ms);
}

void setSpeedRight(int ms) {
  // set the motor speed to a value between 0 and 255
  analogWrite(motorRPin, ms);
}

void forward(int speed, int ms) {
    digitalWrite(dirLPin, HIGH);
    digitalWrite(dirRPin, HIGH);

    setSpeed(speed);

    delay(ms);

}

void forward(int speedL, int speedR, int ms) {
    digitalWrite(dirLPin, HIGH);
    digitalWrite(dirRPin, HIGH);
    setSpeedLeft(speedL);
    setSpeedRight(speedR);
    delay(ms);
    setSpeed(0)
}

void backward(int speed, int ms) {
    digitalWrite(dirLPin, LOW);
    digitalWrite(dirRPin, LOW);
    setSpeed(speed);
    delay(ms);
}

void turnRight(int s, int t) {
    digitalWrite(dirLPin, HIGH);
    digitalWrite(dirRPin, LOW);
    setSpeedLeft(s);
    setSpeedRight(s);
    delay(t);
    setSpeed(0)
}

void brake(int ms) {
  Serial.println("braking....");
  while (speed > 0) {
    speed -= 50;
    setSpeed(speed);
  }
  speed = max(speed, 0);
  setSpeed(speed);

  delay(ms);
}


