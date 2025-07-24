//FormAI DATASET v1.0 Category: Game of Life ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 20
#define COLS 20

int grid[ROWS][COLS] = {0};
int nextGen[ROWS][COLS] = {0};

void initGrid() {
    srand(time(NULL));
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            grid[i][j] = rand() % 2;
        }
    }
}

int getNeighbors(int row, int col) {
    int neighbors = 0;
    for (int i = row - 1; i <= row + 1; i++) {
        for (int j = col - 1; j <= col + 1; j++) {
            if (i == row && j == col) continue;
            if (i < 0 || i >= ROWS) continue;
            if (j < 0 || j >= COLS) continue;
            neighbors += grid[i][j];
        }
    }
    return neighbors;
}

void updateGrid() {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            int neighbors = getNeighbors(i, j);
            if (grid[i][j] == 1) {
                if (neighbors < 2 || neighbors > 3) {
                    nextGen[i][j] = 0;
                } else {
                    nextGen[i][j] = 1;
                }
            } else {
                if (neighbors == 3) {
                    nextGen[i][j] = 1;
                } else {
                    nextGen[i][j] = 0;
                }
            }
        }
    }
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            grid[i][j] = nextGen[i][j];
        }
    }
}

void printGrid() {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%c ", grid[i][j] == 1 ? 'X' : ' ');
        }
        printf("\n");
    }
}

int main() {
    initGrid();

    while (1) {
        system("clear");
        printGrid();
        updateGrid();
        usleep(100000);
    }

    return 0;
}