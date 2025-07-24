//FormAI DATASET v1.0 Category: Robot movement control ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>

int main() {
    // Initialize variables
    int x = 0, y = 0, z = 0;
    char direction = 'N';
    
    // Cyberpunk style console output
    printf("Initializing robotic movement control...\n");
    printf("System online. Ready for input.\n");
    printf("Enter directional commands: F (forward), B (backward), L (left), R (right), U (up), D (down)\n");
    printf("Enter Q to quit\n");
    
    // Main loop for receiving input commands
    while (1) {
        printf("Current position: (%d, %d, %d), Facing: %c\n", x, y, z, direction);
        char command = getchar();
        
        if (command == 'Q') {
            // Quit program
            printf("Exiting program...\n");
            break;
        } else if (command == '\n') {
            // Ignore newline characters
            continue;
        } else if (command == 'F') {
            // Move forward
            if (direction == 'N') {
                y++;
            } else if (direction == 'S') {
                y--;
            } else if (direction == 'E') {
                x++;
            } else if (direction == 'W') {
                x--;
            } else if (direction == 'U') {
                z++;
            } else if (direction == 'D') {
                z--;
            }
        } else if (command == 'B') {
            // Move backward
            if (direction == 'N') {
                y--;
            } else if (direction == 'S') {
                y++;
            } else if (direction == 'E') {
                x--;
            } else if (direction == 'W') {
                x++;
            } else if (direction == 'U') {
                z--;
            } else if (direction == 'D') {
                z++;
            }
        } else if (command == 'L') {
            // Turn left
            if (direction == 'N') {
                direction = 'W';
            } else if (direction == 'S') {
                direction = 'E';
            } else if (direction == 'E') {
                direction = 'N';
            } else if (direction == 'W') {
                direction = 'S';
            } else {
                // Cannot turn left while moving up or down
                printf("Cannot turn left while moving up or down\n");
            }
        } else if (command == 'R') {
            // Turn right
            if (direction == 'N') {
                direction = 'E';
            } else if (direction == 'S') {
                direction = 'W';
            } else if (direction == 'E') {
                direction = 'S';
            } else if (direction == 'W') {
                direction = 'N';
            } else {
                // Cannot turn right while moving up or down
                printf("Cannot turn right while moving up or down\n");
            }
        } else if (command == 'U') {
            // Move up
            if (direction == 'U') {
                z++;
            } else if (direction == 'D') {
                z--;
            } else {
                // Cannot move up if not facing up or down
                printf("Cannot move up if not facing up or down\n");
            }
        } else if (command == 'D') {
            // Move down
            if (direction == 'U') {
                z--;
            } else if (direction == 'D') {
                z++;
            } else {
                // Cannot move down if not facing up or down
                printf("Cannot move down if not facing up or down\n");
            }
        } else {
            // Invalid command
            printf("Invalid command\n");
        }
        
        // Clear input buffer
        while (getchar() != '\n');
    }
    
    return 0;
}