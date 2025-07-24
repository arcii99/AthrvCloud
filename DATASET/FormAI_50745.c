//FormAI DATASET v1.0 Category: Weather simulation ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(0)); // initialize random seed
    
    float temperature = 25.0; // starting temperature
    float humidity = 60.0; // starting humidity
    float wind_speed = 5.0; // starting wind speed
    float sunshine_hours = 8.0; // starting sunshine hours
    float precipitation = 0.0; // starting precipitation
    int day_count = 1; // starting day count
    
    printf("Welcome to the Weather Simulation Program!\n\n");
    
    // run simulation for 365 days
    for (int i = 1; i <= 365; i++)
    {
        printf("Day %d:\n", day_count);
        printf("Temperature: %.1f°C\n", temperature);
        printf("Humidity: %.1f%%\n", humidity);
        printf("Wind Speed: %.1f mph\n", wind_speed);
        printf("Sunshine Hours: %.1f hours\n", sunshine_hours);
        printf("Precipitation: %.1f mm\n", precipitation);
        
        // update weather conditions for the day
        temperature += (float)(rand() % 11 - 5) / 10; // temperature change between -0.5°C to 0.5°C
        humidity += (float)(rand() % 21 - 10) / 10; // humidity change between -1% to 1%
        wind_speed += (float)(rand() % 11 - 5) / 10; // wind speed change between -0.5 mph to 0.5 mph
        
        // calculate sunshine hours and precipitation
        if (temperature >= 20.0 && humidity <= 80.0 && wind_speed <= 8.0)
        {
            sunshine_hours += (float)(rand() % 2 + 1) / 2; // random increase in sunshine hours between 0.5 to 1.5 hours
            precipitation += (float)(rand() % 6) / 10; // random precipitation between 0.0 to 0.5 mm
        }
        else
        {
            sunshine_hours -= (float)(rand() % 2 + 1) / 2; // random decrease in sunshine hours between 0.5 to 1.5 hours
            precipitation += (float)(rand() % 11) / 10; // random precipitation between 0.0 to 1.0 mm
        }
        
        // keep weather conditions within reasonable limits
        if (temperature < -10.0) temperature = -10.0;
        if (temperature > 40.0) temperature = 40.0;
        if (humidity < 20.0) humidity = 20.0;
        if (humidity > 100.0) humidity = 100.0;
        if (wind_speed < 0.0) wind_speed = 0.0;
        if (sunshine_hours < 0.0) sunshine_hours = 0.0;
        if (precipitation < 0.0) precipitation = 0.0;
        
        day_count++; // increment day count
        printf("\n");
    }
    
    printf("Thank you for using the Weather Simulation Program!\n");
    
    return 0;
}