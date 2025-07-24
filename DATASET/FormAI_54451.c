//FormAI DATASET v1.0 Category: Game of Life ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GRID_SIZE 20
#define GENERATIONS 50

int grid[GRID_SIZE][GRID_SIZE];

void initializeGrid() {
    srand(time(NULL));

    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            grid[i][j] = rand() % 2;
        }
    }
}

void printGrid() {
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            if (grid[i][j] == 1) {
                printf("\u25A0 "); // Unicode for a black square
            } else {
                printf("\u25A1 "); // Unicode for a white square
            }
        }
        printf("\n");
    }
}

int countLiveNeighbours(int row, int col) {
    int count = 0;

    for (int i = row - 1; i <= row + 1; i++) {
        for (int j = col - 1; j <= col + 1; j++) {
            if (i < 0 || i >= GRID_SIZE || j < 0 || j >= GRID_SIZE || (i == row && j == col)) {
                continue;
            }
            if (grid[i][j] == 1) {
                count++;
            }
        }
    }

    return count;
}

void updateGrid() {
    int newGrid[GRID_SIZE][GRID_SIZE];

    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            int liveNeighbours = countLiveNeighbours(i, j);

            if (grid[i][j] == 1) {
                if (liveNeighbours < 2 || liveNeighbours > 3) {
                    newGrid[i][j] = 0;
                } else {
                    newGrid[i][j] = 1;
                }
            } else {
                if (liveNeighbours == 3) {
                    newGrid[i][j] = 1;
                } else {
                    newGrid[i][j] = 0;
                }
            }
        }
    }

    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            grid[i][j] = newGrid[i][j];
        }
    }
}

int main() {
    initializeGrid();

    for (int i = 0; i <= GENERATIONS; i++) {
        printGrid();
        printf("\nGeneration #%d\n\n", i);
        updateGrid();
    }

    return 0;
}