//FormAI DATASET v1.0 Category: Robot movement control ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define States
typedef enum {
    FORWARD,
    BACKWARD,
    LEFT,
    RIGHT,
    IDLE
} RobotState;

// Define Functions
void moveForward();
void moveBackward();
void turnLeft();
void turnRight();
void idle();

// Define main function
int main() {
    srand(time(NULL));
    RobotState currentState = IDLE;

    while (1) {
        int randomNum = rand() % 5;

        // Change state based on random number
        switch (randomNum) {
            case FORWARD:
                currentState = FORWARD;
                break;
            case BACKWARD:
                currentState = BACKWARD;
                break;
            case LEFT:
                currentState = LEFT;
                break;
            case RIGHT:
                currentState = RIGHT;
                break;
            case IDLE:
                currentState = IDLE;
                break;
            default:
                printf("Invalid state.\n");
                break;
        }

        // Execute current state
        switch (currentState) {
            case FORWARD:
                moveForward();
                break;
            case BACKWARD:
                moveBackward();
                break;
            case LEFT:
                turnLeft();
                break;
            case RIGHT:
                turnRight();
                break;
            case IDLE:
                idle();
                break;
            default:
                printf("Invalid state.\n");
                break;
        }
    }

    return 0;
}

// Define Functions
void moveForward() {
    printf("Moving Forward.\n");
}

void moveBackward() {
    printf("Moving Backward.\n");
}

void turnLeft() {
    printf("Turning Left.\n");
}

void turnRight() {
    printf("Turning Right\n");
}

void idle() {
    printf("Idle.\n");
}