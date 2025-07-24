//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ROW 5
#define COL 6

/* Maze */
int maze[ROW][COL] = {
    {0, 0, 0, 0, 0, 0},
    {1, 1, 0, 1, 1, 0},
    {0, 0, 0, 0, 0, 0},
    {0, 1, 1, 1, 1, 1},
    {0, 0, 0, 0, 0, 0}
};

/* Check if the current postion is valid */
bool isValid(int x, int y) {
    if (x < 0 || x >= ROW || y < 0 || y >= COL || maze[x][y] == 1)
        return false;
    
    return true;
}

/* Print the maze */
void printMaze(int path[ROW][COL]) {
    printf("The path is:\n");
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            if (maze[i][j] == 1) {
                printf("X ");
            } else if (path[i][j] == 1) {
                printf("P ");
            } else {
                printf("O ");
            }
        }
        printf("\n");
    }
}

/* Find Path */
bool findPath(int x, int y, int path[ROW][COL]) {
    /* Base Case */
    if (x == ROW - 1 && y == COL - 1) {
        path[x][y] = 1;
        return true;
    }

    if (isValid(x, y)) {
        /* Mark the current position */
        path[x][y] = 1;

        /* Move Right */
        if (findPath(x, y+1, path))
            return true;

        /* Move Down */
        if (findPath(x+1, y, path))
            return true;

        /* Unmark the current position */
        path[x][y] = 0;
    }

    return false;
}

int main() {
    /* Array to keep track of visited positions */
    int path[ROW][COL] = {0};

    /* Starting position */
    int x = 0;
    int y = 0;

    /* Find Path */
    if (findPath(x, y, path)) {
        printMaze(path);
    } else {
        printf("No path found.\n");
    }

    return 0;
}