//FormAI DATASET v1.0 Category: Smart home automation ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define the status of each device
bool isLightOn = false;
bool isFanOn = false;
bool isTVOn = false;
bool isDoorLocked = true;

// Function to turn on/off the light
void toggleLight() {
    isLightOn = !isLightOn;
    if (isLightOn) {
        printf("Light is on\n");
    } else {
        printf("Light is off\n");
    }
}

// Function to turn on/off the fan
void toggleFan() {
    isFanOn = !isFanOn;
    if (isFanOn) {
        printf("Fan is on\n");
    } else {
        printf("Fan is off\n");
    }
}

// Function to turn on/off the TV
void toggleTV() {
    isTVOn = !isTVOn;
    if (isTVOn) {
        printf("TV is on\n");
    } else {
        printf("TV is off\n");
    }
}

// Function to lock/unlock the door
void toggleDoor() {
    isDoorLocked = !isDoorLocked;
    if (isDoorLocked) {
        printf("Door is locked\n");
    } else {
        printf("Door is unlocked\n");
    }
}

// Main function to control smart home devices
int main() {
    printf("Welcome to Smart Home Automation!\n");

    // Loop to listen for user input
    while (true) {
        printf("Enter command [l]ight, [f]an, [t]v, [d]oor, [q]uit: ");
        char input = getchar();

        // Handle user input
        switch (input) {
            case 'l':
                toggleLight();
                break;
            case 'f':
                toggleFan();
                break;
            case 't':
                toggleTV();
                break;
            case 'd':
                toggleDoor();
                break;
            case 'q':
                printf("Goodbye!\n");
                exit(0);
            default:
                printf("Invalid command. Try again.\n");
                break;
        }

        // Clear input buffer
        while ((getchar()) != '\n');
    }

    return 0;
}