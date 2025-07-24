//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10
#define COLS 10

void print_grid(int grid[][COLS]) {
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            printf("%c ", grid[i][j] == 0 ? '.' : 'O');
        }
        printf("\n");
    }
}

void dfs(int grid[][COLS], int row, int col) {
    if(row < 0 || row >= ROWS || col < 0 || col >= COLS || grid[row][col] == 1) {
        return;
    }
    grid[row][col] = 1;
    dfs(grid, row+1, col);
    dfs(grid, row-1, col);
    dfs(grid, row, col+1);
    dfs(grid, row, col-1);
}

int percolates(int grid[][COLS]) {
    for(int i = 0; i < COLS; i++) {
        if(grid[0][i] == 0) {
            dfs(grid, 0, i);
        }
    }
    for(int i = 0; i < ROWS; i++) {
        if(grid[i][0] == 0) {
            dfs(grid, i, 0);
        }
    }
    for(int i = 0; i < COLS; i++) {
        if(grid[ROWS-1][i] == 0) {
            dfs(grid, ROWS-1, i);
        }
    }
    for(int i = 0; i < ROWS; i++) {
        if(grid[i][COLS-1] == 0) {
            dfs(grid, i, COLS-1);
        }
    }
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            if(grid[i][j] == 0) {
                return 0;
            }
        }
    }
    return 1;
}

int main() {
    srand(time(NULL));
    int grid[ROWS][COLS];
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            grid[i][j] = rand() % 2;
        }
    }
    print_grid(grid);
    if(percolates(grid)) {
        printf("\nOh yeah! This baby can percolate!\n");
    } else {
        printf("\nSorry, this baby just can't percolate. :(\n");
    }
    return 0;
}