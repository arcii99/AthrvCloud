//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: peaceful
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define N 10

int grid[N][N];
int visited[N][N];

void initialize_grid() {
    // Fill the grid with 0s and 1s randomly
    srand(time(NULL));
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            grid[i][j] = rand()%2;
            visited[i][j] = 0;
        }
    }
}

void dfs(int row, int col) {
    visited[row][col] = 1;
    if(row > 0 && grid[row-1][col] && !visited[row-1][col]) {
        dfs(row-1, col);
    }
    if(row < N-1 && grid[row+1][col] && !visited[row+1][col]) {
        dfs(row+1, col);
    }
    if(col > 0 && grid[row][col-1] && !visited[row][col-1]) {
        dfs(row, col-1);
    }
    if(col < N-1 && grid[row][col+1] && !visited[row][col+1]) {
        dfs(row, col+1);
    }
}

int is_percolating() {
    int flag = 0;
    for(int j = 0; j < N; j++) {
        if(visited[0][j]) {
            dfs(0, j);
        }
    }
    for(int j = 0; j < N; j++) {
        if(visited[N-1][j]) {
            flag = 1;
        }
    }
    return flag;
}

int main() {
    initialize_grid();
    printf("Initial grid:\n");
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
    if(is_percolating()) {
        printf("The grid is percolating.\n");
    }
    else {
        printf("The grid is not percolating.\n");
    }
    return 0;
}