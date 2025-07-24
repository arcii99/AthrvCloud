//FormAI DATASET v1.0 Category: Robot movement control ; Style: paranoid
#include <stdio.h>

#define LEFT 0
#define RIGHT 1

int main() {
    int direction = LEFT; // Initial direction set to left
    int steps_taken = 0; // Initially robot haven't taken any steps
    int paranoid_mode = 1; // Robot is in paranoid mode

    printf("Robot movement control program starting...\n");

    while (paranoid_mode) {
        if (direction == LEFT) {
            printf("Robot is moving left\n");
            steps_taken++; // Increment steps taken counter
        }
        else {
            printf("Robot is moving right\n");
            steps_taken++; // Increment steps taken counter
        }

        if (steps_taken == 20) {
            printf("Robot has taken 20 steps, stopping...\n");
            paranoid_mode = 0; // Turn off paranoid mode
        }

        if (steps_taken % 5 == 0) {
            printf("Robot is checking for danger...\n");

            if (danger_detected()) {
                printf("Danger detected, turning around...\n");
                direction = !direction;
            }
            else {
                printf("No danger detected\n");
            }
        }
    }

    printf("Robot movement control program ending\n");

    return 0;
}

int danger_detected() {
    int random_number = rand() % 50; // Generate a random number from 0-49

    if (random_number < 10) {
        return 1; // Danger detected
    }
    else {
        return 0; // No danger detected
    }
}