//FormAI DATASET v1.0 Category: Temperature monitor ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    float temperature[24]; // temperature values for 24 hours
    float minTemp = 100, maxTemp = -100;
    float avgTemp = 0;
    time_t currentTime; // current time

    // Seed the random number generator
    srand(time(NULL));

    // Generate random temperature values for 24 hours
    for (int i = 0; i < 24; i++) {
        temperature[i] = ((float)rand()/(float)(RAND_MAX)) * 50.0; // set temperature as random float between 0 and 50 degrees Celsius
        avgTemp += temperature[i]; // add current temperature to the average temperature
        if (temperature[i] < minTemp) {
            minTemp = temperature[i]; // update minimum temperature
        }
        if (temperature[i] > maxTemp) {
            maxTemp = temperature[i]; // update maximum temperature
        }
    }
    avgTemp /= 24;

    // Get the current time
    currentTime = time(NULL);
    char *timeString = ctime(&currentTime); // convert current time to string format

    // Display results
    printf("Temperature Monitor Results for %s", timeString);
    printf("Minimum temperature: %.1f\n", minTemp);
    printf("Maximum temperature: %.1f\n", maxTemp);
    printf("Average temperature: %.1f\n", avgTemp);

    return 0;
}