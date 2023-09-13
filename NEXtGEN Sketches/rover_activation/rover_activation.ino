#define FORWARD 1
#define BACKWARD -1

const int touchSensorPin = 9;
int motorLPin = 2; // PWM output pin connected to the motor
int dirLPin = 3; // direction pin connected to the motor
int motorRPin = 5; // PWM output pin connected to the motor
int dirRPin = 6 ; // direction pin connected to the motor
int speed = 0; // speed value between 0 and 255
int forward_speed = 255;
int backward_speed = 150;
int speed_increment = 5;
int direction = FORWARD;

int num_times_to_repeat = 1;

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
  // Read the touch sensor state
  int touchState = digitalRead(touchSensorPin);
  
  if(num_times_to_repeat < 2 && touchState) {    
    delay(1000); // wait 1 second before driving

    forward(forward_speed, 500);

    brake(); 

    backward(backward_speed, 500);

    brake();
    
    // Stop race
    num_times_to_repeat++;    
  }
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
}

void backward(int speed, int ms) {
    digitalWrite(dirLPin, LOW);
    digitalWrite(dirRPin, LOW);

    setSpeed(speed);
    
    delay(ms);
}

void brake() {
  Serial.println("braking....");
  while (speed > 0) {
    speed -= 50;
    setSpeed(speed);
  }
  speed = max(speed, 0);
  setSpeed(speed);
}


