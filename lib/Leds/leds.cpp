#include "leds.h"


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

void Leds::colorWipe(int _red, int _green, int _blue, unsigned long wait_ms)
{ // анимация цветового ряда
    off();
    on((i + 3) % 4, _red * last / 100, _green * last / 100, _blue * last / 100);
    on(i, _red * first / 100, _green * first / 100, _blue * first / 100);
    if (time_last_change - millis() >= wait_ms)
    {
        i = (i + 1) % 4;
        time_last_change = millis();
        first = 0;
        last = 100;
    }
    last = 100 - 100 * (time_last_change - millis()) / wait_ms;
    first = 100 * (time_last_change - millis()) / wait_ms;
}

