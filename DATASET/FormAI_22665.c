//FormAI DATASET v1.0 Category: Weather simulation ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_DAYS 30
#define MAX_TEMP 100
#define MIN_TEMP 0

int main() {
    int temps[NUM_DAYS];
    int i;
    int total_temp = 0;

    // Seed random number generator
    srand(time(NULL));

    // Generate random temperature for each day
    for (i = 0; i < NUM_DAYS; i++) {
        temps[i] = rand() % (MAX_TEMP - MIN_TEMP + 1) + MIN_TEMP;
        total_temp += temps[i];
    }

    // Calculate average temperature
    float avg_temp = (float)total_temp / NUM_DAYS;

    // Calculate standard deviation of temperature
    float std_dev = 0;
    for (i = 0; i < NUM_DAYS; i++) {
        std_dev += (temps[i] - avg_temp) * (temps[i] - avg_temp);
    }
    std_dev /= NUM_DAYS;
    std_dev = sqrt(std_dev);

    // Print simulation results
    printf("30 day weather simulation\n");
    printf("-------------------------\n");
    printf("Average temperature: %.2f degrees Fahrenheit\n", avg_temp);
    printf("Standard deviation: %.2f degrees Fahrenheit\n", std_dev);
    printf("Temperatures by day:\n");
    for (i = 0; i < NUM_DAYS; i++) {
        printf("Day %2d: %2d degrees Fahrenheit\n", i+1, temps[i]);
    }
    return 0;
}