#include<LiquidCrystal.h>

LiquidCrystal lcd(7, 6, 5, 4, 3, 2);

float input_voltage = 0.0;
float temp = 0.0;
float r1 = 1000000.0;
float r2 = 10000.0;

void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);
  lcd.print("Digital Voltmeter");
}

void loop() {
  float analog_value = analogRead(A0);
  temp = (analog_value * 5.0) / 1024.0;
  input_voltage = temp / (r2 / (r1 + r2));

  if (input_voltage < 0.1) {
    input_voltage = 0.0;
  }
  Serial.print("V = ");
  Serial.println(input_voltage);
  lcd.setCursor(0, 1);
  lcd.print("Voltage = ");
  lcd.print(input_voltage);
  delay(1000);
}