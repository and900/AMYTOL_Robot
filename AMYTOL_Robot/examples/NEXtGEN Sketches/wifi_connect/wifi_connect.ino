#include <WiFiNINA.h>

char ssid[] = "SPRINKYV2"; // Replace with your network name (SSID)
char pass[] = "0802197031051977"; // Replace with your network password

int status = WL_IDLE_STATUS; // Start with WiFi status as idle

void setup() {
  Serial.begin(9600); // Start Serial communication
  while (!Serial); // Wait for Serial Monitor to open
  
  // Attempt to connect to WiFi network
  Serial.print("Attempting to connect to network ");
  Serial.println(ssid);
  status = WiFi.begin(ssid, pass);
  
  // Wait for WiFi connection to be established
  while (status != WL_CONNECTED) {
    Serial.print("Failed to connect, status code: ");
    Serial.println(status);
    delay(1000);
    status = WiFi.begin(ssid, pass);
  }
  
  Serial.println("Connected to WiFi network");
}

void loop() {
  // Add your code here
}