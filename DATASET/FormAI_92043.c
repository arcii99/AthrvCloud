//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10

int main()
{
    int grid[N][N];
    int visited[N][N];
    int i, j, k;

    // Initialize the grid and visited arrays
    for (i = 0; i < N; i++)
        for (j = 0; j < N; j++)
        {
            grid[i][j] = rand() % 2;
            visited[i][j] = 0;
        }

    // Print the initial grid
    printf("Initial grid:\n");
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
            printf("%d ", grid[i][j]);
        printf("\n");
    }

    // Check if the percolation is possible
    int percolates = 0;
    for (j = 0; j < N; j++)
        if (grid[0][j] == 1)
        {
            visited[0][j] = 1;
            percolates = percolation(visited, grid, 0, j);
            if (percolates)
                break;
        }

    // Print the result
    if (percolates)
        printf("Percolation is possible!\n");
    else
        printf("Percolation is not possible.\n");

    return 0;
}

int percolation(int visited[][N], int grid[][N], int i, int j)
{
    // Mark the cell as visited
    visited[i][j] = 1;

    // Check if the cell is at the bottom
    if (i == N-1)
        return 1;

    // Check if the neighboring cells can be percolated
    int percolates = 0;
    if (i > 0 && grid[i-1][j] && !visited[i-1][j])
        percolates = percolation(visited, grid, i-1, j);
    if (i < N-1 && grid[i+1][j] && !visited[i+1][j] && !percolates)
        percolates = percolation(visited, grid, i+1, j);
    if (j > 0 && grid[i][j-1] && !visited[i][j-1] && !percolates)
        percolates = percolation(visited, grid, i, j-1);
    if (j < N-1 && grid[i][j+1] && !visited[i][j+1] && !percolates)
        percolates = percolation(visited, grid, i, j+1);

    return percolates;
}