#define PIR 13
#define LED 12
bool pir_val=0;

void setup() 
{
  Serial.begin(9600);
  pinMode(LED, OUTPUT);
  pinMode(PIR, INPUT);
}
void loop() {
  pir_val = digitalRead(PIR);
  if(pir_val==HIGH)
  {
    Serial.println("Motion Detected");
    digitalWrite(LED, HIGH);
  }
  else
  {
    Serial.println("No Motion Detected");
    digitalWrite(LED,LOW);
  }
}