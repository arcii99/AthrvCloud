//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: recursive
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

#define GRID_SIZE 10

bool grid[GRID_SIZE][GRID_SIZE];
bool visited[GRID_SIZE][GRID_SIZE];
bool percolates = false;

void fill() {
    srand(time(NULL));
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            int r = rand() % 10;
            if (r == 0) {
                grid[i][j] = true;
            } else {
                grid[i][j] = false;
            }
        }
    }
}

void printGrid() {
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            if (grid[i][j]) {
                printf("* ");
            } else {
                printf(". ");
            }
        }
        printf("\n");
    }
}

void dfs(int i, int j) {
    visited[i][j] = true;
    if (i == GRID_SIZE - 1) {
        percolates = true;
        return;
    }
    if (i > 0 && !visited[i - 1][j] && grid[i - 1][j]) {
        dfs(i - 1, j);
    }
    if (i < GRID_SIZE - 1 && !visited[i + 1][j] && grid[i + 1][j]) {
        dfs(i + 1, j);
    }
    if (j > 0 && !visited[i][j - 1] && grid[i][j - 1]) {
        dfs(i, j - 1);
    }
    if (j < GRID_SIZE - 1 && !visited[i][j + 1] && grid[i][j + 1]) {
        dfs(i, j + 1);
    }
}

bool percolate() {
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            visited[i][j] = false;
        }
    }
    percolates = false;
    for (int j = 0; j < GRID_SIZE; j++) {
        if (grid[0][j]) {
            dfs(0, j);
        }
    }
    return percolates;
}

int main() {
    fill();
    printf("Initial Grid:\n");
    printGrid();
    if (percolate()) {
        printf("The grid percolates!\n");
    } else {
        printf("The grid does not percolate.\n");
    }
    return 0;
}