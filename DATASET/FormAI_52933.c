//FormAI DATASET v1.0 Category: Game of Life ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>

#define ROWS 20
#define COLS 50

// function to print the grid
void printGrid(int grid[][COLS])
{
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            if (grid[i][j] == 0) // for dead cells
            {
                printf(". ");
            }
            else // for alive cells
            {
                printf("# ");
            }
        }
        printf("\n");
    }
}

// function to count the number of live neighbors
int countNeighbors(int grid[][COLS], int x, int y)
{
    int count = 0;

    // check left neighbor
    if (y > 0 && grid[x][y-1] == 1) 
    {
        count++;
    }

    // check right neighbor
    if (y < COLS-1 && grid[x][y+1] == 1) 
    {
        count++;
    }

    // check top neighbor
    if (x > 0 && grid[x-1][y] == 1) 
    {
        count++;
    }

    // check bottom neighbor
    if (x < ROWS-1 && grid[x+1][y] == 1) 
    {
        count++;
    }

    // check top left neighbor
    if (x > 0 && y > 0 && grid[x-1][y-1] == 1) 
    {
        count++;
    }

    // check top right neighbor
    if (x > 0 && y < COLS-1 && grid[x-1][y+1] == 1) 
    {
        count++;
    }

    // check bottom left neighbor
    if (x < ROWS-1 && y > 0 && grid[x+1][y-1] == 1) 
    {
        count++;
    }

    // check bottom right neighbor
    if (x < ROWS-1 && y < COLS-1 && grid[x+1][y+1] == 1) 
    {
        count++;
    }

    return count;
}

// function to update the grid for the next generation
void updateGrid(int grid[][COLS])
{
    int newGrid[ROWS][COLS] = {0}; // initialize all cells to dead

    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            // count the number of live neighbors
            int count = countNeighbors(grid, i, j);

            if (grid[i][j] == 1) // for live cells
            {
                if (count < 2 || count > 3) // rule 1 and rule 3
                {
                    newGrid[i][j] = 0; // cell dies
                }
                else // rule 2
                {
                    newGrid[i][j] = 1; // cell stays alive
                }
            }
            else // for dead cells
            {
                if (count == 3) // rule 4
                {
                    newGrid[i][j] = 1; // cell comes alive
                }
            }
        }
    }

    // copy the new grid to the original grid
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            grid[i][j] = newGrid[i][j];
        }
    }
}

// main function to initialize and run the game
int main()
{
    int grid[ROWS][COLS] = {0}; // initialize all cells to dead

    // initialize some live cells
    grid[5][5] = 1;
    grid[6][5] = 1;
    grid[7][5] = 1;

    grid[10][20] = 1;
    grid[11][20] = 1;
    grid[12][20] = 1;

    grid[15][40] = 1;
    grid[15][41] = 1;
    grid[15][42] = 1;

    // run the game for 50 generations
    for (int i = 1; i <= 50; i++)
    {
        printf("Generation %d:\n", i);
        printGrid(grid);
        updateGrid(grid);
    }

    return 0;
}