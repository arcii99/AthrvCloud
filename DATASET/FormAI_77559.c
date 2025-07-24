//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10

int grid[N][N];
int open[N][N];

// Initialize the grid
void initialize() {
    int row, col;
    for (row = 0; row < N; row++) {
        for (col = 0; col < N; col++) {
            grid[row][col] = 0;
            open[row][col] = 0;
        }
    }
}

// Print the grid
void printGrid() {
    int row, col;
    for (row = 0; row < N; row++) {
        for (col = 0; col < N; col++) {
            if (open[row][col]) {
                printf(" ");
                if (grid[row][col]) {
                    printf("*");
                } else {
                    printf("-");
                }
            } else {
                printf("#");
            }
        }
        printf("\n");
    }
}

// Check if cell (row, col) is valid
int isValid(int row, int col) {
    return row >= 0 && row < N && col >= 0 && col < N;
}

// Open cell (row, col)
void openCell(int row, int col) {
    open[row][col] = 1;
    if (!grid[row][col]) {
        return;
    }
    int dr[] = {-1, 0, 1, 0};
    int dc[] = {0, 1, 0, -1};
    int i;
    for (i = 0; i < 4; i++) {
        int nr = row + dr[i];
        int nc = col + dc[i];
        if (isValid(nr, nc) && !open[nr][nc]) {
            openCell(nr, nc);
        }
    }
}

// Check if the top row is full
int isFull(int row, int col) {
    if (!isValid(row, col)) {
        return 0;
    }
    if (grid[row][col] && !open[row][col]) {
        openCell(row, col);
    }
    return open[row][col];
}

// Check if the grid percolates
int percolates() {
    int row;
    for (row = 0; row < N; row++) {
        if (isFull(0, row)) {
            return 1;
        }
    }
    return 0;
}

// Randomly open cells
void percolate() {
    while (!percolates()) {
        int row = rand() % N;
        int col = rand() % N;
        openCell(row, col);
    }
}

// Main function
int main() {
    srand(time(NULL));
    initialize();
    percolate();
    printGrid();
    return 0;
}