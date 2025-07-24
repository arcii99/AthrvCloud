//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: automated
#include <stdio.h>
#include <stdlib.h>

#define ROW 10
#define COL 15

// Maze
int maze[ROW][COL] = {
    {1,0,0,0,0,1,1,1,0,1,0,0,0,1,1},
    {1,0,0,1,0,0,0,0,0,1,0,0,0,1,1},
    {1,0,0,1,1,1,0,0,0,1,0,0,1,0,0},
    {1,0,0,0,0,0,0,1,0,0,0,0,0,0,1},
    {1,0,0,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,0,0,0,0,0,0,1,0,0,0,0,0,0,1},
    {1,0,0,1,0,0,1,1,1,1,0,0,1,0,0},
    {1,0,0,1,1,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,1,1,1,0,0,1,1,1},
    {1,1,1,1,1,1,1,1,0,1,0,0,0,0,1}
};

// Array containing path
int path[ROW][COL];

// Functions
void printMaze();
int findPath(int, int);

int main()
{
    // Print maze
    printMaze();

    // Find path starting from the top left corner
    if(findPath(0, 0))
    {
        printf("\n\nPath found!\n");
        printMaze();
    }
    else
    {
        printf("\n\nNo path found.\n");
    }
    
    return 0;
}

// Function to print the maze
void printMaze()
{
    printf("MAZE:\n");
    for(int i=0; i<ROW; i++)
    {
        for(int j=0; j<COL; j++)
        {
            printf("%d ", maze[i][j]);
        }
        printf("\n");
    }
}

// Function to find path through the maze recursively
int findPath(int row, int col)
{
    // Check if we have reached the bottom right corner
    if(row == ROW-1 && col == COL-1)
    {
        path[row][col] = 1;
        return 1;
    }

    // Check if current cell is valid
    if(row < 0 || row >= ROW || col < 0 || col >= COL || maze[row][col] == 0 || path[row][col] == 1)
    {
        return 0;
    }

    // Mark the current cell as part of the path
    path[row][col] = 1;

    // Recursively check all neighbouring cells
    if(findPath(row-1, col) || findPath(row+1, col) || findPath(row, col-1) || findPath(row, col+1))
    {
        return 1;
    }

    // If no path is found, unmark current cell and return 0
    path[row][col] = 0;
    return 0;
}