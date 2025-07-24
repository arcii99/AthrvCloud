//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: multivariable
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <time.h>

#define SIZE 10 // size of the grid
#define THRESHOLD 0.6 // probability of a cell being open

bool grid[SIZE][SIZE];
bool connected[SIZE][SIZE];

void printGrid() {
    printf("\n----------------\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (grid[i][j]) {
                printf("|_|");
            } else {
                printf("|X|");
            }
        }
        printf("\n----------------\n");
    }
}

bool percolates() {
    for (int i = 0; i < SIZE; i++) {
        if (connected[0][i] && connected[SIZE - 1][i]) {
            return true;
        }
    }
    return false;
}

void dfs(int x, int y) {
    if (x < 0 || x >= SIZE || y < 0 || y >= SIZE) {
        return;
    }
    if (!grid[x][y] || connected[x][y]) {
        return;
    }
    connected[x][y] = true;
    dfs(x + 1, y);
    dfs(x - 1, y);
    dfs(x, y + 1);
    dfs(x, y - 1);
}

void connect() {
    for (int i = 0; i < SIZE; i++) {
        dfs(0, i);
    }
}

void percolation() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            double p = ((double) rand() / RAND_MAX);
            if (p < THRESHOLD) {
                grid[i][j] = true;
            }
        }
    }
    connect();
}

int main() {
    srand(time(NULL));
    percolation();
    printGrid();
    if (percolates()) {
        printf("\nThe grid percolates!\n");
    } else {
        printf("\nThe grid does not percolate.\n");
    }
    return 0;
}