//FormAI DATASET v1.0 Category: Weather simulation ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_DAYS 365
#define MAX_TEMPERATURE 50
#define MIN_TEMPERATURE -20

// Function to generate a random temperature between MIN_TEMPERATURE and MAX_TEMPERATURE.
int generateTemperature() {
    return (rand() % (MAX_TEMPERATURE - MIN_TEMPERATURE + 1)) + MIN_TEMPERATURE;
}

// Main function to run the program.
int main() {
    int temperatures[MAX_DAYS];
    srand(time(NULL)); // Seed the random number generator.
    
    // Generate temperatures for each day.
    for (int i = 0; i < MAX_DAYS; i++) {
        temperatures[i] = generateTemperature();
    }
    
    // Printing daily temperatures.
    printf("Daily temperatures: \n");
    for (int i = 0; i < MAX_DAYS; i++) {
        printf("Day %d: %d degree Celsius\n", i+1, temperatures[i]); 
    }
    
    // Average temperature calculation.
    float avg_temperature = 0;
    for (int i = 0; i < MAX_DAYS; i++) {
        avg_temperature += temperatures[i];
    }
    avg_temperature /= MAX_DAYS;
    printf("\nAverage temperature for the year: %.2f degree Celsius", avg_temperature);
    
    // Extreme temperature checking.
    int highest_temperature = MIN_TEMPERATURE, lowest_temperature = MAX_TEMPERATURE;
    for (int i = 0; i < MAX_DAYS; i++) {
        if (temperatures[i] > highest_temperature) {
            highest_temperature = temperatures[i];
        }
        if (temperatures[i] < lowest_temperature) {
            lowest_temperature = temperatures[i];
        }
    }
    printf("\nHighest temperature for the year: %d degree Celsius", highest_temperature);
    printf("\nLowest temperature for the year: %d degree Celsius", lowest_temperature);
    
    return 0;
}