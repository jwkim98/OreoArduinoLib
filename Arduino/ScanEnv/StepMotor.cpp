#include "StepMotor.h"

StepMotor::StepMotor(int pin1, int pin2, int pin3, int pin4)
    : m_motorPin1(pin1), m_motorPin2(pin2), m_motorPin3(pin3),
      m_motorPin4(pin4) {
  pinMode(m_motorPin1, OUTPUT);
  pinMode(m_motorPin2, OUTPUT);
  pinMode(m_motorPin3, OUTPUT);
  pinMode(m_motorPin4, OUTPUT);
}

void StepMotor::Drive(size_t numStep, bool dir, size_t delayTime) {

  if (dir) {
    for (size_t idx = 0; idx < numStep; ++idx) {
      digitalWrite(m_motorPin1, HIGH);
      digitalWrite(m_motorPin2, LOW);
      digitalWrite(m_motorPin3, LOW);
      digitalWrite(m_motorPin4, LOW);
      delay(delayTime);
      digitalWrite(m_motorPin1, LOW);
      digitalWrite(m_motorPin2, HIGH);
      digitalWrite(m_motorPin3, LOW);
      digitalWrite(m_motorPin4, LOW);
      delay(delayTime);
      digitalWrite(m_motorPin1, LOW);
      digitalWrite(m_motorPin2, LOW);
      digitalWrite(m_motorPin3, HIGH);
      digitalWrite(m_motorPin4, LOW);
      delay(delayTime);
      digitalWrite(m_motorPin1, LOW);
      digitalWrite(m_motorPin2, LOW);
      digitalWrite(m_motorPin3, LOW);
      digitalWrite(m_motorPin4, HIGH);
      delay(delayTime);
    }
  } else {
    for (size_t idx = 0; idx < numStep; ++idx) {
      digitalWrite(m_motorPin1, LOW);
      digitalWrite(m_motorPin2, LOW);
      digitalWrite(m_motorPin3, LOW);
      digitalWrite(m_motorPin4, HIGH);
      delay(delayTime);
      digitalWrite(m_motorPin1, LOW);
      digitalWrite(m_motorPin2, LOW);
      digitalWrite(m_motorPin3, HIGH);
      digitalWrite(m_motorPin4, LOW);
      delay(delayTime);
      digitalWrite(m_motorPin1, LOW);
      digitalWrite(m_motorPin2, HIGH);
      digitalWrite(m_motorPin3, LOW);
      digitalWrite(m_motorPin4, LOW);
      delay(delayTime);
      digitalWrite(m_motorPin1, HIGH);
      digitalWrite(m_motorPin2, LOW);
      digitalWrite(m_motorPin3, LOW);
      digitalWrite(m_motorPin4, LOW);
      delay(delayTime);
    }
  }
}
