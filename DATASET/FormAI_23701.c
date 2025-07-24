//FormAI DATASET v1.0 Category: Game of Life ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 20
#define COLS 20

// Function to print the grid
void printGrid(int grid[][COLS])
{
    for(int i = 0; i < ROWS; i++)
    {
        for(int j = 0; j < COLS; j++)
        {
            printf("%c ", grid[i][j] ? '#' : '.');
        }
        printf("\n");
    }
    printf("-------------------------\n");
}

// Function to count living neighbors
int countNeighbors(int row, int col, int grid[][COLS])
{
    int neighbors = 0;

    for(int i = -1; i <= 1; i++)
    {
        for(int j = -1; j <= 1; j++)
        {
            if(!(i == 0 && j == 0)) // exclude current cell
            {
                int r = (row + i + ROWS) % ROWS; // handle edge cases
                int c = (col + j + COLS) % COLS;
                neighbors += grid[r][c];
            }
        }
    }

    return neighbors;
}

// Function to simulate a generation of life
void simulateGeneration(int grid[][COLS])
{
    int newGrid[ROWS][COLS];

    for(int i = 0; i < ROWS; i++)
    {
        for(int j = 0; j < COLS; j++)
        {
            int neighbors = countNeighbors(i, j, grid);
            
            // Cell is dead
            if(grid[i][j] == 0)
            {
                if(neighbors == 3)
                    newGrid[i][j] = 1; // resurrect
                else
                    newGrid[i][j] = 0; // keep dead
            }

            // Cell is alive
            if(grid[i][j] == 1)
            {
                if(neighbors < 2 || neighbors > 3)
                    newGrid[i][j] = 0; // die
                else
                    newGrid[i][j] = 1; // stay alive
            }
        }
    }

    // Copy new grid to original grid
    for(int i = 0; i < ROWS; i++)
    {
        for(int j = 0; j < COLS; j++)
        {
            grid[i][j] = newGrid[i][j];
        }
    }
}

int main()
{
    // Seed RNG
    srand(time(NULL));

    // Initialize grid randomly
    int grid[ROWS][COLS];
    for(int i = 0; i < ROWS; i++)
    {
        for(int j = 0; j < COLS; j++)
        {
            grid[i][j] = rand() % 2;
        }
    }

    // Simulate and print generations
    for(int i = 0; i < 100; i++)
    {
        printGrid(grid);
        simulateGeneration(grid);
    }

    return 0;
}