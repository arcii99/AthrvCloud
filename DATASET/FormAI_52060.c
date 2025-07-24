//FormAI DATASET v1.0 Category: Weather simulation ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_OF_DAYS 7
#define LOW_TEMP 10
#define HIGH_TEMP 30

int main() {
    int temperatures[NUM_OF_DAYS];
    int i, j;

    srand(time(NULL));

    printf("Weather simulation for the next %d days:\n", NUM_OF_DAYS);
    printf("---------------------------------------------\n");

    for (i = 0; i < NUM_OF_DAYS; i++) {
        temperatures[i] = rand() % (HIGH_TEMP - LOW_TEMP + 1) + LOW_TEMP;

        printf("Day %d: ", i + 1);

        for (j = 0; j < temperatures[i]; j++) {
            printf("*");
        }
        printf("\n");
    }

    printf("---------------------------------------------\n");

    int avgTemp = 0;
    for (i = 0; i < NUM_OF_DAYS; i++) {
        avgTemp += temperatures[i];
    }

    avgTemp /= NUM_OF_DAYS;

    printf("Average temperature for the next %d days: %d\n", NUM_OF_DAYS, avgTemp);

    if (avgTemp >= LOW_TEMP && avgTemp < HIGH_TEMP) {
        printf("The weather will be moderate.\n");
    } else if (avgTemp >= HIGH_TEMP) {
        printf("The weather will be hot.\n");
    } else {
        printf("The weather will be cold.\n");
    }

    return 0;
}