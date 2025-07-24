//FormAI DATASET v1.0 Category: Robot movement control ; Style: relaxed
#include <stdio.h>

#define FORWARD 1
#define BACKWARD -1
#define LEFT 1
#define RIGHT -1

void moveForward(int steps);
void moveBackward(int steps);
void turnLeft(void);
void turnRight(void);

int main(void) {
    int direction = FORWARD; // assume robot is facing forward
    int position = 0; // starting position is 0

    printf("Robot starting position: %d\n", position);

    // move forward 5 steps
    moveForward(5);
    position += 5;

    printf("Robot position after moving forward: %d\n", position);

    // turn right
    turnRight();
    direction = RIGHT;

    // move backward 3 steps
    moveBackward(3);
    position -= 3;

    printf("Robot position after moving backward: %d\n", position);

    // turn left
    turnLeft();
    direction = LEFT;

    // move forward 2 steps
    moveForward(2);
    position += 2;

    printf("Robot position after moving forward: %d\n", position);

    return 0;
}

void moveForward(int steps) {
    printf("Moving forward %d steps\n", steps);
    // code to move robot forward goes here
}

void moveBackward(int steps) {
    printf("Moving backward %d steps\n", steps);
    // code to move robot backward goes here
}

void turnLeft(void) {
    printf("Turning left\n");
    // code to turn robot left goes here
}

void turnRight(void) {
    printf("Turning right\n");
    // code to turn robot right goes here
}