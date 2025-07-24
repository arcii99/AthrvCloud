//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10
#define COLS 10

int grid[ROWS][COLS];
int visited[ROWS][COLS];
int openSites = 0;

void initGrid() {
    srand(time(NULL));
    int i,j;
    for (i=0;i<ROWS;i++) {
        for (j=0;j<COLS;j++) {
            grid[i][j] = rand() % 2;
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void percolate(int row, int col) {
    if (grid[row][col]) return;
    if (visited[row][col]) return;

    visited[row][col] = 1;
    openSites++;

    if (col > 0) percolate(row, col-1);
    if (col < COLS-1) percolate(row, col+1);
    if (row > 0) percolate(row-1, col);
    if (row < ROWS-1) percolate(row+1, col);
}

int main() {
    initGrid();
    int i,j;
    for (i=0;i<ROWS;i++) {
        for (j=0;j<COLS;j++) {
            visited[i][j] = 0;
        }
    }

    for (j=0;j<COLS;j++) {
        percolate(0,j);
    }

   if (openSites == ROWS*COLS) {
        printf("Percolation achieved!\n");
    } else {
        printf("Percolation not achieved\n");
    }

    return 0;
}