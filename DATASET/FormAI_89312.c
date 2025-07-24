//FormAI DATASET v1.0 Category: Weather simulation ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_DAYS 7
#define NUM_HOURS 24
#define MAX_TEMP 100
#define MIN_TEMP -100

int main()
{
    srand(time(NULL)); // seed the random number generator with current time
    int temperatures[NUM_DAYS][NUM_HOURS];
    
    // Generate random temperatures for each hour of each day
    for(int i = 0; i < NUM_DAYS; i++)
    {
        for(int j = 0; j < NUM_HOURS; j++)
        {
            temperatures[i][j] = (rand() % (MAX_TEMP - MIN_TEMP + 1)) + MIN_TEMP;
        }
    }
    
    // Print average temperature for each day
    int totalTemp, averageTemp;
    printf("Average temperatures for each day:\n");
    for(int i = 0; i < NUM_DAYS; i++)
    {
        totalTemp = 0;
        for(int j = 0; j < NUM_HOURS; j++)
        {
            totalTemp += temperatures[i][j];
        }
        averageTemp = totalTemp / NUM_HOURS;
        printf("Day %d: %d\n", i+1, averageTemp);
    }
    
    // Print temperature change percentage from previous hour for each hour of each day
    int changePerc;
    printf("Temperature change percentage from previous hour:\n");
    for(int i = 0; i < NUM_DAYS; i++)
    {
        for(int j = 1; j < NUM_HOURS; j++)
        {
            changePerc = ((double)(temperatures[i][j]-temperatures[i][j-1])/temperatures[i][j-1]) * 100;
            printf("Day %d, Hour %d: %d%%\n", i+1, j, changePerc);
        }
    }
    return 0;
}