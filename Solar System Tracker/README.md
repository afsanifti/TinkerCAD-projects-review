# Solar System Tracker Using Arduino and LDR
Link: [Solar System Tracker - YouTube](https://www.youtube.com/watch?v=WvijIBj12nI&list=PLWqnlHhsmcI4eBDLBtaZs16XZq0WL1SlP&index=40)

This project demonstrate how you can calculate the intensity of sunlight and keep moving your solar panel towards the sunlight using servo motor.
### Components
1. Arduino Uno R3 (x1)
2. Positional Micro Servo (x2)
3. Photoresistor (x4)
4. 1 kΩ Resistor (x4)

### Circuit View
![](https://lh7-rt.googleusercontent.com/docsz/AD_4nXdcb7WDVYt4ws5L4GEqtgCkLN3tCT9Ni_trsoA56sYKEojfDeovWsnwKC4xo2l-n3YpKz-saVb-bmcMghFNWU6huZMmoBjtsnMtH3dudO7ZjvXsJXNzZg-Ajh-IaxCG3fcGlawaQw?key=GpTTvGIJQ4TL-FgKQCt63g)

### Components Placement and Explanation
- **The servos:** Servo connected to pin 9 controls horizontal movement and the servo connected to pin 10 controls vertical movement.
- **Photoresistors / LDR:** From the picture two LDRs are higher than the other two. One is identified as LDR_TOP_LEFT and the other is LDR_TOP_RIGHT. Similarly the two on the bottom are LDR_DOWN_LEFT and LDR_DOWN_RIGHT. These are used to calculate the position of sunlight where it is more intense.
- **Analog pins:** Here is the data of how each LDR is connected to analog pins -
	- LDR_TOP_LEFT → A2
	- LDR_TOP_RIGHT → A0
	- LDR_DOWN_LEFT → A3
	- LDR_DOWN_RIGHT → A1

### Circuit Schematic
![](https://lh7-rt.googleusercontent.com/docsz/AD_4nXdFh2tUmoSvNOUGXFP-wCI9QhK45bhwMDp8FVJk0O8W6tAarEAe5NXiOXaQ0xGWGw-XBfYkQXIIbHfbmYKH2Imfq7LicW8Ft8EtU8n8jPB0mSmfACdlgKIvrH0HA1x-DzqWPdEOTA?key=GpTTvGIJQ4TL-FgKQCt63g)

### Code Explanation
#### Explanation of the variables and their calculation
```cpp
#include<Servo.h>

// These are a Servo objects created form the Servo class
// Each objects have different values
Servo horizontal;
/* code */

Servo vertical;
/* code */

void setup() {

// Defining the pins of each servo motors
// The [horizontal] servo attaches to pin 9
// The [vertical] servo attaches to pin 10
	horizontal.attach(9);
	vertical.attach(10);

// Defining the initial angles of each servos
	horizontal.write(180);
	vertical.write(45);

// delays to give time to servos to reach the initial positions
	delay(2500);
}

void loop() {
// small delays between each iterations to prevent the loop running too fast
	int dTime = 10;
	
// This is tolerance.
// The code only reacts if the difference in LDR values exceeds this amount.
	int tol = 90;

// This gives average light intensity in the direction of
// left, right, top and bottom halves
	int avgTop = (leftTop + rightTop) / 2;
	int avgDown = (leftDown + rightDown) / 2;
	int avgLeft = (leftTop + leftDown) / 2;
	int avgRight = (rightTop + rightDown) / 2;

// Calculate vertical and horizontal difference
// `dVert`: if positive, light is stronger at top → move up
// `dHoriz`: if positive, light is stronger on the left → move left
	int dVert = avgTop - avgDown;
	int dHoriz = avgLeft - avgRight;
}
```

#### Explanation of how the servos actually move by calculating the data from 4 LDRs
If the difference is outside the tolerance (`tol`), move the servos -
**For vertical:**
```cpp
if (avgTop > avgDown) { servov++; } 
else if (avgTop < avgDown) { servov--; }
```

**For horizontal:**
```cpp
if (avgLeft > avgRight) { servoh--; } 
else if (avgLeft < avgRight) { servoh++; }
```

They are constrained by `servohLimitHigh/Low` and `servovLimitHigh/Low` to avoid over-rotation.

**Special Case:** When avgLeft is equal to avgRight, it pauses tracking for 5s.
