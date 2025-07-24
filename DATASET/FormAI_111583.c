//FormAI DATASET v1.0 Category: Smart home automation ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int temperature = 25;
    int humidity = 50;
    int light_status = 0;
    int AC_status = 0;

    srand(time(NULL));
    int rand_temp_change = rand() % 3 - 1; // generates random number between -1 to 1

    temperature += rand_temp_change; // randomly increase/decrease temperature

    if (temperature > 28)
    {
        AC_status = 1;
    }
    else if (temperature < 22)
    {
        AC_status = 2;
    }
    else
    {
        AC_status = 0;
    }

    if (humidity < 40)
    {
        printf("Humidity is below desired level. Turning on humidifier.\n");
    }

    if (rand() % 2 == 0)
    {
        printf("Someone has entered the room. Turning on lights.\n");
        light_status = 1;
    }
    else
    {
        printf("No one is in the room. Turning off lights.\n");
        light_status = 0;
    }

    if (AC_status == 1)
    {
        printf("Temperature is too high. AC turned on to cool down the room.\n");
    }
    else if (AC_status == 2)
    {
        printf("Temperature is too low. AC turned on to heat up the room.\n");
    }
    else
    {
        printf("Temperature is within desired range. AC turned off.\n");
    }

    return 0;
}