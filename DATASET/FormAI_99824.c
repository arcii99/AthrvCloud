//FormAI DATASET v1.0 Category: Robot movement control ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_X 1000
#define MAX_Y 1000

// This is the struct that represents the robot's position and orientation
typedef struct {
    int posX;
    int posY;
    int orientation; // 0: North, 1: East, 2: South, 3: West
} RobotPos;

// This function initializes the robot at the given position and orientation
RobotPos initRobot(int x, int y, int orientation) {
    RobotPos robot = {x, y, orientation};
    return robot;
}

// This function moves the robot one step forward in the current orientation
void move(RobotPos *robot) {
    switch (robot->orientation) {
        case 0: // North
            if (robot->posY < MAX_Y - 1)
                robot->posY++;
            break;
        case 1: // East
            if (robot->posX < MAX_X - 1)
                robot->posX++;
            break;
        case 2: // South
            if (robot->posY > 0)
                robot->posY--;
            break;
        case 3: // West
            if (robot->posX > 0)
                robot->posX--;
            break;
    }
}

// This function turns the robot 90 degrees to the left
void turnLeft(RobotPos *robot) {
    robot->orientation = (robot->orientation + 3) % 4;
}

// This function turns the robot 90 degrees to the right
void turnRight(RobotPos *robot) {
    robot->orientation = (robot->orientation + 1) % 4;
}

int main() {
    // Initialize the robot at position (0, 0) facing North
    RobotPos robot = initRobot(0, 0, 0);

    // Move the robot forward 10 times
    for (int i = 0; i < 10; i++) {
        move(&robot);
        printf("Robot position: (%d, %d)\n", robot.posX, robot.posY);
    }

    // Turn the robot left and move forward 5 times
    turnLeft(&robot);
    for (int i = 0; i < 5; i++) {
        move(&robot);
        printf("Robot position: (%d, %d)\n", robot.posX, robot.posY);
    }

    // Turn the robot right and move forward 3 times
    turnRight(&robot);
    for (int i = 0; i < 3; i++) {
        move(&robot);
        printf("Robot position: (%d, %d)\n", robot.posX, robot.posY);
    }

    // Turn the robot left and move forward 2 times
    turnLeft(&robot);
    for (int i = 0; i < 2; i++) {
        move(&robot);
        printf("Robot position: (%d, %d)\n", robot.posX, robot.posY);
    }

    // Turn the robot right and move forward 1 time
    turnRight(&robot);
    move(&robot);
    printf("Robot position: (%d, %d)\n", robot.posX, robot.posY);

    return 0;
}