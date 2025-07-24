//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: recursive
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Size of the grid
#define N 10

// Probability of a site being open
#define P 0.5

// Grid to keep track of open/closed sites
bool grid[N][N];

// Recursive function to check if there is a percolation
bool percolate(int i, int j)
{
    // If we reached the end, then there is percolation
    if (i == N - 1)
        return true;

    // If current site is closed, there is no percolation
    if (!grid[i][j])
        return false;

    // Open the site
    grid[i][j] = false;

    bool percolates = false;

    // Check neighbouring sites
    if (i > 0)
        percolates |= percolate(i - 1, j);
    if (j > 0)
        percolates |= percolate(i, j - 1);
    if (i < N - 1)
        percolates |= percolate(i + 1, j);
    if (j < N - 1)
        percolates |= percolate(i, j + 1);

    // If percolates, we don't need to close the site anymore
    if (percolates)
        return true;

    // If there is no percolation, close the site again
    grid[i][j] = true;

    // If we reached this point, there is no percolation
    return false;
}

int main()
{
    // Seed random number generator
    srand(time(NULL));

    // Randomly open/closed sites in grid
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            grid[i][j] = (rand() / (float)RAND_MAX) < P;
        }
    }

    // Print current grid configuration
    printf("Initial grid:\n");
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            printf("%c", grid[i][j] ? ' ' : '#');
        }
        printf("\n");
    }
    printf("\n");

    // Check if there is percolation
    bool percolates = false;
    for (int j = 0; j < N; j++)
    {
        percolates |= percolate(0, j);
    }

    // Print final grid configuration
    printf("Final grid:\n");
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            printf("%c", grid[i][j] ? ' ' : '#');
        }
        printf("\n");
    }
    printf("\n");

    // Output result
    printf("The grid %s percolates.\n", percolates ? "does" : "does not");

    return 0;
}