//FormAI DATASET v1.0 Category: Weather simulation ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main()
{
    srand(time(NULL)); //seed for random number generation
    int temperature = (rand() % 40) - 10; //ranges from -10°C to 30°C
    int humidity = rand() % 101; //ranges from 0 to 100%
    int windSpeed = rand() % 61; //ranges from 0 to 60 km/h

    char weatherType[16]; //maximum characters for each weather type
    int randNum = rand() % 4;

    //assign weather types based on random number generated
    if(randNum == 0)
        strcpy(weatherType, "Sunshine");
    else if(randNum == 1)
        strcpy(weatherType, "Cloudy");
    else if(randNum == 2)
        strcpy(weatherType, "Rain");
    else if(randNum == 3)
        strcpy(weatherType, "Snow");

    //print out weather simulation details
    printf("Today's weather simulation:\n");
    printf("Temperature: %d \370C\n", temperature); //\370 is the degree symbol in ASCII
    printf("Humidity: %d %%\n", humidity);
    printf("Wind speed: %d km/h\n", windSpeed);
    printf("Weather type: %s\n", weatherType);

    return 0;
}