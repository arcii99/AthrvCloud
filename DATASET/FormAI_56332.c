//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10
#define P 0.6

// function to print the percolation grid
void print_grid(int grid[][N])
{
    printf("\nThe percolation grid is:\n\n");

    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
}

// function to check if the percolation has occurred
int check_percolation(int grid[][N])
{
    int top_row[N] = {0}; // to store the top row of the grid
    int bottom_row[N] = {0}; // to store the bottom row of the grid

    // check for open sites in top and bottom rows
    for(int j=0;j<N;j++)
    {
        if(grid[0][j] == 1) top_row[j] = 1;
        if(grid[N-1][j] == 1) bottom_row[j] = 1;
    }

    // check if there is a path from top row to bottom row
    for(int j=0;j<N;j++)
    {
        if(top_row[j] == 1 && bottom_row[j] == 1) return 1;
    }

    return 0;
}

// function to simulate percolation
void simulate_percolation()
{
    int grid[N][N] = {0}; // initialize grid with all the sites being blocked

    // randomly open sites with probability P
    srand(time(0));
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            float r = (float)rand()/(float)RAND_MAX;
            if(r < P) grid[i][j] = 1;
        }
    }

    print_grid(grid); // print the initial grid

    // keep opening sites until percolation occurs
    while(!check_percolation(grid))
    {
        // random site coordinates
        int i = rand() % N;
        int j = rand() % N;

        // open the site if it is not already open
        if(grid[i][j] == 0) grid[i][j] = 1;
    }

    print_grid(grid); // print the final percolation grid
}

int main()
{
    simulate_percolation(); // simulate percolation
    return 0;
}