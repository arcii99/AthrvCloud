//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>

#define ROWS 10
#define COLS 10

// Maze
char maze[ROWS][COLS] = {
    {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
    {'#', '.', '.', '#', '.', '.', '.', '#', '.', '#'},
    {'#', '.', '.', '#', '.', '#', '.', '.', '.', '#'},
    {'#', '.', '.', '.', '.', '#', '.', '#', '.', '#'},
    {'#', '.', '.', '#', '.', '.', '.', '.', '.', '#'},
    {'#', '#', '.', '#', '.', '#', '.', '.', '#', '#'},
    {'#', '.', '.', '.', '.', '.', '#', '.', '.', '#'},
    {'#', '.', '#', '#', '#', '.', '#', '#', '.', '#'},
    {'#', '.', '.', '.', '#', '.', '.', '.', '.', '#'},
    {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'}
};

// Utility function to print the maze
void printMaze()
{
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            printf("%c ", maze[i][j]);
        }
        printf("\n");
    }
}

// Recursive function to find the route through the maze
int solveMaze(int x, int y)
{
    if (maze[x][y] == 'X')
    {
        // We found the end of the maze!
        return 1;
    }
    else if (maze[x][y] == '#')
    {
        // Hit a wall, can't go further in this direction
        return 0;
    }
    else if (maze[x][y] == '.')
    {
        // Mark the current position as part of the solution path
        maze[x][y] = 'o';

        // Try moving in all four directions
        if (solveMaze(x + 1, y) || solveMaze(x - 1, y) || solveMaze(x, y + 1) || solveMaze(x, y - 1))
        {
            // We found a solution path
            return 1;
        }
        else
        {
            // No solution path found, mark current position as visited
            maze[x][y] = 'v';
            return 0;
        }
    }
}

// Main function
int main()
{
    printf("Maze before solving:\n");
    printMaze();

    if (solveMaze(1, 1))
    {
        printf("Maze after solving:\n");
        printMaze();
    }
    else
    {
        printf("No solution found.\n");
    }

    return 0;
}