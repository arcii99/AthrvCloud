//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define N 10

int grid[N][N];
bool visited[N][N];

void initialize_grid() {
    srand(time(NULL));
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            int p = rand() % 101;
            if(p < 40) {
                grid[i][j] = 1;
            }
            else {
                grid[i][j] = 0;
            }
            visited[i][j] = false;
        }
    }
}

bool can_percolate(int row, int col) {
    if(row < 0 || col < 0 || row >= N || col >= N) {
        return false;
    }
    if(grid[row][col] == 0) {
        return false;
    }
    if(visited[row][col]) {
        return false;
    }
    if(row == N - 1) {
        return true;
    }
    visited[row][col] = true;
    if(can_percolate(row - 1, col) || can_percolate(row + 1, col) || can_percolate(row, col - 1) || can_percolate(row, col + 1)) {
        return true;
    }
    else {
        return false;
    }
}

bool percolates() {
    for(int i = 0; i < N; i++) {
        if(can_percolate(0, i)) {
            return true;
        }
    }
    return false;
}

void print_grid() {
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
}

int main() {
    initialize_grid();
    printf("Initial Grid:\n");
    print_grid();
    if(percolates()) {
        printf("The system percolates!\n");
    }
    else {
        printf("The system does not percolate.\n");
    }
    return 0;
}