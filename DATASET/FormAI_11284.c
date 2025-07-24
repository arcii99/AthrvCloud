//FormAI DATASET v1.0 Category: Temperature monitor ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function prototypes
void readTemperature();
void checkTemperature();
double getTemperature();

// Global variables
double currentTemperature;

int main() {
    // Seed the random number generator with the current time
    srand(time(NULL));

    // Loop infinitely to continuously monitor temperature
    while (1) {
        readTemperature();
        checkTemperature();
        // Delay for 3 seconds before monitoring temperature again
        sleep(3);
    }

    return 0;
}

// Function to read temperature from sensor
void readTemperature() {
    // Generate random temperature between 0 and 100 degrees Celsius
    currentTemperature = (double) rand() / (double) RAND_MAX * 100.0;
    printf("Temperature reading: %.2lf\n", currentTemperature);
}

// Function to check temperature and take appropriate action
void checkTemperature() {
    if (currentTemperature < 0) {
        printf("Error: Sensor malfunction. Temperature reading below 0 degrees Celsius.\n");
        exit(1);
    } else if (currentTemperature >= 0 && currentTemperature < 20) {
        printf("Warning: Low temperature. Current temperature is %.2lf degrees Celsius.\n", currentTemperature);
    } else if (currentTemperature >= 20 && currentTemperature < 30) {
        printf("Temperature is within normal range. Current temperature is %.2lf degrees Celsius.\n", currentTemperature);
    } else if (currentTemperature >= 30 && currentTemperature < 40) {
        printf("Warning: High temperature. Current temperature is %.2lf degrees Celsius.\n", currentTemperature);
    } else {
        printf("Danger: Temperature is too high. Current temperature is %.2lf degrees Celsius.\n", currentTemperature);
        exit(1);
    }
}

// Function to simulate getting temperature from sensor
double getTemperature() {
    // Generate random temperature between 0 and 100 degrees Celsius
    double temperature = (double) rand() / (double) RAND_MAX * 100.0;
    return temperature;
}