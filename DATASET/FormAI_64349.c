//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: real-life
// Maze Route Finder Example

#include <stdio.h>
#include <stdlib.h>

#define ROWS 10
#define COLS 10

// Function to display the maze
void displayMaze(int maze[][COLS])
{
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++)
            printf("%d ", maze[i][j]);
        printf("\n");
    }
}

// Function to check if a given cell is valid
int isValid(int x, int y)
{
    return (x >= 0 && x < ROWS && y >= 0 && y < COLS);
}

// Function to find the route in the maze
int findRoute(int maze[][COLS], int x, int y, int soln[][COLS])
{
    // If destination is reached, return true
    if (x == ROWS - 1 && y == COLS - 1) {
        soln[x][y] = 1;
        return 1;
    }
 
    // Check if the current cell is valid
    if (isValid(x, y) && maze[x][y] == 1 && soln[x][y] != 1) {
        soln[x][y] = 1;
 
        // Move down
        if (findRoute(maze, x + 1, y, soln) == 1)
            return 1;
 
        // Move right
        if (findRoute(maze, x, y + 1, soln) == 1)
            return 1;
 
        // Move up
        if (findRoute(maze, x - 1, y, soln) == 1)
            return 1;
 
        // Move left
        if (findRoute(maze, x, y - 1, soln) == 1)
            return 1;
 
        // If none of the movements work, backtrack
        soln[x][y] = 0;
        return 0;
    }
    return 0;
}

// Main function
int main()
{
    int maze[ROWS][COLS] = {
     { 1, 0, 1, 1, 1, 0, 0, 0, 0, 1 },
     { 1, 1, 1, 0, 1, 1, 1, 1, 0, 1 },
     { 0, 0, 0, 1, 1, 0, 0, 1, 0, 0 },
     { 0, 0, 0, 1, 0, 0, 0, 1, 0, 0 },
     { 0, 0, 0, 1, 1, 1, 1, 1, 0, 0 },
     { 0, 0, 0, 0, 0, 0, 0, 1, 0, 0 },
     { 0, 0, 0, 0, 0, 0, 0, 1, 0, 0 },
     { 0, 0, 0, 0, 0, 0, 0, 1, 1, 1 },
     { 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
     { 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 }
    };
 
    int soln[ROWS][COLS] = { // Initialization
        { 0, 0, 0, 0, 0, 0, 0, 0, 0,0 },
        { 0, 0, 0, 0, 0, 0, 0, 0, 0,0 },
        { 0, 0, 0, 0, 0, 0, 0, 0, 0,0 },
        { 0, 0, 0, 0, 0, 0, 0, 0, 0,0 },
        { 0, 0, 0, 0, 0, 0, 0, 0, 0,0 },
        { 0, 0, 0, 0, 0, 0, 0, 0, 0,0 },
        { 0, 0, 0, 0, 0, 0, 0, 0, 0,0 },
        { 0, 0, 0, 0, 0, 0, 0, 0, 0,0 },
        { 0, 0, 0, 0, 0, 0, 0, 0, 0,0 },
        { 0, 0, 0, 0, 0, 0, 0, 0, 0,0 }
    };
 
    if (findRoute(maze, 0, 0, soln) == 1)
        displayMaze(soln);
    else
        printf("No route found!");
 
    return 0;
}