//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10

int grid[N][N];
int visited[N][N];

int percolate(int x, int y);

int main() {
    srand(time(NULL));
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            grid[i][j] = rand() % 2;
            visited[i][j] = 0;
        }
    }
    
    printf("Welcome to the Percolator! \n\n");
    printf("Here's your randomly generated grid: \n\n");
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
    
    printf("\n");
    
    int percolation_status = percolate(0, 0);
    
    if (percolation_status == 1) {
        printf("Congratulations! The grid percolated! \n");
    } else {
        printf("Sorry, the grid did not percolate. \n");
    }
    
    return 0;
}

int percolate(int x, int y) {
    if (x < 0 || x >= N || y < 0 || y >= N) {
        return 0;
    }
    
    if (visited[x][y] == 1 || grid[x][y] == 0) {
        return 0;
    }
    
    visited[x][y] = 1;
    
    if (x == N - 1) {
        return 1;
    }
    
    if (percolate(x - 1, y)) {
        return 1;
    }
    
    if (percolate(x + 1, y)) {
        return 1;
    }
    
    if (percolate(x, y - 1)) {
        return 1;
    }
    
    if (percolate(x, y + 1)) {
        return 1;
    }
    
    return 0;
}