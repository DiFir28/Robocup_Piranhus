#include "config.h"


class button 
{
public:
    init(int pin);
    void interrupt_callback();

    bool condition;
    short value;

private:
    int pin_;
    
};