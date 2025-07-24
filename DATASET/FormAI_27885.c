//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10 //Grid size
#define p 0.5 //Probability of filling a site.
#define OPEN 0 //Defines an open site.
#define FULL 1 //Defines a full site.

//Function declarations.
void init_grid(int grid[N][N]);
void print_grid(int grid[N][N]);
int is_percolated(int grid[N][N]);

int main()
{
    srand(time(0)); //Seed generation for random number generation.
    int grid[N][N]; //Main grid to be filled.
    int i, j, num_open = 0;

    init_grid(grid); //Initializes the grid.
    print_grid(grid); //Prints the initial grid.

    // Loop to fill the grid.
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            if (((double)rand() / (double)RAND_MAX) < p)
            {
                grid[i][j] = OPEN;
                num_open++; //Increments the number of open sites.
            }
        }
    }
    
    printf("\nAfter filling random sites:\n");
    print_grid(grid); //Prints the grid after filling random sites.

    if(is_percolated(grid)){
        printf("\nCongratulations! The grid percolates!\n");
    }
    else
    {
        printf("\nSorry, the grid does not percolate.\n");
    }
    return 0;
}

//Sets every element of the grid to FULL.
void init_grid(int grid[N][N])
{
    int i, j;
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            grid[i][j] = FULL;
        }
    }
}

//Prints each site of the grid.
void print_grid(int grid[N][N])
{
    int i, j;
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            if (grid[i][j] == OPEN)
            {
                printf("0 ");
            }
            else
            {
                printf("1 ");
            }
        }
        printf("\n");
    }
}

//Determines if the grid percolates.
int is_percolated(int grid[N][N])
{
    int i, j;

    //Creates an array to keep track of which grids have been visited.
    int visited[N][N] = {0};

    //Despite the init_grid function, we will re-assign the first row here with OPEN site checks.
    for (j = 0; j < N; j++)
    {
        if (grid[0][j] == OPEN)
        {
            visited[0][j] = 1;
        }
    }

    //Checking if the current site has a neighbour (left, right, top, bottom), and is either visited or open.
    for (i = 0; i < N; i++)
    {
        for(j = 0; j < N; j++)
        {
            if (visited[i][j] == 1)
            {
                if (i + 1 < N && grid[i + 1][j] == OPEN && visited[i + 1][j] != 1) visited[i + 1][j] = 1;
                if (i - 1 >= 0 && grid[i - 1][j] == OPEN && visited[i - 1][j] != 1) visited[i - 1][j] = 1;
                if (j + 1 < N && grid[i][j + 1] == OPEN && visited[i][j + 1] != 1) visited[i][j + 1] = 1;
                if (j - 1 >= 0 && grid[i][j - 1] == OPEN && visited[i][j - 1] != 1) visited[i][j - 1] = 1;
            }
        }
    }

    //Checking if last row is visited.
    for (j = 0; j < N; j++)
    {
        if (visited[N - 1][j] == 1) return 1;
    }
    return 0;
}