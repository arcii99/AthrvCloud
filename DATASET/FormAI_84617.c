//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10
#define COLS 10
#define WALL '#'
#define PATH ' '

int main() {
    char maze[ROWS][COLS];
    int i, j;
    srand(time(NULL));

    // Generate maze walls
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            if (i == 0 || i == ROWS - 1 || j == 0 || j == COLS - 1) {
                maze[i][j] = WALL;  // Enclose maze borders
            } else {
                maze[i][j] = (rand() % 2 == 0) ? WALL : PATH;  // Randomly place walls/path
            }
        }
    }

    // Print maze
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            printf("%c", maze[i][j]);
        }
        printf("\n");
    }

    return 0;
}