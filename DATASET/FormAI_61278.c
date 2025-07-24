//FormAI DATASET v1.0 Category: Weather simulation ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_DAYS 30
#define MAX_TEMP 35
#define MIN_TEMP 5
#define MAX_CHANGE 6

void printTemperature(int day, int temperature);

int main()
{
    int temperatures[NUM_DAYS];
    srand(time(NULL)); // Initialize random seed

    // Generate random starting temperature
    int currentTemp = (rand() % (MAX_TEMP - MIN_TEMP + 1)) + MIN_TEMP;
    temperatures[0] = currentTemp;
    printTemperature(1, currentTemp); // Print temperature for day 1

    // Generate temperature for other days
    for (int i = 1; i < NUM_DAYS; i++)
    {
        int tempChange = (rand() % (MAX_CHANGE * 2 + 1)) - MAX_CHANGE; // Generate random temperature change
        currentTemp += tempChange; // Update current temperature
        
        // Ensure temperature remains within range
        if (currentTemp > MAX_TEMP)
        {
            currentTemp = MAX_TEMP;
        }
        else if (currentTemp < MIN_TEMP)
        {
            currentTemp = MIN_TEMP;
        }

        temperatures[i] = currentTemp; // Save temperature for current day
        printTemperature(i+1, currentTemp); // Print temperature for current day
    }

    // Print average temperature for the month
    int sumTemp = 0;
    for (int i = 0; i < NUM_DAYS; i++)
    {
        sumTemp += temperatures[i];
    }
    float averageTemp = (float)sumTemp / NUM_DAYS;

    printf("\n=======================");
    printf("\nAverage temperature: %.1f degrees Celsius\n", averageTemp);

    return 0;
}

void printTemperature(int day, int temperature)
{
    printf("Day %2d: ", day);

    for (int i = 0; i < temperature; i++)
    {
        printf("*");
    }

    printf(" %2dC\n", temperature);
}