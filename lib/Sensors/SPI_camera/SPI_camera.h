#ifndef _SPI_camera_H_
#define _SPI_camera_H_
#include <SPI.h>

#include "config.h"
#include "geometry.h"
#include "structs.h"

//----------------------------------------------------------------

class spi_camera
{
public:
    void init();
    void update();
    void coords_find(int, bool); //0 - синие, 1 - жёлтые
    int goal_ans[2];
    coords crds;
private:
    int perf_ang[3];
};

#endif // _SPI_H_