//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: mind-bending
#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 10

int maze[MAX_SIZE][MAX_SIZE] = {
    {1, 0, 1, 1, 1},
    {1, 1, 1, 0, 1},
    {0, 0, 0, 0, 1},
    {1, 1, 1, 0, 1},
    {1, 0, 1, 1, 1}
};

int path[MAX_SIZE][MAX_SIZE] = {0};

void printSolution(int n)
{
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            printf(" %d ", path[i][j]);
        printf("\n");
    }
}

bool isValidMove(int row, int col, int n)
{
    if (row >= 0 && col >= 0 && row < n && col < n && maze[row][col] == 1)
        return true;
    return false;
}

bool solveMazeUtil(int row, int col, int n)
{
    if (row == n - 1 && col == n - 1) {
        path[row][col] = 1;
        return true;
    }

    if (isValidMove(row, col, n)) {
        path[row][col] = 1;

        if (solveMazeUtil(row + 1, col, n))
            return true;

        if (solveMazeUtil(row, col + 1, n))
            return true;

        path[row][col] = 0;
        return false;
    }

    return false;
}

void solveMaze(int n)
{
    if (solveMazeUtil(0, 0, n))
        printSolution(n);
    else
        printf("Solution does not exist.\n");
}

int main()
{
    solveMaze(MAX_SIZE);
    return 0;
}