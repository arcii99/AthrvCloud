//FormAI DATASET v1.0 Category: Robot movement control ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int robots[10][10]; // Create a 10x10 grid for the robots
    int x = 0, y = 0; // Initialize robot position to (0, 0)
    int direction = 0; // Initialize robot direction to North (0)

    srand(time(NULL)); // Seed the random number generator

    // Randomly place 10 obstacles on the grid
    for (int i = 0; i < 10; i++) {
        int obs_x = rand() % 10;
        int obs_y = rand() % 10;
        robots[obs_y][obs_x] = 1;
    }

    printf("Starting position: (%d, %d)\n", x, y);

    for (int i = 0; i < 20; i++) { // Move the robot 20 times
        int new_x = x, new_y = y; // Initialize new robot position

        // Determine new position based on direction
        switch(direction) {
            case 0: // North
                new_y--;
                break;
            case 1: // East
                new_x++;
                break;
            case 2: // South
                new_y++;
                break;
            case 3: // West
                new_x--;
                break;
        }

        // Check if new position is within the grid
        if (new_x >= 0 && new_x < 10 && new_y >= 0 && new_y < 10) {
            // Check if new position is not an obstacle
            if (robots[new_y][new_x] != 1) {
                x = new_x;
                y = new_y;
            } else {
                printf("Obstacle at (%d, %d)\n", new_x, new_y);
            }
        } else {
            printf("Boundary reached at (%d, %d)\n", new_x, new_y);
        }

        // Randomly change direction for next move
        direction = rand() % 4;

        printf("Position after move %d: (%d, %d)\n", i+1, x, y);
    }

    return 0;
}