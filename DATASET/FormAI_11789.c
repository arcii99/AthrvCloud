//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 20 // size of the grid
#define THRESHOLD 0.45 // probability threshold for filling a site
#define EMPTY 0 // empty site
#define FILLED 1 // filled site
#define CONNECTED FILLED // connected site

void display(int grid[N][N]);

void initialize(int grid[N][N])
{
    // initialize the grid with empty sites
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            grid[i][j] = EMPTY;
        }
    }
}

void fill_sites(int grid[N][N])
{
    // randomly fill the sites based on threshold
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            float probability = (float)rand() / RAND_MAX;
            if(probability <= THRESHOLD)
            {
                grid[i][j] = FILLED;
            }
        }
    }
}

void percolate(int grid[N][N])
{
    // check if sites are connected
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            if(grid[i][j] == FILLED)
            {
                if(i == 0)
                {
                    grid[i][j] = CONNECTED;
                }
                else
                {
                    if(grid[i-1][j] == CONNECTED || grid[i][j-1] == CONNECTED || grid[i+1][j] == CONNECTED || grid[i][j+1] == CONNECTED)
                    {
                        grid[i][j] = CONNECTED;
                    }
                }
            }
        }
    }
}

void display(int grid[N][N])
{
    // display the grid
    printf("------------------------\n");
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            if(grid[i][j] == EMPTY)
            {
                printf(". ");
            }
            else if(grid[i][j] == FILLED)
            {
                printf("# ");
            }
            else if(grid[i][j] == CONNECTED)
            {
                printf("o ");
            }
        }
        printf("\n");
    }
    printf("------------------------\n");
}

int main()
{
    // seed the random number generator
    srand(time(NULL));

    // initialize the grid
    int grid[N][N];
    initialize(grid);

    // fill the sites
    fill_sites(grid);

    // run the percolation algorithm
    percolate(grid);

    // display the final result
    display(grid);

    return 0;
}