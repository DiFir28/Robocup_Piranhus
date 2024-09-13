#include "button.h"

void button::init(int pin, void (*func)())
{
    pinMode(pin, INPUT_PULLUP);
    attachInterrupt(digitalPinToInterrupt(pin), func, LOW);
}

void button::init(int pin)
{
    pinMode(pin, INPUT_PULLUP);
}
