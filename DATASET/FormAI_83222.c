//FormAI DATASET v1.0 Category: Temperature monitor ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BUFFER_SIZE 100

int main() {
    float temperature[BUFFER_SIZE];
    int index = 0;
    char input = ' ';

    while (input != 'q') {
        // Generate random temperature value (0-100)
        float tempValue = (float) (rand() % 100);

        // Add temperature value to array
        temperature[index % BUFFER_SIZE] = tempValue;

        // Increment index counter
        index++;

        // Output current temperature value
        printf("Current Temperature: %.2f degrees Celsius\n", tempValue);

        // Check if buffer is full
        if (index >= BUFFER_SIZE) {
            // Calculate average temperature
            float averageTemp = 0;
            for (int i = 0; i < BUFFER_SIZE; i++) {
                averageTemp += temperature[i];
            }
            averageTemp /= BUFFER_SIZE;

            // Output average temperature
            printf("Average Temperature: %.2f degrees Celsius\n", averageTemp);
        }

        // Wait for user input
        printf("Press any key to continue or 'q' to quit.\n");
        input = getchar();
    }

    return 0;
}