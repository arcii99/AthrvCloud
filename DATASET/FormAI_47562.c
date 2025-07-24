//FormAI DATASET v1.0 Category: Temperature monitor ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MIN_TEMP 0
#define MAX_TEMP 100

int main() {
    int temperature;
    bool running = true;

    while (running) {
        // Get temperature from user input
        printf("Enter temperature: ");
        scanf("%d", &temperature);

        if (temperature < MIN_TEMP || temperature > MAX_TEMP) {
            printf("Error: Temperature must be between %d and %d degrees\n", MIN_TEMP, MAX_TEMP);
            continue;
        }

        // Print message based on temperature
        if (temperature < 20) {
            printf("It's very cold\n");
        } else if (temperature < 40) {
            printf("It's a bit chilly\n");
        } else if (temperature < 60) {
            printf("It's a comfortable temperature\n");
        } else if (temperature < 80) {
            printf("It's getting warm\n");
        } else {
            printf("It's very hot\n");
        }

        // Ask user if they want to continue
        printf("Do you want to continue? (y/n) ");
        char input;
        scanf(" %c", &input);

        if (input == 'n') {
            running = false;
        }
    }

    return EXIT_SUCCESS;
}