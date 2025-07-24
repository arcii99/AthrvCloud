//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10

// Function to generate random numbers
double randNum()
{
    return (double) rand() / (double) RAND_MAX;
}

// Function to initialize the grid
void initialize(int grid[][N])
{
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            grid[i][j] = 0;
        }
    }
}

// Function to print the grid
void printGrid(int grid[][N])
{
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            if(grid[i][j])
            {
                printf("* ");
            }
            else
            {
                printf(". ");
            }
        }
        printf("\n");
    }
}

// Function to run the percolation simulation
int simulate(int grid[][N])
{
    int top[N], bottom[N];

    // Initialize top and bottom rows as not connected
    for(int i = 0; i < N; i++)
    {
        top[i] = 0;
        bottom[i] = 0;
    }

    // Check if top and bottom rows are connected
    for(int i = 0; i < N; i++)
    {
        if(grid[0][i] && !top[i])
        {
            top[i] = 1;
            for(int j = 0; j < N; j++)
            {
                if(grid[N-1][j] && !bottom[j])
                {
                    bottom[j] = 1;
                }
            }
        }
    }

    // Check if there is a percolation path
    for(int i = 0; i < N; i++)
    {
        if(top[i] && bottom[i])
        {
            return 1;
        }
    }

    return 0;
}

int main()
{
    int grid[N][N];

    srand(time(NULL));

    // Initialize the grid
    initialize(grid);

    // Open sites randomly and print the updated grid
    for(int i = 0; i < N*N; i++)
    {
        int row = rand() % N;
        int col = rand() % N;
        grid[row][col] = 1;
        printGrid(grid);
        printf("\n");

        // Check if percolation is possible
        if(simulate(grid))
        {
            printf("Percolation has occured!\n");
            return 0;
        }
    }

    printf("Percolation has not occured.\n");

    return 0;
}