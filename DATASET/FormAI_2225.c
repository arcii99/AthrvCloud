//FormAI DATASET v1.0 Category: Weather simulation ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_DAYS 7
#define NUM_HOURS 24
#define NUM_REGIONS 5
#define TEMP_RANGE 30

int main()
{
    // Seed the random number generator
    srand((unsigned) time(NULL));

    // Initialize arrays to store weather data
    int temperature[NUM_DAYS][NUM_HOURS][NUM_REGIONS];
    int precipitation[NUM_DAYS][NUM_HOURS][NUM_REGIONS];

    // Simulate weather for each day
    for (int day = 0; day < NUM_DAYS; day++)
    {
        // Simulate weather for each hour
        for (int hour = 0; hour < NUM_HOURS; hour++)
        {
            // Simulate weather for each region
            for (int region = 0; region < NUM_REGIONS; region++)
            {
                // Generate temperature for each region
                int temp = rand() % TEMP_RANGE;
                
                // If temperature falls below a certain threshold in a region, simulate rainfall
                if (temp <= 10) {
                    precipitation[day][hour][region] = rand() % 30;
                } 
                else if (temp <= 20) {
                    precipitation[day][hour][region] = rand() % 10;
                }
                else {
                    precipitation[day][hour][region] = 0;
                }
                
                temperature[day][hour][region] = temp;
            }
            printf("\nDay %d, Hour %d", day+1, hour+1);
            for (int region = 0; region < NUM_REGIONS; region++)
            {
                printf("\nRegion %d:\nTemperature: %d C\tPrecipitation: %d mm", 
                       region+1, temperature[day][hour][region], precipitation[day][hour][region]);
            }
        }
    }
    return 0;
}