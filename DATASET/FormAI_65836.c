//FormAI DATASET v1.0 Category: Robot movement control ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>

// function moveForward takes one integer argument n which represents
// the number of steps the robot will take in the forward direction
void moveForward(int n) {
    printf("Robot is moving forward %d steps.\n", n);
}

// function moveBackward takes one integer argument n which represents
// the number of steps the robot will take in the backward direction
void moveBackward(int n) {
    printf("Robot is moving backward %d steps.\n", n);
}

// function turnLeft takes no arguments and turns the robot 90 degrees
// to the left
void turnLeft() {
    printf("Robot is turning left.\n");
}

// function turnRight takes no arguments and turns the robot 90 degrees
// to the right
void turnRight() {
    printf("Robot is turning right.\n");
}

// function moveInSquare takes one integer argument n which represents
// the side length of a square, and moves the robot in a square shape
// with side length n
void moveInSquare(int n) {
    int i;
    for (i = 0; i < 4; i++) {
        moveForward(n);
        turnLeft();
    }
}

// function moveRandomly takes no arguments and moves the robot in a
// random pattern, taking either 1 or 2 steps in a random direction,
// and turning randomly to either the left or the right
void moveRandomly() {
    int i;
    for (i = 0; i < 10; i++) {
        int steps = rand() % 2 + 1;
        int direction = rand() % 2;
        if (direction == 0) {
            moveForward(steps);
        } else {
            moveBackward(steps);
        }
        int turn = rand() % 2;
        if (turn == 0) {
            turnLeft();
        } else {
            turnRight();
        }
    }
}

int main() {
    // move the robot in a square
    moveInSquare(5);

    // move the robot randomly
    moveRandomly();

    return 0;
}