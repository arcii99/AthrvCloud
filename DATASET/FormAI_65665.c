//FormAI DATASET v1.0 Category: Weather simulation ; Style: configurable
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

// Configurable Parameters
#define MAX_DAYS 30
#define MAX_TEMPERATURE 50
#define MIN_TEMPERATURE 0

int main() {
    // Seed the random number generator
    srand(time(0)); 

    // Generate temperature data for each day in the month
    int temperatures[MAX_DAYS];
    for(int i = 0; i < MAX_DAYS; i++) {
        temperatures[i] = rand() % (MAX_TEMPERATURE - MIN_TEMPERATURE + 1) + MIN_TEMPERATURE;
    }

    // Print out the temperature data
    printf("Temperature Data for the Month:\n\n");
    for(int i = 0; i < MAX_DAYS; i++) {
        printf("Day %d: %d degrees Celsius\n", i+1, temperatures[i]);
    }

    // Find the highest and lowest temperatures for the month
    int highest_temperature = MIN_TEMPERATURE;
    int lowest_temperature = MAX_TEMPERATURE;
    for(int i = 0; i < MAX_DAYS; i++) {
        if(temperatures[i] > highest_temperature) {
            highest_temperature = temperatures[i];
        }

        if(temperatures[i] < lowest_temperature) {
            lowest_temperature = temperatures[i];
        }
    }

    // Print out the highest and lowest temperatures for the month
    printf("\nHighest Temperature for the Month: %d degrees Celsius\n", highest_temperature);
    printf("Lowest Temperature for the Month: %d degrees Celsius\n", lowest_temperature);

    return 0;
}