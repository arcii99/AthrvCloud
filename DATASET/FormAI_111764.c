//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: intelligent
#include<stdio.h>

#define N 4 // size of the maze

/*
* The maze is represented by a 2D matrix where 0 represents a blocked path 
* and 1 represents an open path.
*/
int maze[N][N] = {{1, 0, 1, 1},
                {1, 1, 1, 0},
                {0, 1, 0, 1},
                {1, 1, 1, 1}};

int sol[N][N]; //  Solution matrix

void printSolution()
{
    printf("The solved maze is:\n");
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            printf("%d ", sol[i][j]);
        }
        printf("\n");
    }
}

int isSafe(int x, int y)
{
    // If (x, y) is a valid position and there is an open path
    if (x >= 0 && x < N && y >= 0 && y < N && maze[x][y] == 1)
        return 1;

    return 0;
}

int solveMazeUtil(int x, int y)
{
    // If the destination is reached
    if (x == N - 1 && y == N - 1)
    {
        sol[x][y] = 1;
        return 1;
    }

    // Check if (x, y) is a valid position
    if (isSafe(x, y) == 1)
    {
        sol[x][y] = 1; // Mark (x, y) as part of solution path

        // Move in the x direction
        if (solveMazeUtil(x + 1, y) == 1)
            return 1;
  
        // If moving in the x direction doesn't work,
        // move in the y direction
        if (solveMazeUtil(x, y + 1) == 1)
            return 1;
  
        // If neither of the directions work,
        // unmark (x, y) as part of the solution path 
        sol[x][y] = 0;
        return 0;
    }

    return 0;
}

void solveMaze()
{
    // Initialize solution matrix to all 0's
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            sol[i][j] = 0;
        }
    }

    // Start solving the maze from the top left corner
    if (solveMazeUtil(0, 0) == 0)
    {
        printf("Solution doesn't exist.");
    }

    printSolution();
}

int main()
{
    solveMaze();
    return 0;
}