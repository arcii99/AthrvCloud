//FormAI DATASET v1.0 Category: Robot movement control ; Style: shocked
#include <stdio.h>
#include <stdlib.h>

int main() {

    int x = 0, y = 0; // Initializing the robot position to (0, 0)
    char direction = 'N'; // Initializing the robot direction to North

    printf("Starting position: (%d,%d,%c)\n", x, y, direction);

    // Accepting the movement commands from the user
    char command;
    printf("Enter movement commands (Press Q to exit): ");
    scanf("%c", &command);

    while(command != 'Q') {

        switch(command) {
            case 'F':
                // Move the robot forward based on its current direction
                switch(direction) {
                    case 'N': y++; break;
                    case 'S': y--; break;
                    case 'E': x++; break;
                    case 'W': x--; break;
                }
                break;
            case 'B':
                // Move the robot backward based on its current direction
                switch(direction) {
                    case 'N': y--; break;
                    case 'S': y++; break;
                    case 'E': x--; break;
                    case 'W': x++; break;
                }
                break;
            case 'L':
                // Change the robot direction to left (counter-clockwise)
                switch(direction) {
                    case 'N': direction = 'W'; break;
                    case 'S': direction = 'E'; break;
                    case 'E': direction = 'N'; break;
                    case 'W': direction = 'S'; break;
                }
                break;
            case 'R':
                // Change the robot direction to right (clockwise)
                switch(direction) {
                    case 'N': direction = 'E'; break;
                    case 'S': direction = 'W'; break;
                    case 'E': direction = 'S'; break;
                    case 'W': direction = 'N'; break;
                }
                break;
            default:
                printf("Invalid command! Please enter a valid movement command.\n");
        }
        
        // Print the current position and direction of the robot
        printf("Current position: (%d,%d,%c)\n", x, y, direction);
        
        // Accepting the next movement command from the user
        printf("Enter movement commands (Press Q to exit): ");
        scanf(" %c", &command);
    }

    printf("Exiting...\n");

    return 0;
}