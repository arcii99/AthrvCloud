//FormAI DATASET v1.0 Category: Weather simulation ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int temperature[24];
    int i, totalTemp = 0;
    double avgTemp;

    srand(time(0)); // use time as seed for random number generator

    printf("Hour\tTemperature (C)\n");

    // generate random temperature for each hour of the day
    for (i = 0; i < 24; i++)
    {
        temperature[i] = rand() % 20 + 10; // temperature range from 10C to 30C
        printf("%d\t%d\n", i, temperature[i]);
        totalTemp += temperature[i]; // calculate total temperature for the day
    }

    avgTemp = (double)totalTemp / 24; // calculate average temperature for the day

    printf("\nAverage temperature for the day: %.2fC\n", avgTemp);

    if (avgTemp >= 25)
    {
        printf("It is hot today. Please stay hydrated and wear light clothes.\n");
    }
    else if (avgTemp >= 15 && avgTemp < 25)
    {
        printf("It is pleasant today. Enjoy the weather!\n");
    }
    else
    {
        printf("It is cold today. Please wear warm clothes and stay indoors if possible.\n");
    }

    return 0;
}