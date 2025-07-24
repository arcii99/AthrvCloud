//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 20
#define P 0.5

int grid[N][N];
int visited[N][N];

void print_grid(int grid[][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
}

void percolate_recurse(int row, int col) {
    if (row < 0 || row >= N || col < 0 || col >= N) {
        return;
    } else if (visited[row][col] || !grid[row][col]) {
        return;
    }
    
    visited[row][col] = 1;
    grid[row][col] = 2;
    
    percolate_recurse(row-1, col);
    percolate_recurse(row+1, col);
    percolate_recurse(row, col-1);
    percolate_recurse(row, col+1);
}

int percolation(int grid[][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            visited[i][j] = 0;
        }
    }
    
    for (int i = 0; i < N; i++) {
        if (!visited[0][i] && grid[0][i]) {
            percolate_recurse(0, i);
        }
    }
    
    for (int i = 0; i < N; i++) {
        if (grid[N-1][i] == 2) {
            return 1;
        }
    }
    
    return 0;
}

int main() {
    srand(time(0));
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if ((double)rand() / RAND_MAX < P) {
                grid[i][j] = 1;
            } else {
                grid[i][j] = 0;
            }
        }
    }
    
    print_grid(grid);
    
    if (percolation(grid)) {
        printf("The system percolates\n");
    } else {
        printf("The system does not percolate\n");
    }
    
    return 0;
}