//FormAI DATASET v1.0 Category: Robot movement control ; Style: portable
#include <stdio.h>
#include <stdlib.h>

// Define constants for robot movement
#define LEFT 0
#define RIGHT 1
#define FORWARD 2
#define BACKWARD 3

// Define robot struct
struct Robot {
    int x, y; // current position
};

// Function to move robot
void moveRobot(struct Robot *robot, int direction, int distance) {
    switch (direction) {
        case LEFT:
            robot->x -= distance;
            break;
        case RIGHT:
            robot->x += distance;
            break;
        case FORWARD:
            robot->y += distance;
            break;
        case BACKWARD:
            robot->y -= distance;
            break;
        default:
            printf("Invalid direction!\n");
            break;
    }
}

int main() {
    // Create robot
    struct Robot robot = {0, 0};
    
    // Move robot 5 units left
    moveRobot(&robot, LEFT, 5);
    printf("Robot position: (%d, %d)\n", robot.x, robot.y);
    
    // Move robot 3 units forward
    moveRobot(&robot, FORWARD, 3);
    printf("Robot position: (%d, %d)\n", robot.x, robot.y);
    
    // Move robot 2 units right
    moveRobot(&robot, RIGHT, 2);
    printf("Robot position: (%d, %d)\n", robot.x, robot.y);
    
    // Move robot 1 unit backward
    moveRobot(&robot, BACKWARD, 1);
    printf("Robot position: (%d, %d)\n", robot.x, robot.y);
    
    return 0;
}