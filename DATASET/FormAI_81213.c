//FormAI DATASET v1.0 Category: Robot movement control ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define movement constants
#define FORWARD 1
#define BACKWARD -1
#define LEFT 2
#define RIGHT -2

// Robot position and direction
int x = 0;
int y = 0;
int direction = FORWARD;

// Function to move the robot
void move(int steps) {
    if (direction == FORWARD) {
        y += steps;
    } else if (direction == BACKWARD) {
        y -= steps;
    } else if (direction == LEFT) {
        x -= steps;
    } else if (direction == RIGHT) {
        x += steps;
    }
}

// Function to turn the robot
void turn(int degrees) {
    direction += degrees;
    if (direction > RIGHT) {
        direction = FORWARD;
    } else if (direction < FORWARD) {
        direction = RIGHT;
    }
}

int main() {
    // Seed the random number generator with the current time
    srand(time(NULL));

    // Move the robot randomly for a few steps
    for (int i = 0; i < 20; i++) {
        int steps = rand() % 10 + 1;
        int action = rand() % 2;

        if (action == 0) {
            move(steps);
            printf("Moved %d steps %s.\n", steps, (direction == FORWARD) ? "forward" : (direction == BACKWARD) ? "backward" : (direction == LEFT) ? "left" : "right");
        } else {
            int degrees = ((rand() % 2) == 0) ? 90 : -90;
            turn(degrees);
            printf("Turned %d degrees %s.\n", abs(degrees), (degrees > 0) ? "right" : "left");
        }
    }

    // Display final position and direction of the robot
    printf("\nFinal position: (%d, %d)\n", x, y);
    printf("Direction: %s\n", (direction == FORWARD) ? "forward" : (direction == BACKWARD) ? "backward" : (direction == LEFT) ? "left" : "right");

    return 0;
}