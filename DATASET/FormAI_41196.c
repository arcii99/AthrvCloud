//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 20 // Grid size
#define PERCENT 20 // Percent chance to fill cell

int grid[SIZE][SIZE] = {0}; // Grid array
int visited[SIZE][SIZE] = {0}; // Visited array

// Function to simulate percolation
void simulate()
{
    int row, col, top = 0, bottom = 0, flag = 0;
    // Check if top and bottom rows are connected
    for (col = 0; col < SIZE; col++)
    {
        if (visited[0][col] && visited[SIZE - 1][col])
        {
            printf("Percolation occured!\n");
            flag = 1;
            break;
        }
    }
    if (!flag)
    {
        // Check if grid can be expanded
        for (col = 0; col < SIZE; col++)
        {
            if (visited[0][col])
            {
                // Visit adjacent cells
                if (col > 0 && grid[0][col - 1] && !visited[0][col - 1])
                {
                    visited[0][col - 1] = 1;
                    top++;
                }
                if (col < SIZE - 1 && grid[0][col + 1] && !visited[0][col + 1])
                {
                    visited[0][col + 1] = 1;
                    top++;
                }
                if (grid[1][col] && !visited[1][col])
                {
                    visited[1][col] = 1;
                    top++;
                }
            }
            if (visited[SIZE - 1][col])
            {
                // Visit adjacent cells
                if (col > 0 && grid[SIZE - 1][col - 1] && !visited[SIZE - 1][col - 1])
                {
                    visited[SIZE - 1][col - 1] = 1;
                    bottom++;
                }
                if (col < SIZE - 1 && grid[SIZE - 1][col + 1] && !visited[SIZE - 1][col + 1])
                {
                    visited[SIZE - 1][col + 1] = 1;
                    bottom++;
                }
                if (grid[SIZE - 2][col] && !visited[SIZE - 2][col])
                {
                    visited[SIZE - 2][col] = 1;
                    bottom++;
                }
            }
        }
        // Check if percolation occured
        if (top && bottom)
        {
            printf("Percolation occured!\n");
        }
        else
        {
            // Expand grid by visiting adjacent cells
            for (row = 1; row < SIZE - 1; row++)
            {
                for (col = 0; col < SIZE; col++)
                {
                    if (visited[row][col])
                    {
                        if (col > 0 && grid[row][col - 1] && !visited[row][col - 1])
                        {
                            visited[row][col - 1] = 1;
                        }
                        if (col < SIZE - 1 && grid[row][col + 1] && !visited[row][col + 1])
                        {
                            visited[row][col + 1] = 1;
                        }
                        if (row > 0 && grid[row - 1][col] && !visited[row - 1][col])
                        {
                            visited[row - 1][col] = 1;
                        }
                        if (row < SIZE - 1 && grid[row + 1][col] && !visited[row + 1][col])
                        {
                            visited[row + 1][col] = 1;
                        }
                    }
                }
            }
            // Check if new cells were visited and repeat simulation
            flag = 1;
            for (row = 0; row < SIZE; row++)
            {
                for (col = 0; col < SIZE; col++)
                {
                    if (visited[row][col])
                    {
                        flag = 0;
                    }
                }
            }
            if (!flag)
            {
                simulate();
            }
            else
            {
                printf("Percolation did not occur.\n");
            }
        }
    }
}

int main()
{
    srand(time(NULL));
    int row, col, count = 0;
    // Fill grid
    for (row = 0; row < SIZE; row++)
    {
        for (col = 0; col < SIZE; col++)
        {
            if (rand() % 100 < PERCENT)
            {
                grid[row][col] = 1;
                count++;
            }
        }
    }
    // Print grid
    printf("Initial Grid (%d/%d cells filled):\n", count, SIZE * SIZE);
    for (row = 0; row < SIZE; row++)
    {
        for (col = 0; col < SIZE; col++)
        {
            printf("%c", grid[row][col] ? '#' : '.');
        }
        printf("\n");
    }
    // Initialize visited array
    visited[0][0] = 1;
    // Simulate percolation
    simulate();
    return 0;
}