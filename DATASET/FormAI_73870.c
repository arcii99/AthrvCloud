//FormAI DATASET v1.0 Category: Robot movement control ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>

// Define constants for robot movements
#define MOVE_FORWARD 0
#define MOVE_BACKWARD 1

// Define constants for robot directions
#define DIRECTION_LEFT 0
#define DIRECTION_RIGHT 1

// Define constants for robot speeds
#define SPEED_SLOW 0
#define SPEED_FAST 1

// Define constants for robot positions
#define POSITION_START 0
#define POSITION_END 10

// Define the robot struct
typedef struct {
    int xPos;
    int speed;
} Robot;

// Define the robot movement function
void moveRobot(Robot *robot, int movement, int direction) {
    if(movement == MOVE_FORWARD) {
        if(direction == DIRECTION_LEFT) {
            robot->xPos--;
            printf("Moving robot left to position %d\n", robot->xPos);
        } else {
            robot->xPos++;
            printf("Moving robot right to position %d\n", robot->xPos);
        }
    } else {
        if(direction == DIRECTION_LEFT) {
            robot->xPos++;
            printf("Moving robot right to position %d\n", robot->xPos);
        } else {
            robot->xPos--;
            printf("Moving robot left to position %d\n", robot->xPos);
        }
    }
}

int main() {
    // Create a new robot
    Robot robot;
    
    // Initialize the robot's variables
    robot.xPos = POSITION_START;
    robot.speed = SPEED_SLOW;
    
    // Move the robot to the right at slow speed
    moveRobot(&robot, MOVE_FORWARD, DIRECTION_RIGHT);
    printf("Current speed: %d\n", robot.speed);
    
    // Move the robot to the left at fast speed
    robot.speed = SPEED_FAST;
    moveRobot(&robot, MOVE_BACKWARD, DIRECTION_LEFT);
    printf("Current speed: %d\n", robot.speed);
    
    // Move the robot back to the starting position
    while(robot.xPos > POSITION_START) {
        moveRobot(&robot, MOVE_BACKWARD, DIRECTION_LEFT);
    }
    
    printf("Robot has returned to starting position.\n");
    
    return 0;
}