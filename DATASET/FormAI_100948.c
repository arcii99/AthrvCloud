//FormAI DATASET v1.0 Category: Smart home automation ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main() {
    // Define variables for sensors and devices
    bool motionSensor = false;
    bool doorSensor = false;
    bool lightBulb = false;
    bool airConditioner = false;

    // Set up the system
    printf("Initializing smart home automation system...\n\n");

    // Continuously monitor the sensors
    while (true) {
        // Check motion sensor
        if (motionSensor) {
            printf("Motion detected! Turning on lights...\n");
            lightBulb = true;
        } else {
            printf("No motion detected.\n");
            lightBulb = false;
        }

        // Check door sensor
        if (doorSensor) {
            printf("Door opened! Turning on air conditioner...\n");
            airConditioner = true;
        } else {
            printf("Door closed.\n");
            airConditioner = false;
        }

        // Allow user to input sensor values
        printf("Enter 1 if motion is detected, 0 otherwise: ");
        scanf("%d", &motionSensor);
        printf("Enter 1 if door is opened, 0 otherwise: ");
        scanf("%d", &doorSensor);

        printf("--------------------------------------\n");
    }
    
    return 0;
}