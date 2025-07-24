//FormAI DATASET v1.0 Category: Temperature monitor ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_TEMPERATURE 100
#define MIN_TEMPERATURE 0

// Function to generate random temperature between MIN_TEMPERATURE and MAX_TEMPERATURE
int generateRandomTemperature() {
    int temperature = (rand() % (MAX_TEMPERATURE - MIN_TEMPERATURE + 1)) + MIN_TEMPERATURE;
    return temperature;
}

int main() {
    int temperature;
    srand(time(NULL)); // Set the seed for generating random numbers
    
    // Loop to generate and display the temperatures every 5 seconds
    while(1) {
        temperature = generateRandomTemperature();
        printf("Current temperature: %d\n", temperature);
        if(temperature >= 90) {
            printf("Warning: High temperature detected!\n");
        }
        printf("--------------------------------\n");
        sleep(5); // Wait for 5 seconds
    }
    return 0;
}