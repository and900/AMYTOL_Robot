#include <Amytol.h>
#define NEXTGEN // NextGen CodeCamp Specifics
Rbt rbt (007); //Secret Agent PIN Assignment
void setup()
{
  rbt.begin();
}
void loop()
{
  if(num_times_to_repeat < 5) {      // Repeats 4 times
  Serial.print("Number of repeats: "); // Prints in the Serial Monitor
  Serial.println(num_times_to_repeat); // Prints in the Serial Monitor
   rbt.forward(fast_speed, halfaSecond); // PMW 255 for 500 milliseconds
   rbt.turnRight(medium_speed,halfaSecond); // PMW 140 for 500 milliseconds
   rbt.stopBrake(oneSecond); // Stop for 1000 miliseconds
  num_times_to_repeat++;        // Add 1 to num_times_to_repeat
  }
}

