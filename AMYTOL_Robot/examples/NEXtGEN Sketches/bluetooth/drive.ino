#define FORWARD 1
#define BACKWARD -1

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
  pinMode(motorLPin, OUTPUT);
  pinMode(dirLPin, OUTPUT);
  pinMode(motorRPin, OUTPUT);
  pinMode(dirRPin, OUTPUT);

  // Delay the motion for 2 seconds
  delay(2000);
}

// Now we can write the main loop of the program. 
// We will use the analogWrite() function to send a PWM signal to the motor pin, and digitalWrite() to set the direction pin:

void loop() {

  if(num_times_to_repeat < 2) {             // When num_times_to_repeat reaches 2, the code inside the 'if' won't run

    forward(forward_speed, 750);            // Drive forward for 750 milliseconds

    brake();                                // Brake to a halt

    backward(backward_speed, 750);          // Drive backward for 750 milliseconds

    brake();                                // Brake to a halt

    num_times_to_repeat++;                  // Add 1 to num_times_to_repeat
  }
}


void setSpeed(int s) {
  // set the motor speed to a value between 0 and 255
  analogWrite(motorLPin, s);
  analogWrite(motorRPin, s);
}

void forward(int s, int t) {
    digitalWrite(dirLPin, HIGH);
    digitalWrite(dirRPin, HIGH);

    setSpeed(s);

    delay(t);
}

void backward(int s, int t) {
    digitalWrite(dirLPin, LOW);
    digitalWrite(dirRPin, LOW);

    setSpeed(s);
    
    delay(t);
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


