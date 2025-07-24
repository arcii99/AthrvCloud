//FormAI DATASET v1.0 Category: Robot movement control ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>

// Robot structure to store the location and direction
struct Robot {
    int x, y; // x and y coordinates
    char direction; // N, S, E, or W for North, South, East, and West respectively
};

// Function to move the robot forward one unit based on its direction
void moveForward(struct Robot *robot) {
    switch(robot->direction) {
        case 'N':
            robot->y++;
            break;
        case 'S':
            robot->y--;
            break;
        case 'E':
            robot->x++;
            break;
        case 'W':
            robot->x--;
            break;
    }
}

// Function to turn the robot left by changing its direction
void turnLeft(struct Robot *robot) {
    switch(robot->direction) {
        case 'N':
            robot->direction = 'W';
            break;
        case 'S':
            robot->direction = 'E';
            break;
        case 'E':
            robot->direction = 'N';
            break;
        case 'W':
            robot->direction = 'S';
            break;
    }
}

// Function to turn the robot right by changing its direction
void turnRight(struct Robot *robot) {
    switch(robot->direction) {
        case 'N':
            robot->direction = 'E';
            break;
        case 'S':
            robot->direction = 'W';
            break;
        case 'E':
            robot->direction = 'S';
            break;
        case 'W':
            robot->direction = 'N';
            break;
    }
}

int main() {
    struct Robot myRobot = {0, 0, 'N'}; // create a robot at (0, 0) facing North

    // Move the robot forward twice and then turn it left and right
    moveForward(&myRobot);
    moveForward(&myRobot);
    turnLeft(&myRobot);
    turnRight(&myRobot);

    // Print the final location and direction of the robot
    printf("Robot is at (%d, %d) facing %c\n", myRobot.x, myRobot.y, myRobot.direction);

    return 0;
}