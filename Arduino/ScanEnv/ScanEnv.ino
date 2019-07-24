#include "StepMotor.hpp"
#include <SharpIR.h>

const int shortPsdPin = 0;
const int longPsdPin = 1;
const int maxStep = 300;

SharpIR shortPsd(shortPsdPin, 1080);
SharpIR longPsd(longPsdPin, 100500);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("MAMMAMIA");
}

void drive(size_t numStep);

struct DistInfo {
  DistInfo(int shortDist, int longDist, int stepIdx)
      : ShortDist(shortDist), LongDist(longDist), StepIdx(stepIdx){};
  int ShortDist;
  int LongDist;
  int StepIdx;
};

void loop() {
  // put your main code here, to run repeatedly

  for (int idx = 0; idx < maxStep; ++idx) {
    int shortDist = shortPsd.distance();
    int longDist = longPsd.distance();

    DistInfo distInfo(shortDist, longDist, idx);
  }
  for (int idx = maxStep; idx >= 0; --idx) {
    int shortDist = shortPsd.distance();
    int longDist = longPsd.distance();

    DistInfo distInfo(shortDist, longDist, idx);
  }
}
