//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 15
#define COLS 25

// Function to print the maze
void print_maze(int maze[ROWS][COLS])
{
    // Loop through each cell in the maze
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            // If the cell is a path, print a space
            if (maze[i][j] == 0)
            {
                printf(" ");
            }
            // If the cell is a wall, print a pound sign
            else
            {
                printf("#");
            }
        }
        printf("\n");
    }
}

int main()
{
    srand(time(NULL)); // Seed random number generator

    int maze[ROWS][COLS]; // Array to hold maze data

    // Initialize maze to all walls
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            maze[i][j] = 1;
        }
    }

    // Generate a random starting point
    int row = rand() % ROWS;
    int col = rand() % COLS;

    // Mark the starting point as a path
    maze[row][col] = 0;

    // Loop through the maze until all cells are paths
    while (1)
    {
        // Choose a random direction to move in
        int direction = rand() % 4; // 0 = up, 1 = right, 2 = down, 3 = left

        // Move in the chosen direction
        if (direction == 0 && row > 0 && maze[row - 1][col] == 1) // Up
        {
            maze[row - 1][col] = 0;
            row--;
        }
        else if (direction == 1 && col < COLS - 1 && maze[row][col + 1] == 1) // Right
        {
            maze[row][col + 1] = 0;
            col++;
        }
        else if (direction == 2 && row < ROWS - 1 && maze[row + 1][col] == 1) // Down
        {
            maze[row + 1][col] = 0;
            row++;
        }
        else if (direction == 3 && col > 0 && maze[row][col - 1] == 1) // Left
        {
            maze[row][col - 1] = 0;
            col--;
        }

        // Check if all cells are paths
        int all_paths = 1;
        for (int i = 0; i < ROWS; i++)
        {
            for (int j = 0; j < COLS; j++)
            {
                if (maze[i][j] == 1)
                {
                    all_paths = 0;
                    break;
                }
            }
            if (!all_paths)
            {
                break;
            }
        }
        if (all_paths)
        {
            break;
        }
    }

    // Print the maze
    print_maze(maze);

    return 0;
}