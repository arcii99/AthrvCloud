//FormAI DATASET v1.0 Category: Robot movement control ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>

#define FORWARD 1
#define BACKWARD 2
#define LEFT 3
#define RIGHT 4

int current_x = 0; // Current x position of robot
int current_y = 0; // Current y position of robot

void moveRobot(int direction, int distance) {
    // Move the robot based on the specified direction and distance.
    switch(direction) {
        case FORWARD:
            current_y += distance;
            break;
        case BACKWARD:
            current_y -= distance;
            break;
        case LEFT:
            current_x -= distance;
            break;
        case RIGHT:
            current_x += distance;
            break;
        default:
            printf("Invalid direction");
    }
}

int main() {
    int i;
    int moves[4][2] = {{FORWARD, 5}, {LEFT, 3}, {BACKWARD, 2}, {RIGHT, 4}};
    
    // Perform each move in sequence
    for(i = 0; i < 4; i++) {
        moveRobot(moves[i][0], moves[i][1]);
    }

    // Print final position of robot
    printf("Robot is now at position (%d, %d)", current_x, current_y);

    return 0;
}