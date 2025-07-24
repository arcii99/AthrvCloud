//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: satisfied
#include <stdio.h>
#include <stdbool.h>
#define ROW 10
#define COL 10

// Create a boolean 2D array visited to keep track of visited cells
bool visited[ROW][COL];

// Create a maze as a 2D array of integers
int maze[ROW][COL] = {
    {1, 0, 0, 0, 0, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 0, 1, 0, 0, 0, 1},
    {0, 0, 0, 1, 0, 1, 1, 1, 0, 1},
    {0, 1, 0, 1, 0, 0, 0, 1, 0, 0},
    {0, 1, 1, 1, 0, 1, 1, 1, 1, 1},
    {0, 1, 0, 0, 0, 1, 0, 0, 0, 1},
    {0, 0, 0, 1, 0, 1, 1, 1, 0, 1},
    {0, 1, 1, 1, 0, 0, 0, 1, 0, 0},
    {0, 1, 0, 0, 0, 1, 0, 0, 1, 0},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
};

// Recursive function to find the path in the maze
void find_path(int row, int col, int previous_row, int previous_col, int steps)
{
    // Check if the current cell is out of bounds or blocked or visited
    if (row < 0 || col < 0 || row >= ROW || col >= COL || maze[row][col] == 0 || visited[row][col])
    {
        return;
    }
    
    // Check if the current cell is the destination
    if (row == ROW - 1 && col == COL - 1)
    {
        printf("Path found in %d steps!\n\n", steps);
        return;
    }
    
    // Mark the current cell as visited
    visited[row][col] = true;
    
    // Check the neighboring cells for the path
    if (row - 1 != previous_row)
    {
        find_path(row - 1, col, row, col, steps + 1); // Up
    }
    if (col + 1 != previous_col)
    {
        find_path(row, col + 1, row, col, steps + 1); // Right
    }
    if (row + 1 != previous_row)
    {
        find_path(row + 1, col, row, col, steps + 1); // Down
    }
    if (col - 1 != previous_col)
    {
        find_path(row, col - 1, row, col, steps + 1); // Left
    }
    
    // Mark the current cell as unvisited for backtracking
    visited[row][col] = false;
}

// Main function
int main()
{
    printf("Maze:\n\n");
    // Print the maze
    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COL; j++)
        {
            printf("%d ", maze[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    
    // Find the path in the maze starting from (0, 0) with 0 steps taken
    printf("Finding path in maze...\n\n");
    find_path(0, 0, -1, -1, 0);
    
    return 0;
}