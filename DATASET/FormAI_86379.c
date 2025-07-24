//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: visionary
#include <stdio.h>
#define n 4 

void printSolution(int maze[n][n])
{
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            printf("%d ", maze[i][j]);
        }
        printf("\n");
    }
}

int solveMazeUtil(int maze[n][n], int x, int y, int sol[n][n])
{
    if(x == n - 1 && y == n - 1) {
        sol[x][y] = 1;
        return 1;
    }
    
    if(x >= 0 && x < n && y >= 0 && y < n && maze[x][y] == 1) {
        sol[x][y] = 1;

        if(solveMazeUtil(maze, x + 1, y, sol) == 1) {
            return 1;
        }

        if(solveMazeUtil(maze, x, y + 1, sol) == 1) {
            return 1;
        }

        sol[x][y] = 0;
        return 0;
    }
    return 0;
}

int solveMaze(int maze[n][n])
{
    int sol[n][n] = { { 0, 0, 0, 0 },
                      { 0, 0, 0, 0 },
                      { 0, 0, 0, 0 },
                      { 0, 0, 0, 0 } };

    if(solveMazeUtil(maze, 0, 0, sol) == 0) {
        printf("Solution doesn't exist!");
        return 0;
    }

    printSolution(sol);
    return 1;
}

int main()
{
    int maze[n][n] = { { 1, 0, 0, 0 },
                       { 1, 1, 0, 1 },
                       { 0, 1, 0, 0 },
                       { 1, 1, 1, 1 } };

    solveMaze(maze);
    return 0;
}