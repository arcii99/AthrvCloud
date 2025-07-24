//FormAI DATASET v1.0 Category: Robot movement control ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>

// Define constants
#define FORWARD 1
#define BACKWARD 2
#define LEFT 3
#define RIGHT 4
#define DISTANCE_PER_STEP 1.5

// Define function to move the robot
void move_robot(int direction, int steps) {
    double distance = steps * DISTANCE_PER_STEP;
    switch(direction) {
        case FORWARD:
            printf("Moving forward %d steps, %.2f meters...\n", steps, distance);
            break;
        case BACKWARD:
            printf("Moving backward %d steps, %.2f meters...\n", steps, distance);
            break;
        case LEFT:
            printf("Moving left %d steps, %.2f meters...\n", steps, distance);
            break;
        case RIGHT:
            printf("Moving right %d steps, %.2f meters...\n", steps, distance);
            break;
        default:
            printf("Invalid direction!\n");
            break;
    }
}

int main() {
    // Move the robot forward 5 steps
    move_robot(FORWARD, 5);
    
    // Move the robot backward 3 steps
    move_robot(BACKWARD, 3);
    
    // Move the robot left 2 steps
    move_robot(LEFT, 2);
    
    // Move the robot right 4 steps
    move_robot(RIGHT, 4);
    
    return 0;
}