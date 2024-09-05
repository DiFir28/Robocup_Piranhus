#ifndef _geometry_CPP_
#define _geometry_CPP_

#include "structs.h"



int sign(int num_sign)
{
    return (num_sign > 0) * 2 - 1;
}

extern short between(short first_angle_b, short second_angle_b)
{
    int output = int(first_angle_b - second_angle_b);
    output = (360 - abs(output)) % 180 * (abs(output) > 180) * sign(-output) + !(abs(output) > 180) * output;
    // Serial.println(output);
    return output;
}

line bisector(line first, line second)
{
    line bisector_return;

    bisector_return.angle = (first.angle + second.angle + 360) % 360 / 2 + 180 * (abs(first.angle - second.angle) > 180);
    bisector_return.lenght = 2 * first.lenght * second.lenght * cos(bisector_return.angle / 2 * DEG_TO_RAD) / (first.lenght + second.lenght);

    return bisector_return;
}

line height(line first, line second)
{
    line height_return, third;

    short area = first.lenght * second.lenght * sin(abs(between(first.angle, second.angle)) * DEG_TO_RAD) / 2;
    third.lenght = sqrt(pow(first.lenght, 2) + pow(second.lenght, 2) - 2 * first.lenght * second.lenght * cos(abs(between(first.angle, second.angle)) * DEG_TO_RAD));
    height_return.lenght = area / third.lenght;
    height_return.angle = max(first.angle, second.angle) - abs(acos(height_return.lenght / first.lenght) * RAD_TO_DEG);

    return height_return;
}

line median(line first, line second)
{
    line median_return, third;

    third.lenght = sqrt(pow(first.lenght, 2) + pow(second.lenght, 2) - 2 * first.lenght * second.lenght * cos(abs(between(first.angle, second.angle)) * DEG_TO_RAD));
    median_return.lenght = sqrt(2 * (first.lenght + second.lenght) - third.lenght) / 2;
    median_return.angle = max(first.angle, second.angle) - abs(acos(((pow(median_return.lenght, 2) + pow(second.lenght, 2) - pow(third.lenght / 2, 2)) / 2 * first.lenght * second.lenght) * DEG_TO_RAD) * RAD_TO_DEG);

    return median_return;
}



 #endif
