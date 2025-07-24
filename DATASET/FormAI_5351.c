//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10
#define COLS 10

int grid[ROWS][COLS];
int visited[ROWS][COLS];

void print_grid(int grid[][COLS], int rows, int cols) {
    printf("\n");
    for (int i = 0; i < rows; i++) {
        printf("[ ");
        for (int j = 0; j < cols; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("]\n");
    }
    printf("\n");
}

void dfs(int i, int j) {
    visited[i][j] = 1;
    if (i > 0 && grid[i-1][j] && !visited[i-1][j]) dfs(i-1, j);
    if (j > 0 && grid[i][j-1] && !visited[i][j-1]) dfs(i, j-1);
    if (i < ROWS-1 && grid[i+1][j] && !visited[i+1][j]) dfs(i+1, j);
    if (j < COLS-1 && grid[i][j+1] && !visited[i][j+1]) dfs(i, j+1);
}

int percolate(int grid[][COLS]) {
    for (int i=0; i<ROWS; i++) {
        visited[i][0] = 1;
        if (grid[i][0]) dfs(i, 0);
    }
    for (int j=1; j<COLS; j++) {
        for (int i=0; i<ROWS; i++) {
            if (visited[i][j]) {
                if (j == COLS-1) return 1;
                if (i > 0 && grid[i-1][j+1] && !visited[i-1][j+1]) dfs(i-1, j+1);
                if (i < ROWS-1 && grid[i+1][j+1] && !visited[i+1][j+1]) dfs(i+1, j+1);
                if (grid[i][j+1] && !visited[i][j+1]) dfs(i, j+1);
            }
        }
    }
    return 0;
}

int main() {
    srand(time(NULL));

    for (int i=0; i<ROWS; i++) {
        for (int j=0; j<COLS; j++) {
            grid[i][j] = rand() % 2;
        }
    }

    print_grid(grid, ROWS, COLS);

    int result = percolate(grid);

    if (result) {
        printf("The grid percolates!\n");
    } else {
        printf("The grid does not percolate.\n");
    }

    return 0;
}