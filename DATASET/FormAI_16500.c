//FormAI DATASET v1.0 Category: Game of Life ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 20
#define COLS 20
#define ALIVE '*'
#define DEAD ' '

// Declare global variables
char grid[ROWS][COLS];
char tempGrid[ROWS][COLS];

// Function prototypes
void initializeGrid(char grid[ROWS][COLS]);
void printGrid(char grid[ROWS][COLS]);
int getNeighbors(char grid[ROWS][COLS], int row, int col);
void updateGrid(char grid[ROWS][COLS], char tempGrid[ROWS][COLS]);

int main()
{
    // Seed random number generator
    srand(time(NULL));

    // Initialize grid with random values
    initializeGrid(grid);

    // Print initial grid
    printGrid(grid);

    // Loop through each generation
    int generation = 1;
    while (1)
    {
        printf("Press Enter to continue to next generation, or type 'q' to quit.\n");
        // Wait for user input
        int c;
        while ((c = getchar()) != '\n' && c != EOF);
        if (getchar() == 'q')
            break;

        // Update grid
        updateGrid(grid, tempGrid);

        // Print updated grid
        printf("\nGeneration %d:\n", generation);
        printGrid(grid);

        // Increment generation count
        generation++;
    }

    return 0;
}

void initializeGrid(char grid[ROWS][COLS])
{
    for (int row = 0; row < ROWS; row++)
    {
        for (int col = 0; col < COLS; col++)
        {
            // Use random number to determine if cell is alive or dead
            if (rand() % 2 == 0)
                grid[row][col] = ALIVE;
            else
                grid[row][col] = DEAD;
        }
    }
}

void printGrid(char grid[ROWS][COLS])
{
    for (int row = 0; row < ROWS; row++)
    {
        for (int col = 0; col < COLS; col++)
        {
            printf("%c ", grid[row][col]);
        }
        printf("\n");
    }
}

int getNeighbors(char grid[ROWS][COLS], int row, int col)
{
    int count = 0;

    // Check top-left neighbor
    if (row > 0 && col > 0 && grid[row-1][col-1] == ALIVE)
        count++;

    // Check top neighbor
    if (row > 0 && grid[row-1][col] == ALIVE)
        count++;

    // Check top-right neighbor
    if (row > 0 && col < COLS-1 && grid[row-1][col+1] == ALIVE)
        count++;

    // Check left neighbor
    if (col > 0 && grid[row][col-1] == ALIVE)
        count++;

    // Check right neighbor
    if (col < COLS-1 && grid[row][col+1] == ALIVE)
        count++;

    // Check bottom-left neighbor
    if (row < ROWS-1 && col > 0 && grid[row+1][col-1] == ALIVE)
        count++;

    // Check bottom neighbor
    if (row < ROWS-1 && grid[row+1][col] == ALIVE)
        count++;

    // Check bottom-right neighbor
    if (row < ROWS-1 && col < COLS-1 && grid[row+1][col+1] == ALIVE)
        count++;

    return count;
}

void updateGrid(char grid[ROWS][COLS], char tempGrid[ROWS][COLS])
{
    for (int row = 0; row < ROWS; row++)
    {
        for (int col = 0; col < COLS; col++)
        {
            // Get the number of alive neighbors
            int neighbors = getNeighbors(grid, row, col);

            // Update tempGrid according to Game of Life rules
            if (grid[row][col] == ALIVE)
            {
                if (neighbors < 2)
                    tempGrid[row][col] = DEAD;
                else if (neighbors == 2 || neighbors == 3)
                    tempGrid[row][col] = ALIVE;
                else
                    tempGrid[row][col] = DEAD;
            }
            else
            {
                if (neighbors == 3)
                    tempGrid[row][col] = ALIVE;
                else
                    tempGrid[row][col] = DEAD;
            }
        }
    }

    // Copy tempGrid back to grid
    for (int row = 0; row < ROWS; row++)
    {
        for (int col = 0; col < COLS; col++)
        {
            grid[row][col] = tempGrid[row][col];
        }
    }
}