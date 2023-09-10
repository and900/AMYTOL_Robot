/*
  This the constructor  Source File  AmyytolRobot.cpp
  .cpp - Library for Nexgen Robot Motor Direction and Speed
  Forward Back Left Right Stop etc.
  Created by Andrew Morgan September 8th 2023.
  All My Things On Line AMYTOL
  wwww.AllMyThingsOnLine.com
  Not Released into the public domain.
*/

#include "Arduino.h"
#include "AmytolRobot.h"

Rbt::Rbt(int pin)
{
  _pin   = 0;
 // _tpin  = 9; //touch Sensor Pin
 //_bpin  = 8; //buzzer Pin 
 //_upin  = 7; //Ultrosonic Pin 
  _lpin  = 6; // dirLPin direction left pin connected to the motor
  _mlpin = 5; //motorLPin PWM output pin connected to the motor left pin
  _rpin  = 3; // dirRPin direction right pin connected to the motor
  _mrpin = 2; //motorRPin PWM output pin connected to the motor right pin
  
 }

void Rbt::begin()
{
  Serial.begin(9600);
  pinMode(_pin, OUTPUT);
 // pinMode(_bpin, OUTPUT);
 // pinMode(_tpin, OUTPUT);
 // pinMode(_upin, OUTPUT);
  pinMode(_lpin, OUTPUT);
  pinMode(_rpin, OUTPUT);
  pinMode(_mlpin, OUTPUT);
  pinMode(_mrpin, OUTPUT);
  delay(2000);
}

void Rbt::dot()
{
  digitalWrite(_pin, HIGH);
  delay(250);
  digitalWrite(_pin, LOW);
  delay(250);  
}

void Rbt::dash()
{
  digitalWrite(_pin, HIGH);
  delay(1000);
  digitalWrite(_pin, LOW);
  delay(250);
}

void Rbt::setSpeed(int PWMcl) {
  // set the PWM cycle length for around 140 to give a reasonable motor speed. Value between 0 and 255
  Serial.print("set Speed mlpin: ");
  Serial.print(_mlpin);
  Serial.print(" set Speed mrpin: ");
  Serial.print(_mrpin);
  Serial.print(" set Speed ms: ");
  Serial.print(PWMcl);
  Serial.println(" ....");
  analogWrite(_mlpin, PWMcl);
  analogWrite(_mrpin, PWMcl);
}
void Rbt::setSpeedLeft(int PWMcl) {
  // set the motor speed to a value between 0 and 255
  Serial.print("set Speed left mlpin: ");
  Serial.print(_mlpin);
  Serial.print(" PWMcl ms: ");
  Serial.print(PWMcl);
  Serial.println(" ....");

  analogWrite(_mlpin, PWMcl);
}
void Rbt::setSpeedRight(int PWMcl) {
  // set the motor speed to a value between 0 and 255
  Serial.print("set Speed left mrpin: ");
  Serial.print(_mrpin);
  Serial.print(" PWMcl ms: ");
  Serial.print(PWMcl);
  Serial.println(" ....");
  analogWrite(_mrpin, PWMcl);
}
void Rbt::forwardFor(int PWMcl, int delayms) {
  Serial.print("forward for lpin: ");
  Serial.print(_lpin);
  Serial.print(" rpin: ");
  Serial.print(_rpin);
    Serial.print(" speed: ");
    Serial.print(PWMcl);
    Serial.print(" delay ms: ");
    Serial.print(delayms);
    Serial.println(" ....");
    digitalWrite(_lpin, HIGH);
    digitalWrite(_rpin, HIGH);
    setSpeed(PWMcl);
    delay(delayms);
    setSpeed(0);
}
void Rbt::forward(int speed, int delayms) {
  Serial.print("forward lpin: ");
  Serial.print(_lpin);
  Serial.print(" rpin: ");
  Serial.print(_rpin);
    Serial.print(" speed: ");
    Serial.print(speed);
    Serial.print(" ms: ");
    Serial.print(delayms);
    Serial.println(" ....");
    digitalWrite(_lpin, HIGH);
    digitalWrite(_rpin, HIGH);
    setSpeed(speed);
    delay(delayms);
}
void Rbt::forward(int speedL, int speedR, int delayms) {
  Serial.print("forward lpin: ");
  Serial.print(_lpin);
  Serial.print(" rpin: ");
  Serial.print(_rpin);
   Serial.print(" speedL: ");
    Serial.print(speedL);
    Serial.print(" speedR: ");
    Serial.print(speedR);
    Serial.print(" ms: ");
    Serial.print(delayms);
    Serial.println(" ....");
    digitalWrite(_lpin, HIGH);
    digitalWrite(_rpin, HIGH);
    setSpeedLeft(speedL);
    setSpeedRight(speedR);
    delay(delayms);
    setSpeed(0);
}
void Rbt::backwardFor(int PWMcl, int delayms) {
  Serial.print("forward for lpin: ");
  Serial.print(_lpin);
  Serial.print(" rpin: ");
  Serial.print(_rpin);
    Serial.print(" speed: ");
    Serial.print(PWMcl);
    Serial.print(" delay ms: ");
    Serial.print(delayms);
    Serial.println(" ....");
    digitalWrite(_lpin, LOW);
    digitalWrite(_rpin, LOW);
    setSpeed(PWMcl);
    delay(delayms);
    setSpeed(0);
}
void Rbt::backward(int speed, int delayms) {
    Serial.print("backward lpin: ");
    Serial.print(_lpin);
    Serial.print(" rpin: ");
    Serial.print(_rpin);
    Serial.print(" speed: ");
    Serial.print(speed);
    Serial.print(" ms: ");
    Serial.print(delayms);
    Serial.println(" ....");
    digitalWrite(_lpin, LOW);
    digitalWrite(_rpin, LOW);
    setSpeed(0);
    delay(delayms);
}
void Rbt::turnRight(int speed,int delayms) 
{
  Serial.print("turn right Speed lpin: ");
  Serial.print(_lpin);
  Serial.print(" rpin: ");
  Serial.print(_rpin);
  Serial.print(" speed: ");
    Serial.print(speed);
    Serial.print(" delay ms: ");
    Serial.print(delayms);
    Serial.println(" ....");
    digitalWrite(_lpin, HIGH);
    digitalWrite(_rpin, LOW);
    setSpeedLeft(speed);
    setSpeedRight(speed);
    delay(delayms);
    setSpeed(0);
    delay(1000);
  }
void Rbt::turnLeft(int speed, int delayms) 
{
  Serial.print("turn left Speed lpin: ");
  Serial.print(_lpin);
  Serial.print(" rpin: ");
  Serial.print(_rpin);
   Serial.print(" speed: ");
    Serial.print(speed);
    Serial.print(" ms: ");
    Serial.print(delayms);
    Serial.println(" ....");
    digitalWrite(_lpin, LOW);
    digitalWrite(_rpin, HIGH);
    setSpeedLeft(speed);
    setSpeedRight(speed);
    delay(delayms);
    setSpeed(0);
    delay(1000);
 }
void Rbt::stopCoast(){
analogWrite(_mlpin, 0);  
analogWrite(_mrpin, 0);
digitalWrite(_lpin,HIGH);
digitalWrite(_rpin,HIGH);
}

void Rbt::stopHard(){
analogWrite(_mlpin, 0);  
analogWrite(_mrpin, 0);
digitalWrite(_lpin,LOW);
digitalWrite(_rpin,LOW);
}
void Rbt::stopBrake(int delayms) {
  setSpeed(0);
  delay(delayms);
}