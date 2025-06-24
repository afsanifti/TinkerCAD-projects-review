#define led 0

int val = 0;
int sensor = A3;

void setup()
{
  pinMode(led, OUTPUT);
  pinMode(sensor, INPUT);
}

void loop()
{
  val = analogRead(sensor);
  val = map(val, 0, 1023, 0, 255);
  analogWrite(led, val);
}
