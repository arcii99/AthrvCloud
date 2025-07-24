//FormAI DATASET v1.0 Category: Robot movement control ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Defining struct for robot movement control
struct Robot {
    int xpos, ypos;
};

// Function to move robot in the x direction
void moveX(struct Robot *robot, int distance) {
    robot->xpos += distance;
    printf("Robot moved %d units in the x direction. New position: (%d, %d)\n", distance, robot->xpos, robot->ypos);
}

// Function to move robot in the y direction
void moveY(struct Robot *robot, int distance) {
    robot->ypos += distance;
    printf("Robot moved %d units in the y direction. New position: (%d, %d)\n", distance, robot->xpos, robot->ypos);
}

// Function to move robot randomly
void moveRandom(struct Robot *robot) {
    int xdir = rand() % 2; // Randomly choosing between 0 and 1 to decide x direction
    int ydir = rand() % 2; // Randomly choosing between 0 and 1 to decide y direction
    int xdist = rand() % 11; // Randomly choosing distance in x direction between 0 and 10
    int ydist = rand() % 11; // Randomly choosing distance in y direction between 0 and 10
    if (xdir == 0) {
        xdist *= -1; // If 0, move leftwards (negative x direction)
    }
    if (ydir == 0) {
        ydist *= -1; // If 0, move downwards (negative y direction)
    }
    robot->xpos += xdist;
    robot->ypos += ydist;
    printf("Robot moved %d units in the x direction and %d units in the y direction. New position: (%d, %d)\n", xdist, ydist, robot->xpos, robot->ypos);
}

int main() {

    struct Robot myrobot;
    myrobot.xpos = 0;
    myrobot.ypos = 0;

    printf("Robot initialized at position (%d, %d)\n", myrobot.xpos, myrobot.ypos);

    // Move robot a specific distance in the x direction
    moveX(&myrobot, 5);

    // Move robot a specific distance in the y direction
    moveY(&myrobot, 3);

    // Move robot randomly
    srand(time(0)); // Initialize random number generator with current time
    moveRandom(&myrobot);
    moveRandom(&myrobot);
    moveRandom(&myrobot);

    return 0;
}