//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 20 // size of grid
#define P 0.6 // probability of a cell being open
#define BLOCKED -1 // value representing a blocked cell
#define OPEN 0 // value representing an open cell
#define CONNECTED 1 // value representing a connected cell

void printGrid(int grid[N][N]);
int isFull(int grid[N][N], int row, int col);
void percolate(int grid[N][N]);

int main() {
    srand(time(NULL)); // seed random number generator with current time

    int grid[N][N]; // initialize grid
    for (int row = 0; row < N; row++) {
        for (int col = 0; col < N; col++) {
            if ((double)rand() / (double)RAND_MAX <= P) { // generate random value for cell
                grid[row][col] = OPEN;
            } else {
                grid[row][col] = BLOCKED;
            }
        }
    }

    percolate(grid); // percolate through grid

    printGrid(grid); // print final state of grid

    return 0;
}

void printGrid(int grid[N][N]) {
    printf("\n");
    for (int row = 0; row < N; row++) {
        for (int col = 0; col < N; col++) {
            if (grid[row][col] == BLOCKED) {
                printf("%c", 'X'); // print X for blocked cell
            } else if (isFull(grid, row, col)) {
                printf("%c", 'O'); // print O for connected cell
            } else {
                printf("%c", ' '); // print space for open cell
            }
        }
        printf("\n");
    }
    printf("\n");
}

int isFull(int grid[N][N], int row, int col) {
    if (row < 0 || row >= N || col < 0 || col >= N) {
        return 0; // cell is out of bounds
    }
    if (grid[row][col] == BLOCKED || grid[row][col] == CONNECTED) {
        return 0; // cell is blocked or already connected
    }
    if (row == N - 1) {
        return 1; // cell is in bottom row, so is full
    }
    grid[row][col] = CONNECTED; // mark cell as connected
    // check if neighboring cells are also full
    int up = isFull(grid, row - 1, col);
    int down = isFull(grid, row + 1, col);
    int left = isFull(grid, row, col - 1);
    int right = isFull(grid, row, col + 1);
    return up || down || left || right; // return true if any neighboring cell is full
}

void percolate(int grid[N][N]) {
    for (int col = 0; col < N; col++) {
        if (grid[0][col] == OPEN) {
            isFull(grid, 0, col); // check if cell is full
        }
    }
}