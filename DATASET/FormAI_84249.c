//FormAI DATASET v1.0 Category: Robot movement control ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>

// Function prototypes
void moveForward();
void turnRight();
void turnLeft();
void stop();

int main() {
    int direction = 0; // 0 = north, 1 = east, 2 = south, 3 = west
    bool running = true;

    printf("Starting robot...\n");
    sleep(1);

    while (running) {
        // Move the robot forward
        moveForward();

        // Generate a random number for the next move
        int moveChoice = rand() % 3;

        // Make a turn based on the random number
        switch (moveChoice) {
            case 0:
                turnLeft();
                break;
            case 1:
                turnRight();
                break;
            case 2:
                // Do nothing, move forward again
                break;
        }

        // Update the direction of the robot
        direction = (direction + moveChoice - 1) % 4;

        // Check if the robot has reached the edge of the room
        if (direction == 0) {
            printf("Robot has reached the north edge of the room.\n");
            stop();
            running = false;
        } else if (direction == 1) {
            printf("Robot has reached the east edge of the room.\n");
            stop();
            running = false;
        } else if (direction == 2) {
            printf("Robot has reached the south edge of the room.\n");
            stop();
            running = false;
        } else if (direction == 3) {
            printf("Robot has reached the west edge of the room.\n");
            stop();
            running = false;
        }
    }

    return 0;
}

// Move the robot forward
void moveForward() {
    printf("Moving forward...\n");
    sleep(1);
}

// Turn the robot right
void turnRight() {
    printf("Turning right...\n");
    sleep(1);
}

// Turn the robot left
void turnLeft() {
    printf("Turning left...\n");
    sleep(1);
}

// Stop the robot
void stop() {
    printf("Stopping robot...\n");
    sleep(1);
}