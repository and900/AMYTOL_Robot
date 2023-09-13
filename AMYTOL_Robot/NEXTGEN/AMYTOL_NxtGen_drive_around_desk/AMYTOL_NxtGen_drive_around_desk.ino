#include <Amytol.h> // Path to the Library and Variables
#define NEXTGEN     // NextGen CodeCamp Specifics
Rbt rbt (007);      //Secret Agent PIN Assignment
void setup()        // Where we setup the initalising code which run one
{
  rbt.begin();      // Initalise the Workspace
}
void loop()         // Continualy repeats unless told to stop  
{
delay(1000);        // Time to switch on Robot 
if(num_times_to_repeat < 5)   {               // Repeates code below 5 times
    if(num_times_to_repeat < 4) {             // Repeates code below 4 times
    Serial.print("Number of repeats 5: ");    // Prints in the Serial Monitor
    Serial.println(num_times_to_repeat);      
    rbt.forward(fast_speed, halfaSecond); // PMW 255 for 500 milliseconds
    delay(100);
    rbt.turnRight(medium_speed,halfaSecond);// PMW 140 for 500 milliseconds
    delay(100);
    num_times_to_repeat++;                  // Add 1 to num_times_to_repeat
  }
else  // if =>4
  {
  num_times_to_repeat++; 
  Serial.print("Number of repeats 6: "); 
  rbt.forward(medium_speed, halfaSecond);   
  rbt.stopCoast(); // No Pulse Pin High Rolls to a slow stop
  //   delay(250);
  //rbt.stopHard(); // No Pulse Pin LOW Stop like a using break
  }
  }  
}