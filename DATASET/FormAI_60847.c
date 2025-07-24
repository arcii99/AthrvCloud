//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define WIDTH 20
#define HEIGHT 20

bool grid[WIDTH][HEIGHT];
bool visited[WIDTH][HEIGHT];

void initializeGrid()
{
    // Initialize all cells to be blocked
    for (int i = 0; i < WIDTH; i++) {
        for (int j = 0; j < HEIGHT; j++) {
            grid[i][j] = false;
            visited[i][j] = false;
        }
    }

    // Open the top and bottom rows
    for (int i = 0; i < WIDTH; i++) {
        grid[i][0] = true;
        grid[i][HEIGHT-1] = true;
    }

    // Open the left and right columns
    for (int j = 0; j < HEIGHT; j++) {
        grid[0][j] = true;
        grid[WIDTH-1][j] = true;
    }
}

void printGrid()
{
    for (int i = 0; i < WIDTH; i++) {
        for (int j = 0; j < HEIGHT; j++) {
            if (grid[i][j]) {
                printf(" ");
            } else {
                printf("#");
            }
        }
        printf("\n");
    }
}

bool percolates()
{
    // Check if the grid percolates (i.e. there is a path from top to bottom)
    for (int i = 1; i < WIDTH-1; i++) {
        if (visited[i][1]) {
            return true;
        }
    }
    return false;
}

void dfs(int i, int j)
{
    visited[i][j] = true;

    if (i > 1 && !visited[i-1][j] && grid[i-1][j]) {
        dfs(i-1, j);
    }
    if (i < WIDTH-2 && !visited[i+1][j] && grid[i+1][j]) {
        dfs(i+1, j);
    }
    if (j > 1 && !visited[i][j-1] && grid[i][j-1]) {
        dfs(i, j-1);
    }
    if (j < HEIGHT-2 && !visited[i][j+1] && grid[i][j+1]) {
        dfs(i, j+1);
    }
}

void generateRandomGrid()
{
    // Generate a random grid with open cells and blocked cells
    srand(time(NULL));

    for (int i = 1; i < WIDTH-1; i++) {
        for (int j = 1; j < HEIGHT-1; j++) {
            bool isOpen = rand() % 2;
            grid[i][j] = isOpen;
        }
    }
}

int main()
{
    initializeGrid();

    printf("Initial grid:\n");
    printGrid();

    generateRandomGrid();
    printf("\nRandom grid:\n");
    printGrid();

    dfs(1, 1);
    bool doesPercolate = percolates();
    if (doesPercolate) {
        printf("\nThe grid percolates!\n");
    } else {
        printf("\nThe grid does not percolate.\n");
    }

    return 0;
}