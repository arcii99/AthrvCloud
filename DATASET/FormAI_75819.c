//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 20
#define COLS 20
#define PERC_OPEN 0.6  // percentage of cells to randomly open

int grid[ROWS][COLS];
int visited[ROWS][COLS];

void init_grid() {
    int i, j;
    for (i = 0; i < ROWS; i++)
        for (j = 0; j < COLS; j++) {
            grid[i][j] = 0;
            visited[i][j] = 0;
        }
}

void print_grid() {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++)
            printf("%c ", grid[i][j] ? 'o' : 'x');
        printf("\n");
    }
}

int percolates() {
    int i, j;
    for (j = 0; j < COLS; j++)
        if (visited[ROWS-1][j])
            return 1;
    return 0;
}

void dfs(int i, int j) {
    if (i < 0 || i >= ROWS || j < 0 || j >= COLS) return;
    if (visited[i][j] || !grid[i][j]) return;
    visited[i][j] = 1;
    dfs(i-1, j);
    dfs(i+1, j);
    dfs(i, j-1);
    dfs(i, j+1);
}

void propagate() {
    int i, j;

    for (j = 0; j < COLS; j++)
        if (grid[0][j]) visited[0][j] = 1;

    for (i = 1; i < ROWS; i++)
        for (j = 0; j < COLS; j++)
            if (grid[i][j]) {
                if (visited[i-1][j]) visited[i][j] = 1;
                if (visited[i-1][j-1]) visited[i][j] = 1;
                if (visited[i-1][j+1]) visited[i][j] = 1;
            }

    for (j = 0; j < COLS; j++)
        if (visited[ROWS-1][j]) dfs(ROWS-1, j);
}

int main() {
    srand(time(NULL));
    init_grid();

    int i, j, num_open = PERC_OPEN * ROWS * COLS;

    for (i = 0; i < num_open; i++) {
        int rand_row = rand() % ROWS;
        int rand_col = rand() % COLS;
        grid[rand_row][rand_col] = 1;
    }

    propagate();

    print_grid();
    printf("\n");

    if (percolates())
        printf("The system percolates!\n");
    else
        printf("The system does not percolate.\n");

    return 0;
}