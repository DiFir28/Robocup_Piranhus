#ifndef _classes_H_
#define _classes_H_

#include "config.h"
#include "Wire.h"
#include "Adafruit_NeoPixel.h"

class motor
{

public:
    void init(int direction_pin1, int direction_pin2, int pwm_pin, int wheel_angle);
    void go(short speed, short direction);

    float acceleration_s = 0.2;

    short pwm_ = 0;
    short speed_ = 0;
    unsigned long time_last_change = 0;

private:
    int direction_pin1_;
    int direction_pin2_;
    int pwm_pin_;
    int motor_angle_;
};

class Leds
{

public:
    void init(int pixeles, int LED_PINL, int LED_PINR);
    void off();
    void on(int _port, int _red, int _green, int _blue);
    void colorWipe(int _red, int _green, int _blue, int wait_ms);

private:
    int _pixeles;
    Adafruit_NeoPixel _stripL;
    Adafruit_NeoPixel _stripR;
};

class gyro
{

public:
    void init();
    void update();
    float angle;

private:
    unsigned char Re_buf[8], counter = 0;
};

class IR_sensor
{

public:
    void init(int);
    void update();
    float angle;
    int address_;

    char char_angle, ball_char[10];

private:
    
};

class Sensors
{

public:
private:
};

#endif