//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 20
#define HEIGHT 10

int main() {
    srand(time(NULL));

    // Create maze grid
    int maze[HEIGHT][WIDTH];

    // Fill maze with walls
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            maze[i][j] = 1;
        }
    }

    // Generate random starting point
    int startX = rand() % (WIDTH - 2) + 1;
    int startY = rand() % (HEIGHT - 2) + 1;

    // Mark starting point as open
    maze[startY][startX] = 0;

    // Create list of directions
    int directions[4][2] = {{0,-1}, {0,1}, {-1,0}, {1,0}};

    // Randomly traverse maze
    int x = startX;
    int y = startY;
    while (1) {
        // Generate random direction
        int dir = rand() % 4;

        // Calculate new position
        int newX = x + directions[dir][0];
        int newY = y + directions[dir][1];

        // Check if new position is within bounds
        if (newX >= 0 && newX < WIDTH && newY >= 0 && newY < HEIGHT) {
            // Check if new position is a wall
            if (maze[newY][newX] == 1) {
                // Open up wall and move to new position
                maze[newY][newX] = 0;
                maze[y + directions[dir][1]/2][x + directions[dir][0]/2] = 0;
                x = newX;
                y = newY;
            }
        }

        // Check if all walls have been opened up
        int allOpen = 1;
        for (int i = 0; i < HEIGHT; i++) {
            for (int j = 0; j < WIDTH; j++) {
                if (maze[i][j] == 1) {
                    allOpen = 0;
                }
            }
        }
        if (allOpen) {
            break;
        }
    }

    // Print maze
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            if (maze[i][j] == 1) {
                printf("█ ");
            } else {
                printf("  ");
            }
        }
        printf("\n");
    }

    return 0;
}