//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: shape shifting
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10
#define COLS 10

int grid[ROWS][COLS];
bool visited[ROWS][COLS];

void print_grid() {
    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLS; j++) {
            if(grid[i][j] == 1) printf("* ");
            else printf(". ");
        }
        printf("\n");
    }
}

int is_percolated() {
    for(int i=0; i<ROWS; i++) {
        if(visited[0][i] && visited[ROWS-1][i]) return 1;
    }
    return 0;
}

void dfs(int row, int col) {
    if(row<0 || row>=ROWS || col<0 || col>=COLS || visited[row][col] || grid[row][col]==0) return;
    visited[row][col] = true;
    dfs(row-1, col);
    dfs(row+1, col);
    dfs(row, col-1);
    dfs(row, col+1);
}

void percolate() {
    int row = 0;
    while(!is_percolated()) {
        int col = rand() % COLS;
        while(grid[row][col] != 1) {
            col = rand() % COLS;
        }
        visited[row][col] = true;
        dfs(row, col);
        print_grid();
        printf("\n");
    }
}

int main() {
    srand(time(NULL));
    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLS; j++) {
            if(rand()%2) grid[i][j] = 0;
            else grid[i][j] = 1;
        }
    }
    print_grid();
    printf("\n");
    percolate();
    return 0;
}