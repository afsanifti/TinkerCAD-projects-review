/* Temperature-based LED control */
const float baselineTem = 20.0;
const int sensorPin = A2, redPin = 0,
bluePin = 1, greenPin = 2;
float temp;

// Color arrays
// Format: color[] = {R, G, B};
bool yellow[] = {1, 1, 0}; 
bool red[] = {1, 0, 0};
bool green[] = {0, 1, 0};
bool blue[] = {0, 0, 1};
bool white[] = {1, 1, 1}; 
bool cyan[] = {0, 1, 1};
bool off[] = {0, 0, 0};

void setup() {
  pinMode(redPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(5, OUTPUT);
  digitalWrite(5, HIGH);
}

void loop() {
  readSensor();
  colorConditions();
  delay(1000);
}

void colorConditions() {
  /* blink white*/ if (temp <= 9) ledControlBlink(white);
  /* blink red */ if (temp >= 35) ledControlBlink(red);
  /* white */ if (temp >= 10 && temp <= 14.0) ledControl(white);
  /* cyan */ if (temp >= 15.0 && temp <= 20.0) ledControl(cyan);
  /* green */ if (temp >= 21 && temp <= 24) ledControl(green);
  /* yellow */ if (temp >= 25 && temp <= 29) ledControl(yellow);
  /* red */ if (temp >= 30) ledControl(red);
}

// takes a boolean array for each RGB value
// sets each LED pin based on color array: [red, green, blue]
void ledControl(bool color[]) {
  digitalWrite(redPin, color[0]);    // Set red LED
  digitalWrite(greenPin, color[1]);  // Set green LED
  digitalWrite(bluePin, color[2]);   // Set blue LED
}

// blinks the specified color once
// turns LED on for 500ms, then off for 500ms
void ledControlBlink(bool color[]) {
  ledControl(color);  // Turn on the color
  delay(500);         // Wait 500ms
  ledControl(off);    // Turn off all LEDs
  delay(500);         // Wait 500ms
}

// reads data, converts to degree celsius
void readSensor() {
  int sensor = analogRead(sensorPin);
  float volt = sensor * 3.0;
  volt /= 1024.0;
  temp = (volt - 0.5) * 100;
}