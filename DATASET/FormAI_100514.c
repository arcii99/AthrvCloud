//FormAI DATASET v1.0 Category: Smart home automation ; Style: puzzling
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// Function to lock or unlock the front door
void lockFrontDoor(bool locked) {
    if (locked) {
        printf("The front door is now locked\n");
    } else {
        printf("The front door is now unlocked\n");
    }
}

// Function to turn on or off the living room light
void toggleLivingRoomLight(bool on) {
    if (on) {
        printf("The living room light is turned on\n");
    } else {
        printf("The living room light is turned off\n");
    }
}

int main() {
    bool frontDoorLocked = false;
    bool livingRoomLightOn = false;
    char userInput[10];

    printf("Welcome to the smart home automation system!\n");
    printf("To lock or unlock the front door, type 'lock' or 'unlock'\n");
    printf("To turn on or off the living room light, type 'light on' or 'light off'\n");

    while (true) {
        printf("\n> ");
        fgets(userInput, 10, stdin);
        userInput[strcspn(userInput, "\n")] = '\0';

        if (strcmp(userInput, "lock") == 0) {
            frontDoorLocked = !frontDoorLocked;
            lockFrontDoor(frontDoorLocked);
        } else if (strcmp(userInput, "unlock") == 0) {
            frontDoorLocked = !frontDoorLocked;
            lockFrontDoor(frontDoorLocked);
        } else if (strcmp(userInput, "light on") == 0) {
            livingRoomLightOn = true;
            toggleLivingRoomLight(livingRoomLightOn);
        } else if (strcmp(userInput, "light off") == 0) {
            livingRoomLightOn = false;
            toggleLivingRoomLight(livingRoomLightOn);
        } else {
            printf("Invalid command. Please try again.\n");
        }
    }

    return 0;
}