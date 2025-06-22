#define RED 13
#define BLUE 12
#define GREEN 11

void setup() {
  pinMode(RED, OUTPUT);
  pinMode(BLUE, OUTPUT);
  pinMode(GREEN, OUTPUT);
}

void loop() {
  color(255, 0, 0); // red
  delay(500);
  color(0, 255, 0); // green
  delay(500);
  color(0, 0, 255); // blue
  delay(500);
  color(255, 255, 255); // white
  delay(500);
  color(0, 0, 0); // Off
  delay(500);
}

void color(unsigned char red, unsigned char green, unsigned char blue) {
  analogWrite(RED, red);
  analogWrite(GREEN, green);
  analogWrite(BLUE, blue);
}