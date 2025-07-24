//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: active
#include <stdio.h>
#include <stdbool.h>

// Function to control the C drone
void controlDrone(char command) {
    printf("Command received: %c\n", command);

    // Some code to control the drone based on the command received
    // For example, we can use a switch-case statement to decide the course of action based on the command
    switch(command) {
        case 'U':
            printf("Moving up.\n");
            break;
        case 'D':
            printf("Moving down.\n");
            break;
        case 'F':
            printf("Moving forward.\n");
            break;
        case 'B':
            printf("Moving backward.\n");
            break;
        case 'L':
            printf("Moving left.\n");
            break;
        case 'R':
            printf("Moving right.\n");
            break;
        case 'S':
            printf("Stopping.\n");
            break;
        default:
            printf("Invalid command. Please try again.\n");
    }
}

int main() {
    char command; // This variable will hold the command received from the remote control

    // Main loop of the program
    while(true) {
        printf("Waiting for command...\n");
        scanf(" %c", &command);

        controlDrone(command); // Call the drone control function with the command received
    }

    return 0;
}