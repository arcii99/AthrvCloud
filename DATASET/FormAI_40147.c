//FormAI DATASET v1.0 Category: Weather simulation ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int temperature[24];
    int i, j;

    srand(time(NULL)); // seed random number generator with current time

    // generate random temperature values for 24 hours
    for (i = 0; i < 24; i++) {
        temperature[i] = rand() % 20 + 10; // temperatures between 10-30 degrees Celsius
    }

    // display temperature values for each hour
    for (i = 0; i < 24; i++) {
        printf("Temperature at hour %d: %d degrees Celsius\n", i+1, temperature[i]);
    }

    // calculate average temperature for the day
    int sum = 0;
    for (i = 0; i < 24; i++) {
        sum += temperature[i];
    }
    double average = (double) sum / 24;
    printf("Average temperature for the day: %.2lf degrees Celsius\n", average);

    // calculate maximum temperature and its corresponding hour
    int maxTemp = temperature[0];
    for (i = 1; i < 24; i++) {
        if (temperature[i] > maxTemp) {
            maxTemp = temperature[i];
            j = i + 1;
        }
    }
    printf("Maximum temperature for the day: %d degrees Celsius\n", maxTemp);
    printf("At hour %d\n", j);

    // calculate minimum temperature and its corresponding hour
    int minTemp = temperature[0];
    for (i = 1; i < 24; i++) {
        if (temperature[i] < minTemp) {
            minTemp = temperature[i];
            j = i + 1;
        }
    }
    printf("Minimum temperature for the day: %d degrees Celsius\n", minTemp);
    printf("At hour %d\n", j);

    return 0;
}