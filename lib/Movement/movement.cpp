#ifndef _movement_CPP_
#define _movement_CPP_

#include "motors/motor.h"
#include "sensors.h"

motor motorA;
motor motorB;
motor motorC;
motor motorD;
Sensors sensors;

void motors_init()
{

    motorA.init(4, 2, 3, -45);
    motorB.init(28, 30, 29, +45 );
    motorC.init(38, 36, 37, +135);
    motorD.init(21, 22, 23, -135);
}

void acceleration(float acc)
{

    motorA.acceleration_s = acc;
    motorB.acceleration_s = acc;
    motorC.acceleration_s = acc;
    motorD.acceleration_s = acc;
}

void go(short direction_go, short turn_direction)
{
    
    motorA.go(direction_go, turn_direction, gyro);
    motorB.go(direction_go, turn_direction, gyro);
    motorC.go(direction_go, turn_direction, gyro);       
    motorD.go(direction_go, turn_direction, gyro);
}

void stop(){
    motorA.setSpeed(0);
    motorB.setSpeed(0);
    motorC.setSpeed(0);
    motorD.setSpeed(0);
    
    }

#endif