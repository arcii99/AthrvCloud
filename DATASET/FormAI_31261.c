//FormAI DATASET v1.0 Category: Robot movement control ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_X 20
#define MAX_Y 20

// Function to generate random number between min and max
int generateRandomNumber(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

int main() {
    // Seed random number generator
    srand(time(NULL));

    // Initialize robot position
    int robot_x = generateRandomNumber(1, MAX_X);
    int robot_y = generateRandomNumber(1, MAX_Y);

    // Define robot possible movement directions
    char directions[] = {'N', 'S', 'E', 'W'};

    // Begin robot movement
    while(1) {
        // Determine new movement direction
        int direction_index = generateRandomNumber(0, 3);
        char direction = directions[direction_index];

        // Determine new robot position based on movement direction
        int new_x = robot_x;
        int new_y = robot_y;
        if (direction == 'N') {
            new_y++;
        } else if (direction == 'S') {
            new_y--;
        } else if (direction == 'E') {
            new_x++;
        } else if (direction == 'W') {
            new_x--;
        }

        // Check if new position is within the boundaries
        if (new_x >= 1 && new_x <= MAX_X && new_y >= 1 && new_y <= MAX_Y) {
            // Set new robot position
            robot_x = new_x;
            robot_y = new_y;

            // Print new robot position
            printf("Robot moved %c and is now at position (%d,%d)\n", direction, robot_x, robot_y);
        }
    }

    return 0;
}