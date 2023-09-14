#include <Amytol.h>
#include <Servo.h>
#include "Ultrasonic.h" //Grove Ultrasonic Ranger by Seed
#include "scr/pitches.h"
#define NEXTGEN     // NextGen CodeCamp Specifics
#define BATTERY_PIN A0 //A1
//#define FORWARD 1
//#define BACKWARD -1
// PINS to set up the pins as outputs:
Rbt rbt (007); //Secret Agent Pin Declaration .-.  .-.  --..::==
//                                           (   )(   )  //"
//                                            '-'  '-'  /
//   Is this Possible?     Millie                    Maggie
//   __________________       .-"-.       ||                 _.._            ||
//  ()_________________\     /|6 6|\      ||               .'  ..=`_         ||
//   ________________  |    {/(_0_)\}     ||              / _ ='. )`,        ||
//  ()____________| |  |     _/ ^ \_      ||             | .--:'./`\ \       ||
//   ______________\|  |    (/ /^\ \)     ||            .'    .-'   | )      ||
//  ()_________________|     ""' '""      ||           / /:';' _   _( |      ||
//                                        ||          /.' | |  " | "| |      ||
//                                        ||         (  .|  |   __  ' /      ||
//                                        ||         |  |/ / \  `- /( |      ||
//                                        ||         )_.:./)   `--'._\     


Servo servo;
Ultrasonic ultrasonic(ultrasonicPin);

int speed = 0; // speed value between 0 and 255
int f_speed = 150; //forward_speed 
int backward_speed = 150;
int speed_increment = 5;



boolean isMoving = false;

const int DISTANCE_TO_STOP_AT = 30;

void setup()        // Where we setup the initalising code which run one
{
  rbt.begin();      // Initalise the Workspace
  servo.attach(4);   // Setup servo
  delay(2000);  // Give Time ot initalise Delay the motion for 2 seconds
  // Set servo to front
  servo.write(90);  // Play initialised tone
 // tone(buzzerPin, 262, 1000);
  Serial.println("Rover v3 initialised...");
  // Wait for 2 seconds before drive
  delay(2000);
}

// We will use the analogWrite() function to send a PWM signal to the motor pin, and digitalWrite() to set the direction pin:
void loop()         // Continualy repeats unless told to stop  
{
 delay(1000);        // Time to switch on Robot 
 if(num_times_to_repeat < 1)   {               // Repeates code below 5 times
  // CHECK BATTERY!
  if(checkBattery() == -1){
    // alert with buzzer!
   // tone(buzzer, NOTE_C4, 500);
   // tone(buzzer, NOTE_C5, 500);
   // tone(buzzer, NOTE_C6, 500);
    //return;
  }
    num_times_to_repeat++;                  // Add 1 to num_times_to_repeat
  }

  // Point 'eyes' forward and check distance
  if(scanForward() > DISTANCE_TO_STOP_AT) {
    if(!isMoving) {
      // Move forward if not already moving and set moving to TRUE
      rbt.forward(medLow_speed);
      Serial.println("forward");
      isMoving = true;
    }
  }
  else {
    // distance is less then 30cm so brake, backup and turn left OR right
    rbt.stopBrake(1000);
    isMoving = false;
    rbt.backwardFor(backward_speed, 400);

    int leftDistance = scanLeft();
    int rightDistance = scanRight();

    // Turn whichever direction has a greater distance to travel
    if(leftDistance > rightDistance){
      rbt.turnLeft(140,400);
  Serial.print("left dist: ");
  Serial.print(leftDistance);
   Serial.print(" right dist: ");
  Serial.print(rightDistance);
      Serial.println(" Turn left");
    }
    else {
      rbt.turnRight(140,400);
        Serial.print("left dist: ");
  Serial.print(leftDistance);
   Serial.print(" right dist: ");
  Serial.print(rightDistance);
      Serial.println(" Turn right");
    }
  }
  delay(500);

}

//=============================================
//************* Functions *********************
//=============================================
long getDistance() {
  long rangeInCentimeters;
  rangeInCentimeters = ultrasonic.MeasureInCentimeters(); // two measurements should keep an interval
  Serial.print("rangeInCentimeters: ");//0~400cm
  Serial.print(rangeInCentimeters);//0~400cm
  Serial.println(" cm ");
  return rangeInCentimeters;
}

long scanForward() {
  servo.write(90);
  return getDistance(); 
}

long scanLeft() {
  servo.write(180);
  delay(2000);
  long distance = getDistance();
  scanForward();
  return distance;
  Serial.print("left dist: ");
  Serial.println(distance);
 
}

long scanRight() {
  servo.write(0);
  delay(2000);
  long distance = getDistance();
  scanForward();
  return distance;
  Serial.print("right dist: ");
  Serial.println(distance);
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
