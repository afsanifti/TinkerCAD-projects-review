#define LDR  A0
#define LED  6

void setup()
{
  Serial.begin(9600);
  pinMode(LDR, INPUT);
  pinMode(LED, OUTPUT);
}

void loop()
{
  int value = analogRead(LDR);
  Serial.print("LDR: ");
  Serial.println(value);

  // The [map()] function rescales a value from one range to another range proportionally.
  // map(value, fromLow, fromHigh, toLow, toHigh)
  analogWrite(LED, map(value, 0, 1023, 0, 255));
  delay(100);
}