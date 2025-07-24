//FormAI DATASET v1.0 Category: Robot movement control ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>

// Define constants for robot movements
#define FORWARD 1
#define BACKWARD 2
#define LEFT 3
#define RIGHT 4

// Global variables for robot position
int x_pos = 0;
int y_pos = 0;

// Function to move robot based on direction input
void move_robot(int direction, int distance){

    switch(direction){
        case FORWARD:
            y_pos += distance;
            break;
        case BACKWARD:
            y_pos -= distance;
            break;
        case LEFT:
            x_pos -= distance;
            break;
        case RIGHT:
            x_pos += distance;
            break;
        default:
            printf("Error: Invalid Direction\n");
    }

    // Print robot's new position
    printf("Robot is now at (%d,%d)\n", x_pos, y_pos);
}

int main(){

    // Move robot forward 5 units
    move_robot(FORWARD, 5);

    // Move robot right 3 units
    move_robot(RIGHT, 3);

    // Move robot backward 4 units
    move_robot(BACKWARD, 4);

    // Move robot left 2 units
    move_robot(LEFT, 2);

    return 0;
}