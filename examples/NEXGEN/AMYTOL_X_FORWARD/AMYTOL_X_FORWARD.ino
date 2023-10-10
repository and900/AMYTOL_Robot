#include <Amytol.h>
Rbt rbt (007); //Secret Agent Pin Declaration 

void setup() 
{
   rbt.begin();   // Initalise the Workspace
} 
void loop() {
  rbt.direction_FR(); // _FR _FR _BL _BR == F = Front B = Back 
    delay(1000);
 // rbt.stopCoast(250);
 delay(500);
}

