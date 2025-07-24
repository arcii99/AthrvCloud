//FormAI DATASET v1.0 Category: Game of Life ; Style: satisfied
// This is a unique game of life program that simulates the growth and decay of cells in a 2D space
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the size of the 2D space
#define ROWS 10
#define COLS 20

// Define the maximum number of generations the simulation will run for
#define MAX_GENERATIONS 50

// Function to print the current state of the 2D space
void print_grid(int grid[ROWS][COLS])
{
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            if (grid[i][j] == 0)
                printf("-");
            else
                printf("O");
        }
        printf("\n");
    }
    printf("\n");
}

// Function to calculate the number of live neighbors around a given cell
int count_neighbors(int grid[ROWS][COLS], int row, int col)
{
    int count = 0;
    for (int i = row - 1; i <= row + 1; i++)
    {
        for (int j = col - 1; j <= col + 1; j++)
        {
            if (i >= 0 && i < ROWS && j >= 0 && j < COLS && !(i == row && j == col) && grid[i][j] == 1)
                count++;
        }
    }
    return count;
}

int main()
{
    // Initialize the 2D space with random live and dead cells
    srand(time(NULL));
    int grid[ROWS][COLS];
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            grid[i][j] = rand() % 2;
        }
    }

    // Run the simulation for a maximum of MAX_GENERATIONS generations
    for (int gen = 0; gen < MAX_GENERATIONS; gen++)
    {
        printf("Generation %d:\n", gen + 1);
        print_grid(grid);

        // Create a copy of the grid to hold the new generation
        int new_grid[ROWS][COLS];

        // Calculate the new state of each cell based on the number of live neighbors
        for (int i = 0; i < ROWS; i++)
        {
            for (int j = 0; j < COLS; j++)
            {
                int neighbors = count_neighbors(grid, i, j);
                if (grid[i][j] == 1 && (neighbors < 2 || neighbors > 3))
                    new_grid[i][j] = 0;
                else if (grid[i][j] == 0 && neighbors == 3)
                    new_grid[i][j] = 1;
                else
                    new_grid[i][j] = grid[i][j];
            }
        }

        // Replace the old grid with the new one for the next generation
        for (int i = 0; i < ROWS; i++)
        {
            for (int j = 0; j < COLS; j++)
            {
                grid[i][j] = new_grid[i][j];
            }
        }
    }

    return 0;
}