//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GRID_SIZE 10
#define PERCOLATION_PROBABILITY 0.6

int grid[GRID_SIZE][GRID_SIZE];
int visited[GRID_SIZE][GRID_SIZE];

void initializeGrid() {
    srand(time(NULL));
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            if ((double) rand() / RAND_MAX < PERCOLATION_PROBABILITY) {
                grid[i][j] = 1;
            } else {
                grid[i][j] = 0;
            }
        }
    }
}

int percolates(int row) {
    for (int i = 0; i < GRID_SIZE; i++) {
        if (visited[row][i] == 1) {
            return 1;
        }
    }
    return 0;
}

void dfs(int row, int col) {
    visited[row][col] = 1;

    if (row < GRID_SIZE - 1 && grid[row + 1][col] == 1 && visited[row + 1][col] == 0) {
        dfs(row + 1, col);
    }
    if (col < GRID_SIZE - 1 && grid[row][col + 1] == 1 && visited[row][col + 1] == 0) {
        dfs(row, col + 1);
    }
    if (row > 0 && grid[row - 1][col] == 1 && visited[row - 1][col] == 0) {
        dfs(row - 1, col);
    }
    if (col > 0 && grid[row][col - 1] == 1 && visited[row][col - 1] == 0) {
        dfs(row, col - 1);
    }
}

int main() {
    initializeGrid();

    printf("Original Grid:\n");
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }

    for (int col = 0; col < GRID_SIZE; col++) {
        if (grid[0][col] == 1) {
            dfs(0, col);
        }
    }

    int isPercolated = 0;
    for (int col = 0; col < GRID_SIZE; col++) {
        if (grid[GRID_SIZE - 1][col] == 1 && percolates(GRID_SIZE - 1)) {
            isPercolated = 1;
            break;
        }
    }

    printf("\nPercolated Grid:\n");
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            if (visited[i][j] == 1) {
                printf("P ");
            } else if (grid[i][j] == 1) {
                printf("O ");
            } else {
                printf("~ ");
            }
        }
        printf("\n");
    }

    if (isPercolated == 1) {
        printf("\nThe system percolates!\n");
    } else {
        printf("\nThe system does not percolate.\n");
    }

    return 0;
}