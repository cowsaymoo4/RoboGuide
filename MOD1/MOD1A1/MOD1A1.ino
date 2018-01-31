
#define LEDPINR 8
#define inPIN 2
#define LEDPING 5
int val = 0;
void setup() {
  // put your setup code here, to run once:
  pinMode(LEDPINR, OUTPUT);      // sets the digital pin 13 as output
  pinMode(inPIN, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  
  val = digitalRead(inPIN);     
  while(val == LOW)
  {
    delay(50);
    val = digitalRead(inPIN);
    while (val == HIGH)
    {
      digitalWrite(LEDPINR, HIGH);       
      delay(1000);                  
      digitalWrite(LEDPINR, LOW);       
      delay(1000);
      break;
      }
    }
 }

