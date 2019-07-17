#include <SharpIR.h>

const int motorPin1 = 1;
const int motorPin2 = 2;
const int motorPin3 = 3;
const int motorPin4 = 4;
const int shortPsdPin = 0;
const int longPsdPin = 1;
const int maxStep = 300;

SharpIR shortPsd(shortPsdPin, 1080);
SharpIR longPsd(longPsdPin, 100500);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("MAMMAMIA");

  
  pinMode(motorPin1, OUTPUT);
  pinMode(motorPin2, OUTPUT);
  pinMode(motorPin3, OUTPUT);
  pinMode(motorPin4, OUTPUT);

 
}

void drive(size_t numStep);

struct DistInfo{
  DistInfo(int shortDist, int longDist, int stepIdx) : ShortDist(shortDist), LongDist(longDist), StepIdx(stepIdx)
  {};
  int ShortDist;
  int LongDist;
  int StepIdx;
};

void loop() {
  // put your main code here, to run repeatedly

  for(int idx = 0; idx < maxStep; ++idx){ 
    int shortDist = shortPsd.distance();
    int longDist = longPsd.distance();

    DistInfo distInfo(shortDist, longDist, idx);
  }
  for(int idx = maxStep; idx >=0 ; --idx){ 
    int shortDist = shortPsd.distance();
    int longDist = longPsd.distance();

    DistInfo distInfo(shortDist, longDist, idx);
  }
  
}



void Drive(size_t numStep, bool dir, size_t delayTime) {

  if(dir){
    for(size_t idx = 0; idx < numStep; ++idx)
    {
      digitalWrite(motorPin1, HIGH);
      digitalWrite(motorPin2, LOW);
      digitalWrite(motorPin3, LOW);
      digitalWrite(motorPin4, LOW);
      delay(delayTime);
      digitalWrite(motorPin1, LOW);
      digitalWrite(motorPin2, HIGH);
      digitalWrite(motorPin3, LOW);
      digitalWrite(motorPin4, LOW);
      delay(delayTime);
      digitalWrite(motorPin1, LOW);
      digitalWrite(motorPin2, LOW);
      digitalWrite(motorPin3, HIGH);
      digitalWrite(motorPin4, LOW);
      delay(delayTime);
      digitalWrite(motorPin1, LOW);
      digitalWrite(motorPin2, LOW);
      digitalWrite(motorPin3, LOW);
      digitalWrite(motorPin4, HIGH);
      delay(delayTime);
    }
  }
  else
  {
    for(size_t idx = 0; idx < numStep; ++idx)
    {
      digitalWrite(motorPin1, LOW);
      digitalWrite(motorPin2, LOW);
      digitalWrite(motorPin3, LOW);
      digitalWrite(motorPin4, HIGH);
      delay(delayTime);
      digitalWrite(motorPin1, LOW);
      digitalWrite(motorPin2, LOW);
      digitalWrite(motorPin3, HIGH);
      digitalWrite(motorPin4, LOW);
      delay(delayTime);
      digitalWrite(motorPin1, LOW);
      digitalWrite(motorPin2, HIGH);
      digitalWrite(motorPin3, LOW);
      digitalWrite(motorPin4, LOW);
      delay(delayTime);
      digitalWrite(motorPin1, HIGH);
      digitalWrite(motorPin2, LOW);
      digitalWrite(motorPin3, LOW);
      digitalWrite(motorPin4, LOW);
      delay(delayTime);
    }
  }
}
