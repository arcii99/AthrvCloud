//FormAI DATASET v1.0 Category: Temperature monitor ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to get the current temperature
float getTemperature() {
    // Generate a random temperature between -10 and 30 degrees Celsius
    float temperature = ((float)rand()/(float)(RAND_MAX)) * (30 + 10) - 10;
    return temperature;
}

int main() {
    float temperature = 0.0;
    int count = 0;
    time_t currentTime;

    // Print the program introduction
    printf("Welcome to the Temperature Monitor Program!\n");

    // Loop to get the temperature every 10 seconds for 10 times
    while (count < 10) {
        // Get the current time
        time(&currentTime);

        // Get the current temperature
        temperature = getTemperature();

        // Print the current temperature and time
        printf("%.2f degrees Celsius at %s", temperature, ctime(&currentTime));

        // Wait for 10 seconds before getting the next temperature
        sleep(10);

        count++;
    }

    // Print the program conclusion
    printf("Thank you for using the Temperature Monitor Program!\n");
    
    return 0;
}