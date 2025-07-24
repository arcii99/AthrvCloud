//FormAI DATASET v1.0 Category: Game of Life ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 20
#define COLS 60

// Function to initialize the grid randomly
void initialize_grid(int grid[][COLS])
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

// Function to print the grid
void print_grid(int grid[][COLS])
{
    printf("\033[2J\033[1;1H"); // clear the terminal screen

    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            if (grid[i][j] == 1)
            {
                printf("%c", '#');
            }
            else
            {
                printf("%c", ' ');
            }
        }
        printf("\n");
    }
}

// Function to count the number of living neighbors
int count_neighbors(int grid[][COLS], int row, int col)
{
    int count = 0;

    // check top neighbor
    if (row > 0 && grid[row-1][col] == 1)
    {
        count++;
    }

    // check bottom neighbor
    if (row < ROWS-1 && grid[row+1][col] == 1)
    {
        count++;
    }

    // check left neighbor
    if (col > 0 && grid[row][col-1] == 1)
    {
        count++;
    }

    // check right neighbor
    if (col < COLS-1 && grid[row][col+1] == 1)
    {
        count++;
    }

    // check top-left neighbor
    if (row > 0 && col > 0 && grid[row-1][col-1] == 1)
    {
        count++;
    }

    // check top-right neighbor
    if (row > 0 && col < COLS-1 && grid[row-1][col+1] == 1)
    {
        count++;
    }

    // check bottom-left neighbor
    if (row < ROWS-1 && col > 0 && grid[row+1][col-1] == 1)
    {
        count++;
    }

    // check bottom-right neighbor
    if (row < ROWS-1 && col < COLS-1 && grid[row+1][col+1] == 1)
    {
        count++;
    }

    return count;
}

// Function to update the grid for the next generation
void update_grid(int grid[][COLS])
{
    int new_grid[ROWS][COLS] = {0};

    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            int neighbors = count_neighbors(grid, i, j);

            // Living cell rules
            if (grid[i][j] == 1)
            {
                if (neighbors < 2 || neighbors > 3)
                {
                    new_grid[i][j] = 0; // Cell dies
                }
                else
                {
                    new_grid[i][j] = 1; // Cell lives
                }
            }
            // Dead cell rules
            else
            {
                if (neighbors == 3)
                {
                    new_grid[i][j] = 1; // Cell becomes alive
                }
            }
        }
    }

    // Copy the new grid to the original grid
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            grid[i][j] = new_grid[i][j];
        }
    }
}

int main()
{
    int grid[ROWS][COLS] = {0};
    initialize_grid(grid);

    // Display the initial grid
    printf("Two households, both alike in dignity,\n");
    printf("In fair Verona, where we lay our scene,\n\n");
    printf("The citizens of this city are represented by the following grid:\n\n");
    print_grid(grid);

    // Generate the next generations
    for (int generation = 1; generation <= 100; generation++)
    {
        update_grid(grid);
        printf("Generation: %d\n", generation);
        print_grid(grid);
    }

    printf("Good night, good night! parting is such\n");
    printf("sweet sorrow, That I shall say good night till it be morrow.\n");
    return 0;
}