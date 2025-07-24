//FormAI DATASET v1.0 Category: Weather simulation ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_DAYS 7
#define MAX_TEMPERATURE 100
#define MIN_TEMPERATURE -20

int main(void) {
    int temperature[MAX_DAYS];
    int avgTemperature = 0;

    srand(time(NULL));

    printf("Retro Weather Simulator\n");
    printf("-----------------------\n");

    for (int i = 1; i <= MAX_DAYS; i++) {
        temperature[i-1] = (rand() % (MAX_TEMPERATURE - MIN_TEMPERATURE + 1)) + MIN_TEMPERATURE;
        avgTemperature += temperature[i-1];

        printf("Day %d: ", i);

        if (temperature[i-1] < 0) {
            printf("%dF. Bundle up, it's cold out there!\n", temperature[i-1]);
        } else if (temperature[i-1] >= 0 && temperature[i-1] < 60) {
            printf("%dF. It's a bit chilly, bring a jacket.\n", temperature[i-1]);
        } else {
            printf("%dF. It's hot out there, stay cool!\n", temperature[i-1]);
        }
    }

    avgTemperature /= MAX_DAYS;

    printf("\nAverage Temperature for the week: %dF\n", avgTemperature);

    return 0;
}