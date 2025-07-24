//FormAI DATASET v1.0 Category: Weather simulation ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL)); // Initialize random seed

    int temperature = (rand() % 101) - 50; // Generate a random temperature between -50°C to 50°C
    int humidity = rand() % 101; // Generate a random humidity value between 0% to 100%
    int precipitation = rand() % 101; // Generate a random precipitation value between 0% to 100%
    
    printf("***** CYBERPUNK WEATHER SIMULATION *****\n\n");
    printf("Today's temperature is: %d°C\n", temperature);
    
    if (temperature >= 35)
    {
        printf("Warning! Extreme heat detected.\n");
    }
    else if (temperature >= 25)
    {
        printf("Hot weather detected.\n");
    }
    else if (temperature >= 10)
    {
        printf("Mild weather detected.\n");
    }
    else if (temperature >= 0)
    {
        printf("Cold weather detected.\n");
    }
    else
    {
        printf("Warning! Extreme cold detected.\n");
    }
    
    printf("Today's humidity is: %d%%\n", humidity);
    
    if (humidity >= 70)
    {
        printf("Warning! High humidity detected.\n");
    }
    else if (humidity >= 40)
    {
        printf("Normal humidity detected.\n");
    }
    else
    {
        printf("Warning! Low humidity detected.\n");
    }
    
    printf("Today's precipitation is: %d%%\n", precipitation);
    
    if (precipitation >= 70)
    {
        printf("Warning! Heavy rain detected.\n");
    }
    else if (precipitation >= 40)
    {
        printf("Normal rainfall detected.\n");
    }
    else if (precipitation >= 20)
    {
        printf("Light rainfall detected.\n");
    }
    else if (precipitation >= 10)
    {
        printf("Chance of drizzle.\n");
    }
    else
    {
        printf("Dry weather detected.\n");
    }
    
    return 0;
}