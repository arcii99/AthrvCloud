//FormAI DATASET v1.0 Category: Game of Life ; Style: scalable
// C Game of Life example program
// By [Your Name]

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define grid size
#define ROWS 10
#define COLS 10

// Define function prototypes
void initializeGrid(int grid[][COLS]);
void displayGrid(int grid[][COLS]);
void updateGrid(int grid[][COLS]);

int main()
{
    // Initialize grid and random seed
    int grid[ROWS][COLS];
    srand(time(NULL));

    // Fill grid with random values
    initializeGrid(grid);
    displayGrid(grid);

    // Run game loop
    while (1)
    {
        // Update grid values
        updateGrid(grid);

        // Display updated grid
        displayGrid(grid);

        // Delay for visual effect
        printf("\033[2J");
        fflush(stdout);
        usleep(100000);
    }

    return 0;
}

// Function to initialize grid values
void initializeGrid(int grid[][COLS])
{
    int i, j;

    for (i = 0; i < ROWS; i++)
    {
        for (j = 0; j < COLS; j++)
        {
            grid[i][j] = rand() % 2;
        }
    }
}

// Function to display grid values
void displayGrid(int grid[][COLS])
{
    int i, j;

    for (i = 0; i < ROWS; i++)
    {
        for (j = 0; j < COLS; j++)
        {
            if (grid[i][j] == 0)
            {
                printf(".");
            }
            else
            {
                printf("O");
            }
        }
        printf("\n");
    }
}

// Function to update grid values based on Game of Life rules
void updateGrid(int grid[][COLS])
{
    int i, j, count;

    int tempGrid[ROWS][COLS];

    // Copy grid to temporary grid
    for (i = 0; i < ROWS; i++)
    {
        for (j = 0; j < COLS; j++)
        {
            tempGrid[i][j] = grid[i][j];
        }
    }

    for (i = 0; i < ROWS; i++)
    {
        for (j = 0; j < COLS; j++)
        {
            count = 0;

            // Check top
            if (i > 0)
            {
                count += grid[i - 1][j];
            }

            // Check bottom
            if (i < ROWS - 1)
            {
                count += grid[i + 1][j];
            }

            // Check left
            if (j > 0)
            {
                count += grid[i][j - 1];
            }

            // Check right
            if (j < COLS - 1)
            {
                count += grid[i][j + 1];
            }

            // Check top-left
            if (i > 0 && j > 0)
            {
                count += grid[i - 1][j - 1];
            }

            // Check top-right
            if (i > 0 && j < COLS - 1)
            {
                count += grid[i - 1][j + 1];
            }

            // Check bottom-left
            if (i < ROWS - 1 && j > 0)
            {
                count += grid[i + 1][j - 1];
            }

            // Check bottom-right
            if (i < ROWS - 1 && j < COLS - 1)
            {
                count += grid[i + 1][j + 1];
            }

            // Apply rules to decide if cell survives or dies
            if (grid[i][j] == 1)
            {
                if (count < 2 || count > 3)
                {
                    tempGrid[i][j] = 0;
                }
            }
            else
            {
                if (count == 3)
                {
                    tempGrid[i][j] = 1;
                }
            }
        }
    }

    // Copy temporary grid back to main grid
    for (i = 0; i < ROWS; i++)
    {
        for (j = 0; j < COLS; j++)
        {
            grid[i][j] = tempGrid[i][j];
        }
    }
}