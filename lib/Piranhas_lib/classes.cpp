#include "classes.h"

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

void motor::go(short speed, short direction)
{
    pwm_ = -speed * cos((direction - 90 - motor_angle_) * DEG_TO_RAD);
    digitalWrite(direction_pin1_, pwm_ > 0);
    digitalWrite(direction_pin2_, pwm_ < 0);
    analogWrite(pwm_pin_, abs(pwm_));
}

void Leds::init(int pixeles, int LED_PINL, int LED_PINR)
{
    _pixeles = pixeles;
    _stripL = Adafruit_NeoPixel(_pixeles, LED_PINL, NEO_GRB + NEO_KHZ800);
    _stripR = Adafruit_NeoPixel(_pixeles, LED_PINR, NEO_GRB + NEO_KHZ800);
    _stripL.begin();
    _stripR.begin();
    off();
}

void Leds::off()
{ // выключение всех неопикселей
    for (int i = 0; i < _pixeles; i++)
    {
        _stripL.setPixelColor(i, _stripL.Color(0, 0, 0));
        _stripR.setPixelColor(i, _stripR.Color(0, 0, 0));
        _stripL.show();
        _stripR.show();
    }
}

void Leds::on(int _port, int _red, int _green, int _blue)
{ // включение на конкретнй цвет двух неопикселей с одинаковым индексом
    _stripL.setPixelColor(_port, _stripL.Color(_red, _green, _blue));
    _stripL.show();
    _stripR.setPixelColor(_port, _stripR.Color(_red, _green, _blue));
    _stripR.show();
}

void Leds::colorWipe(int _red, int _green, int _blue, int wait_ms)
{ // анимация цветового ряда
    for (uint16_t i = 0; i < _pixeles; i++)
    {
        on(i, _red, _green, _blue);
        delay(wait_ms);
        off();
    }
}

void gyro::init()
{
    GYRO_SERIAL_.begin(115200);
    delay(3000);

    GYRO_SERIAL_.write(0xA5);
    GYRO_SERIAL_.write(0x54);
    delay(1000);

    GYRO_SERIAL_.write(0xA5);
    GYRO_SERIAL_.write(0x55);
    delay(1000);

    GYRO_SERIAL_.write(0xA5);
    GYRO_SERIAL_.write(0x53);
}

void gyro::update()
{
    GYRO_SERIAL_.write(0XA5);
    GYRO_SERIAL_.write(0X51); // send it for each read
    while (Serial8.available())
    {
        Re_buf[counter] = (unsigned char)GYRO_SERIAL_.read();
        if (counter == 0 && Re_buf[0] != 0xAA)
            return;
        counter++;
        if (counter == 8) // package is complete
        {
            counter = 0;
            if (Re_buf[0] == 0xAA && Re_buf[7] == 0x55) // полученные данны правильны
            {
                angle = (int16_t)(Re_buf[1] << 8 | Re_buf[2]) / 100.00;
            }
        }
    }

    Serial.print(" Gyro: ");
    Serial.println(angle);
}

void IR_sensor::init(int address)
{
    address_ = address;
    Wire.begin();
}

void IR_sensor::update()
{
    Wire.requestFrom(address_, 8);
    int i = 0;
    while (1 < Wire.available()) // organizes the data from the slave in the table
    {
        ball_char[i] = Wire.read(); // receive a byte as character
        i++;
    }
    char *char_link = strchr(ball_char, ',');
    Serial.println(char_link - ball_char);
    char ball_a[4] = "";
    strncpy(char_angle, ball_char, char_link - ball_char);
    angle = atoi(char_angle);

    Serial.print(" ball: ");
    Serial.println(angle);
}