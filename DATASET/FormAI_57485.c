//FormAI DATASET v1.0 Category: Temperature monitor ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>

/* Function to generate random temperature readings between 0 and 50 */
int getTemperatureReading() {
    return rand() % 51;
}

int main() {
    int maxTemp = INT_MIN;
    int minTemp = INT_MAX;
    float avgTemp = 0;
    int numOfReadings = 0;

    printf("Starting temperature monitor...\n");

    /* Loop to collect temperature readings for 24 hours */
    for(int i = 0; i < 24; i++) {
        printf("\nHour %d\n", i + 1);

        /* Collecting 4 temperature readings each hour */
        for(int n = 0; n < 4; n++) {
            int reading = getTemperatureReading();

            printf("Reading %d: %d C\n", n + 1, reading);

            /* Updating min and max temperatures */
            if(reading > maxTemp) {
                maxTemp = reading;
            }
            if(reading < minTemp) {
                minTemp = reading;
            }

            /* Calculating average temperature */
            avgTemp += (float) reading / (4 * 24);
            numOfReadings++;
        }
    }

    printf("\n\nTemperature Monitor Summary\n");
    printf("----------------------------\n");
    printf("Number of Readings: %d\n", numOfReadings);
    printf("Maximum Temperature: %d C\n", maxTemp);
    printf("Minimum Temperature: %d C\n", minTemp);
    printf("Average Temperature: %.2f C\n", avgTemp);

    return 0;
}