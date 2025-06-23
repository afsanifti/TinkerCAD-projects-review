int buttonState = 0;
const int button=2;

#define RED 13
#define YELLOW 12
#define GREEN 8

void setup()
{
  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(YELLOW, OUTPUT);
  pinMode(button, INPUT);
  Serial.begin(9600);
}

void loop ()
{
  buttonState = digitalRead(button);
  if (buttonState == 1) {
    digitalWrite(RED, HIGH);
    Serial.print("STOP\n");
    delay(2000);
    digitalWrite(RED, LOW);
    delay(500);
    
    digitalWrite(YELLOW, HIGH);
    Serial.print("GET READY\n");
    delay(2000);
    digitalWrite(YELLOW, LOW);
    delay(500);
    
    digitalWrite(GREEN, HIGH);
    Serial.print("GO\n");
    delay(2000);
    digitalWrite(GREEN, LOW);
  }
}
  


