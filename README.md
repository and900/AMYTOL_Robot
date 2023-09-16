<div align="center">
  <a href="https://github.com/and900/Reference/blob/main/images/">
    <img src="https://github.com/and900/Reference/blob/main/images/logo.jpg" alt="Logo" width="80" height="80">
  </a>

  <h3 align="center">All My Things Online</h3>
<img src="https://github.com/and900/Reference/blob/main/images/I_Amytol_L_0.png" alt="Logo" width="80" height="80">
  <p align="center">
    An awesome Robot project to jumpstart your knowledge!
    <br />
    <a href="https://github.com/and900/AMYTOL_Robot/blob/main/AMYTOL_Robot"><strong>Explore the docs »</strong></a>
    <br />
    <br />
    <a href="https://github.com/and900/AMYTOL_Robot/blob/main/AMYTOL_Robot">View Demo</a>
    ·
    <a href="https://github.com/and900/AMYTOL_Robot/blob/main/AMYTOL_Robot/issues">Report Bug</a>
    ·
    <a href="https://github.com/and900/AMYTOL_Robot/blob/main/AMYTOL_Robot/issues">Request Feature</a>
  </p>
</div>

  <h3 align="left"></h3>

# AMYTOL Robot
AMYTOL created Library and Sample Code for the NEXTGEN CODECAMP
# Amytol Robot NEXTGEN
The NexGen Robot has a number of built in sensors. 
    <br />
This library is designed to easily access the robot's functionality.
    <br />
AMYTOL Robot provides a library for Forward, Back, Brake, Turn Left and Turn Right classes for the motors of the to the NextGen Robot

# WIRING
This program assumes the wiring for the Rover 3V is as follows:
  <br />
Wiring for the motor driver inputs are:
  <br />
| Connector | Pin | Wire Colour | To Motor Driver |
| --- | --- | --- | --- |
| J1| 1| Yellow| PWM A |
| J1| 2| White| DIR A |
| J1| 3| Not Used| Not Used |
| J1| 4| Black| GND |
| J4| 1| Yellow| PWM B|
| J4| 2| White| DIR B |
| J4| 3| Not Used| Not Used |
| J4| 4| Black| GND |
 
Motor Driver Outputs

| From Motor Driver | Motor | Wire Colour | 
| --- | --- | --- |
| A+ | Right Motor | Black | 
| A- | Right Motor | Red |   
| B- | Left Motor | Black |
| B+ | Left Motor | Red |


<div align="center">
<a href="https://github.com/and900/Reference/blob/main/images/">
    <img src="https://github.com/and900/Reference/blob/main/images/NEXTGEN%20ROBOT.png" alt="Logo" width="249" height="189">
</a>
</div>


# Author
  Created by Andrew Morgan September 8th 2023
  All My Things On Line AMYTOL
  wwww.AllMyThingsOnLine.com

## Description
This is an Arduino library to demonstrate how you to extend the functionality of Arduino C+.
Pin configuration is stored in the Construction file called by yhe constraint
Libary autocomplete prefix is "rbt" 
<br />
   ArduinoWorkspace --- /
<br />
       AMYTOL_Robot/ ----+ /
<br />
           examples/--------   + AmytolRobot.ino
<br />
               src/ --------   + AmytolRobot.cpp
<br />
                               + AmytolRobot.h

### Initalise 
Rbt rbt (007);   Secret Agent Pin Delaration

#### Fixed Variables
ultrasonicPin = 7;
buzzerPin = 8;
touchSensorPin = 9;
buzzer = 8;
fast_speed = 255;
medium_speed = 140;
slow_speed = 80;
tenthofaSecond = 100 milliseconds
halfaSecond = 500;
oneSecond = 1000;
twoSeconds = 2000;
fiveSeconds = 5000;
num_times_to_repeat =1;

##### WARRANTY
This library is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
