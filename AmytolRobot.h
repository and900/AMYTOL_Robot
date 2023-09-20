/*
  This is the Header File .h
  Rbt.h - Library for Nexgen Robot forward Back Left Right Stop
  Created by Andrew Morgan September 8th 2023
  All My Things On Line AMYTOL
  wwww.AllMyThingsOnLine.com
  Not Released into the public domain.
*/


#ifdef NEXTGEN
{
byte pwm_pin[] = { 5, 6, };
#define VOLTAGE_DETECTION_PIN A0
#define BATTERY_PIN A0
#define LOW_VOLTAGE 440
#define BAUD_RATE 9600
#define FORWARD 1
#define BACKWARD -1


};
#endif


#ifndef Rbt_h
#define Rbt_h

class Rbt
{
public:
  Rbt(int pin);
  void begin();
  void dot();
  void dash();
  void speed_increment(int speed_increment);
  void setSpeed(int PWM);
  void setSpeed(int PWML,int PWMR);
  void setSpeedLeft(int PWML);
  void setSpeedRight(int PWML );
  void turnRight(int speed, int delayms);
  void turnLeft(int PWM, int delayms);
  void turnLeft(int PWML, int PWMR, int delayms);
  void forwardFor(int PWM, int delayms);
  void forward(int speed, int delayms);
  void forward(int PWM);
  void frwrdSpedVar(int PWML,int PWMR, int delayms);
  void backwardFor(int PWM, int delayms);
  void backward(int speedd, int delayms);
  void stopCoast();
  void stopHard();
  void stopBrake(int delayms);
  void batteryCheckTone();
 private:
  int _pin;
  int _bpin;
  int _tpin;
  int _upin;
  int _lpin;
  int _rpin;
  int _mlpin;
  int _mrpin;
  int tuningLeftMotor;
  int tuningRightMotor;
};

#endif

