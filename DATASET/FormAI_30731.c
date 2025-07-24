//FormAI DATASET v1.0 Category: Robot movement control ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define FORWARD 'w'
#define BACKWARD 's'
#define LEFT 'a'
#define RIGHT 'd'

int main() {
    // Set up random seed
    srand(time(NULL));

    int moveChoice, steps = 0;
    char direction = FORWARD;

    // Introduce robot
    printf("Hello! I am the Genius Robot.\n");
    printf("I can move around on a 2D plane.\n");
    printf("Let me show you my skills.\n");

    // Generate random number of steps to take
    steps = rand() % 101;
    printf("I am going to move %d steps.\n", steps);

    // Move around randomly on 2D plane
    for (int i = 0; i < steps; i++) {
        // Generate random direction to move
        moveChoice = rand() % 4;

        if (moveChoice == 0) {
            printf("I am moving forward.\n");
            direction = FORWARD;
        } else if (moveChoice == 1) {
            printf("I am moving backward.\n");
            direction = BACKWARD;
        } else if (moveChoice == 2) {
            printf("I am moving left.\n");
            direction = LEFT;
        } else {
            printf("I am moving right.\n");
            direction = RIGHT;
        }

        // Move in chosen direction
        switch (direction) {
            case FORWARD:
                printf("Moved forward.\n");
                break;
            case BACKWARD:
                printf("Moved backward.\n");
                break;
            case LEFT:
                printf("Moved left.\n");
                break;
            case RIGHT:
                printf("Moved right.\n");
                break;
        }
    }

    printf("I am done moving now! Wasn't that impressive?\n");

    return 0;
}