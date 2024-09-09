#ifndef _SPI_H_
#define _SPI_H_

#include "config.h"
#include <SPI.h>

//----------------------------------------------------------------

class camera
{
public:
    void init();
    void read_data_from_camera();
    char buff[128];
private:
    int SS_PIN = 10;
    int BAUD_RATE = 19200;
    int CHAR_BUFF = 128;

};

#endif // _SPI_H_