/*
 *          ----------------------------------------
 *          |  This Code Doesn't Work in TinkerCAD |
 *          |  Library version not supported       |
 *          ----------------------------------------
*/

// #include <IRremote.h>
// #include <Servo.h>

// #define RECV_PIN 3
// IRrecv irrecv(RECV_PIN);

// decode_results results;                       // used to convert hexa decimal value from the remote
// Servo servo;
// int pos = 0;


// void setup() {
//   Serial.begin(9600);
//   Serial.println("Enabling IRin");
//   irrecv.enableIRIn();                        // starts the receiver
//   Serial.println("Enabled IRin");
//   servo.attach(6);
//   servo.write(pos);
// }

// void loop() {
//   if (irrecv.decode(&results)) {
//     Serial.println(results.value, DEC);

//     if (results.value == 16582903) {
//       servo.write(45);
//       delay(1000);
//     } else if (results.value == 16615543) {    // corrsponds to button 2 in the remote
//       servo.write(90);
//       delay(1000);
//     } else if (results.value == 16599223) {    //
//       servo.write(135);
//       delay(2000);
//     } else if (results.value == 16591063)
//       servo.write(180);
//       delay(2000);
//   }

//   servo.write(pos);
//   irrecv.resume();
//   delay(100);
// }



/*
 *      ----------------------------------
 *      | Generated from Claude AI       |
 *      | with updated library           |
 *      ----------------------------------
*/

#include <IRremote.hpp>  // Note: .hpp instead of .h for newer versions
#include <Servo.h>

#define RECV_PIN 3
Servo servo;
int pos = 0;

void setup() {
  Serial.begin(9600);
  Serial.println("Starting IR Remote Servo Control");
  
  // Initialize IR receiver with new syntax
  IrReceiver.begin(RECV_PIN, ENABLE_LED_FEEDBACK);
  
  servo.attach(6);
  servo.write(pos);
  delay(1000);
  
  Serial.println("IR Receiver initialized. Press remote buttons...");
}

void loop() {
  // Check if IR data is available with new syntax
  if (IrReceiver.decode()) {
    
    // Print received data for debugging
    Serial.print("Received IR code: 0x");
    Serial.println(IrReceiver.decodedIRData.decodedRawData, HEX);
    
    // Check the command/address instead of raw data for more reliability
    uint16_t command = IrReceiver.decodedIRData.command;
    Serial.print("Command: ");
    Serial.println(command);
    
    // Handle different commands (adjust these values based on your remote)
    switch(command) {
      case 12:  // Usually button 1
        pos = 45;
        servo.write(pos);
        Serial.println("Button 1 - Servo to 45 degrees");
        delay(500);
        break;
        
      case 24:  // Usually button 2
        pos = 90;
        servo.write(pos);
        Serial.println("Button 2 - Servo to 90 degrees");
        delay(500);
        break;
        
      case 94:  // Usually button 3
        pos = 135;
        servo.write(pos);
        Serial.println("Button 3 - Servo to 135 degrees");
        delay(500);
        break;
        
      case 8:   // Usually button 4
        pos = 180;
        servo.write(pos);
        Serial.println("Button 4 - Servo to 180 degrees");
        delay(500);
        break;
        
      case 28:  // Usually button 5
        pos = 0;
        servo.write(pos);
        Serial.println("Button 5 - Servo to 0 degrees");
        delay(500);
        break;
        
      default:
        Serial.print("Unknown command: ");
        Serial.println(command);
        break;
    }
    
    // Resume receiving with new syntax
    IrReceiver.resume();
  }
  
  delay(100);
}
