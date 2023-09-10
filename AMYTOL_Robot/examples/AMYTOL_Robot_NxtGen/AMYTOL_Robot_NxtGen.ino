#include <AmytolRobot.h>
#define FORWARD 1
#define BACKWARD -1

Rbt rbt (007); //Secret Agent Man

int speed = 0; //forward speed
int f_speed = 255; //forward speed

int num_times_to_repeat = 1;
void setup()
{
  Serial.begin(9600);
  rbt.begin();
  delay(2000);
}

void loop()
{
  if(num_times_to_repeat < 5) {
  Serial.print("Number of repeats: "); // Prints in the Serial Monitor
  Serial.print(num_times_to_repeat); // Prints in the Serial Monitor
  
  rbt.forward(f_speed, 400); // .4 seconds 400 milliseconds
  rbt.turnRight(140,400); // Speed ms Delay ms
  rbt.stopBrake(1000); 
  
  num_times_to_repeat++;        // Add 1 to num_times_to_repeat
  }
}

