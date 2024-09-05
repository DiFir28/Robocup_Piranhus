#ifndef _leds_H_
#define _leds_H_

#include "Adafruit_NeoPixel.h"
// #include "geometry.h"

class Leds
{
public:
    void init(int pixeles, int LED_PINL, int LED_PINR);
    void off();
    void on(int _port, int _red, int _green, int _blue);
    void colorWipe(int _red, int _green, int _blue, unsigned long wait_ms);

private:
    int i = 0;
    unsigned long time_last_change = 0;
    int first = 100;
    int last = 0;
    int _pixeles;
    Adafruit_NeoPixel _stripL;
    Adafruit_NeoPixel _stripR;
};

#endif // _leds_H_