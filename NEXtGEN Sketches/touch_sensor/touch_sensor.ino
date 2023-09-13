
// Use digital pin 9
const int touchSensorPin = 9;

void setup() {
  // Start serial communication
  Serial.begin(9600);

  // Set the touch sensor pin as input
  pinMode(touchSensorPin, INPUT);
}

void loop() {
  // Read the touch sensor state
  int touchState = digitalRead(touchSensorPin);

  // Print the touch sensor state
  Serial.print("Touch sensor state: ");
  Serial.println(touchState);

  // Wait for a short period
  delay(100);
}