//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: ultraprecise
#include <stdio.h>

// Defining the size of the maze
#define ROW 7
#define COL 10

// Function to check if the given cell is valid or not
int isValid(int x, int y, int maze[][COL])
{
    if (x >= 0 && x < ROW && y >= 0 && y < COL && maze[x][y] == 1)
    {
        return 1;
    }
    return 0;
}

// Function to solve the maze using recursion
int solveMazeUtil(int maze[][COL], int x, int y, int sol[][COL])
{
    // Check if we have reached the end of the maze
    if (x == ROW - 1 && y == COL - 1 && maze[x][y] == 1)
    {
        sol[x][y] = 1;
        return 1;
    }

    // Check if the given cell is valid or not
    if (isValid(x, y, maze) == 1)
    {
        // Mark the current cell as part of the solution
        sol[x][y] = 1;

        // Move right
        if (solveMazeUtil(maze, x, y+1, sol) == 1)
        {
            return 1;
        }

        // Move down
        if (solveMazeUtil(maze, x+1, y, sol) == 1)
        {
            return 1;
        }

        // Move left
        if (solveMazeUtil(maze, x, y-1, sol) == 1)
        {
            return 1;
        }

        // Move up
        if (solveMazeUtil(maze, x-1, y, sol) == 1)
        {
            return 1;
        }

        // Backtrack if none of the above movements work
        sol[x][y] = 0;
        return 0;
    }

    return 0;
}

// Function to solve the maze
void solveMaze(int maze[][COL])
{
    int sol[ROW][COL];

    // Initialize all the elements of solution matrix with 0
    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COL; j++)
        {
            sol[i][j] = 0;
        }
    }

    // If there is a solution, print the path
    if (solveMazeUtil(maze, 0, 0, sol) == 1)
    {
        printf("The solution path is: \n");
        for (int i = 0; i < ROW; i++)
        {
            for (int j = 0; j < COL; j++)
            {
                printf("%d ", sol[i][j]);
            }
            printf("\n");
        }
    }
    else
    {
        printf("There is no solution path for the given maze.\n");
    }
}

// Driver program to test the above functions
int main()
{
    int maze[ROW][COL] = {{1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {1, 1, 1, 1, 1, 1, 0, 1, 1, 1},
                          {0, 0, 0, 0, 0, 1, 0, 0, 0, 1},
                          {0, 1, 1, 1, 0, 1, 1, 1, 0, 1},
                          {0, 1, 0, 0, 0, 0, 0, 1, 0, 1},
                          {0, 1, 1, 1, 1, 1, 1, 1, 1, 1},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 1}};

    solveMaze(maze);

    return 0;
}