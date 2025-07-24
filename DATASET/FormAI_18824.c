//FormAI DATASET v1.0 Category: Smart home automation ; Style: safe
#include <stdio.h>

// Function to turn on the lights
void turnOnLights() {
    printf("Lights turned on!\n");
}

// Function to turn off the lights
void turnOffLights() {
    printf("Lights turned off!\n");
}

// Function to lock the doors
void lockDoors() {
    printf("Doors locked!\n");
}

// Function to unlock the doors
void unlockDoors() {
    printf("Doors unlocked!\n");
}

int main() {
    // Smart home automation program

    // Initialize variables for sensors
    int lightSensor = 0;
    int doorSensor = 0;

    // Loop to simulate sensor readings
    while (1) {
        // Simulate light sensor
        if (lightSensor == 0) {
            printf("No light detected.\n");
            turnOffLights();
        } else {
            printf("Light detected.\n");
            turnOnLights();
        }

        // Simulate door sensor
        if (doorSensor == 0) {
            printf("Doors are closed.\n");
            lockDoors();
        } else {
            printf("Doors are open.\n");
            unlockDoors();
        }

        // Pause for 5 seconds to simulate passage of time
        sleep(5);
    }

    return 0;
}