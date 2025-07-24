//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10

int grid[N][N];

int isOpen(int row, int col) {
    return grid[row][col];
}

void open(int row, int col) {
    grid[row][col] = 1;
}

int isFull(int row, int col) {
    int top = 0;
    if (row == 0) {
        return 1;
    }
    if (row > 0 && isOpen(row-1, col)) {
        top = isFull(row-1, col);
    }
    return top;
}

int percolates() {
    int i;
    for (i = 0; i < N; i++) {
        if (isOpen(N-1, i) && isFull(N-1, i)) {
            return 1;
        }
    }
    return 0;
}

void printGrid() {
    int i, j;
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            if (isOpen(i, j)) {
                printf(" ");
            } else {
                printf("#");
            }
        }
        printf("\n");
    }
}

int main() {
    int i, j, r, c;
    srand(time(NULL));

    // initialize all grid squares to be closed
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            grid[i][j] = 0;
        }
    }

    // randomly open squares until the system percolates
    while (!percolates()) {
        r = rand() % N;
        c = rand() % N;
        if (!isOpen(r, c)) {
            open(r, c);
        }
    }

    // print final grid
    printGrid();

    return 0;
}