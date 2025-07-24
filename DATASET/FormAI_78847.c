//FormAI DATASET v1.0 Category: Weather simulation ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int numDays, temperature;
    float averageTemp = 0;
    time_t t;
    srand((unsigned) time(&t)); // generate a random seed

    printf("Welcome to the Weather Simulator!\n");
    printf("How many days of weather data would you like to simulate? ");
    scanf("%d", &numDays);

    printf("\n");

    for (int i = 1; i <= numDays; i++) {
        temperature = rand() % 50 - 20; // generate a random temperature between -20 and 30
        averageTemp += temperature; // accumulate temperature for calculating average
        
        printf("Day %d: %d degrees\n", i, temperature);
    }

    averageTemp /= numDays; // calculate average temperature

    printf("\n");
    printf("Average temperature over %d days: %.2f degrees", numDays, averageTemp);

    return 0;
}