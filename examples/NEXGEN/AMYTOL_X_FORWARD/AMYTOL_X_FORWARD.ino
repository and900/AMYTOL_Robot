#include <Amytol.h>
#include <Servo.h>  //Arduino IDE included Servo motor library
#define NEXTGEN     // NextGen CodeCamp Specifics
// PINS to set up the pins as outputs:
Rbt rbt (007); //Secret Agent Pin Declaration 

//int tuningLeftMotor = 250/200;
//int tuningRightMotor = 0;
void setup()        // Where we setup the initalising code which run one
{
  rbt.begin();      // Initalise the Workspace

  delay(500);  

}
void loop() {         // Continualy repeats unless told to stop  

rbt.frwrdSpedVar(250, 200, medLow_speed);



}







