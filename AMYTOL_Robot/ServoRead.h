/*
  This is the Servo Read - Header File ServoRead.h
  ServoRead.h - Library for creating Clases for the built in Ardurino IDE Servo 
  This file wraps methods to expose to the Arduino® library.
  Created by Andrew Morgan September 10th 2023
  All My Things On Line AMYTOL
  wwww.AllMyThingsOnLine.com
  Not Released into the public domain.
  https://www.mathworks.com/help/supportpkg/arduino/ug/create-a-c-code-for-servo-read-library.html
*/

#include "Servo.h"
#ifndef ServoRead_h
#define ServoRead_h
class ServoRead : public LibraryBase
{
    public:
        Servo myServo;
    public:
        ServoRead(MWArduinoClass& a)
        {
            libName = "ServoRead/ServoRead";
            a.registerLibrary(this);
        }
        void commandHandler(byte cmdID, byte* inputs, unsigned int payload_size)
        {
            switch (cmdID){
                case 0x01:{ 
                    byte val;
                    if(!myServo.attached())
                        myServo.attach(inputs[0]);
                    val = myServo.read();
                    sendResponseMsg(cmdID, &val, 1);
                    break;
                }
                default:{
                    // Do nothing
                }
            }
        }
};

#endif

