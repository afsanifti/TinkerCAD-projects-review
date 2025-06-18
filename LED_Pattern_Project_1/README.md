## LED Pattern Project 1
Video Link: [LED Pattern Project](https://www.youtube.com/watch?v=gFbouXJXPo0&list=PLWqnlHhsmcI4eBDLBtaZs16XZq0WL1SlP&index=39)

This project demonstrates how different values of potentiometer can light up different patterns in LEDs. 

### Components
- Arduino Uno R3 (x1)
- Red LED (x2)
- Yellow LED ( x2)
- Green LED (x2)
- 220 Ω Resistor (x6)
- 250 kΩ Potentiometer (x1)

### Circuit View
![[led-patter-1.png]]

### Component Placement and Explanation
- **LEDs:** Each LED have a 220$\Omega$ resistor attached to cathode to limit the current flowing through them.
-  **Potentiometer:** This is a 250k$\Omega$ potetiometer. Different voltages can be measured by rotating the dial from the range of 0 - 1023 through `analogRead()` 

### Circuit Schematic
![[led-pattern-schematic.png]]

### Code Explanation
```cpp
// defined the LED pins

void setup() {
	value = analogRead(pot) // potentiometer value
    Serial.println(9600); // to monitor the change in value of potentiometer
    // defined OUTPUT pins
}

void loop() {
	if (value == 0) {
		// all LED off
	} else if (//0 < value <= 250) {
		// only LED6 & LED5 on
	} else if (// 251 <= value < 500) {
		// LED6, LED5, LED4 and LED3 on
	} else if (// value >= 501) {
		// all LEDs are on
	}
}
```
