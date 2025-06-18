#include <Servo.h>

Servo horizontal;
int servoh = 180;
int servohLimitHigh = 175;
int servohLimitLow = 5;

Servo vertical;
int servov = 45;
int servovLimitHigh = 60;
int servovLimitLow = 1;

#define ldrLeftTop A2
#define ldrRightTop A0
#define ldrLeftDown A3
#define ldrRightDown A1

void setup() {
  horizontal.attach(9); // what is this attach function
  vertical.attach(10);
  horizontal.write(180); // what do we do with write?
  vertical.write(45);
  delay(2500); // why a delay?
}

void loop() {
  int leftTop = analogRead(ldrLeftTop);
  int leftDown = analogRead(ldrLeftDown);
  int rightTop = analogRead(ldrRightTop);
  int rightDown = analogRead(ldrRightDown);

  int dTime = 10;
  int tol = 90; // tolerance

  int avgTop = (leftTop + rightTop) / 2;
  int avgDown = (leftDown + rightDown) / 2;
  int avgLeft = (leftTop + leftDown) / 2;
  int avgRight = (rightTop + rightDown) / 2;

  int dVert = avgTop - avgDown;
  int dHoriz = avgLeft - avgRight;

  if (-1 * tol > dVert || dVert > tol) {
    if (avgTop > avgDown) {
      servov = ++servov;

      if (servov > servovLimitHigh) {
        servov = servovLimitHigh;
      }
    } else if (avgTop < avgDown) {
      servov = --servov;

      if (servov < servovLimitLow) {
        servov = servovLimitLow;
      } 
    }

    vertical.write(servov);
  }

  if (-1 * tol > dHoriz || dHoriz > tol) {
    if (avgLeft > avgRight) {
      servoh = --servoh;

      if (servoh < servohLimitLow) {
        servoh = servohLimitLow;
      }
    } else if (avgLeft < avgRight) {
      servoh = ++servoh;

      if (servoh > servohLimitHigh) {
        servoh = servohLimitHigh;
      }
    } else if (avgLeft == avgRight) {
      delay(5000);
    }

    horizontal.write(servoh);
  }

  delay(dTime);
}