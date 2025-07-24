//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Constants
#define SIZE 10 // Size of grid
#define THRESHOLD 0.6 // Probability threshold for percolation

// Function prototypes
void print_grid(int grid[SIZE][SIZE]);
void percolate(int grid[SIZE][SIZE]);

int main()
{
    // Initialize random seed
    srand(time(0));
    
    // Declare and initialize grid
    int grid[SIZE][SIZE] = {0};
    
    // Print initial grid
    printf("Initial grid:\n");
    print_grid(grid);
    
    // Percolate grid
    percolate(grid);
    
    // Print final grid
    printf("Final grid:\n");
    print_grid(grid);
    
    return 0;
}

// Function to print grid
void print_grid(int grid[SIZE][SIZE])
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            if (grid[i][j] == 1)
            {
                printf("[ ]");
            }
            else
            {
                printf("[X]");
            }
        }
        printf("\n");
    }
    printf("\n");
}

// Function to percolate grid
void percolate(int grid[SIZE][SIZE])
{
    // Generate random values and update grid
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            double prob = (double)rand() / (double)RAND_MAX;
            if (prob < THRESHOLD)
            {
                grid[i][j] = 1;
            }
        }
    }
    
    // Check if top and bottom rows are connected
    for (int i = 0; i < SIZE; i++)
    {
        if (grid[0][i] == 1 && grid[SIZE - 1][i] == 1)
        {
            printf("Percolation achieved!\n");
            return;
        }
    }
    
    // If we get here, percolation was not achieved
    printf("Percolation not achieved.\n");
}