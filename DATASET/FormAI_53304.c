//FormAI DATASET v1.0 Category: Robot movement control ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL)); // Set random seed

    int x = 0, y = 0, direction = 0; // Initialize robot's position and direction
    // Directions: 0 = north, 1 = east, 2 = south, 3 = west

    printf("Starting position: (%d, %d)\n", x, y);

    int i;
    for (i = 0; i < 10; i++) { // Move robot 10 times
        int r = rand() % 2; // Randomly choose to turn or move forward
        if (r == 0) { // Turn
            r = rand() % 2; // Randomly choose to turn left or right
            if (r == 0) { // Turn left
                direction--;
            } else { // Turn right
                direction++;
            }
            while (direction < 0) { // Keep direction within bounds
                direction += 4;
            }
            direction %= 4;
            printf("Robot turned ");
            if (r == 0) {
                printf("left.\n");
            } else {
                printf("right.\n");
            }
        } else { // Move forward
            if (direction == 0) { // North
                y++;
            } else if (direction == 1) { // East
                x++;
            } else if (direction == 2) { // South
                y--;
            } else if (direction == 3) { // West
                x--;
            }
            printf("Robot moved to position (%d, %d).\n", x, y);
        }
    }

    return 0;
}