//FormAI DATASET v1.0 Category: Weather simulation ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DAYS_IN_MONTH 30
#define MIN_TEMP -10
#define MAX_TEMP 50

int main() {
    srand(time(NULL));
    int temp[DAYS_IN_MONTH];
    int total_temp = 0, avg_temp = 0, highest_temp = 0, lowest_temp = 0;

    // Generate random temperatures for the month
    for(int i=0; i<DAYS_IN_MONTH; i++) {
        temp[i] = rand() % (MAX_TEMP - MIN_TEMP) + MIN_TEMP;
        total_temp += temp[i];

        // Check for highest and lowest temperature
        if(temp[i] > highest_temp) {
            highest_temp = temp[i];
        }
        if(temp[i] < lowest_temp) {
            lowest_temp = temp[i];
        }
    }

    // Calculate average temperature for the month
    avg_temp = total_temp / DAYS_IN_MONTH;

    // Display the weather simulation results
    printf("Weather Simulation for the Month of January:\n");
    printf("------------------------------------------------\n");
    printf("Average Temperature:\t%d deg Celsius\n", avg_temp);
    printf("Highest Temperature:\t%d deg Celsius\n", highest_temp);
    printf("Lowest Temperature:\t%d deg Celsius\n", lowest_temp);
    printf("Temperature for each day:\n");
    for(int i=0; i<DAYS_IN_MONTH; i++) {
        printf("Day %d:\t\t\t%d deg Celsius\n", i+1, temp[i]);
    }

    return 0;
}