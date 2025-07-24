//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: minimalist
#include <stdio.h>

// Define the initial coordinates of the vehicle
int x_pos = 0;
int y_pos = 0;

int main() {
    // Loop until the user quits the program
    while (1) {
        // Print the current location of the vehicle
        printf("Current Position: (%d,%d)\n", x_pos, y_pos);
        
        // Get user input for the direction they want to move the vehicle
        printf("Enter direction (N/S/E/W): ");
        char direction;
        scanf(" %c", &direction);
        
        // Update the vehicle's coordinates based on the user's input
        switch (direction) {
            case 'N':
                y_pos++;
                break;
            case 'S':
                y_pos--;
                break;
            case 'E':
                x_pos++;
                break;
            case 'W':
                x_pos--;
                break;
            default:
                printf("Invalid direction entered.\n");
        }
    }
    
    return 0;
}