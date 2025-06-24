# Interfacing PIR Sensor

A PIR sensor detects motion by measuring changes in infrared radiation (heat) emitted by surrounding objects, especially human bodies.

### How It Works:

Infrared Detection:

- All objects emit infrared radiation depending on their temperature.

- Human bodies emit infrared in the range of ~9–10 µm wavelength.

Dual Sensing Element:

- A PIR sensor has two slots of infrared-sensitive material.

- When no motion is present, both slots detect the same amount of IR.

- When a warm body (like a human or animal) moves across the sensor, it causes a difference in the IR level between the two slots.

Signal Generation:

- This IR difference generates a voltage change, which is processed and converted into a digital signal (usually HIGH or LOW).

Output:

- The sensor outputs HIGH when motion is detected and LOW otherwise.

- Most modules include a lens (like a Fresnel lens) to focus IR from a wide area onto the sensor.

### Components
-  Arduino Uno R3
- 1 kΩ Resistor
- Red LED
-  PIR Sensor

### Circuit View
![alt text](image.png)

### Circuit Schematic
![alt text](image.png)