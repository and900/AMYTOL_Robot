#include <WiFiNINA.h>

char ssid[] = "SPRINKYV2"; // Replace with your network name (SSID)
char pass[] = "0802197031051977"; // Replace with your network password

int status = WL_IDLE_STATUS; // Start with WiFi status as idle

WiFiServer server(80); // Create a WiFi server on port 80

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
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP()); // Print the local IP address
  
  server.begin(); // Start the server
  Serial.println("Server started");
}

void loop() {
  WiFiClient client = server.available(); // Check if a client has connected
  
  if (client) {
    Serial.println("New client");
    String request = client.readStringUntil('\r'); // Read the first line of the request
    
    Serial.println(request); // Print the request to the Serial Monitor
    
    client.println("HTTP/1.1 200 OK"); // Send a response header
    client.println("Content-Type: text/html"); // Send the content type
    client.println(); // Send a blank line to separate headers from body
    
    client.println("<html><body><h1>Hello, world!</h1></body></html>"); // Send the HTML body
    
    delay(1); // Wait a bit before closing the connection
    client.stop(); // Close the connection
    Serial.println("Client disconnected");
  }
}