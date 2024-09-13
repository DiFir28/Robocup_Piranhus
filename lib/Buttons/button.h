#ifndef _button_H_
#define _button_H_

#include "config.h"

class button 
{
public:
    void init(int pin);
    void init(int pin, void (*func)());

    bool condition;
    short value;

private:
    int pin_;
};

#endif // _button_H_