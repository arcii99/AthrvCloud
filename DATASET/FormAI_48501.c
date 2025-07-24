//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10    // Grid size
#define p 0.6   // Probability of site being open

int grid[N][N];
int opened[N][N];
int top[N], bottom[N];

// Function to check if two sites are connected
int connected(int row1, int col1, int row2, int col2)
{
    return (opened[row1][col1] && opened[row2][col2]);
}

// Function to open a site
void open(int row, int col)
{
    opened[row][col] = 1;
    if (row == 0)
        top[col] = 1;
    if (row == N-1)
        bottom[col] = 1;
}

// Function to check if grid percolates
int percolates()
{
    for (int c = 0; c < N; c++)
    {
        if (top[c] && bottom[c])
            return 1;
    }
    return 0;
}

int main()
{
    // Seed random number generator
    srand(time(NULL));
    
    // Initialize grid with closed sites
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            grid[i][j] = 0;
            opened[i][j] = 0;
        }
    }
    
    // Open random sites
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            double rand_num = (double) rand() / RAND_MAX;
            if (rand_num < p)
                open(i, j);
        }
    }
    
    // Print grid with open sites
    printf("Grid:\n");
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (opened[i][j])
                printf("* ");
            else
                printf(". ");
        }
        printf("\n");
    }
    
    // Check if percolates
    if (percolates())
        printf("Percolates!\n");
    else
        printf("Does not percolate.\n");
    
    return 0;
}