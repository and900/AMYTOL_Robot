#define BATTERY_PIN A0 //A1

float ResistorUp = 100000; //100K
float ResistorDown = 33000; //33K

/**
  NOTE: vRef of the original Arduino Nano is 5v
        vRef of the Arduino Nano 33 IoT is 3.3v

        Please set the following variable accordingly!
**/
float vRef = 5; 
float maxVoltage = 8.4; // Vmax
float minVoltage = 7.0; // Vmin

void setup() {
  Serial.begin(9600);
}

void loop() {
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
  }

  Serial.print("BATTERY VOLTAGE: ");Serial.println(totalBatteryVoltage); 
  Serial.print("CAPACITY: "); Serial.print(batteryPercentage); Serial.println("%");
  delay(1000);
}