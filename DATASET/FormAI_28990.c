//FormAI DATASET v1.0 Category: Temperature monitor ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate random temperature values between 0 and 100
int generateRandomTemp() {
    return rand() % 101;
}

int main() {
    // Declare variables to store temperature values
    int currentTemp = 0, maxTemp = 0, minTemp = 100;
    
    // Seed the random number generator with current time
    srand(time(NULL));
    
    // Main loop to monitor temperature every five seconds
    while (1) {
        // Generate random temperature value
        currentTemp = generateRandomTemp();
        
        // Check if current temperature is greater than maximum temperature
        if (currentTemp > maxTemp) {
            maxTemp = currentTemp;
        }
        
        // Check if current temperature is less than minimum temperature
        if (currentTemp < minTemp) {
            minTemp = currentTemp;
        }
        
        // Print current, maximum and minimum temperature values
        printf("Current Temperature: %d\n", currentTemp);
        printf("Maximum Temperature: %d\n", maxTemp);
        printf("Minimum Temperature: %d\n", minTemp);
        
        // Sleep for 5 seconds before generating next temperature value
        sleep(5);
    }
    
    return 0;
}