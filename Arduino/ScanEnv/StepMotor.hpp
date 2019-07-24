
#pragma once
#include <Arduino.h>

class StepMotor {
public:
  StepMotor(int pin1, int pin2, int pin3, int pin4);

  void Drive(size_t numStep, bool dir, size_t delayTime);

private:
  const int m_motorPin1;
  const int m_motorPin2;
  const int m_motorPin3;
  const int m_motorPin4;
};
