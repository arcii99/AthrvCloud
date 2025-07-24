//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: curious
#include <stdio.h>
#define ROWS 10
#define COLS 10

char map[ROWS][COLS] = {
    {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
    {'#', ' ', '#', ' ', ' ', ' ', ' ', '#', ' ', '#'},
    {'#', ' ', '#', ' ', '#', '#', ' ', '#', ' ', '#'},
    {'#', ' ', '#', ' ', ' ', '#', ' ', ' ', ' ', '#'},
    {'#', ' ', '#', '#', ' ', '#', ' ', '#', '#', '#'},
    {'#', ' ', ' ', ' ', ' ', '#', ' ', '#', ' ', '#'},
    {'#', '#', '#', '#', '#', '#', '#', '#', ' ', '#'},
    {'#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
    {'#', ' ', '#', '#', '#', '#', '#', '#', '#', '#'},
    {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'}
};

int visited[ROWS][COLS];

// Recursive function to find a path from start to end using DFS
int find_path(char maze[][COLS], int visited[][COLS], int row, int col)
{
    // mark the current cell as visited
    visited[row][col] = 1;

    // if the current cell is the destination, return true
    if (maze[row][col] == 'E')
        return 1;

    // if the current cell is not blocked and has not been visited yet, 
    // visit its adjacent cells recursively
    if (maze[row][col] == ' ' || maze[row][col] == 'S')
    {
        // Check for right cell
        if (col < COLS - 1 && visited[row][col + 1] != 1) 
            if (find_path(maze, visited, row, col + 1)) 
                return 1;

        // Check for down cell
        if (row < ROWS - 1 && visited[row + 1][col] != 1)
            if (find_path(maze, visited, row + 1, col))
                return 1;

        // Check for left cell
        if (col > 0 && visited[row][col - 1] != 1) 
            if (find_path(maze, visited, row, col - 1)) 
                return 1;

        // Check for up cell
        if (row > 0 && visited[row - 1][col] != 1) 
            if (find_path(maze, visited, row - 1, col)) 
                return 1;
    }

    // backtrack from the current cell
    visited[row][col] = 0;

    // return false if no path is found
    return 0;
}

int main()
{
    int i, j;
    printf("Welcome to the Maze Route Finder program!\n");
    printf("The following maze has been created:\n\n");

    // Print the maze
    for (i = 0; i < ROWS; i++) 
    {
        for (j = 0; j < COLS; j++) 
            printf("%c", map[i][j]);
        
        printf("\n");
    }
    
    printf("\n");

    printf("The program will now find the path from starting point (1,1)");
    printf(" to the finish point (8,8).\n\n");

    // Find the path using DFS
    if (find_path(map, visited, 1, 1))
    {
        printf("A path has been found!\n\n");
        printf("The path is marked with '.' below:\n\n");

        // Mark the path with '.'
        for (i = 0; i < ROWS; i++) 
        {
            for (j = 0; j < COLS; j++) 
                if (visited[i][j])
                    printf(".");
                else
                    printf("%c", map[i][j]);

            printf("\n");
        }
    }
    else
    {
        printf("No path found!\n\n");
    }

    return 0;
}