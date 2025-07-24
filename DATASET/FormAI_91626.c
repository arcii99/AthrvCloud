//FormAI DATASET v1.0 Category: Game of Life ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 20
#define COLS 50

int grid[ROWS][COLS], nextGrid[ROWS][COLS];

void initGrid() {
    srand(time(NULL));
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            grid[i][j] = nextGrid[i][j] = rand() % 2;
        }
    }
}

void printGrid() {
    system("clear");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (grid[i][j] == 1) {
                printf("%c", 219);
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

int countNeighbors(int row, int col) {
    int count = 0;
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            int r = (row + i + ROWS) % ROWS;
            int c = (col + j + COLS) % COLS;
            count += grid[r][c];
        }
    }
    count -= grid[row][col];
    return count;
}

void updateGrid() {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            int neighbors = countNeighbors(i, j);
            if (grid[i][j] == 1 && (neighbors < 2 || neighbors > 3)) {
                nextGrid[i][j] = 0;
            } else if (grid[i][j] == 0 && neighbors == 3) {
                nextGrid[i][j] = 1;
            } else {
                nextGrid[i][j] = grid[i][j];
            }
        }
    }
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            grid[i][j] = nextGrid[i][j];
        }
    }
}

int main() {
    initGrid();
    while (1) {
        printGrid();
        updateGrid();
        usleep(100000);
    }
    return 0;
}