#include "motor.h"

#include "geometry.h"



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

void motor::init(int direction_pin1, int direction_pin2, int pwm_pin, int motor_angle, int k_reverse)
{
    direction_pin1_ = direction_pin1;
    direction_pin2_ = direction_pin2;
    pwm_pin_ = pwm_pin;
    motor_angle_ = motor_angle;
    pinMode(direction_pin1, OUTPUT);
    pinMode(direction_pin2, OUTPUT);
    pinMode(pwm_pin, OUTPUT);
    k_reverse_ = k_reverse;
}


void motor::setSpeed(short speed)
{
    // for (int acs = time_last_change; acs < millis(); acs++){
    int iter = ((millis() - time_last_change))/4;
    for(int d_t = 0;d_t < iter;d_t++){ 
    our_speed += int(sqrt(abs(speed-our_speed))*sign(speed-our_speed) * acceleration_s) ;}
    digitalWrite(direction_pin1_, our_speed > 0);   
    digitalWrite(direction_pin2_, our_speed < 0);
    analogWrite(pwm_pin_, abs(our_speed));
    // time_last_change = millis();
        Serial.print(" Motor active ");
    Serial.print(our_speed);
   Serial.print(" ");
    Serial.print(sign(speed-our_speed));
    Serial.print(" ");
    Serial.print(our_speed - speed);
    time_last_change  = millis();
}


void motor::go(int moving_direction, int turn_direction, int gyro_direction)
{
    turn_err = between(turn_direction, gyro_direction);
    turn_up = (turn_err * kp + (turn_last_err - turn_err)*kd)/ POWER_ROT_MAX;
    moving_direction = between(moving_direction, gyro_direction);
    setSpeed( constrain(POWER * (turn_up + cos((moving_direction + motor_angle_) * DEG_TO_RAD)),-255,255));
    // Serial.print(" Motor active ");
    // Serial.print(POWER * ( turn_up+ cos((moving_direction + motor_angle_) * DEG_TO_RAD)));
    // Serial.print(" ");
    // Serial.print(turn_up);
    // Serial.print(" ");
    // Serial.print(cos((moving_direction + motor_angle_) * DEG_TO_RAD));
     turn_last_err = turn_err;
}