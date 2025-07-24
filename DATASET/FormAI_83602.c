//FormAI DATASET v1.0 Category: Temperature monitor ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

// Function to read temperature sensor
float readTemperatureSensor() {
    return (float) (rand() % 50);
}

// Function to print temperature
void printTemperature(float temp) {
    printf("Current Temperature: %.2f Celsius\n", temp);
}

// Function to check if temperature is too high
bool isTemperatureTooHigh(float temp, float threshold) {
    return (temp >= threshold);
}

// Function to send alert message
void sendAlertMessage(float temp) {
    printf("Alert! Temperature has reached %.2f Celsius!\n", temp);
}

int main() {
    const float THRESHOLD = 30.0;
    float currentTemperature;

    srand(time(NULL)); // Seed for random number generation

    while (true) {
        currentTemperature = readTemperatureSensor();
        printTemperature(currentTemperature);

        if (isTemperatureTooHigh(currentTemperature, THRESHOLD)) {
            sendAlertMessage(currentTemperature);
        }

        // Wait for 5 seconds
        for (int i = 0; i < 5; i++) {
            printf(".");
            fflush(stdout);
            sleep(1);
        }
        printf("\n");
    }

    return 0;
}