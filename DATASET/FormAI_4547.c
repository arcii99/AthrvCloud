//FormAI DATASET v1.0 Category: Smart home automation ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define functions for each smart home automation task
void turnOnLights() {
    printf("Turning on lights...\n");
}

void turnOffLights() {
    printf("Turning off lights...\n");
}

void lockDoors() {
    printf("Locking doors...\n");
}

void unlockDoors() {
    printf("Unlocking doors...\n");
}

int main() {
    char choice[20];  // define variable to hold user choice

    // Loop through smart home automation options until user quits
    while (1) {
        printf("\nWhat would you like to do?\n");
        printf("(1) Turn on lights\n");
        printf("(2) Turn off lights\n");
        printf("(3) Lock doors\n");
        printf("(4) Unlock doors\n");
        printf("(5) Quit\n");

        // Get user choice from input
        printf("Enter your choice: ");
        fgets(choice, 20, stdin);

        // Remove the newline character from input
        choice[strcspn(choice, "\n")] = 0;

        // Execute corresponding function based on user choice
        if (strcmp(choice, "1") == 0) {
            turnOnLights();
        } else if (strcmp(choice, "2") == 0) {
            turnOffLights();
        } else if (strcmp(choice, "3") == 0) {
            lockDoors();
        } else if (strcmp(choice, "4") == 0) {
            unlockDoors();
        } else if (strcmp(choice, "5") == 0) {
            printf("Exiting program...\n");
            break;
        } else {
            printf("Invalid input. Please try again.\n");
        }
    }

    return 0;
}