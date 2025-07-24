//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: invasive
//Percolation Simulator in C

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define grid size 
#define N 10

// Define probability of each site being open
#define P 0.5

// Define grid as array
int grid[N][N];

// Function to generate random number between 0 and 1
float rand_num()
{
    float num = (float)rand() / (float)RAND_MAX;
    return num;
}

// Function to check if a site is open
int is_open(int i, int j)
{
    return grid[i][j] == 1;
}

// Function to open a site
void open_site(int i, int j)
{
    grid[i][j] = 1;
}

// Function to print the grid
void print_grid()
{
    printf("\n");
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            if(grid[i][j] == 1)
                printf("▓");
            else
                printf("░");
        }
        printf("\n");
    }
}

int main()
{
    // Set random seed
    srand(time(NULL));
    
    // Initialize grid as closed
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            grid[i][j] = 0;
        }
    }
    
    // Open sites at random with probability P
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            float r = rand_num();
            if(r < P)
                open_site(i, j);
        }
    }
    
    // Print initial grid
    print_grid();
    
    // Check if the grid percolates
    for(int i = 0; i < N; i++)
    {
        if(is_open(0, i))
        {
            for(int j = 0; j < N; j++)
            {
                if(is_open(N-1, j))
                {
                    printf("The grid percolates!\n");
                    return 0;
                }
            }
        }
    }
    
    printf("The grid does not percolate!\n");
    
    return 0;
}