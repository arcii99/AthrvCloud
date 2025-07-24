//FormAI DATASET v1.0 Category: Weather simulation ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL)); // Initialize random number generator

    // Constants
    const int MONTHS_PER_YEAR = 12;
    const int MAX_TEMP = 100;
    const int MIN_TEMP = 10;
    const int MAX_PRECIPITATION = 30;
    const int MIN_PRECIPITATION = 0;
    const int MIN_SUNSHINE = 0;
    const int MAX_SUNSHINE = 16;

    // Arrays to hold weather data
    int temperatures[MONTHS_PER_YEAR];
    int precipitation[MONTHS_PER_YEAR];
    int sunshine[MONTHS_PER_YEAR];

    // Generate random weather data for each month
    for (int i = 0; i < MONTHS_PER_YEAR; i++) {
        temperatures[i] = rand() % (MAX_TEMP - MIN_TEMP + 1) + MIN_TEMP; // Random temperature between 10 and 100
        precipitation[i] = rand() % (MAX_PRECIPITATION - MIN_PRECIPITATION + 1) + MIN_PRECIPITATION; // Random precipitation amount between 0 and 30
        sunshine[i] = rand() % (MAX_SUNSHINE - MIN_SUNSHINE + 1) + MIN_SUNSHINE; // Random sunshine hours between 0 and 16
    }

    // Print out the weather data for each month
    printf("Month\tTemperature\tPrecipitation (inches)\tSunshine (hours)\n");
    for (int i = 0; i < MONTHS_PER_YEAR; i++) {
        printf("%d\t%d\t\t%d\t\t\t%d\n", i+1, temperatures[i], precipitation[i], sunshine[i]);
    }

    return 0;
}