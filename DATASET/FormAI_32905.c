//FormAI DATASET v1.0 Category: Robot movement control ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024 // Maximum buffer size for storing read-in commands

int main() {
    int x_pos = 0, y_pos = 0; // Initialize robot position to (0, 0)

    printf("Welcome to CRobot! Enter commands to move the robot (type 'exit' to quit).\n");

    while(1) {
        char buffer[MAX_BUFFER_SIZE]; // Buffer to store user input

        printf(">> ");
        fgets(buffer, MAX_BUFFER_SIZE, stdin); // Reads in user input from stdin

        if(strncmp(buffer, "exit", 4) == 0) { // If user enters 'exit', break out of loop and quit
            break;
        }

        // Parse user input to determine direction and distance to move robot
        char direction = buffer[0];
        int distance = atoi(buffer + 2); // atoi() used to convert second character in buffer to integer

        // Adjust robot position based on movement command
        switch(direction) {
            case 'U': // Move up
                y_pos += distance;
                break;
            case 'D': // Move down
                y_pos -= distance;
                break;
            case 'L': // Move left
                x_pos -= distance;
                break;
            case 'R': // Move right
                x_pos += distance;
                break;
            default: // If direction character isn't recognized, print error message and continue loop
                printf("Error: unknown direction '%c'\n", direction);
                continue;
        }

        // Print new robot position after movement
        printf("New position: (%d, %d)\n", x_pos, y_pos);
    }

    printf("Thanks for using CRobot! Goodbye.\n");

    return 0;
}