#define LTHRESH 25
#define CTHRESH 25
#define RTHRESH 25
#define R 0
#define C 1
#define L 2

int sensorValueR = 0;
int sensorValueC = 0;
int sensorValueL = 0;

void setup() {
  // put your setup code here, to run once:
   Serial.begin(9600);
   pinMode(R, INPUT);
   pinMode(C, INPUT);
   pinMode(L, INPUT);
   //sensorValueR = analogRead(R);
   //sensorValueC = analogRead(C);
  // sensorValueL = analogRead(L);
}

void loop() {
  // put your main code here, to run repeatedly:
    readSensor(sensorValueR,sensorValueC,sensorValueL);
    delay(4000);
}


void readSensor(int RR,int RC,int RL){
  RR = analogRead(R);
  RC = analogRead(C);
  RL = analogRead(L);
  Serial.print("\nsensorR = ");
  Serial.print(RR);
  Serial.print("\nsensorC = ");
  Serial.print(RC);
  Serial.print("\nsensorL = ");
  Serial.print(RL);

}




  

