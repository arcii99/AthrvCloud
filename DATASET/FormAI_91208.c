//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: Claude Shannon
/*
* C Percolation Simulator - A program to simulate percolation in a two-dimensional grid.
* Written in the style of Claude Shannon by [Your Name]
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GRID_SIZE 20 // Define the size of the grid
#define THRESHOLD 0.6 // Define the threshold for percolation

int main()
{
    srand(time(NULL)); // Seed the random number generator with the current time

    // Initialize the grid
    int grid[GRID_SIZE][GRID_SIZE];
    for (int i = 0; i < GRID_SIZE; i++)
    {
        for (int j = 0; j < GRID_SIZE; j++)
        {
            grid[i][j] = (rand() < (RAND_MAX * THRESHOLD)) ? 1 : 0; // Fill the grid randomly with 0 or 1 values based on the threshold
        }
    }

    // Print the initial grid
    printf("Initial grid:\n");
    for (int i = 0; i < GRID_SIZE; i++)
    {
        for (int j = 0; j < GRID_SIZE; j++)
        {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }

    // Check if percolation occurs
    int top_row[GRID_SIZE] = {0}; // Initialize the top row of the grid to all 0 values
    for (int j = 0; j < GRID_SIZE; j++)
    {
        if (grid[0][j] == 1) // If an open site is found in the top row
        {
            top_row[j] = 1; // Mark that column as open in the top row
            for (int i = 1; i < GRID_SIZE; i++)
            {
                if ((grid[i][j] == 1) && ((top_row[j-1] == 1) || (top_row[j] == 1) || (top_row[j+1] == 1))) // If an open site is found in the column below an open site in the top row
                {
                    top_row[j] = 1; // Mark that column as open in the top row
                    break;
                }
            }
        }
    }

    // Print the final grid
    printf("\nFinal grid:\n");
    for (int i = 0; i < GRID_SIZE; i++)
    {
        for (int j = 0; j < GRID_SIZE; j++)
        {
            if ((i == 0) && (top_row[j] == 1)) // If the site is in the top row and also open in the top row
            {
                printf("x "); // Print x to indicate the site is connected to the top
            }
            else
            {
                printf("%d ", grid[i][j]); // Otherwise, print the value of the site
            }
        }
        printf("\n");
    }

    return 0;
}