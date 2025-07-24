//FormAI DATASET v1.0 Category: Robot movement control ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_DISTANCE 100 // Maximum distance the robot can move in one step

int main() {
    srand(time(NULL)); // Seed the random number generator with the current time

    int x = 0, y = 0; // Initial position of the robot
    printf("Starting position: (%d, %d)\n", x, y);

    while (1) { // Loop infinitely until user terminates program
        int dx = rand() % (2 * MAX_DISTANCE + 1) - MAX_DISTANCE; // Compute random x-distance to move
        int dy = rand() % (2 * MAX_DISTANCE + 1) - MAX_DISTANCE; // Compute random y-distance to move
        printf("Moving to (%d, %d)\n", x+dx, y+dy);
        x += dx; // Update current position
        y += dy;

        char input; // Prompt user for input to continue or terminate program
        printf("Type 'q' to quit, anything else to continue: ");
        scanf(" %c", &input);
        if (input == 'q') {
            break; // Exit program if user enters 'q'
        }
    }

    printf("Final position: (%d, %d)\n", x, y);
    return 0;
}