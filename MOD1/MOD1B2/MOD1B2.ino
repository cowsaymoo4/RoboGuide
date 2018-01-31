
#define LEDPINR 8
#define inPIN 2
#define SPEAKER 5
#define analogPIN 0

int val = 0;
int stater = 1;
int pval = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(LEDPINR, OUTPUT);      // sets the digital pin 13 as output
  pinMode(inPIN, INPUT);
  pinMode(SPEAKER, OUTPUT);
  pinMode(analogPIN, INPUT);
  Serial.begin(9600);
  digitalWrite(LEDPINR, HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:
  
    
  if (stater == 1){
    val = digitalRead(inPIN);     
    while (val == LOW && stater == 1)
    {
      delay(50);
      val = digitalRead(inPIN);
      while(val == HIGH)
      {
        val = digitalRead(inPIN);
        delay(50);
        pval = analogRead(analogPIN);     // read the input pin
        Serial.println(pval);
        digitalWrite(LEDPINR, LOW);
        digitalWrite(SPEAKER, HIGH); 
        tone(5,pval); 
        stater = 0;    
      }
    }
  }
  if (stater == 0){
    val = digitalRead(inPIN);     
    while (val == LOW && stater == 0)
    {

      val = digitalRead(inPIN);
      while (val == HIGH)
      {
        val = digitalRead(inPIN);
        delay(50);
        digitalWrite(LEDPINR, HIGH);
        digitalWrite(SPEAKER, LOW); 
        noTone(5);
        stater = 1;
      }
    }
  }
}
