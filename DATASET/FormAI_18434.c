//FormAI DATASET v1.0 Category: Temperature monitor ; Style: configurable
#include <stdio.h>
#include <stdlib.h>

// Function to read temperature from sensor
float readTemperature() {
    // Code to read temperature from sensor goes here
    // For the purpose of this example, we will just return a random temperature between 50 and 100 degrees Celsius
    return (float)(rand() % 51 + 50);
}

int main() {
    float temperature;
    int maxTemperature = 80; // Default maximum temperature for the configuration
    char choice;

    // Prompt user for configuration
    printf("Do you want to configure the maximum temperature? (Y/N): ");
    scanf(" %c", &choice);

    if (choice == 'Y' || choice == 'y') {
        // Prompt user for maximum temperature
        printf("Enter the maximum temperature: ");
        scanf("%d", &maxTemperature);

        // Validate the entered maximum temperature
        while (maxTemperature <= 0 || maxTemperature > 100) {
            printf("Invalid temperature! Enter a value between 1 and 100 degrees Celsius: ");
            scanf("%d", &maxTemperature);
        }
    }

    // Main loop to continuously read temperature
    while (1) {
        temperature = readTemperature();

        printf("Temperature: %.2f C\n", temperature);

        // Check if the temperature exceeds the maximum temperature
        if (temperature > maxTemperature) {
            printf("WARNING: Temperature has exceeded the configured maximum temperature of %d C!\n", maxTemperature);
        }

        // Delay for 1 second before reading temperature again
        sleep(1);
    }

    return 0;
}