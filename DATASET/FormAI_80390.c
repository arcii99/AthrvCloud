//FormAI DATASET v1.0 Category: Weather simulation ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MIN_TEMP 10 // minimum temperature in Celsius
#define MAX_TEMP 40 // maximum temperature in Celsius
#define DAYS 7 // number of days to simulate
#define HOURS 24 // number of hours in a day

int main() {
    srand(time(NULL)); // seed random number generator
    int temperatures[DAYS][HOURS]; // array to store temperatures
    
    // generate random temperatures for each hour in each day
    for (int i = 0; i < DAYS; i++) {
        for (int j = 0; j < HOURS; j++) {
            int temp = rand() % (MAX_TEMP - MIN_TEMP + 1) + MIN_TEMP;
            temperatures[i][j] = temp;
        }
    }
    
    // print temperatures for each day
    for (int i = 0; i < DAYS; i++) {
        printf("Temperatures for day %d:\n", i+1);
        for (int j = 0; j < HOURS; j++) {
            printf("%02d:00: %d°C\n", j, temperatures[i][j]);
        }
        printf("\n");
    }
    
    // calculate average temperature for each day
    for (int i = 0; i < DAYS; i++) {
        int sum = 0;
        for (int j = 0; j < HOURS; j++) {
            sum += temperatures[i][j];
        }
        int average = sum / HOURS;
        printf("Average temperature for day %d: %d°C\n", i+1, average);
    }
    
    // calculate overall average temperature for the week
    int overall_sum = 0;
    for (int i = 0; i < DAYS; i++) {
        for (int j = 0; j < HOURS; j++) {
            overall_sum += temperatures[i][j];
        }
    }
    int overall_average = overall_sum / (DAYS*HOURS);
    printf("Overall average temperature for the week: %d°C\n", overall_average);
    
    return 0;
}