//FormAI DATASET v1.0 Category: Robot movement control ; Style: authentic
#include <stdio.h>

// Macro definitions for the robot's movement directions
#define UP 1
#define DOWN 2
#define LEFT 3
#define RIGHT 4

// Structure to represent the robot's current position and direction of movement
struct Robot {
    int x;
    int y;
    int direction;
};

// Function to move the robot in the specified direction
void moveRobot(struct Robot *robot, int direction) {
    switch (direction) {
        case UP:
            robot->y++;
            break;
        case DOWN:
            robot->y--;
            break;
        case LEFT:
            robot->x--;
            break;
        case RIGHT:
            robot->x++;
            break;
    }
}

// Function to turn the robot left
void turnLeft(struct Robot *robot) {
    switch (robot->direction) {
        case UP:
            robot->direction = LEFT;
            break;
        case DOWN:
            robot->direction = RIGHT;
            break;
        case LEFT:
            robot->direction = DOWN;
            break;
        case RIGHT:
            robot->direction = UP;
            break;
    }
}

// Function to turn the robot right
void turnRight(struct Robot *robot) {
    switch (robot->direction) {
        case UP:
            robot->direction = RIGHT;
            break;
        case DOWN:
            robot->direction = LEFT;
            break;
        case LEFT:
            robot->direction = UP;
            break;
        case RIGHT:
            robot->direction = DOWN;
            break;
    }
}

int main() {
    struct Robot robot;
    robot.x = 0;
    robot.y = 0;
    robot.direction = UP; // Robot starts moving upwards
    
    printf("Robot started at (%d,%d) and is moving upwards\n", robot.x, robot.y);
    
    // Move the robot in a square pattern
    for (int i = 0; i < 4; i++) {
        moveRobot(&robot, robot.direction);
        printf("Robot moved to (%d,%d)\n", robot.x, robot.y);
        turnRight(&robot);
    }
    
    printf("Robot finished moving in a square pattern\n");
    
    return 0;
}