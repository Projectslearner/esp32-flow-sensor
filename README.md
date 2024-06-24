# ESP32 Flow Sensor Project

## Project Overview
This project demonstrates how to interface a flow sensor with an ESP32 microcontroller to measure flow rates. Flow sensors are essential in applications where monitoring liquid flow is crucial, such as in water management systems, industrial equipment, and environmental monitoring.

## Components Needed
- ESP32 Microcontroller
- Flow Sensor
- Jumper Wires
- Breadboard

## Block diagram


## Circuit Setup
1. **Connecting the Flow Sensor to ESP32:**
   - Connect the digital output pin of the flow sensor to GPIO pin 18 on the ESP32.
   - Ensure a stable power supply and common ground (GND) connection between the ESP32 and the flow sensor.

## Instructions
1. **Setup:**
   - Initialize serial communication at a baud rate of 115200 using `Serial.begin()`.
   - Configure the flow sensor pin as an input with internal pull-up resistor using `pinMode()`.

2. **Operation:**
   - Define an interrupt service routine (`pulseCounter()`) to count pulses from the flow sensor. This routine increments `pulseCount` each time a pulse is detected.
   - In the `loop()` function:
     - Calculate the flow rate in liters per minute based on the accumulated pulse count and a calibration factor.
     - Print the calculated flow rate to the Serial Monitor every second.

3. **Considerations:**
   - **Calibration Factor:** Adjust the `calibrationFactor` based on your specific flow sensor's calibration to ensure accurate flow rate measurements.
   - **Interrupt Handling:** Use interrupts (`attachInterrupt()` and `detachInterrupt()`) to accurately count pulses without missing any transitions.
   - **Power Requirements:** Ensure the ESP32 and flow sensor are powered adequately to maintain reliable operation.

## Applications
- **Water Management Systems:** Monitor water flow in irrigation systems, water meters, and plumbing systems.
- **Industrial Equipment:** Measure flow rates in manufacturing processes and equipment.
- **Environmental Monitoring:** Monitor flow rates in environmental monitoring stations and research projects.

## Notes
- **Flow Sensor Output:** The flow sensor provides digital pulses that can be counted to determine flow rate.
- **Real-Time Monitoring:** Continuous monitoring of flow rates allows for timely adjustments and interventions based on the measured data.

---

## Useful Links
🌐 [ProjectsLearner - ESP32 Flow Sensor](https://projectslearner.com/learn/esp32-flow-sensor)  
📧 [Email](mailto:projectslearner@gmail.com)  
📸 [Instagram](https://www.instagram.com/projectslearner/)  
📘 [Facebook](https://www.facebook.com/projectslearner)  
▶️ [YouTube](https://www.youtube.com/@ProjectsLearner)  
📘 [LinkedIn](https://www.linkedin.com/in/projectslearner)

Created with ❤️ by ProjectsLearner