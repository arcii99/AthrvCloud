//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: systematic
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define ROW 10
#define COL 10

// Helper functions
void printMaze(int maze[][COL]);
void printSolution(int maze[][COL], int sol[][COL]);
bool solveMaze(int maze[][COL], int row, int col, int sol[][COL]);

int main()
{
    // Define the maze
    int maze[ROW][COL] = {
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {0, 0, 1, 0, 0, 0, 1, 0, 0, 1},
        {1, 0, 1, 0, 1, 0, 1, 0, 1, 1},
        {1, 0, 1, 0, 1, 0, 1, 0, 0, 1},
        {1, 0, 1, 0, 1, 0, 1, 1, 0, 1},
        {1, 0, 0, 0, 1, 0, 0, 0, 0, 1},
        {1, 1, 1, 0, 1, 1, 1, 1, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
    };

    // Set up solution matrix
    int sol[ROW][COL] = {0};

    // Define start position
    int row = 0, col = 0;

    // Solve the maze
    if (solveMaze(maze, row, col, sol) == false)
    {
        printf("No solution found.\n");
        return 0;
    }

    // Print the maze and the solution
    printf("Maze:\n");
    printMaze(maze);
    printf("\nSolution:\n");
    printSolution(maze, sol);

    return 0;
}

void printMaze(int maze[][COL])
{
    int i, j;
    for (i = 0; i < ROW; i++)
    {
        for (j = 0; j < COL; j++)
        {
            printf("%d ", maze[i][j]);
        }
        printf("\n");
    }
}

void printSolution(int maze[][COL], int sol[][COL])
{
    int i, j;
    for (i = 0; i < ROW; i++)
    {
        for (j = 0; j < COL; j++)
        {
            if (sol[i][j] == 1)
            {
                printf("x ");
            }
            else
            {
                printf("%d ", maze[i][j]);
            }
        }
        printf("\n");
    }
}

bool solveMaze(int maze[][COL], int row, int col, int sol[][COL])
{
    // Check if we have reached the end
    if (row == ROW - 1 && col == COL - 1)
    {
        sol[row][col] = 1;
        return true;
    }
 
    // Check if we are within the boundaries of the maze
    if (row >= 0 && row < ROW && col >= 0 && col < COL && maze[row][col] == 1 && sol[row][col] == 0)
    {
        // Mark the current cell as part of the path
        sol[row][col] = 1;
 
        // Try moving in all four directions
        if (solveMaze(maze, row + 1, col, sol) == true)
        {
            return true;
        }
 
        if (solveMaze(maze, row, col + 1, sol) == true)
        {
            return true;
        }
 
        if (solveMaze(maze, row - 1, col, sol) == true)
        {
            return true;
        }
 
        if (solveMaze(maze, row, col - 1, sol) == true)
        {
            return true;
        }
 
        // If none of the directions work, backtrack and unmark the current cell
        sol[row][col] = 0;
        return false;
    }
 
    return false;
}