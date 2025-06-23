#include <IRremote.h>

#define IR 7
#define BLUE 11
#define YELLOW 12
#define GREEN 13

IRrecv irrecv(IR);//reading input
decode_results results; //decodes input

void setup() 
{
  Serial.begin(9600); 
  irrecv.enableIRIn();// starts the receiver
  pinMode(BLUE, OUTPUT);
  pinMode(YELLOW, OUTPUT);
  pinMode(GREEN, OUTPUT);
}

void loop()
{
 //decodes the ir input
  if(irrecv.decode(&results))
  {
    long int decCode = results.value;
    Serial.println(results.value);
    // switch case to use selected remote control
    switch (results.value){
      case 16582903: //pressing 1
      digitalWrite(BLUE, HIGH);
      break;
      case 16615543: // pressing 2
      digitalWrite(BLUE, LOW);
      break;
      case 16599223: // pressing 3
      digitalWrite(YELLOW, HIGH);
      break;
      case 16591063: // pressing 4
      digitalWrite(YELLOW, LOW);
      break;
      case 16623703: // pressing 5
      digitalWrite(GREEN, HIGH);
      break;
      case 16607383: // pressing 6
      digitalWrite(GREEN, LOW);
      break;
    }
    irrecv.resume(); // receives the next value fromm the button u press
  }
  delay(10);
}
