//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10
#define COLS 20

// A retro-style pathfinding algorithm using random movements
// Starting at (0, 0), we randomly move left, right, up, or down until we reach the end

int main(void) {
    srand(time(NULL)); // Seed the random number generator with the current time

    int maze[ROWS][COLS]; // 2D array to represent the maze
    int x = 0; // Current x position in the maze
    int y = 0; // Current y position in the maze

    // Initialize the maze
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            maze[i][j] = rand() % 2; // randomly fill each cell with either 0 or 1
        }
    }

    // Print the maze
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%d", maze[i][j]);
        }
        printf("\n");
    }

    // Start moving through the maze
    while (x < COLS - 1 || y < ROWS - 1) { // Keep moving until we reach the end of the maze
        int direction = rand() % 4; // Randomly choose a direction to move in
        if (direction == 0 && x > 0 && maze[y][x-1] == 0) { // Move left
            x--;
        } else if (direction == 1 && x < COLS - 1 && maze[y][x+1] == 0) { // Move right
            x++;
        } else if (direction == 2 && y > 0 && maze[y-1][x] == 0) { // Move up
            y--;
        } else if (direction == 3 && y < ROWS - 1 && maze[y+1][x] == 0) { // Move down
            y++;
        }
    }

    printf("Congratulations! You made it to the end of the maze!\n");
    return 0;
}