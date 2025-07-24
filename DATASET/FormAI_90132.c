//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: Alan Touring
#include <stdlib.h>
#include <stdio.h>

int main()
{
    int x = 0, y = 0; // Starting position of the vehicle
    char command; // Variable to store user command

    printf("Welcome to the Remote Control Vehicle Simulation.\n");
    printf("Use 'w', 'a', 's', 'd' keys to move the vehicle.\n");
    printf("Enter 'q' to quit.");

    do {
        printf("\nPosition: (%d, %d)\n", x, y); // Display current position

        // Read user command
        printf("Enter command: ");
        scanf(" %c", &command);

        switch (command) {
            case 'w': // Move forward
                y++;
                printf("Moving forward...\n");
                break;
            case 'a': // Move left
                x--;
                printf("Moving left...\n");
                break;
            case 's': // Move backward
                y--;
                printf("Moving backward...\n");
                break;
            case 'd': // Move right
                x++;
                printf("Moving right...\n");
                break;
            case 'q': // Quit
                printf("Quitting...\n");
                break;
            default: // Invalid command
                printf("Invalid command.\n");
        }
    } while (command != 'q'); // Continue until user enters 'q'

    return 0;
}