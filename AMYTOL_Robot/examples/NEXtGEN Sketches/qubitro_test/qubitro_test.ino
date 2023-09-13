#include <QubitroMqttClient.h>
#include <WiFiNINA.h> 

WiFiClient wifiClient;
QubitroMqttClient mqttClient(wifiClient);

// WiFi Credentials
char ssid[] = "SPRINKYV2";   
char pass[] = "0802197031051977";


char deviceID[] = "68a33275-d6c1-4bd6-b5d0-e3063fc56272";
char deviceToken[] = "bpKa79FhMgeNXgbWGCZOcok1bsa74azLch-JNF4F";
char host[] = "broker.qubitro.com";
int port = 1883;

void setup(){
  // Initialize serial port
  Serial.begin(9600);
  while (!Serial) {;} 
  
  // connect to Wifi network:
  Serial.println("Connecting to WiFi...");
  
  while (WiFi.begin(ssid, pass) != WL_CONNECTED) {
    Serial.print(".");
    delay(1000);
  }
  Serial.println("Connected to the WiFi");

  // You need to provide client id and a username with password for authentication
   mqttClient.setId(deviceID);
   
   mqttClient.setDeviceIdToken(deviceID, deviceToken);

  Serial.println("Connecting to Qubitro...");

  if (!mqttClient.connect(host, port)) {
    Serial.println("Connection failed! Error code = ");
    Serial.println(mqttClient.connectError());
    Serial.println("Visit docs.qubitro.com or create a new issue on github.com/qubitro");
    while (1);
  }
  Serial.println("Connected to the Qubitro !");

  mqttClient.onMessage(receivedMessage);    
                                      
  mqttClient.subscribe(deviceID);
}
void loop() {
    mqttClient.poll();   
    mqttClient.beginMessage(deviceID);   
    mqttClient.print("{\"Temp\":33}"); //insert key value JSON string to send
    mqttClient.endMessage();                

    delay(2000);   //wait 2 seconds
}

void receivedMessage(int messageSize) {
  Serial.print("New message received:");
  while (mqttClient.available()) 
  {
    Serial.print((char)mqttClient.read());
  }
  Serial.println();
}