//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ROWS 10
#define COLS 10

// Maze layout
char maze[ROWS][COLS] = {
    {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
    {'#', '.', '.', '.', '#', '.', '.', '.', '.', '#'},
    {'.', '.', '#', '.', '#', '.', '#', '#', '.', '#'},
    {'#', '#', '#', '.', '#', '.', '.', '.', '.', '#'},
    {'#', '.', '.', '.', '.', '#', '#', '#', '.', '.'},
    {'#', '#', '#', '#', '.', '#', '.', '#', '#', '#'},
    {'#', '.', '.', '#', '.', '#', '.', '#', '.', '#'},
    {'#', '#', '.', '#', '.', '#', '#', '#', '.', '#'},
    {'#', '.', '.', '.', '.', '.', '.', '.', '.', '#'},
    {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'}};

// Array to mark visited positions in the maze
bool visited[ROWS][COLS];

// Function to check if a given position is valid
bool is_valid_position(int row, int col)
{
    return (row >= 0 && row < ROWS && col >= 0 && col < COLS && maze[row][col] != '#' && !visited[row][col]);
}

// Function to print the current state of the maze
void print_maze()
{
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            if (visited[i][j])
            {
                printf("+ ");
            }
            else
            {
                printf("%c ", maze[i][j]);
            }
        }
        printf("\n");
    }
}

// Recursive function to traverse the maze and find a route
bool traverse_maze(int row, int col)
{
    // If current position is the endpoint, we found a route
    if (maze[row][col] == 'E')
    {
        visited[row][col] = true;
        print_maze();
        return true;
    }

    // Mark current position as visited
    visited[row][col] = true;

    // Print current state of the maze
    print_maze();

    // Check if adjacent positions are valid and try to move there
    if (is_valid_position(row - 1, col) && traverse_maze(row - 1, col))
    {
        return true;
    }
    if (is_valid_position(row + 1, col) && traverse_maze(row + 1, col))
    {
        return true;
    }
    if (is_valid_position(row, col - 1) && traverse_maze(row, col - 1))
    {
        return true;
    }
    if (is_valid_position(row, col + 1) && traverse_maze(row, col + 1))
    {
        return true;
    }

    // If none of the adjacent positions lead to the endpoint, backtrack
    visited[row][col] = false;
    return false;
}

int main()
{
    // Start at the entrance point
    int start_row = 1, start_col = 0;

    // Call function to traverse the maze and find a route
    if (!traverse_maze(start_row, start_col))
    {
        printf("No route found.\n");
    }

    return 0;
}