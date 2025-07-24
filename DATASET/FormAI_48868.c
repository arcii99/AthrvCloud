//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COMMAND_LENGTH 50
#define MAX_SPEED 10

int main() {
    // Initialize variables
    int speed = 0;
    char command[MAX_COMMAND_LENGTH];

    // Prompt user for commands
    printf("\nWelcome to the Remote Control Vehicle Simulator!\n\n");
    while (strncmp(command, "exit", 4) != 0) {
        printf("Current speed: %d\n", speed);
        printf("Enter a command (accelerate, brake, turn left, turn right, exit): ");
        fgets(command, MAX_COMMAND_LENGTH, stdin);
        // Process commands
        if (strncmp(command, "accelerate", 10) == 0) {
            speed += 2;
            if (speed > MAX_SPEED) {
                speed = MAX_SPEED;
            }
            printf("Accelerating...\n");
        } else if (strncmp(command, "brake", 5) == 0) {
            speed -= 2;
            if (speed < 0) {
                speed = 0;
            }
            printf("Braking...\n");
        } else if (strncmp(command, "turn left", 9) == 0) {
            printf("Turning left...\n");
        } else if (strncmp(command, "turn right", 10) == 0) {
            printf("Turning right...\n");
        } else if (strncmp(command, "exit", 4) == 0) {
            printf("Exiting remote control vehicle simulator.\n");
        } else {
            printf("Invalid command. Please try again.\n");
        }
    }

    return 0;
}