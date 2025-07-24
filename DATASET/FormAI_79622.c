//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10
#define P 0.6

int grid[N][N];
int visited[N][N];

void initialize_grid() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if ((double)rand() / (double)RAND_MAX < P) {
                grid[i][j] = 1;
            }
            else {
                grid[i][j] = 0;
            }
            visited[i][j] = 0;
        }
    }
}

void print_grid() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
}

int percolates() {
    for (int i = 0; i < N; i++) {
        if (visited[0][i] == 0 && grid[0][i] == 1) {
            visited[0][i] = 1;
            if (percolates_recursive(0, i)) {
                return 1;
            }
        }
    }
    return 0;
}

int percolates_recursive(int row, int col) {
    visited[row][col] = 1;
    if (row == N - 1) {
        return 1;
    }
    if (col != 0 && visited[row][col - 1] == 0 && grid[row][col - 1] == 1) {
        if (percolates_recursive(row, col - 1)) {
            return 1;
        }
    }
    if (col != N - 1 && visited[row][col + 1] == 0 && grid[row][col + 1] == 1) {
        if (percolates_recursive(row, col + 1)) {
            return 1;
        }
    }
    if (row != N - 1 && visited[row + 1][col] == 0 && grid[row + 1][col] == 1) {
        if (percolates_recursive(row + 1, col)) {
            return 1;
        }
    }
    return 0;
}

int main() {
    srand(time(NULL));
    initialize_grid();
    printf("Grid:\n");
    print_grid();
    if (percolates()) {
        printf("Percolates!\n");
    }
    else {
        printf("Does not percolate.\n");
    }
    return 0;
}