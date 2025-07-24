//FormAI DATASET v1.0 Category: Robot movement control ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>

// Define a struct to hold the robot's current location
struct location {
    int x;
    int y;
};

// Define a function to move the robot one unit in a given direction
void move_robot(struct location *loc, char direction) {
    switch (direction) {
        case 'u': // move up
            loc->y++;
            break;
        case 'd': // move down
            loc->y--;
            break;
        case 'l': // move left
            loc->x--;
            break;
        case 'r': // move right
            loc->x++;
            break;       
        default: // invalid direction
            printf("Error: Invalid direction '%c'!\n", direction);
            break;
    }
}

int main() {
    // Initialize the robot's location to (0,0)
    struct location robot_loc = {0, 0};
    
    // Read in a sequence of directions from user input
    char input[100];
    printf("Enter a sequence of directions (udlr): ");
    fgets(input, 100, stdin);
    
    // Move the robot according to the input directions
    for (int i = 0; input[i] != '\0'; i++) {
        if (input[i] == '\n') {
            break; // end the loop if we reach the end of the input
        }
        move_robot(&robot_loc, input[i]);
    }
    
    // Print the robot's final location
    printf("The robot ended up at (%d, %d)\n", robot_loc.x, robot_loc.y);
    
    return 0;
}