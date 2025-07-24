//FormAI DATASET v1.0 Category: Temperature monitor ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_TEMP 200
#define MIN_TEMP -50
#define TEMP_THRESHOLD 100

int main() {

    int currentTemp = 0;
    bool warningTriggered = false;
    char response;

    while(1) {

        // Getting the current temperature
        printf("Enter current temperature in Celsius: \n");
        scanf("%d", &currentTemp);

        // Checking if the temperature is within range
        if(currentTemp < MIN_TEMP || currentTemp > MAX_TEMP) {
            printf("Error: Temperature must be between -50°C and 200°C\n");
            continue;
        }

        if(currentTemp >= TEMP_THRESHOLD && !warningTriggered) {
            printf("Warning: Temperature has exceeded the threshold of 100°C\n");
            warningTriggered = true;
        }

        // Asking user if they want to exit
        printf("Do you wish to exit? (y/n)\n");
        scanf(" %c", &response);
        if(response == 'y' || response == 'Y') {
            break;
        }
    }

    return 0;
}