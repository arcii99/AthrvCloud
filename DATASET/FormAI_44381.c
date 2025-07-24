//FormAI DATASET v1.0 Category: Temperature monitor ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

int getCurrentTemperature() {
    // Generate a random temperature between 0 to 100.
    return rand() % 101;
}

bool isTemperatureHigh(int temperature) {
    // Temperature threshold is 70 degrees Celsius.
    return temperature > 70;
}

int main() {
    // Seed the random number generator with current time in seconds.
    srand(time(NULL));

    while (true) {
        int temperature = getCurrentTemperature();
        printf("Current temperature is %d degrees Celsius\n", temperature);

        if (isTemperatureHigh(temperature)) {
            printf("Temperature is above 70 degrees Celsius! Cooling down...\n");
            // Implement the cooling down mechanism here.
        }

        // Wait for 5 seconds before checking again.
        sleep(5);
    }
    
    return 0;
}