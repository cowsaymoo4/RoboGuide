#define E1 6
#define M1 7
#define E2 5
#define M2 4
#define inPIN 3

int speedM = 100;

void setup() {
  // put your setup code here, to run once:
  pinMode(E1, OUTPUT);      
  pinMode(E2, OUTPUT);
  pinMode(M1, OUTPUT);
  pinMode(M2, OUTPUT);
  pinMode(inPIN, INPUT);
  digitalWrite(M1, HIGH);

  while (digitalRead(inPIN) == LOW){
  }
}

void loop() {
    delay(1000);
    turn(M1,M2,speedM);
    delay (3000);
    stopM()
    delay (1000);
    turn(M2,M1,speedM);
    delay (3000);
    stopM();
}

void turn(A,B,s){
        digitalWrite(A, LOW);
        digitalWrite(B, HIGH); 
        analogWrite (E1, s);
        analogWrite (E2, s);
}

void stopM(){
  analogWrite (E1, 0);
  analogWrite (E2, 0);
}
