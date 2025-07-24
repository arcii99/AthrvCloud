//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GRID_SIZE 10

int grid[GRID_SIZE][GRID_SIZE];
int visited[GRID_SIZE][GRID_SIZE];
int number_of_clusters = 0;

void dfs(int row, int col, int cluster) {
    if (row < 0 || row >= GRID_SIZE || col < 0 || col >= GRID_SIZE) return;
    if (visited[row][col] == 1 || grid[row][col] == 0) return;
    visited[row][col] = 1;
    dfs(row + 1, col, cluster);
    dfs(row - 1, col, cluster);
    dfs(row, col + 1, cluster);
    dfs(row, col - 1, cluster);
}

int main() {
    srand(time(NULL));
    int row, col;
    for (row = 0; row < GRID_SIZE; row++) {
        for (col = 0; col < GRID_SIZE; col++) {
            grid[row][col] = rand() % 2;
            visited[row][col] = 0;
        }
    }
    printf("Initial Grid:\n");
    for (row = 0; row < GRID_SIZE; row++) {
        for (col = 0; col < GRID_SIZE; col++) {
            printf("%d ", grid[row][col]);
        }
        printf("\n");
    }
    for (row = 0; row < GRID_SIZE; row++) {
        for (col = 0; col < GRID_SIZE; col++) {
            if (visited[row][col] == 0 && grid[row][col] == 1) {
                number_of_clusters++;
                dfs(row, col, number_of_clusters);
            }
        }
    }
    printf("Final Grid:\n");
    for (row = 0; row < GRID_SIZE; row++) {
        for (col = 0; col < GRID_SIZE; col++) {
            printf("%d ", grid[row][col]);
        }
        printf("\n");
    }
    printf("Number of Clusters: %d\n", number_of_clusters);
    return 0;
}