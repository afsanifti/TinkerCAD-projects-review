#include<Servo.h>

Servo MyServo;
int pos = 0;

void setup() {
    MyServo.attach(10);
}

void loop() {
    for(pos = 0; pos <= 180; pos++) {
        MyServo.write(pos);
        delay(15);
    }

    delay(3000);

    for(pos = 180; pos >= 0; pos--) {
        MyServo.write(pos);
        delay(15);
    }

    delay(1000);
}