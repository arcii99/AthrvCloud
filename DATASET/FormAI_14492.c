//FormAI DATASET v1.0 Category: Game of Life ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 20           // number of rows in the grid
#define COLS 40           // number of columns in the grid
#define GENERATIONS 100   // number of generations to simulate

// function prototypes
void init_grid(int grid[ROWS][COLS]);
void print_grid(int grid[ROWS][COLS]);
void update_grid(int grid[ROWS][COLS]);
int get_neighbor_count(int grid[ROWS][COLS], int row, int col);

int main()
{
    int grid[ROWS][COLS];
    int generation;

    // initialize the grid
    init_grid(grid);

    // simulate the generations
    for (generation = 1; generation <= GENERATIONS; generation++)
    {
        printf("Generation %d:\n", generation);
        print_grid(grid);
        update_grid(grid);
    }

    return 0;
}

// initializes the grid
void init_grid(int grid[ROWS][COLS])
{
    int row, col;

    // seed the random number generator
    srand(time(NULL));

    // populate the grid randomly
    for (row = 0; row < ROWS; row++)
    {
        for (col = 0; col < COLS; col++)
        {
            grid[row][col] = rand() % 2;
        }
    }
}

// prints the grid to the console
void print_grid(int grid[ROWS][COLS])
{
    int row, col;

    for (row = 0; row < ROWS; row++)
    {
        for (col = 0; col < COLS; col++)
        {
            printf("%c", (grid[row][col] == 0) ? ' ' : '*');
        }
        printf("\n");
    }
}

// updates the grid for the next generation
void update_grid(int grid[ROWS][COLS])
{
    int row, col;
    int neighbor_count;
    int new_grid[ROWS][COLS];

    // copy the current grid to a new grid
    for (row = 0; row < ROWS; row++)
    {
        for (col = 0; col < COLS; col++)
        {
            new_grid[row][col] = grid[row][col];
        }
    }

    // update each cell in the new grid
    for (row = 0; row < ROWS; row++)
    {
        for (col = 0; col < COLS; col++)
        {
            neighbor_count = get_neighbor_count(grid, row, col);

            if (grid[row][col] == 0 && neighbor_count == 3)
            {
                new_grid[row][col] = 1;
            }
            else if (grid[row][col] == 1 && (neighbor_count < 2 || neighbor_count > 3))
            {
                new_grid[row][col] = 0;
            }
        }
    }

    // copy the new grid back to the current grid
    for (row = 0; row < ROWS; row++)
    {
        for (col = 0; col < COLS; col++)
        {
            grid[row][col] = new_grid[row][col];
        }
    }
}

// gets the number of live neighbors for a given cell
int get_neighbor_count(int grid[ROWS][COLS], int row, int col)
{
    int count = 0;
    int i, j;

    for (i = row - 1; i <= row + 1; i++)
    {
        for (j = col - 1; j <= col + 1; j++)
        {
            // skip the current cell
            if (i == row && j == col)
            {
                continue;
            }

            // check if the neighbor is in bounds
            if (i >= 0 && i < ROWS && j >= 0 && j < COLS)
            {
                count += grid[i][j];
            }
        }
    }

    return count;
}