//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ROW 8
#define COL 8

// Function to print the solution matrix
void printSolution(int sol[ROW][COL])
{
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++)
            printf(" %2d ", sol[i][j]);
        printf("\n");
    }
}

// Function to check if given indices are within bounds
bool isValid(int x, int y)
{
    return (x >= 0 && x < ROW && y >= 0 && y < COL);
}

// Function to check if the current cell is safe to move
bool isSafe(int maze[ROW][COL], int x, int y)
{
    return (isValid(x, y) && maze[x][y] == 1);
}

// Recursive function to find the path in the maze
bool findPath(int maze[ROW][COL], int x, int y, int sol[ROW][COL])
{
    // if we have reached the destination, return true
    if (x == ROW - 1 && y == COL - 1) {
        sol[x][y] = 1;
        return true;
    }
    // check if the current cell is safe to move
    if (isSafe(maze, x, y)) {
        // mark the current cell as part of solution
        sol[x][y] = 1;
        // move down
        if (findPath(maze, x + 1, y, sol))
            return true;
        // move right
        if (findPath(maze, x, y + 1, sol))
            return true;
        // if none of the moves worked, backtrack
        sol[x][y] = 0;
        return false;
    }
    return false;
}

// Main function to solve the maze
void solveMaze(int maze[ROW][COL])
{
    int sol[ROW][COL] = { {0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0}
                        };
    // start from the top-left corner
    int x = 0, y = 0;
    if (findPath(maze, x, y, sol))
        printSolution(sol);
    else
        printf("No solution exists\n");
}

// Driver function
int main()
{
    int maze[ROW][COL] = { {1, 0, 0, 0, 0, 0, 0, 0},
                          {1, 1, 1, 1, 1, 1, 0, 1},
                          {0, 1, 0, 0, 0, 0, 0, 1},
                          {1, 1, 0, 1, 1, 1, 1, 1},
                          {0, 1, 1, 1, 0, 0, 0, 0},
                          {0, 0, 0, 1, 0, 0, 0, 0},
                          {0, 1, 1, 1, 1, 1, 1, 1},
                          {0, 0, 0, 0, 0, 0, 0, 1}
                        };
    solveMaze(maze);
    return 0;
}