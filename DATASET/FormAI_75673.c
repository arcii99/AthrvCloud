//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10

int grid[SIZE][SIZE];
int visited[SIZE][SIZE];

void dfs(int x, int y) {
    if (visited[x][y]) return;
    visited[x][y] = 1;
    if (x-1 >= 0 && grid[x-1][y]) dfs(x-1, y);
    if (x+1 < SIZE && grid[x+1][y]) dfs(x+1, y);
    if (y-1 >= 0 && grid[x][y-1]) dfs(x, y-1);
    if (y+1 < SIZE && grid[x][y+1]) dfs(x, y+1);
}

int main() {
    srand(time(NULL));
    // Initialize the grid randomly
    for (int i = 0; i < SIZE * SIZE / 2; ++i) {
        int x = rand() % SIZE;
        int y = rand() % SIZE;
        grid[x][y] = 1;
        grid[SIZE-1-x][SIZE-1-y] = 1;
    }
    // Print the initial grid
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            printf("%d", grid[i][j]);
        }
        printf("\n");
    }
    // Check if there's a percolation path
    dfs(0, 0);
    int percolates = 0;
    for (int i = 0; i < SIZE; ++i) {
        if (visited[SIZE-1][i]) percolates = 1;
    }
    printf("Percolates: %d\n", percolates);
    return 0;
}