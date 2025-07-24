//FormAI DATASET v1.0 Category: Game of Life ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 30
#define COLUMNS 30
#define GENERATIONS 100

int grid[ROWS][COLUMNS];
int newGrid[ROWS][COLUMNS];

void initializeGrid() {
    srand(time(NULL));
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLUMNS; j++) {
            grid[i][j] = rand() % 2;
        }
    }
}

void copyGrid() {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLUMNS; j++) {
            newGrid[i][j] = grid[i][j];
        }
    }
}

void printGrid() {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLUMNS; j++) {
            printf("%c ", (grid[i][j]) ? '*' : ' ');
        }
        printf("\n");
    }
    printf("\n");
}

int countNeighbors(int row, int col) {
    int count = 0;
    int i, j;
    for (i = -1; i <= 1; i++) {
        for (j = -1; j <= 1; j++) {
            if (i == 0 && j == 0)
                continue;
            int nRow = row + i;
            int nCol = col + j;
            if (nRow >= ROWS || nRow < 0)
                continue;
            if (nCol >= COLUMNS || nCol < 0)
                continue;
            if (grid[nRow][nCol]) 
                count++;
        }
    }
    return count;
}

void nextGeneration() {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLUMNS; j++) {
            int neighbors = countNeighbors(i, j);
            if (grid[i][j]) {
                if (neighbors < 2 || neighbors > 3)
                    newGrid[i][j] = 0;
            } else {
                if (neighbors == 3)
                    newGrid[i][j] = 1;
            }
        }
    }
}

int main() {
    initializeGrid();
    int gen;
    for (gen = 0; gen < GENERATIONS; gen++) {
        printf("Generation #%d:\n", gen + 1);
        printGrid();
        copyGrid();
        nextGeneration();
    }
    return 0;
}