//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ROWS 15
#define COLS 20

int maze[ROWS][COLS] = {
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,1,1,1,1,0,1,1,1,0,0,0,0,0,0,0,0,1,1,1},
    {1,1,1,0,1,0,1,1,1,0,1,1,1,1,1,1,0,1,1,1},
    {1,1,1,0,1,0,0,0,0,0,1,1,1,1,1,1,0,1,1,1},
    {1,1,1,0,1,1,0,1,1,1,1,1,1,1,1,1,0,1,1,1},
    {1,1,1,0,0,0,0,1,1,1,1,1,1,1,1,1,0,1,1,1},
    {1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1},
    {1,1,1,0,0,0,0,0,0,1,1,1,1,1,1,1,0,1,1,1},
    {1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,0,1,1,1},
    {1,1,1,0,0,0,0,0,0,1,1,0,0,0,0,0,0,1,1,1},
    {1,1,1,0,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1},
    {1,1,1,0,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1},
    {1,0,0,0,0,0,0,0,0,1,1,0,1,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1}
};

int startRow = 1;
int startCol = 1;
int endRow = 13;
int endCol = 18;

bool isMovable(int x, int y) {
    if (x >= ROWS || y >= COLS || x < 0 || y < 0) {
        return false;
    }
    return (maze[x][y] == 0);
}

bool findRoute(int x, int y) {
    if (x == endRow && y == endCol) {
        return true;
    }

    if (isMovable(x, y)) {
        maze[x][y] = 2; // mark as visited

        // Move right
        if (findRoute(x, y+1)) {
            return true;
        }

        // Move down
        if (findRoute(x+1, y)) {
            return true;
        }

        // Move left
        if (findRoute(x, y-1)) {
            return true;
        }

        // Move up
        if (findRoute(x-1, y)) {
            return true;
        }

        maze[x][y] = 0; // mark as unvisited
    }

    return false;
}

int main() {
    if (findRoute(startRow, startCol)) {
        printf("Wow, you have found the way out of the maze! Here is the path:\n");
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                if (maze[i][j] == 0) {
                    printf(".");
                } else if (maze[i][j] == 1) {
                    printf("#");
                } else if (maze[i][j] == 2) {
                    printf("*");
                }
            }
            printf("\n");
        }
    } else {
        printf("Oops, there is no way out of this maze. Please try again. :)\n");
    }
    return 0;
}