#ifndef motor_H
#define motor_H

#include "config.h"

//================================================================


class motor
{
public:
    void init(int direction_pin1, int direction_pin2, int pwm_pin, int wheel_angle);
    void setSpeed(short speed);
    void go(int moving_direction, int turn_direction);

    float acceleration_s = 0.2;

    short pwm_ = 0;
    short speed_ = 0;
    unsigned long time_last_change = 0;

private:
    float kp = 0;
    float kd = 0;
    short turn_err, turn_last_err, turn_up, turn_direction, moving_direction;
    int direction_pin1_;
    int direction_pin2_;
    int pwm_pin_;
    int motor_angle_;
};

#endif // _motor_H_