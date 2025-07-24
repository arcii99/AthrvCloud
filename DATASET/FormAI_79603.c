//FormAI DATASET v1.0 Category: Game of Life ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>

#define ROWS 20
#define COLS 30

void printGrid(bool grid[ROWS][COLS]) {
    system("clear");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (grid[i][j]) {
                printf("O");
            } else {
                printf(".");
            }
        }
        printf("\n");
    }
}

bool applyRules(bool currentGrid[ROWS][COLS], int row, int col) {
    int liveNeighbors = 0;

    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            if (i == 0 && j == 0) {
                continue;
            }

            int currentRow = row + i;
            int currentCol = col + j;

            if (currentRow < 0 || currentRow >= ROWS || currentCol < 0 || currentCol >= COLS) {
                continue;
            }

            if (currentGrid[currentRow][currentCol]) {
                liveNeighbors++;
            }
        }
    }

    if (currentGrid[row][col] && liveNeighbors < 2) {
        // underpopulation
        return false;
    } else if (currentGrid[row][col] && (liveNeighbors == 2 || liveNeighbors == 3)) {
        // live on to next generation
        return true;
    } else if (currentGrid[row][col] && liveNeighbors > 3) {
        // overpopulation
        return false;
    } else if (!currentGrid[row][col] && liveNeighbors == 3) {
        // reproduction
        return true;
    }

    return false;
}

int main() {
    bool grid[ROWS][COLS] = { false };

    // initial grid setup
    grid[5][5] = true;
    grid[5][6] = true;
    grid[6][5] = true;
    grid[6][7] = true;
    grid[7][6] = true;

    while (true) {
        printGrid(grid);

        bool newGrid[ROWS][COLS] = { false };

        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                newGrid[i][j] = applyRules(grid, i, j);
            }
        }

        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                grid[i][j] = newGrid[i][j];
            }
        }

        usleep(100000);
    }
}