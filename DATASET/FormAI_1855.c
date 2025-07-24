//FormAI DATASET v1.0 Category: Temperature monitor ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>

#define TEMPERATURE_THRESHOLD 30 // Set the threshold temperature to 30 degrees Celsius

int main() {
    float currentTemperature;
    char continueMonitoring = 'Y';

    while (continueMonitoring == 'Y') {
        printf("Enter the current temperature in Celsius: ");
        scanf("%f", &currentTemperature);

        if (currentTemperature >= TEMPERATURE_THRESHOLD) {
            printf("WARNING: Temperature above threshold!!!\n");
        } else {
            printf("Temperature within safe limits.\n");
        }

        printf("Do you want to continue monitoring? (Y/N): ");
        scanf(" %c", &continueMonitoring); // need to add space before %c to ignore previous Enter key press
    }

    printf("Exiting temperature monitor program...\n");
    return 0;
}