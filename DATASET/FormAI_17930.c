//FormAI DATASET v1.0 Category: Weather simulation ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MIN_TEMP -10 // minimum temperature in Celsius
#define MAX_TEMP 30  // maximum temperature in Celsius
#define MAX_DIFF 5   // maximum temperature difference between day and night
#define DAYS 7       // number of days to simulate

// function to generate random temperature for day and night
void generateTemperature(int *dayTemp, int *nightTemp)
{
    int randTemp = (rand() % (MAX_TEMP - MIN_TEMP + 1)) + MIN_TEMP;
    *dayTemp = randTemp - (rand() % MAX_DIFF + 1);
    *nightTemp = randTemp + (rand() % MAX_DIFF + 1);
}

// function to display temperature data for a given day
void displayTemperature(int day, int dayTemp, int nightTemp)
{
    printf("Day %d:\n", day);
    printf("Daytime temperature: %d degrees Celsius\n", dayTemp);
    printf("Nighttime temperature: %d degrees Celsius\n", nightTemp);
}

int main()
{
    srand(time(NULL)); // seed the random number generator with current time

    int dayTemperature[DAYS];
    int nightTemperature[DAYS];

    for (int i = 0; i < DAYS; i++)
    {
        generateTemperature(&dayTemperature[i], &nightTemperature[i]);
        displayTemperature(i + 1, dayTemperature[i], nightTemperature[i]);
    }

    return 0;
}