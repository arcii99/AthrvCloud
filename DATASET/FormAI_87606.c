//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ROWS 10
#define COLS 15

int maze[ROWS][COLS] = {
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 1},
    {1, 0, 1, 0, 1, 1, 0, 1, 1, 1, 0, 1, 0, 1, 1},
    {1, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 1},
    {1, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1},
    {1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1},
    {1, 0, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1},
    {1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1},
    {1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1, 0, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
};

bool solveMaze(int row, int col)
{
    if (maze[row][col] == 9) {
        return true;
    }

    if (maze[row][col] == 1) {
        return false;
    }

    maze[row][col] = 1;

    if (row != 0) {
        if (solveMaze(row - 1, col)) {
            return true;
        }
    }

    if (row != ROWS - 1) {
        if (solveMaze(row + 1, col)) {
            return true;
        }
    }

    if (col != 0) {
        if (solveMaze(row, col - 1)) {
            return true;
        }
    }

    if (col != COLS - 1) {
        if (solveMaze(row, col + 1)) {
            return true;
        }
    }

    maze[row][col] = 0;

    return false;
}

int main()
{
    int i, j;

    printf("The maze:\n");

    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            if (maze[i][j] == 0) {
                printf(". ");
            } else {
                printf("%d ", maze[i][j]);
            }
        }
        printf("\n");
    }

    if (solveMaze(1, 1)) {
        printf("\nSolution found!\n");

        for (i = 0; i < ROWS; i++) {
            for (j = 0; j < COLS; j++) {
                if (maze[i][j] == 0) {
                    printf(". ");
                } else {
                    printf("%d ", maze[i][j]);
                }
            }
            printf("\n");
        }
    } else {
        printf("\nSolution not found!\n");
    }

    return 0;
}