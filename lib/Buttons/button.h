#ifndef _button_H_
#define _button_H_

#include "config.h"


class button 
{
public:
    init(int pin);
    init(int pin, void (*func)());
    void interrupt_callback(void (*func)());


    bool condition;
    short value;

private:
    int pin_;
    
};

#endif // _button_H_