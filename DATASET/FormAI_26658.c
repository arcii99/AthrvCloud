//FormAI DATASET v1.0 Category: Robot movement control ; Style: relaxed
#include <stdio.h>

int main() {
    int x = 0, y = 0; // Initialize the robot's starting position.
    char command = ' '; // Initialize the variable for the command the robot will receive.
    
    printf("Enter commands to move robot, 'x' to exit:\n");
    
    // Loop until the user inputs 'x' to exit.
    while (command != 'x') {
        printf("> ");
        scanf(" %c", &command); // Receive the command from the user.
        
        switch(command) {
            case 'u': // Move robot one unit up.
                y++;
                printf("Robot moved up to (%d, %d).\n", x, y);
                break;
            case 'd': // Move robot one unit down.
                y--;
                printf("Robot moved down to (%d, %d).\n", x, y);
                break;
            case 'l': // Move robot one unit to the left.
                x--;
                printf("Robot moved left to (%d, %d).\n", x, y);
                break;
            case 'r': // Move robot one unit to the right.
                x++;
                printf("Robot moved right to (%d, %d).\n", x, y);
                break;
            case 'x': // Exit the program.
                printf("Exiting...\n");
                break;
            default: // Invalid command entered.
                printf("Invalid command. Please enter u, d, l, r, or x.\n");
        }
    }
    
    return 0;
}