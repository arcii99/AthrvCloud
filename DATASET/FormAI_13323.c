//FormAI DATASET v1.0 Category: Weather simulation ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_DAYS 31
#define MAX_TEMPERATURE 100
#define MIN_TEMPERATURE -50

int main(void) {
    srand(time(NULL)); // seed random number generator with current time

    int temperatures[MAX_DAYS]; // array to store daily temperatures
    int sum_temperature = 0; // variable to store sum of daily temperatures
    int max_temperature = MIN_TEMPERATURE; // variable to store maximum temperature
    int min_temperature = MAX_TEMPERATURE; // variable to store minimum temperature

    // generate temperatures for each day in the month
    for(int day = 1; day <= MAX_DAYS; day++) {
        int temperature = rand() % (MAX_TEMPERATURE - MIN_TEMPERATURE + 1) + MIN_TEMPERATURE; // generate a random temperature for the day
        temperatures[day - 1] = temperature; // store temperature in temperature array
        sum_temperature += temperature; // add temperature to sum
        if(temperature > max_temperature) {
            max_temperature = temperature; // update maximum temperature
        }
        if(temperature < min_temperature) {
            min_temperature = temperature; // update minimum temperature
        }
    }

    // calculate average temperature for the month
    float avg_temperature = (float)sum_temperature / MAX_DAYS;

    // print daily temperatures
    printf("Daily temperatures for the month:\n");
    for(int day = 1; day <= MAX_DAYS; day++) {
        printf("Day %2d: %3d\n", day, temperatures[day - 1]);
    }

    // print maximum temperature
    printf("Maximum temperature for the month: %d\n", max_temperature);

    // print minimum temperature
    printf("Minimum temperature for the month: %d\n", min_temperature);

    // print average temperature
    printf("Average temperature for the month: %.2f\n", avg_temperature);

    return 0;
}