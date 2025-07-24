//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define SIZE 20  // Size of the grid

// Function to randomly generate initial state of the grid
void generateGrid(bool grid[][SIZE])
{
    srand(time(NULL));
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            int r = rand() % 100;
            if (r < 50)
                grid[i][j] = false;
            else
                grid[i][j] = true;
        }
    }
}

// Function to print the grid
void printGrid(bool grid[][SIZE])
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            if (grid[i][j])
                printf("1 ");
            else
                printf("0 ");
        }
        printf("\n");
    }
}

// Function to simulate percolation using DFS
void percolate(bool grid[][SIZE], int x, int y, bool visited[][SIZE])
{
    if (x < 0 || x >= SIZE || y < 0 || y >= SIZE || visited[x][y] || !grid[x][y])
        return;
    visited[x][y] = true;
    percolate(grid, x+1, y, visited);
    percolate(grid, x-1, y, visited);
    percolate(grid, x, y+1, visited);
    percolate(grid, x, y-1, visited);
}

// Function to check if the grid percolates
bool doesPercolate(bool grid[][SIZE])
{
    bool visited[SIZE][SIZE] = {false};
    for (int i = 0; i < SIZE; i++)
    {
        if (grid[0][i])
            percolate(grid, 0, i, visited);
    }
    for (int i = 0; i < SIZE; i++)
    {
        if (visited[SIZE-1][i])
            return true;
    }
    return false;
}

// Main function
int main()
{
    bool grid[SIZE][SIZE];
    generateGrid(grid);
    printf("Initial grid:\n");
    printGrid(grid);
    if (doesPercolate(grid))
        printf("The grid percolates!\n");
    else
        printf("The grid does not percolate.\n");
    return 0;
}