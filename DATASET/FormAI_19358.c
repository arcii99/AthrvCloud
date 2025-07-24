//FormAI DATASET v1.0 Category: Weather simulation ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    int temperature[7] = {0};
    printf("Weather Simulation Program\n\n");

    // Generate random temperature values for the week
    srand(time(NULL));
    for (int i = 0; i < 7; i++) {
        temperature[i] = (rand() % 40) - 10; // Temperature range: -10 to 30 degrees Celsius
    }

    // Output temperature values for each day of the week
    printf("Temperature for the week:\n\n");
    printf("Mon: %d\n", temperature[0]);
    printf("Tue: %d\n", temperature[1]);
    printf("Wed: %d\n", temperature[2]);
    printf("Thu: %d\n", temperature[3]);
    printf("Fri: %d\n", temperature[4]);
    printf("Sat: %d\n", temperature[5]);
    printf("Sun: %d\n", temperature[6]);
    printf("\n");

    // Calculate and output average temperature for the week
    float average = 0;
    for (int i = 0; i < 7; i++) {
        average += temperature[i];
    }
    average /= 7;
    printf("Average temperature for the week: %.2f degrees Celsius\n", average);

    // Determine if it was a hot or cold week
    if (average > 25) {
        printf("It was a hot week.\n");
    } else if (average < 10) {
        printf("It was a cold week.\n");
    } else {
        printf("It was a moderate week.\n");
    }

    return 0;
}