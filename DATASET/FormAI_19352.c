//FormAI DATASET v1.0 Category: Weather simulation ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TEMPERATURE_RANGE 50 // Range of temperature in Celsius
#define PRESSURE_RANGE 20 // Range of pressure in kPa

int main()
{
    srand(time(NULL)); // Seed for random number generation

    float temperature, pressure;

    // Generating random values of temperature and pressure within range
    temperature = ((float)rand() / RAND_MAX) * TEMPERATURE_RANGE;
    pressure = ((float)rand() / RAND_MAX) * PRESSURE_RANGE;

    printf("Current weather conditions:\n");
    printf("Temperature: %.2f C\n", temperature);
    printf("Pressure: %.2f kPa\n", pressure);

    // Checking if the temperature is too high or too low
    if (temperature < 0)
    {
        printf("Warning! Temperature below freezing point.\n");
    }
    else if (temperature > 40)
    {
        printf("Warning! Temperature above human tolerance.\n");
    }

    // Checking if the pressure is too high or too low
    if (pressure < 80)
    {
        printf("Warning! Low pressure can cause health problems.\n");
    }
    else if (pressure > 120)
    {
        printf("Warning! High pressure can cause health problems.\n");
    }

    return 0;
}