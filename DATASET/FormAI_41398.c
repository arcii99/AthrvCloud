//FormAI DATASET v1.0 Category: Smart home automation ; Style: modular
#include <stdio.h>
#include <stdbool.h>

// Function to turn on the lights
void turnOnLights() {
    printf("Lights turned on.\n");
}

// Function to turn off the lights
void turnOffLights() {
    printf("Lights turned off.\n");
}

// Function to unlock the door
void unlockDoor() {
    printf("Door unlocked.\n");
}

// Function to lock the door
void lockDoor() {
    printf("Door locked.\n");
}

// Function to adjust temperature
void adjustTemperature(int temp) {
    printf("Temperature adjusted to %d degrees.\n", temp);
}

// Function to play music
void playMusic() {
    printf("Music playing.\n");
}

// Main function for home automation
int main() {
    bool isLightOn = false;
    bool isDoorLocked = true;
    int temperature = 25;

    // Initial status
    printf("Smart home automation started.\n\n");
    printf("Lights are turned off.\n");
    printf("Door is locked.\n");
    printf("Temperature is %d degrees.\n\n", temperature);

    // Interaction with user
    char choice;
    printf("Enter 'L' to turn on/off Lights.\n");
    printf("Enter 'D' to lock/unlock the Door.\n");
    printf("Enter 'T' to adjust Temperature.\n");
    printf("Enter 'M' to play Music.\n");
    printf("Enter 'Q' to quit.\n");

    // Loop to control home automation
    do {
        printf("\nYour choice: ");
        scanf(" %c", &choice);

        switch(choice) {
            case 'L':
                if(isLightOn) {
                    turnOffLights();
                    isLightOn = false;
                } else {
                    turnOnLights();
                    isLightOn = true;
                }
                break;

            case 'D':
                if(isDoorLocked) {
                    unlockDoor();
                    isDoorLocked = false;
                } else {
                    lockDoor();
                    isDoorLocked = true;
                }
                break;

            case 'T':
                int temp;
                printf("Enter temperature: ");
                scanf("%d", &temp);
                adjustTemperature(temp);
                temperature = temp;
                break;

            case 'M':
                playMusic();
                break;

            case 'Q':
                printf("Smart home automation ended.\n");
                break;

            default:
                printf("Invalid choice.\n");
                break;
        }
    } while(choice != 'Q');

    return 0;
}