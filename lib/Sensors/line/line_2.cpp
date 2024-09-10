#include "line_2.h"

void lisenses::init()
{
    for (short ili = 0; ili < 3; ili++)
    {
        pinMode(controlPin[ili], OUTPUT);
    }
    for (short ili = 0; ili < 4; ili++)
    {
        pinMode(slavPins[ili], INPUT);
    }

    for (short ili = 0; ili < 32; ili++)
    {
        line_sensors[ili].value = 0;
        line_sensors[ili].bool_value = false;
        if (ili > 16)
        {
            line_sensors[ili].vector.angle = -all_angles[32 - ili];
        }
        else
        {
            line_sensors[ili].vector.angle = all_angles[ili];
        }

        if (min(abs(ili - 32), abs(ili)) <= 1)
        {
            line_sensors[ili].vector.lenght = all_len[min(abs(ili - 32), abs(ili))];
        }
        else
        {
            line_sensors[ili].vector.lenght = all_len[2];
        }
    }
}

void lisenses::setConfigurate(int conf)
{
    for (int conf_i = 2; conf_i > -1; conf_i--)
    {
        digitalWrite(controlPin[conf_i], (conf >= pow(2, conf_i)));
        conf = conf - pow(2, conf_i) * (conf >= pow(2, conf_i));
    }
}

void lisenses::read_line()
{
    ret_i = 0;

 

    for (int c = 0; c < 8; c++)
    {
        setConfigurate(c);
       delay(1);
        for (int step = 0; step < 4; step++)
        {
            line_sensors[step * 8 + c].value += int(0.95 * (analogRead(slavPins[step]) - line_sensors[step * 8 + c].value));
            line_sensors[step * 8 + c].bool_value = (line_sensors[step * 8 + c].value > line_sensors[step * 8 + c].threshold_value);
            
            if (line_sensors[step * 8 + c].bool_value)
            {
                livectors[ret_i]= line_sensors[step * 8 + c].vector;
            }
            ret_i += line_sensors[step * 8 + c].bool_value;

            // for (int i = 0; i < 32; i++)
            // {
            //     Serial.print(line_sensors[i].vector.angle);
            //     Serial.print(", ");
            //     Serial.print(line_sensors[i].vector.lenght);
            //     Serial.print(", ");
            //     Serial.print(line_sensors[i].value);
            //     Serial.print("/");
            // }
            // Serial.println("}");
        }
    }
    Serial.print("End ");
}

line lisenses::get_line()
{
    line ret;

    int lisin = 0;
    int licos = 0;
    Serial.print(ret_i);
    Serial.print(" ");
  
    for (int i = 0; i < ret_i; i++)
    {

        lisin += sin(livectors[i].angle * DEG_TO_RAD) * livectors[i].lenght;
        licos += cos(livectors[i].angle * DEG_TO_RAD) * livectors[i].lenght;
    }
    Serial.print(lisin);
    Serial.print(" ");
    Serial.print(licos);
    Serial.print(" ");
    ret.angle = (atan2((lisin), (licos)) * DEG_TO_RAD);
    ret.lenght = sqrt(lisin * lisin + licos * licos) / ret_i;
    Serial.print(ret.angle);
    Serial.print(" ");    
    Serial.print(ret.lenght);
    Serial.print(" ");
    return ret;
}

void lisenses::update()
{
    read_line();
    line a = get_line();


     delay(3);
}
