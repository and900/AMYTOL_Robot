#include <AmytolRobot.h>
#include <AmytolRobotVar.h>

Rbt rbt (007); //Secret Agent Man

void setup()
{
  rbt.begin();
}

void loop()
{
  if(num_times_to_repeat < 5) {
  Serial.print("Number of repeats: "); // Prints in the Serial Monitor
  Serial.println(num_times_to_repeat); // Prints in the Serial Monitor
  
  rbt.forward(fast_speed, halfaSecond); // 500 milliseconds
  rbt.turnRight(medium_speed,halfaSecond); // Speed ms Delay ms
  rbt.stopBrake(oneSecond); 
  
  num_times_to_repeat++;        // Add 1 to num_times_to_repeat
  }
}

