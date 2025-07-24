//FormAI DATASET v1.0 Category: Temperature monitor ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Define the lower and upper limits for random temperature
    const int LOWER_LIMIT = 20;
    const int UPPER_LIMIT = 35;

    // Generate a random seed for temperature readings
    srand(time(0));

    // Start the temperature monitoring loop
    while (1) {
        // Generate a random temperature reading between the lower and upper limits
        int temperature = (rand() % (UPPER_LIMIT - LOWER_LIMIT + 1)) + LOWER_LIMIT;

        // Display the temperature reading to the user
        printf("Current temperature is: %d degrees Celsius\n", temperature);

        // Check whether the temperature is within the normal range
        if (temperature >= 25 && temperature <= 30) {
            printf("Temperature is within normal range.\n");
        } else {
            printf("ALERT! Temperature is outside normal range.\n");
        }

        // Wait for 5 seconds before the next temperature reading
        printf("=============================================\n");
        sleep(5);
    }

    return 0;
}