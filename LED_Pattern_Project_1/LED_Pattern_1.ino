#define pot A5
#define LED1 8
#define LED2 9
#define LED3 10
#define LED4 11
#define LED5 12
#define LED6 13

int value = 0

void setup() {
  Serial.begin(9600);
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(8, OUTPUT);
}

void loop() {
  value = analogRead(pot);
  Serial.println(value);
  delay(400);

  if (value == 0) {
    digitalWrite(LED6, 0);
    digitalWrite(LED5, 0);
  } else if (value > 0 && value <= 250) {
    digitalWrite(LED6, HIGH);
    digitalWrite(LED5, HIGH);
    digitalWrite(LED4, 0);
    digitalWrite(LED3, 0);
  } else if (value >= 251 && value < 500) {
    digitalWrite(LED4, HIGH);
    digitalWrite(LED3, HIGH);
    digitalWrite(LED2, 0);
    digitalWrite(LED1, 0);
  } else if (value >= 501) {
    digitalWrite(LED2, HIGH);
    digitalWrite(LED1, HIGH);
  }
}
