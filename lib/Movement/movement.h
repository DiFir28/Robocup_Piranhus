#ifndef _movement_H_
#define _movement_H_

#include "motor.h"


motor motorA;
motor motorB;
motor motorC;
motor motorD;

void motors_init()
{

    motorA.init(2, 4, 3, +135);
    motorB.init(30, 28, 29, -135);
    motorC.init(36, 38, 37, -45);
    motorD.init(22, 21, 23, 45);
}

void acceleration(float acc)
{

    motorA.acceleration_s = acc;
    motorB.acceleration_s = acc;
    motorC.acceleration_s = acc;
    motorD.acceleration_s = acc;
}

void go(short direction_go, short turn_direction )
{

    motorA.go(direction_go, turn_direction);
    motorB.go(direction_go, turn_direction);
    motorC.go(direction_go, turn_direction);
    motorD.go(direction_go, turn_direction);}

#endif