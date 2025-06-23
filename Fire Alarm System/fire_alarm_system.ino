#define LED 8 
#define BUZZ 7

float temp;
float vout;
float vout1;
int gas;

void setup() {
  Serial.begin(9600);
  pinMode(A0,INPUT);
  pinMode(A1,INPUT);
  pinMode(LED,OUTPUT);
  pinMode(BUZZ,OUTPUT);
}

void loop() {
  vout = analogRead(A1);
  vout1=(vout/1023)*5000;
  temp=(vout1-500)/10;
  gas=analogRead(A0);
  
  if (temp>=80) {
    digitalWrite(LED, HIGH);
  } else {
    digitalWrite(LED, LOW);
  } 
  
  if (gas>=100) {
    digitalWrite(BUZZ, HIGH);
  } else {
    digitalWrite(BUZZ, LOW);
  } 

  Serial.print("in DegreeC= ");
  Serial.print(" ");
  Serial.print(temp);
  Serial.print("\t");
  Serial.print("gas= ");
  Serial.print(" ");
  Serial.print(gas);
  Serial.println();
  
  delay(1000);
}
