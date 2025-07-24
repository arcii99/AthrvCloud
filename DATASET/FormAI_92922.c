//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define GRID_SIZE 10

bool grid[GRID_SIZE][GRID_SIZE];
bool visited[GRID_SIZE][GRID_SIZE];

void percolate(int row, int col) {

    if (visited[row][col] || !grid[row][col]) return;
    
    visited[row][col] = true;
    
    if (row != 0) percolate(row - 1, col);
    if (row != GRID_SIZE - 1) percolate(row + 1, col);
    if (col != 0) percolate(row, col - 1);
    if (col != GRID_SIZE - 1) percolate(row, col + 1);
}

bool percolates() {

    for (int i = 0; i < GRID_SIZE; i++)
        if (grid[0][i]) percolate(0, i);

    for (int i = 0; i < GRID_SIZE; i++)
        if (visited[GRID_SIZE-1][i]) return true;

    return false;
}

int main() {

    srand(time(NULL));

    for (int i = 0; i < GRID_SIZE; i++)
        for (int j = 0; j < GRID_SIZE; j++)
            grid[i][j] = rand() % 2;

    printf("Initial grid state:\n");
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++)
            printf("%d ", grid[i][j]);
        printf("\n");
    }

    if (percolates())
        printf("The grid percolates!\n");
    else
        printf("The grid does not percolate.\n");

    return 0;
}