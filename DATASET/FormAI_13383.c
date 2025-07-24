//FormAI DATASET v1.0 Category: Temperature monitor ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

float get_temperature_reading(void);
void check_temperature(float temperature_reading);

int main(void)
{
    float temperature_reading;
    
    while (1)
    {
        temperature_reading = get_temperature_reading();
        check_temperature(temperature_reading);
    }
    
    return 0;
}

float get_temperature_reading(void)
{
    float temperature;
    
    // Generate random temperature between -10°C and 40°C
    temperature = ((float)rand()/(float)(RAND_MAX)) * 50 - 10;
    
    return temperature;
}

void check_temperature(float temperature_reading)
{
    if (temperature_reading < 0)
    {
        printf("Temperature is below freezing point!\n");
    }
    else if (temperature_reading >= 0 && temperature_reading < 10)
    {
        printf("Temperature is chilly.\n");
    }
    else if (temperature_reading >= 10 && temperature_reading < 20)
    {
        printf("Temperature is cool.\n");
    }
    else if (temperature_reading >= 20 && temperature_reading < 30)
    {
        printf("Temperature is warm.\n");
    }
    else if (temperature_reading >= 30 && temperature_reading < 40)
    {
        printf("Temperature is hot.\n");
    }
    else
    {
        printf("Temperature is scorching!\n");
    }
}