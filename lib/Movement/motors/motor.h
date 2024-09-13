#ifndef _motor_H_
#define _motor_H_

#include "config.h"

//================================================================

class motor
{
public:
    void init(int direction_pin1, int direction_pin2, int pwm_pin, int wheel_angle);
    void init(int direction_pin1, int direction_pin2, int pwm_pin, int wheel_angle, int k_revers);
    void setSpeed(short speed);
    void go(int moving_direction, int turn_direction, int gyro_direction);

    float acceleration_s = 0.6;
    unsigned long time_last_change = 0;

private:

    int acceleration(int);
    int our_speed = 0;

    float kp = 1.3;
    float turn_last_err, turn_up;
    short turn_err, turn_direction, moving_direction;

    int direction_pin1_, direction_pin2_, pwm_pin_;
    int motor_angle_;
};

#endif // _motor_H_