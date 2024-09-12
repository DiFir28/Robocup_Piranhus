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

};

#endif // _SPI_H_