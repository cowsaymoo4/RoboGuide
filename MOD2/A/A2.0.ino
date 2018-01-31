#define E1 6
#define M1 7
#define E2 5
#define M2 4
#define inPIN 8


int val = 0;
int speed = 100;



void setup() {
  // put your setup code here, to run once:
	pinMode(E1, OUTPUT);      			// sets the digital pin 13 as output
	pinMode(E2, OUTPUT);
	pinMode(M1, OUTPUT);
	pinMode(M2, OUTPUT);
	pinMode(inPIN, INPUT);
	digitalWrite(M1, HIGH);

	val = digitalRead(inPIN);     
    while (val == LOW) 					// while its pushed
    {
      delay(50);
      val = digitalRead(inPIN);
		 while(val == HIGH)  			 //button released
			loop();							
	}
}
	
void loop() {
	delay(1000);						// delay before starting spin
    turn(M1,M2,speed)					// Left turn
	delay(3000);
	stop();
	turn (M2,M1,speed)					// Right turn
	delay(3000);
	stop();
}

void turn(a,b,speed_1) {
	digitalWrite(a, LOW);				 
    digitalWrite(b, HIGH); 
    analogWrite (E2, speed); 
	analogWrite (E1, speed); 
}

void stop (){
	analogWrite (E2, 0); 
	analogWrite (E1, 0); 
}
