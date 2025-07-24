//FormAI DATASET v1.0 Category: Weather simulation ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_DAYS 7
#define MAX_TEMP 100
#define MIN_TEMP 0

int main()
{
    srand(time(NULL)); // seed random number generator with time
    int temps[NUM_DAYS];
    int total = 0;
    int max_temp = MIN_TEMP;
    int min_temp = MAX_TEMP;

    // generate random temperatures for each day
    for (int i = 0; i < NUM_DAYS; i++)
    {
        temps[i] = rand() % (MAX_TEMP - MIN_TEMP + 1) + MIN_TEMP;
        printf("Day %d: %d\n", i+1, temps[i]);

        // update max and min temps
        if (temps[i] > max_temp)
        {
            max_temp = temps[i];
        }
        if (temps[i] < min_temp)
        {
            min_temp = temps[i];
        }

        total += temps[i]; // update total temp for week
    }

    printf("Maximum temperature of the week: %d\n", max_temp);
    printf("Minimum temperature of the week: %d\n", min_temp);
    printf("Average temperature of the week: %d\n", total / NUM_DAYS);

    printf("\nWeather forecast for next week:\n");

    // simulate weather for next week based on current week's temps
    for (int i = 0; i < NUM_DAYS; i++)
    {
        int variation = rand() % (10 + 1 - (-10)) + (-10); // generate random variation between -10 and 10
        int forecast = temps[i] + variation;

        // check if forecasted temp is outside of range
        if (forecast > MAX_TEMP)
        {
            forecast = MAX_TEMP;
        }
        else if (forecast < MIN_TEMP)
        {
            forecast = MIN_TEMP;
        }

        printf("Day %d: %d\n", i+1, forecast);
    }

    return 0;
}