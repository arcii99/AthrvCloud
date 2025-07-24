//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10

// Define a cell structure to store information about each cell
typedef struct
{
    int value; // 0 = blocked, 1 = open
    int visited; // Has this cell been visited during simulation?
    int row;
    int col;
} cell;

void printGrid(cell grid[SIZE][SIZE])
{
    printf("  ");
    for (int col = 0; col < SIZE; col++)
        printf("%2d", col);
    printf("\n");

    for (int row = 0; row < SIZE; row++)
    {
        printf("%2d", row);
        for (int col = 0; col < SIZE; col++)
        {
            if (grid[row][col].value == 0)
                printf("[]");
            else if (grid[row][col].value == 1)
                printf("  ");
        }
        printf("\n");
    }
}

int isPercolating(cell grid[SIZE][SIZE])
{
    // Check if any cells in bottom row are open
    for (int col = 0; col < SIZE; col++)
    {
        if (grid[SIZE-1][col].value == 1)
        {
            // Start recursive search from this cell
            if (dfs(grid, SIZE-1, col))
                return 1;
        }
    }
    return 0;
}

int dfs(cell grid[SIZE][SIZE], int row, int col)
{
    if (row < 0 || row >= SIZE || col < 0 || col >= SIZE)
        return 0;

    if (grid[row][col].visited)
        return 0;

    if (grid[row][col].value == 0)
        return 0;

    if (row == 0) // Cell is connected to top row
        return 1;

    grid[row][col].visited = 1;

    if (dfs(grid, row+1, col) || dfs(grid, row-1, col) || dfs(grid, row, col+1) || dfs(grid, row, col-1))
        return 1;

    return 0;
}

void percolationSimulation()
{
    // Initialize grid with all cells blocked
    cell grid[SIZE][SIZE];
    for (int row = 0; row < SIZE; row++)
    {
        for (int col = 0; col < SIZE; col++)
        {
            grid[row][col].value = 0;
            grid[row][col].visited = 0;
            grid[row][col].row = row;
            grid[row][col].col = col;
        }
    }

    // Open cells randomly until the grid percolates
    srand(time(NULL));
    int openCount = 0;
    while (!isPercolating(grid))
    {
        int row = rand() % SIZE;
        int col = rand() % SIZE;
        if (grid[row][col].value == 0)
        {
            grid[row][col].value = 1;
            openCount++;
        }
    }

    // Print final grid and statistics
    printf("Final grid:\n");
    printGrid(grid);
    printf("\nOpened %d cells to achieve percolation\n", openCount);
}

int main()
{
    percolationSimulation();
    return 0;
}