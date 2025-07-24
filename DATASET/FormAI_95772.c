//FormAI DATASET v1.0 Category: Game of Life ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 20
#define COLS 60

int grid[ROWS][COLS];

void initialize() {
    int r, c;
    srand(time(NULL));
    for (r = 0; r < ROWS; r++) {
        for (c = 0; c < COLS; c++) {
            grid[r][c] = rand() % 2;
        }
    }
}

void printGrid() {
    int r, c;
    for (r = 0; r < ROWS; r++) {
        for (c = 0; c < COLS; c++) {
            printf(grid[r][c] ? "#" : ".");
        }
        printf("\n");
    }
}

int countNeighbors(int row, int col) {
    int r, c, count = 0;
    for (r = row - 1; r <= row + 1; r++) {
        for (c = col - 1; c <= col + 1; c++) {
            if (r >= 0 && r < ROWS && c >= 0 && c < COLS && !(r == row && c == col)) {
                count += grid[r][c];
            }
        }
    }
    return count;
}

void updateGrid() {
    int r, c, neighbors;
    int newGrid[ROWS][COLS];
    for (r = 0; r < ROWS; r++) {
        for (c = 0; c < COLS; c++) {
            neighbors = countNeighbors(r, c);
            if (grid[r][c]) {
                if (neighbors < 2 || neighbors > 3) {
                    newGrid[r][c] = 0;
                }
                else {
                    newGrid[r][c] = 1;
                }
            }
            else {
                if (neighbors == 3) {
                    newGrid[r][c] = 1;
                }
                else {
                    newGrid[r][c] = 0;
                }
            }
        }
    }
    for (r = 0; r < ROWS; r++) {
        for (c = 0; c < COLS; c++) {
            grid[r][c] = newGrid[r][c];
        }
    }
}

int main() {
    initialize();
    while (1) {
        system("clear");
        printGrid();
        updateGrid();
        usleep(250000);
    }
    return 0;
}