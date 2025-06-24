#define T_C 262
#define T_D 294
#define T_E 329
#define T_F 392
#define T_G 440
#define T_A 493
#define T_B 523
 
const int C = 2;
const int D = 3;
const int E = 4;
const int F = 5;
const int G = 6;
const int A = 7;
const int B = 8;

const int buzz = 13;

void setup()
{
  pinMode(C, INPUT);
  pinMode(D, INPUT);
  pinMode(E, INPUT);
  pinMode(F, INPUT);
  pinMode(G, INPUT);
  pinMode(A, INPUT);
  pinMode(B, INPUT);

  digitalWrite(C, HIGH);
  digitalWrite(D, HIGH);
  digitalWrite(E, HIGH);
  digitalWrite(F, HIGH);
  digitalWrite(G, HIGH);
  digitalWrite(A, HIGH);
  digitalWrite(B, HIGH);
 
  pinMode(buzz,  INPUT);
}

void loop ()
{
  while(digitalRead(C) == LOW) {
    tone(buzz, T_C);
  }
  while(digitalRead(D) == LOW) {
    tone(buzz, T_D);
  }
  while(digitalRead(E) == LOW) {
    tone(buzz, T_E);
  }
  while(digitalRead(F) == LOW) {
    tone(buzz, T_F);
  }
  while(digitalRead(G) == LOW) {
    tone(buzz, T_G);
  }
  while(digitalRead(A) == LOW) {
    tone(buzz, T_A);
  }
  while(digitalRead(B) == LOW) {
    tone(buzz, T_B);
  }
  
  noTone(buzz);
}

// notes for twinkle twinkle little star
// CC GG AA G
//FF EE D d C
// G GF F E E D
// GG FF EE D
// CC GG AA G
// FF EE D D C
