int pb0 = 0;                 // LED pin (digital output)
#define pb2 A1              // TMP36 sensor analog input
double realdegree;          // stores calculated temperature in Celsius

void setup() {
  pinMode(pb0, OUTPUT);     // LED pin as output
  realdegree = 0.0;
}

void loop() {
  int degree;
  degree = analogRead(pb2);                      // Read analog value from TMP36
  realdegree = (double)degree / 1024;            // Normalize to 0–1
  realdegree *= 5;                               // Scale to 0–5V
  realdegree -= 0.5;                             // TMP36 offset: 0.5V at 0°C
  realdegree *= 100;                             // Convert to °C
  realdegree = (9.0 / 5) * realdegree + 32;      // Convert °C to °F

  if (realdegree >= 40 && realdegree <= 68) {
    digitalWrite(pb0, HIGH);
    delay(1000);
    digitalWrite(pb0, LOW);
    delay(1000);
  } else if (realdegree >= 70 && realdegree <= 116) {
    digitalWrite(pb0, HIGH);
    delay(500);
    digitalWrite(pb0, LOW);
    delay(500);
  } else if (realdegree >= 123 && realdegree <= 238) {
    digitalWrite(pb0, HIGH);
    delay(100);
    digitalWrite(pb0, LOW);
    delay(100);
  } else {
    digitalWrite(pb0, HIGH);  // Always ON
  }
}


