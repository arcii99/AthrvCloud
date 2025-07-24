//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define FORWARD 1
#define BACKWARD 2
#define LEFT_TURN 3
#define RIGHT_TURN 4
#define STOP 5

int main() {
    srand(time(NULL)); // initialize random seed

    int direction = 0; // initialize direction to 0
    int speed = rand() % 30 + 10; // generate random speed between 10 and 40 (inclusive)
    int distance = rand() % 50 + 10; // generate random distance between 10 and 60 (inclusive)

    printf("Remote control vehicle simulation\n");
    printf("Speed: %d mph\n", speed);
    printf("Distance: %d miles\n", distance);

    for (int i = 0; i < distance; i++) {
        switch(direction) {
            case FORWARD:
                printf("Moving forward...\n");
                break;
            case BACKWARD:
                printf("Moving backward...\n");
                break;
            case LEFT_TURN:
                printf("Turning left...\n");
                break;
            case RIGHT_TURN:
                printf("Turning right...\n");
                break;
            case STOP:
                printf("Stopping...\n");
                break;
            default:
                printf("Invalid direction...\n");
                break;
        }

        int action = rand() % 5 + 1; // generate random action between 1 and 5 (inclusive)

        // update direction based on action
        if (action == FORWARD || action == BACKWARD) {
            direction = action;
        } else if (action == LEFT_TURN || action == RIGHT_TURN) {
            if (direction == FORWARD) {
                if (action == LEFT_TURN) {
                    direction = LEFT_TURN;
                } else {
                    direction = RIGHT_TURN;
                }
            } else if (direction == BACKWARD) {
                if (action == LEFT_TURN) {
                    direction = RIGHT_TURN;
                } else {
                    direction = LEFT_TURN;
                }
            } else if (direction == LEFT_TURN) {
                if (action == LEFT_TURN) {
                    direction = BACKWARD;
                } else {
                    direction = FORWARD;
                }
            } else if (direction == RIGHT_TURN) {
                if (action == LEFT_TURN) {
                    direction = FORWARD;
                } else {
                    direction = BACKWARD;
                }
            }
        } else {
            direction = STOP;
        }
    }

    printf("Simulation completed.\n");

    return 0;
}