//FormAI DATASET v1.0 Category: Smart home automation ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to randomly generate a temperature value
float generateTemperature() {
    return (float)(rand() % 25 + 15); // Random temperature value between 15°C and 40°C
}

int main() {
    // Initialize variables
    float temperature;
    char homeStatus = 'C'; // Default status is Cool

    // Welcome message
    printf("Welcome to Smart Home Automation System!\n\n");

    // Loop to continuously monitor the temperature and adjust the home status accordingly
    while(1) {
        // Generate a random temperature value for demonstration purposes
        temperature = generateTemperature();

        // Display the current temperature value
        printf("Current temperature: %.1f°C\n", temperature);

        // Check the temperature value and adjust the home status accordingly
        if(temperature < 20) {
            homeStatus = 'H'; // Warm Home Status
        } else if(temperature >= 20 && temperature < 25) {
            homeStatus = 'C'; // Cool Home Status
        } else {
            homeStatus = 'C'; // Cool Home Status
        }

        // Display the current home status
        if(homeStatus == 'C') {
            printf("Home is currently cool.\n\n");
        } else {
            printf("Home is currently warm.\n\n");
        }

        // Wait for 5 seconds before updating the temperature value
        sleep(5);
    }

    return 0;
}