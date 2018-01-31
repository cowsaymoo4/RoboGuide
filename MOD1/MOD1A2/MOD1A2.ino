
#define LEDPINR 8
#define inPIN 2
#define LEDPING 5
int val = 0;
int stater = 1;

void setup() {
  // put your setup code here, to run once:
  pinMode(LEDPINR, OUTPUT);      // sets the digital pin 13 as output
  pinMode(inPIN, INPUT);
  pinMode(LEDPING, OUTPUT);
  digitalWrite(LEDPINR, HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:

  if (stater == 1){
    val = digitalRead(inPIN);     
    if (val == LOW)
    {
      delay(50);
      val = digitalRead(inPIN);
      if (val == HIGH)
      {
        digitalWrite(LEDPINR, LOW);
        digitalWrite(LEDPING, HIGH);   
        stater = 0;    
      }
    }
  }
  if (stater == 0){
    val = digitalRead(inPIN);     
    if (val == LOW)
    {
      delay(50);
      val = digitalRead(inPIN);
      if (val == HIGH)
      {
        digitalWrite(LEDPINR, HIGH);
        digitalWrite(LEDPING, LOW);   
        stater = 1;    
      }
    }
  }
}
