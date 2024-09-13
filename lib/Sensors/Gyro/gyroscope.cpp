#include "gyroscope.h"

void Gyroscope::init()
{
    Serial.begin(115200);   // Serial monitor
    Serial8.begin(115200);  // Serial GY25
    delay(3000);            // Jeda 3 detik
  // Kalibrasi Tilt
    Serial8.write(0xA5);
    Serial8.write(0x54);
    delay(1000);  // Jeda sebelum kalibrasi heading
  // Kalibrasi Heading
    Serial8.write(0xA5);
    Serial8.write(0x55);
    delay(100);  // Jeda sebelum konfigurasi output
  // Output ASCII
    Serial8.write(0xA5);
    Serial8.write(0x53);
    delay(100);  // Jeda sebentar
}

void Gyroscope::update()
{
    char tmp;  // Variabel temporary
    while (Serial8.available()) {
        tmp = Serial8.read();
        buffer[counter++] = tmp;
        if (tmp == '\n') {                                    // Langkah 1
            buffer[counter] = 0;                      // Karakter terminator
            heading = atof(strtok(buffer + 5, ","));  // Langkah 2-4
            counter = 0;
        }
  }
  delay(1);
  angle = heading;
  Serial.print("Gyro");
  Serial.print(angle);
}