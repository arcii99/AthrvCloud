//FormAI DATASET v1.0 Category: Temperature monitor ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TEMP 100
#define MIN_TEMP 0

int main() {
    int currentTemp = 0;
    srand(time(NULL)); // Seed the random number generator with current time

    printf("Temperature Monitor - Press Ctrl+C to quit\n");

    while(1) {
        currentTemp = rand() % (MAX_TEMP + 1 - MIN_TEMP) + MIN_TEMP; // Generate a random temperature between MIN_TEMP and MAX_TEMP
        printf("Current Temperature: %dC\n", currentTemp);
        if(currentTemp >= 80) {
            printf("WARNING: Temperature is too high!\n");
        }
        else if(currentTemp <= 20) {
            printf("WARNING: Temperature is too low!\n");
        }
        sleep(3); // Wait for 3 seconds before checking the temperature again
    }

    return 0;
}