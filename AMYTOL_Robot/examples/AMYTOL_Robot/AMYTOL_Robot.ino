#include <AmytolRobot.h>
#define FORWARD 1
#define BACKWARD -1
#define NEXTGEN

Rbt rbt (007); //Secret Agent Delaration .-.  .-.  --..::==
//                                      (   )(   )  //"
//                                       '-'  '-'  /
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
int speed = 0; //forward speed
int f_speed = 255; //forward speed
int b_speed = 150; //backward speed
int s_inc = 5; //speed increment

int num_times_to_repeat = 1;
//boolean stopped = false;
void setup()
{
  Serial.begin(9600);
  rbt.begin();
  delay(2000);
}

void loop()
{
  #ifdef VOLTAGE_DETECTION_PIN
  lowBattery();  //  block the loop if battery is low
  //  can be disabled to save programming space and reduce the low voltage interruptions
  #endif
  if(num_times_to_repeat < 5) {
   Serial.print("Number of repeats: "); // Prints in the Serial Monitor
   Serial.print(num_times_to_repeat); // Prints in the Serial Monitor
   Serial.println(" ....."); // Prints in the Serial Monitor
  
   Serial.println("** bt_Drve forward **");
   rbt.forward(f_speed, 400); // .4 seconds 400 milliseconds
  
   Serial.println("** bt_Drve turnRight **");
   rbt.turnRight(140,400); // Speed ms Delay ms
   
   Serial.println("** rbt brake **");
   rbt.stopBrake(1000); 
  

num_times_to_repeat++;        // Add 1 to num_times_to_repeat
}
   rbt.forward(f_speed, 400); // .4 seconds 400 milliseconds
   long unsigned int prevCoastMillis;
   prevCoastMillis = millis();
   while (millis() - prevCoastMillis < 150) {
   rbt.stopCoast();}
   {rbt.stopHard();}
}
