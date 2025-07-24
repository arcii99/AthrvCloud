//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: decentralized
// C Percolation Simulator Example Program

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define ROWS 10 // number of rows in grid
#define COLS 10 // number of columns in grid

// determine if the grid percolates
bool percolates(int grid[][COLS])
{
    // check if there is a path from top row to bottom row
    for (int j = 0; j < COLS; j++)
    {
        if (grid[0][j] == 1)
        {
            // create visited matrix
            bool visited[ROWS][COLS];
            for (int i = 0; i < ROWS; i++)
            {
                for (int k = 0; k < COLS; k++)
                {
                    visited[i][k] = false;
                }
            }
            // dfs to find path
            bool found_path = false;
            int row = 0;
            int col = j;
            while (row >= 0 && row < ROWS && col >= 0 && col < COLS)
            {
                if (visited[row][col])
                {
                    found_path = true;
                    break;
                }
                visited[row][col] = true;
                if (row == ROWS - 1)
                {
                    found_path = true;
                    break;
                }
                if (grid[row + 1][col] == 1)
                {
                    row++;
                }
                else if (col > 0 && grid[row][col - 1] == 1)
                {
                    col--;
                }
                else if (col < COLS - 1 && grid[row][col + 1] == 1)
                {
                    col++;
                }
                else
                {
                    row--;
                }
            }
            if (found_path)
            {
                return true;
            }
        }
    }
    return false;
}

// print grid to console
void print_grid(int grid[][COLS])
{
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    // seed random number generator
    srand(time(NULL));
    
    // create empty grid
    int grid[ROWS][COLS];
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            grid[i][j] = 0;
        }
    }
    
    // randomly fill grid with sites
    double p = 0.5; // probability for site to be open
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            double r = (double) rand() / RAND_MAX;
            if (r < p)
            {
                grid[i][j] = 1;
            }
        }
    }
    
    // print grid
    printf("Initial Grid:\n");
    print_grid(grid);
    
    // determine if grid percolates
    if (percolates(grid))
    {
        printf("The Grid percolates!\n");
    }
    else
    {
        printf("The Grid does not percolate.\n");
    }
    
    return 0;
}