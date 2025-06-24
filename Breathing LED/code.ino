int led=11;
void setup()
{
  pinMode(led, OUTPUT);
}

void loop()
{
  for(int a=0; a<=255; a++)
  {
    analogWrite(led,a);
    delay(20);
  }
  for (int a=255; a>=0; a++)
  {analogWrite(led,a);
   delay(20);
  }
  delay(200);
}