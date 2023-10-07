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
#include "Amytol_Robot.h"


Rbt::Rbt(int pin)
{
  _pin   = 0;
 // _tpin  = 9; //touch Sensor Pin
 //_bpin  = 8; //buzzer Pin 
 //_upin  = 7; //Ultrosonic Pin 
  // Reverse NexGen advised wiring
  /*
  _mlpin = 2; // motorLPin PWM output pin connected to the motor left pin
  _lpin  = 3; // dirLPin direction left pin connected to the motor
  _mrpin = 5; // motorRPin PWM output pin connected to the motor right pin
  _rpin  = 6; // dirRPin direction right pin connected to the motor
*/
// NexGen
  _mlpin = 3; // motorLPin PWM output connected to PWM A
  _lpin  = 2; // dirLPin direction left pin connected to the motor
  _mrpin = 6; // motorRPin PWM output pin connected to the motor right pin
  _rpin  = 5; // dirRPin direction right pin connected to the motor

  tuningLeftMotor = 0;
  tuningRightMotor = 0;
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
void Rbt::setMotor(int PWML, int PWMR, int fwrdBackL, int fwrdBackR) {
// Set PWM Duty Cycle value between 0 and 255
// Set Direction 
  analogWrite(_mlpin, PWML);
  digitalWrite(_lpin, fwrdBackL);
  analogWrite(_mrpin, PWMR);
  digitalWrite(_rpin, fwrdBackR);
}
void Rbt::setSpeed(int PWML,int PWMR) {
  analogWrite(_mlpin, PWML);
  analogWrite(_mrpin, PWMR);
}
void Rbt::moveMotor(int PWML, int PWMR, int fwrdBackL, int fwrdBackR, int delayms) {
setMotor(PWML, fwrdBackL, PWMR, fwrdBackR);
delay(delayms);
setSpeed(0,0);
}



void Rbt::setSpeed(int PWM) {
  // set the PWM cycle length for around 140 to give a reasonable motor speed. Value between 0 and 255
 /*
  Serial.print("set Speed mlpin: ");
  Serial.print(_mlpin);
  Serial.print(" set Speed mrpin: ");
  Serial.print(_mrpin);
  Serial.print(" set Speed ms: ");
  Serial.print(PWM);
  Serial.println(" ....");
 */
  analogWrite(_mlpin, PWM);
  analogWrite(_mrpin, PWM);
}
void Rbt::setSpeedLeft(int PWML) {
  // set the motor speed to a value between 0 and 255
/*
  Serial.print("set Speed left mlpin: ");
  Serial.print(_mlpin);
  Serial.print(" PWM ms: ");
  Serial.print(PWM);
  Serial.println(" ....");
*/
  analogWrite(_mlpin, PWML);
}
void Rbt::setSpeedRight(int PWMR) {
  // set the motor speed to a value between 0 and 255
  /*
  Serial.print("set Speed left mrpin: ");
  Serial.print(_mrpin);
  Serial.print(" PWM ms: ");
  Serial.print(PWM);
  Serial.println(" ....");
  */
  analogWrite(_mrpin, PWMR);
}

void Rbt::forwardFor(int PWM, int delayms) {
/*  Serial.print("forward for lpin: ");
  Serial.print(_lpin);
  Serial.print(" rpin: ");
  Serial.print(_rpin);
    Serial.print(" speed: ");
    Serial.print(PWM);
    Serial.print(" delay ms: ");
    Serial.print(delayms);
    Serial.println(" ....");
  */
   
    digitalWrite(_lpin, HIGH);
    digitalWrite(_rpin, HIGH);
    setSpeed(PWM);
    delay(delayms);
    setSpeed(0);
}
void Rbt::forward(int PWM) {
 /*
 Serial.print("forward lpin: ");
  Serial.print(_lpin);
  Serial.print(" rpin: ");
  Serial.print(_rpin);
    Serial.print(" speed: ");
    Serial.print(speed);
    Serial.print(" ms: ");
    Serial.println(" ....");
 */
    setSpeed(PWM);
//  analogWrite(_mlpin, PWM);
//  analogWrite(_mrpin, PWM);
    digitalWrite(_lpin, HIGH);
    digitalWrite(_rpin, HIGH);
}

void Rbt::forward(int speed, int delayms) {
 /*
 Serial.print("forward lpin: ");
  Serial.print(_lpin);
  Serial.print(" rpin: ");
  Serial.print(_rpin);
    Serial.print(" speed: ");
    Serial.print(speed);
    Serial.print(" ms: ");
    Serial.print(delayms);
    Serial.println(" ....");
 */
    setSpeed(speed);
//  analogWrite(_mlpin, PWM);
//  analogWrite(_mrpin, PWM);
    digitalWrite(_lpin, HIGH);
    digitalWrite(_rpin, HIGH);
    delay(delayms);
}

void Rbt::backwardFor(int PWM, int delayms) {
 /*
  Serial.print("forward for lpin: ");
  Serial.print(_lpin);
  Serial.print(" rpin: ");
  Serial.print(_rpin);
    Serial.print(" speed: ");
    Serial.print(PWM);
    Serial.print(" delay ms: ");
    Serial.print(delayms);
    Serial.println(" ....");
 */
    digitalWrite(_lpin, LOW);
    digitalWrite(_rpin, LOW);
    setSpeed(PWM);
    delay(delayms);
    setSpeed(0);
}
void Rbt::backward(int speed, int delayms) {
  /*
    Serial.print("backward lpin: ");
    Serial.print(_lpin);
    Serial.print(" rpin: ");
    Serial.print(_rpin);
    Serial.print(" speed: ");
    Serial.print(speed);
    Serial.print(" ms: ");
    Serial.print(delayms);
    Serial.println(" ....");
  */
    digitalWrite(_lpin, LOW);
    digitalWrite(_rpin, LOW);
    setSpeedLeft(speed);
    setSpeedRight(speed);
    delay(delayms);
    setSpeed(0);
  
}
void Rbt::turnRight(int speed,int delayms) 
{
  /*
  Serial.print("turn right Speed lpin: ");
  Serial.print(_lpin);
  Serial.print(" rpin: ");
  Serial.print(_rpin);
  Serial.print(" speed: ");
    Serial.print(speed);
    Serial.print(" delay ms: ");
    Serial.print(delayms);
    Serial.println(" ....");
  */
    digitalWrite(_lpin, HIGH);
    digitalWrite(_rpin, LOW);
    setSpeedLeft(speed);
    setSpeedRight(speed);
    delay(delayms);
    setSpeed(0);
    //delay(1000);
  }
  void Rbt::turnLeft(int PWML, int PWMR, int delayms) 
{
    digitalWrite(_lpin, LOW);
    digitalWrite(_rpin, HIGH);
//    setSpeedLeft(PWML);
analogWrite(_mlpin, PWML);
 //   setSpeedRight(PWMR);
analogWrite(_mrpin, PWMR);
    delay(delayms);
    setSpeed(0);
    delay(1000);
 }

 void Rbt::frwrdSpedVar(int PWML,int PWMR, int delayms) {
    digitalWrite(_lpin, HIGH);
    digitalWrite(_rpin, HIGH);
 //   setSpeed(PWML,PWMR);
     setSpeed(PWML + tuningLeftMotor,PWMR + tuningRightMotor);
//    an+alogWrite(_mlpin, PWML);
 //   analogWrite(_mrpin, PWMR);
    delay(delayms);
  setSpeed(0,0);
 //   analogWrite(_mlpin,0);
  //  analogWrite(_mrpin,0);
}
void Rbt::turnLeft(int PWM, int delayms) 
{
  /*
  Serial.print("turn left Speed lpin: ");
  Serial.print(_lpin);
  Serial.print(" rpin: ");
  Serial.print(_rpin);
   Serial.print(" speed: ");
    Serial.print(speed);
    Serial.print(" ms: ");
    Serial.print(delayms);
    Serial.println(" ....");
  */
    digitalWrite(_lpin, LOW);
    digitalWrite(_rpin, HIGH);
    setSpeedLeft(PWM);
    setSpeedRight(PWM);
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
void Rbt::stopCoast(int speedPWM){
  while (speedPWM > 0) {
    speedPWM -= 45;
    setSpeed(speedPWM,speedPWM);
  }
  speedPWM= max(speedPWM, 0);
  setSpeed(speedPWM,speedPWM);

}

void Rbt::stopCoastBwd(){
digitalWrite(_lpin,LOW);
digitalWrite(_rpin,LOW);
analogWrite(_mlpin, 0);  
analogWrite(_mrpin, 0);

}


void Rbt::direction_FL() {
  digitalWrite(_lpin, HIGH);
  setSpeed(255, 0); 
}
void Rbt::direction_FR() {
  digitalWrite(_rpin, HIGH);
  setSpeed(0,255); 
}

void Rbt::direction_BL() {
  digitalWrite(_lpin, LOW);
  setSpeed(200, 0); 
}
void Rbt::direction_BR() {
  digitalWrite(_rpin, LOW);
  setSpeed(0,200); 
}

