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

int motor::acceleration(int newSpeed)
{
    int iter = ((millis() - time_last_change)) / 4;
    for (int d_t = 0; d_t < iter; d_t++)
    {
        our_speed += int(sqrt(abs(newSpeed - our_speed)) * sign(newSpeed - our_speed) * acceleration_s);
    }
    time_last_change = millis();
    return our_speed;
}

void motor::setSpeed(short speed)
{

    digitalWrite(direction_pin1_, our_speed > 0);
    digitalWrite(direction_pin2_, our_speed < 0);
    analogWrite(pwm_pin_, abs(our_speed));

    // Serial.print(" Motor active ");
    // Serial.print(our_speed);
    // Serial.print(" ");
    // Serial.print(sign(speed-our_speed));
    // Serial.print(" ");
    // Serial.print(our_speed - speed);
}

void motor::go(int moving_direction, int turn_direction, int gyro_direction)
{
    turn_err = between(turn_direction, gyro_direction);
    turn_up = constrain(turn_err * kp, -POWER_ROT_MAX, POWER_ROT_MAX);
    moving_direction = between(moving_direction, gyro_direction);
    setSpeed(constrain(turn_up + acceleration(POWER * cos((moving_direction + motor_angle_) * DEG_TO_RAD)), -255, 255));
    // Serial.print(" Motor active ");
    // Serial.print(POWER * ( turn_up+ cos((moving_direction + motor_angle_) * DEG_TO_RAD)));
    // Serial.print(" ");
    // Serial.print(turn_up);
    // Serial.print(" ");
    // Serial.print(cos((moving_direction + motor_angle_) * DEG_TO_RAD));
    turn_last_err = turn_err;
}
