//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdbool.h>

// Declaration of maze size
#define ROW 8
#define COL 8

// Function to print the maze
void print_maze(int maze[][COL])
{
    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COL; j++)
            printf("%2d ", maze[i][j]);
        printf("\n");
    }
    printf("\n");
}

// Function to check if the current position is valid
bool is_valid(int maze[][COL], int row, int col)
{
    // Check if the current position is inside the maze
    if (row >= 0 && row < ROW && col >= 0 && col < COL)
    {
        // Check if the current position is not a wall (represented by 0)
        if (maze[row][col] == 1)
            return true;
    }
    return false;
}

// Function to perform depth-first search in the maze
bool find_path(int maze[][COL], int row, int col, int path[], int path_len)
{
    // Check if the current position is inside the maze and not a wall
    if (is_valid(maze, row, col))
    {
        // Mark the current position as visited and add it to the path
        maze[row][col] = 2;
        path[path_len++] = row * COL + col;

        // Check if the current position is the destination (represented by 9)
        if (maze[row][col] == 9)
        {
            // Print the path from start to destination
            printf("Path found: ");
            for (int i = 0; i < path_len; i++)
                printf("%d -> ", path[i]);
            printf("\n");

            return true;
        }

        // Recursively search the neighboring positions
        if (find_path(maze, row - 1, col, path, path_len) ||
            find_path(maze, row, col + 1, path, path_len) ||
            find_path(maze, row + 1, col, path, path_len) ||
            find_path(maze, row, col - 1, path, path_len))
        {
            return true;
        }

        // If no path is found, backtrack and remove the current position from the path
        maze[row][col] = 1;
        path_len--;
    }

    return false;
}

// Main function to test the maze route finder
int main()
{
    int maze[ROW][COL] = {
        {1, 1, 1, 1, 1, 1, 1, 1},
        {1, 0, 1, 0, 1, 0, 0, 1},
        {1, 0, 1, 0, 1, 1, 0, 1},
        {1, 0, 1, 0, 1, 1, 0, 1},
        {1, 0, 0, 0, 1, 0, 0, 1},
        {1, 1, 1, 1, 1, 1, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 9},
        {1, 1, 1, 1, 1, 1, 1, 1}
    };

    printf("Maze:\n");
    print_maze(maze);

    int path[ROW * COL] = {0};
    int path_len = 0;

    if (!find_path(maze, 1, 1, path, path_len))
        printf("No path found\n");

    return 0;
}