#define LTHRESH 20
#define CTHRESH 20
#define RTHRESH 20

#define E1 6
#define M1 7
#define E2 5
#define M2 4
#define inPIN 2 //Push button

#define R 0
#define C 1
#define L 2


int sensorValueR = 0;
int sensorValueC = 0;
int sensorValueL = 0;
int speedM = 100;
int Button = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(E1, OUTPUT);      
  pinMode(E2, OUTPUT);
  pinMode(M1, OUTPUT);
  pinMode(M2, OUTPUT);
  pinMode(R, INPUT);
  pinMode(C, INPUT);
  pinMode(L, INPUT);
  pinMode(inPIN, INPUT);
  analogWrite (E1, 0);
  analogWrite (E2, 0);

   Serial.println("NOT PRESSED");
   
  
  sensorValueR = analogRead(R);
  sensorValueC = analogRead(C);
  sensorValueL = analogRead(L);

  
}


void loop() {
  // put your main code here, to run repeatedly:

while (Button == 0){
    delay (50);
    Serial.println("NOT PRESSED");
    while (digitalRead(inPIN) == 0){
      delay (50);
      Serial.println("PRESSED");
      if (digitalRead(inPIN) == 1){
        Button = 1;
        Serial.println("NOT PRESSED");
      }
    }
  }

    //read Line tracker sensor values
    sensorValueR = analogRead(R);
    sensorValueC = analogRead(C);
    sensorValueL = analogRead(L);

    //print Center Tracker value
    Serial.println(analogRead(C));

    //if black line is met
    if( sensorValueC < (650 - CTHRESH)){ 
       //print Center Tracker value
       Serial.print("\nsensorC = ");
       Serial.print(sensorValueC);
       //Stop motors
       stopM();
       //End program
       while(1){}
    }
    turn(M1,M2,speedM);
    
}

void stopM(){
  analogWrite (E1, 0);
  analogWrite (E2, 0);
} 
void turn(int A,int B, int s){
   digitalWrite(A, LOW);
   digitalWrite(B, HIGH); 
   analogWrite (E1, s);
   analogWrite (E2, s);
   loop();
}

void readSensor(int RR,int RC,int RL){
  RR = analogRead(R);
  RC = analogRead(C);
  RL = analogRead(L);
  Serial.print("\nsensorR = ");
  Serial.print(sensorValueR);
  Serial.print("\nsensorC = ");
  Serial.print(sensorValueC);
  Serial.print("\nsensorL = ");
  Serial.print(sensorValueL);

}





  

