int pir = 13;
int led = 12; 
bool pir_val = 0;

int caliberationTime = 30;
// the time when the sensor outputs a low impulse
long unsigned int lowIn;
// the ammount of milis the sensor has to be low
//before we assume all motion has stopped
long unsigned int pause = 5000;
boolean lockLow = true;
boolean takeLowTime;


void setup() 
{
  Serial.begin(9600);
  pinMode(led, OUTPUT);
  pinMode(pir, INPUT);
  
  digitalWrite(pir, LOW);// give sensor some time to calibrate
  
  Serial.print("calibrating sensor ");
  
  for (int i=0; i < caliberationTime; i++)
  {
    Serial.print(".");
    delay(1000);
  }
  Serial.println(" done");
  Serial.println("SENSOR ACTIVE");
  delay(50);
}

void loop()
{
  pir_val = digitalRead(pir);
  if(pir_val == HIGH)
  {
    digitalWrite(led, HIGH);
    if (lockLow)
    { 
      lockLow = false;
      Serial.println("---");
      Serial.print("motion detected at ");
      Serial.print(millis() / 1000);
      Serial.println("sec");
      delay(50);
    }
    takeLowTime = true;
  }
  
  if (pir_val == LOW)
  {
     digitalWrite(led, LOW);
    if(takeLowTime)
    {
      lowIn = millis(); // save the time of transition from
      takeLowTime=false;
    }
    // if the sensor is low for more than the givem pause
    // we assume that no more motion is going to happen
    if(!lockLow && millis() - lowIn > pause)
    {
      // makes sure this block of code is only executed again after
      // a new motion sequence has been detected
      lockLow=true;
      Serial.print("motion ended at "); // output
      Serial.print((millis() - pause) / 1000);
      Serial.println(" sec");
      delay(50);
    }
  }
}
