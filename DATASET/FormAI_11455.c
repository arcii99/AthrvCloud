//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAZE_SIZE 6

// Function to print the maze
void printMaze(char maze[MAZE_SIZE][MAZE_SIZE])
{
    printf("\nMaze:\n");
    for(int i = 0; i < MAZE_SIZE; i++)
    {
        for(int j = 0; j < MAZE_SIZE; j++)
        {
            printf("%c ", maze[i][j]);
        }
        printf("\n");
    }
}

// Recursive function to find the route in the maze
bool findRoute(char maze[MAZE_SIZE][MAZE_SIZE], int row, int col)
{
    // Check if the destination has been reached
    if(row == MAZE_SIZE - 1 && col == MAZE_SIZE - 1 && maze[row][col] == '.')
    {
        return true;
    }

    // Check if the current position is within the maze and not a wall
    if(row < 0 || col < 0 || row >= MAZE_SIZE || col >= MAZE_SIZE || maze[row][col] != '.')
    {
        return false;
    }

    // Mark the current position as visited
    maze[row][col] = '*';

    // Check the four possible directions for the next move
    bool result = findRoute(maze, row - 1, col) || // Move up
                  findRoute(maze, row, col + 1) || // Move right
                  findRoute(maze, row + 1, col) || // Move down
                  findRoute(maze, row, col - 1);  // Move left

    // If a route has been found, mark the path with 'X'
    if(result)
    {
        maze[row][col] = 'X';
    }

    return result;
}

int main()
{
    // Initialize the maze
    char maze[MAZE_SIZE][MAZE_SIZE] = {
        { '.', '#', '.', '.', '.', '#' },
        { '.', '#', '.', '#', '.', '#' },
        { '.', '.', '.', '#', '.', '.' },
        { '#', '#', '.', '.', '#', '.' },
        { '.', '.', '#', '.', '.', '.' },
        { '#', '#', '.', '#', '.', '.' }
    };

    // Print the initial maze
    printMaze(maze);

    // Find the route through the maze
    if(findRoute(maze, 0, 0))
    {
        printf("\nRoute found!\n");

        // Print the path through the maze
        printMaze(maze);
    }
    else
    {
        printf("\nNo route found.\n");
    }

    return 0;
}