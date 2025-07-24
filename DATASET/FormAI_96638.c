//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 20

int grid[N][N];
int visited[N][N];

void initialize_grid() {
    int i, j;
    for(i = 0; i < N; i++) {
        for(j = 0; j < N; j++) {
            grid[i][j] = rand() % 2;
            visited[i][j] = 0;
        }
    }
}

int is_percolated(int row, int col) {
    if(row < 0 || row >= N || col < 0 || col >= N) return 0;
    if(visited[row][col] || grid[row][col] == 0) return 0;

    visited[row][col] = 1;

    if(row == N - 1) return 1;

    if(is_percolated(row - 1, col) || is_percolated(row + 1, col)
        || is_percolated(row, col - 1) || is_percolated(row, col + 1))
        return 1;

    return 0;
}

int percolates() {
    int i;
    for(i = 0; i < N; i++) {
        if(grid[0][i] == 1 && is_percolated(0, i)) return 1;
    }
    return 0;
}

void print_grid() {
    int i, j;
    for(i = 0; i < N; i++) {
        for(j = 0; j < N; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));
    initialize_grid();
    printf("Percolation Possible? %d\n", percolates());
    print_grid();
    return 0;
}