//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 20
#define HEIGHT 10

void generateMaze(int maze[HEIGHT][WIDTH], int x, int y);

int main(void) {
    int maze[HEIGHT][WIDTH];
    srand(time(NULL));  // Set random seed with current time

    // Generate maze starting from position (0, 0)
    generateMaze(maze, 0, 0);

    // Print the maze
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            if (maze[i][j] == 0) {
                printf("# ");  // Wall
            } else if (maze[i][j] == 1) {
                printf("  ");  // Path
            } else if (maze[i][j] == 2) {
                printf("S ");  // Start
            } else if (maze[i][j] == 3) {
                printf("E ");  // End
            }
        }
        printf("\n");
    }

    return 0;
}

void generateMaze(int maze[HEIGHT][WIDTH], int x, int y) {
    // Set start and end points
    maze[y][x] = 2;  // Start
    maze[HEIGHT-1][WIDTH-1] = 3;  // End

    // Check if maze generation is complete
    int complete = 1;
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            if (maze[i][j] == 0) {
                complete = 0;
                break;
            }
        }
        if (!complete) {
            break;
        }
    }
    if (complete) {
        return;
    }

    // Randomly select a direction to carve
    int directions[4][2] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};  // Up, down, left, right
    int dirIndex;
    do {
        dirIndex = rand() % 4;
    } while ((x == 0 && dirIndex == 2)  // Don't carve left if at left edge
             || (y == 0 && dirIndex == 0)  // Don't carve up if at top edge
             || (x == WIDTH-1 && dirIndex == 3)  // Don't carve right if at right edge
             || (y == HEIGHT-1 && dirIndex == 1));  // Don't carve down if at bottom edge

    // Carve path in the selected direction
    int newX = x + directions[dirIndex][0];
    int newY = y + directions[dirIndex][1];
    if (maze[newY][newX] == 0) {
        maze[newY][newX] = 1;  // Path
    }

    // Recursively generate next part of the maze
    generateMaze(maze, newX, newY);
}