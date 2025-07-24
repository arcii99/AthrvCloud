//FormAI DATASET v1.0 Category: Weather simulation ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int temp[24], i, j, sum=0, average;
    srand(time(0));

    // Generate random temperatures for 24-hour period
    for (i=0; i<24; i++)
    {
        temp[i] = (rand() % (40 - 10 + 1)) + 10; // Random temperature between 10 C - 40 C
        printf("Hour %d temperature: %d C\n", i+1, temp[i]);
        sum += temp[i];
    }

    // Calculate average temperature for 24-hour period
    average = sum/24;

    // Determine if there is a heatwave or cold snap
    for (j=0; j<24; j++)
    {
        if (temp[j] < average)
        {
            printf("Warning: Cold snap detected at hour %d. Temperature dropped below average.\n", j+1);
        }
        else if (temp[j] > average)
        {
            printf("Warning: Heatwave detected at hour %d. Temperature rose above average.\n", j+1);
        }
    }

    return 0;
}