//FormAI DATASET v1.0 Category: Weather simulation ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to simulate weather conditions
void weather_simulation(int season)
{
    int temperature;
    char weather_condition[50];

    // Set temperature based on season
    if (season == 1)    // Winter
    {
        temperature = rand() % 11 - 10;    // Generate random temperature between -10 to 0 degrees Celsius
    }
    else if (season == 2)    // Spring
    {
        temperature = rand() % 16 + 5;    // Generate random temperature between 5 to 20 degrees Celsius
    }
    else if (season == 3)    // Summer
    {
        temperature = rand() % 11 + 20;    // Generate random temperature between 20 to 30 degrees Celsius
    }
    else    // Fall
    {
        temperature = rand() % 11 + 10;    // Generate random temperature between 10 to 20 degrees Celsius
    }

    // Set weather condition based on temperature
    if (temperature < 0)    // Freezing
    {
        sprintf(weather_condition, "Freezing with a temperature of %d degrees Celsius", temperature);
    }
    else if (temperature >= 0 && temperature <= 10)    // Cold
    {
        sprintf(weather_condition, "Cold with a temperature of %d degrees Celsius", temperature);
    }
    else if (temperature >= 11 && temperature <= 20)    // Mild
    {
        sprintf(weather_condition, "Mild with a temperature of %d degrees Celsius", temperature);
    }
    else    // Hot
    {
        sprintf(weather_condition, "Hot with a temperature of %d degrees Celsius", temperature);
    }

    // Print weather condition
    printf("Today's weather condition is %s.\n", weather_condition);
}

int main()
{
    int season;

    // Get current time
    time_t t;
    time(&t);
    srand((unsigned int)t);

    // Generate random season between 1 to 4
    season = rand() % 4 + 1;

    // Simulate weather conditions
    weather_simulation(season);

    return 0;
}