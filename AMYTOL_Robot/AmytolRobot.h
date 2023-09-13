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
  void speed_increment(int speedpeed_increment);
  void setSpeed(int PWMcl);
  void setSpeedLeft(int PWMcl);
  void setSpeedRight(int PWMcl);
  void turnRight(int speed, int delayms);
  void turnLeft(int speed, int delayms);
  void forwardFor(int PWMcl, int delayms);
  void forward(int speedpeed, int delayms);
  void forward(int speedpeedL, int speedpeedR, int delayms);
  void backwardFor(int PWMcl, int delayms);
  void backward(int speedpeed, int delayms);
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
 };

#endif

