#include "motor.h"

void motor::init(int direction_pin1, int direction_pin2, int pwm_pin, int motor_angle)
{
    direction_pin1_ = direction_pin1;
    direction_pin2_ = direction_pin2;
    pwm_pin_ = pwm_pin;
    motor_angle_ = motor_angle;
    pinMode(direction_pin1, OUTPUT);
    pinMode(direction_pin2, OUTPUT);
    pinMode(pwm_pin, OUTPUT);
}

void motor::setSpeed(short speed)
{
    pwm_ = speed;
    digitalWrite(direction_pin1_, pwm_ > 0);
    digitalWrite(direction_pin2_, pwm_ < 0);
    analogWrite(pwm_pin_, abs(pwm_));
}


void motor::go(int moving_direction, int turn_direction)
{
    // turn_err = between(turn_direction, gyro);
    // turn_up = turn_err * kp + (turn_err - turn_last_err) * kd;
    // moving_direction = between(moving_direction, gyro);
    // setSpeed(turn_up + cos((moving_direction - 90 - motor_angle_)) * DEG_TO_RAD);
}