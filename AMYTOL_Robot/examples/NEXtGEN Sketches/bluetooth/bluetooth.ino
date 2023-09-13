#include <ArduinoBLE.h>

// Define BLE service and characteristics
BLEService ledService("19B10000-E8F2-537E-4F6C-D104768A1214");
BLEIntCharacteristic ledCharacteristic("19B10001-E8F2-537E-4F6C-D104768A1214", BLERead | BLEWrite);

void setup() {
  Serial.begin(9600);

  // Initialize BLE
  if (!BLE.begin()) {
    Serial.println("Failed to initialize BLE");
    while (1);
  }

  // Set service and characteristic
  BLE.setLocalName("LED");
  BLE.setAdvertisedService(ledService);
  ledService.addCharacteristic(ledCharacteristic);
  BLE.addService(ledService);
  ledCharacteristic.setValue(0);

  // Start advertising
  BLE.advertise();
  Serial.println("BLE started");

  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  // Check if a client is connected
  BLEDevice central = BLE.central();
  if (central) {
    Serial.print("Connected to central: ");
    Serial.println(central.address());

    // Loop while the client is connected
    while (central.connected()) {
      // Check if LED characteristic was written
      if (ledCharacteristic.written()) {
        char value = ledCharacteristic.value();
        int numValue = value - '0';
        Serial.print("LED value set to: ");
        Serial.println(numValue);

        // Turn on or off LED based on value
        if (numValue == 1) {
          Serial.println("Setting LED on");
          digitalWrite(LED_BUILTIN, HIGH);
        } else {
          digitalWrite(LED_BUILTIN, LOW);
        }
      }
    }

    // Client disconnected
    Serial.print("Disconnected from central: ");
    Serial.println(central.address());
  }
}