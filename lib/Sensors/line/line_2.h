#include "config.h"
#include "structs.h"
#include "geometry.h"

class lisenses
{
public:
    void init();
    void setConfigurate(int conf);

    void update();
    void read_line();
    line get_line();

private:
    int ret_i = 0;
    short controlPin[3] = {9, 8, 7};
    short slavPins[4] = {24, 25, 26, 27};
    struct lisens line_sensors[32];
    std::vector<line> livectors;
    short all_angles[16]={7, 24, 31, 42, 53, 64, 75, 86, 97, 108, 119, 130, 141,152, 163, 174};
    short all_len[16]={73, 90,103}; 
};