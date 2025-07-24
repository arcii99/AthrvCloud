//FormAI DATASET v1.0 Category: Game of Life ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 30
#define COLS 60

// Function to initialize the grid with random cells
void initGrid(int grid[][COLS])
{
    srand(time(NULL));

    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            grid[i][j] = rand() % 2;
        }
    }
}

// Function to print out the current state of the grid
void printGrid(int grid[][COLS])
{
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            if (grid[i][j] == 0)
                printf(".");
            else
                printf("*");
        }
        printf("\n");
    }
    printf("\n");
}

// Function to count the number of neighbors for a given cell
int countNeighbors(int grid[][COLS], int row, int col)
{
    int count = 0;

    for (int i = row - 1; i <= row + 1; i++)
    {
        for (int j = col - 1; j <= col + 1; j++)
        {
            // Check if the neighbor is within bounds of the grid
            if (i >= 0 && i < ROWS && j >= 0 && j < COLS)
            {
                // Don't count the cell itself as a neighbor
                if (i != row || j != col)
                    count += grid[i][j];
            }
        }
    }

    return count;
}

// Function to update the grid based on the rules of the game of life
void updateGrid(int grid[][COLS])
{
    int newGrid[ROWS][COLS];

    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            int neighbors = countNeighbors(grid, i, j);

            // Check the rules of the game of life
            if (grid[i][j] == 1)
            {
                if (neighbors < 2 || neighbors > 3)
                    newGrid[i][j] = 0;
                else
                    newGrid[i][j] = 1;
            }
            else
            {
                if (neighbors == 3)
                    newGrid[i][j] = 1;
                else
                    newGrid[i][j] = 0;
            }
        }
    }

    // Copy the new grid back to the original grid
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            grid[i][j] = newGrid[i][j];
        }
    }
}

int main()
{
    int grid[ROWS][COLS];

    // Initialize the grid with random cells
    initGrid(grid);

    // Print out the initial state of the grid
    printGrid(grid);

    // Run the game of life for 100 iterations
    for (int i = 0; i < 100; i++)
    {
        updateGrid(grid);
        printGrid(grid);
    }

    return 0;
}