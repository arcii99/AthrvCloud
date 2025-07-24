//FormAI DATASET v1.0 Category: Game of Life ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 20
#define COLS 40

int grid[ROWS][COLS];
int newgrid[ROWS][COLS];

// Function to print the current generation of the grid
void printGrid()
{
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            if (grid[i][j] == 1)
                printf("*");
            else
                printf(" ");
        }
        printf("\n");
    }
    printf("\n");
}

// Function to initialize the grid randomly
void initGrid()
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

// Function to update the grid to the next generation
void updateGrid()
{
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            int neighbors = 0;

            // Count the neighbors
            for (int x = -1; x <= 1; x++)
            {
                for (int y = -1; y <= 1; y++)
                {
                    int row = (i + x + ROWS) % ROWS;
                    int col = (j + y + COLS) % COLS;
                    neighbors += grid[row][col];
                }
            }

            // Remove the cell itself
            neighbors -= grid[i][j];

            // Apply the rules of the game
            if (grid[i][j] == 1 && (neighbors < 2 || neighbors > 3))
                newgrid[i][j] = 0;
            else if (grid[i][j] == 0 && neighbors == 3)
                newgrid[i][j] = 1;
            else
                newgrid[i][j] = grid[i][j];
        }
    }

    // Copy the new generation to the grid
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            grid[i][j] = newgrid[i][j];
        }
    }
}

int main()
{
    initGrid();

    // Run the game for 50 generations
    for (int i = 0; i < 50; i++)
    {
        printGrid();
        updateGrid();
    }

    return 0;
}