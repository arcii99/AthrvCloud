//FormAI DATASET v1.0 Category: Game of Life ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 50
#define COLS 50

// Function to initialize the grid with random values
void initialize_grid(int grid[][COLS])
{
    srand(time(NULL));
    for(int i=0; i<ROWS; i++)
    {
        for(int j=0; j<COLS; j++)
        {
            grid[i][j] = rand() % 2;
        }
    }
}

// Function to print the grid
void print_grid(int grid[][COLS])
{
    for(int i=0; i<ROWS; i++)
    {
        for(int j=0; j<COLS; j++)
        {
            if(grid[i][j] == 0)
            {
                printf(".");
            }
            else
            {
                printf("*");
            }
        }
        printf("\n");
    }
}

// Function to count live neighbors of a given cell
int count_neighbors(int grid[][COLS], int row, int col)
{
    int count = 0;
    for(int i=row-1; i<=row+1; i++)
    {
        for(int j=col-1; j<=col+1; j++)
        {
            if(i==row && j==col)
            {
                continue;
            }
            if(i<0 || i>=ROWS || j<0 || j>=COLS)
            {
                continue;
            }
            count += grid[i][j];
        }
    }
    return count;
}

// Function to update the grid according to the rules of the game
void update_grid(int grid[][COLS])
{
    int temp[ROWS][COLS];
    for(int i=0; i<ROWS; i++)
    {
        for(int j=0; j<COLS; j++)
        {
            int neighbors = count_neighbors(grid, i, j);
            if(grid[i][j] == 1) // cell is alive
            {
                if(neighbors < 2 || neighbors > 3)
                {
                    temp[i][j] = 0; // cell dies
                }
                else
                {
                    temp[i][j] = 1; // cell stays alive
                }
            }
            else // cell is dead
            {
                if(neighbors == 3)
                {
                    temp[i][j] = 1; // cell becomes alive
                }
                else
                {
                    temp[i][j] = 0; // cell stays dead
                }
            }
        }
    }
    // Copy the updated grid to the original grid
    for(int i=0; i<ROWS; i++)
    {
        for(int j=0; j<COLS; j++)
        {
            grid[i][j] = temp[i][j];
        }
    }
}

// Main function
int main()
{
    int grid[ROWS][COLS];
    initialize_grid(grid);
    for(int i=0; i<100; i++)
    {
        system("clear");
        printf("Generation %d:\n", i+1);
        print_grid(grid);
        update_grid(grid);
    }
    return 0;
}