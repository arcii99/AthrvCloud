//FormAI DATASET v1.0 Category: Robot movement control ; Style: genious
#include <stdio.h>

// define constants for movement directions
#define LEFT 1
#define RIGHT 2
#define UP 3
#define DOWN 4

// define struct for robot position
typedef struct RobotPosition {
    int x;
    int y;
} RobotPosition;

// function to move robot forward in given direction
void moveRobot(RobotPosition *position, int direction) {
    switch(direction) {
        case LEFT:
            position->x--;
            break;
        case RIGHT:
            position->x++;
            break;
        case UP:
            position->y--;
            break;
        case DOWN:
            position->y++;
            break;
        default:
            printf("Invalid direction!\n");
            break;
    }
}

int main() {
    // create a RobotPosition struct and initialize it to (0,0) position
    RobotPosition robot;
    robot.x = 0;
    robot.y = 0;

    // start moving the robot in a pattern
    moveRobot(&robot, RIGHT);
    moveRobot(&robot, RIGHT);
    moveRobot(&robot, DOWN);
    moveRobot(&robot, LEFT);
    moveRobot(&robot, LEFT);
    moveRobot(&robot, UP);
    moveRobot(&robot, RIGHT);
    moveRobot(&robot, DOWN);
    moveRobot(&robot, RIGHT);
    moveRobot(&robot, UP);
    moveRobot(&robot, UP);
    moveRobot(&robot, RIGHT);
    moveRobot(&robot, RIGHT);
    moveRobot(&robot, DOWN);
    moveRobot(&robot, LEFT);
    moveRobot(&robot, DOWN);

    // print final position of the robot
    printf("Robot final position: (%d,%d)\n", robot.x, robot.y);

    return 0;
}