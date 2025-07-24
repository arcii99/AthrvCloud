//FormAI DATASET v1.0 Category: Weather simulation ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define MIN_TEMP 0   // minimum temperature
#define MAX_TEMP 40  // maximum temperature
#define MIN_WIND 0   // minimum wind speed
#define MAX_WIND 100 // maximum wind speed
#define MIN_HUM 0    // minimum humidity
#define MAX_HUM 100  // maximum humidity

int main()
{
    srand(time(NULL)); // initialize random seed

    int temp = rand() % (MAX_TEMP - MIN_TEMP + 1) + MIN_TEMP; // generate random temperature within range
    int wind = rand() % (MAX_WIND - MIN_WIND + 1) + MIN_WIND; // generate random wind speed within range
    int hum = rand() % (MAX_HUM - MIN_HUM + 1) + MIN_HUM;     // generate random humidity within range
    bool is_raining = rand() % 2;                             // randomly determine if it's raining or not

    printf("Current temperature: %d C\n", temp);
    printf("Current wind speed: %d km/h\n", wind);
    printf("Current humidity: %d %%\n", hum);

    if (is_raining)
    {
        printf("It's currently raining.\n");
        if (temp < 0)
        {
            printf("It's freezing rain.\n");
        }
    }
    else
    {
        printf("It's not currently raining.\n");
    }

    if (temp < 0 && wind > 0)
    {
        printf("It's currently snowing.\n");
    }
    else if (temp >= 0 && temp < 20)
    {
        printf("It's currently a cool day.\n");
    }
    else if (temp >= 20 && temp < 30)
    {
        printf("It's currently a warm day.\n");
    }
    else
    {
        printf("It's currently a hot day.\n");
    }

    if (hum < 30)
    {
        printf("The air is dry.\n");
    }
    else if (hum >= 30 && hum < 60)
    {
        printf("The air is normal.\n");
    }
    else
    {
        printf("The air is humid.\n");
    }

    return 0;
}