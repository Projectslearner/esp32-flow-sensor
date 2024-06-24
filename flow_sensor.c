/*
    Project name : ESP32 Flow Sensor
    Modified Date: 24-06-2024
    Code by : Projectslearner
    Website : https://projectslearner.com/learn/esp32-flow-sensor
*/
const int flowSensorPin = 18; // Digital pin connected to the flow sensor
volatile int pulseCount = 0;  // Variable to count the number of pulses

unsigned long oldTime = 0;
float calibrationFactor = 4.5; // Adjust this value based on your flow sensor's calibration factor

void IRAM_ATTR pulseCounter() {
  pulseCount++; // Increment the pulse count
}

void setup() {
  Serial.begin(115200); // Initialize serial communication
  pinMode(flowSensorPin, INPUT_PULLUP); // Set the flow sensor pin as an input
  attachInterrupt(digitalPinToInterrupt(flowSensorPin), pulseCounter, FALLING); // Attach an interrupt to the flow sensor pin
}

void loop() {
  unsigned long currentTime = millis();
  unsigned long elapsedTime = currentTime - oldTime;

  if (elapsedTime >= 1000) { // If one second has passed
    detachInterrupt(digitalPinToInterrupt(flowSensorPin)); // Disable the interrupt temporarily

    float flowRate = ((float)pulseCount / calibrationFactor); // Calculate the flow rate in liters/minute
    Serial.print("Flow Rate: ");
    Serial.print(flowRate);
    Serial.println(" L/min");

    pulseCount = 0; // Reset the pulse count
    oldTime = currentTime; // Update the old time

    attachInterrupt(digitalPinToInterrupt(flowSensorPin), pulseCounter, FALLING); // Re-enable the interrupt
  }
}
