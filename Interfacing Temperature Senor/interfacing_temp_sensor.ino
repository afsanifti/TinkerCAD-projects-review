#include <LiquidCrystal.h>

// Initialize LCD with pins: RS, Enable, D4, D5, D6, D7
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

// Variables to store temperature readings
int sensorValue;
float voltage;
float tempC;

void setup() {
  // Initialize LCD with 16 columns and 2 rows
  lcd.begin(16, 2);
  lcd.setCursor(0, 0);

  // Display initial message
  lcd.print("Today's Temp:");
}

void loop() {
  // Read analog value from temperature sensor on pin A0
  sensorValue = analogRead(A0);

  // Convert analog reading to voltage (0-5V)
  voltage = sensorValue * (5.0 / 1023.0);
  
  // Convert Voltage to temparature
  tempC = (voltage - 0.5) * 100;

  // Display on LCD
  lcd.setCursor(0, 1);
  lcd.print("                "); // Clear the line
  lcd.setCursor(0, 1);
  
  // Display temperature in Celsius
  lcd.print(tempC, 1);   // 1 decimal place
  lcd.print((char)178); 
  lcd.print("C ");
  
  delay(1000);
} 