//FormAI DATASET v1.0 Category: Game of Life ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 20
#define COLS 20

// Function to initialize the grid randomly
void initializeGrid(int grid[ROWS][COLS])
{
    srand((unsigned) time(0));	// Seed for random number generator
    int i, j;
    for (i = 0; i < ROWS; i++)
    {
        for (j = 0; j < COLS; j++)
        {
            grid[i][j] = rand() % 2;	// Randomly fill cells with either 0 or 1
        }
    }
}

// Function to print the grid
void printGrid(int grid[ROWS][COLS])
{
    int i, j;
    for (i = 0; i < ROWS; i++)
    {
        for (j = 0; j < COLS; j++)
        {
            if (grid[i][j] == 1)
            {
                printf("*");	// Print '*' for live cell
            }
            else
            {
                printf(" ");	// Print ' ' for dead cell
            }
        }
        printf("\n");
    }
}

// Function to calculate next generation of cells based on Game of Life rules
void calculateNextGeneration(int grid[ROWS][COLS])
{
    int nextGrid[ROWS][COLS];
    int i, j, neighbors, currentState;

    for (i = 0; i < ROWS; i++)
    {
        for (j = 0; j < COLS; j++)
        {
            neighbors = 0;

            // Count neighbors for each cell
            if (i-1 >= 0 && j-1 >= 0) {	// Top left
                neighbors += grid[i-1][j-1];
            }
            if (i-1 >= 0) {	// Top
                neighbors += grid[i-1][j];
            }
            if (i-1 >= 0 && j+1 < COLS) {	// Top right
                neighbors += grid[i-1][j+1];
            }
            if (j-1 >= 0) {	// Left
                neighbors += grid[i][j-1];
            }
            if (j+1 < COLS) {	// Right
                neighbors += grid[i][j+1];
            }
            if (i+1 < ROWS && j-1 >= 0) {	// Bottom left
                neighbors += grid[i+1][j-1];
            }
            if (i+1 < ROWS) {	// Bottom
                neighbors += grid[i+1][j];
            }
            if (i+1 < ROWS && j+1 < COLS) {	// Bottom right
                neighbors += grid[i+1][j+1];
            }

            currentState = grid[i][j];

            // Implement Game of Life rules
            if (currentState == 1 && neighbors < 2) {	// Underpopulation
                nextGrid[i][j] = 0;
            } else if (currentState == 1 && neighbors > 3) {	// Overpopulation
                nextGrid[i][j] = 0;
            } else if (currentState == 0 && neighbors == 3) {	// Reproduction
                nextGrid[i][j] = 1;
            } else {	// Stasis
                nextGrid[i][j] = currentState;
            }
        }
    }

    // Copy next generation to current grid
    for (i = 0; i < ROWS; i++)
    {
        for (j = 0; j < COLS; j++)
        {
            grid[i][j] = nextGrid[i][j];
        }
    }
}

int main()
{
    int grid[ROWS][COLS];

    // Initialize grid randomly
    initializeGrid(grid);

    // Print initial grid
    printf("Initial grid:\n");
    printGrid(grid);

    // Wait for user input to continue
    printf("Press enter to begin simulation...");
    getchar();

    // Clear console and begin simulation
    system("clear");

    // Loop through generations and print grid for each generation
    int generations = 10;
    int i;
    for (i = 0; i < generations; i++)
    {
        printf("Generation %d:\n", i);
        printGrid(grid);
        calculateNextGeneration(grid);
        sleep(1);	// Add delay between generations
        system("clear");	// Clear console before printing next generation
    }

    // End of simulation
    printf("Simulation complete.\n");

    return 0;
}