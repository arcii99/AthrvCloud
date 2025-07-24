//FormAI DATASET v1.0 Category: Game ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10
#define COLS 10

void printGrid(int grid[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (grid[i][j] == 0) {
                printf(" - ");
            } else {
                printf(" X ");
            }
        }
        printf("\n");
    }
}

void plantMines(int grid[ROWS][COLS], int numOfMines) {
    int numOfMinesPlanted = 0;
    while (numOfMinesPlanted < numOfMines) {
        int randomRow = rand() % ROWS;
        int randomCol = rand() % COLS;
        if (grid[randomRow][randomCol] == 0) {
            grid[randomRow][randomCol] = 1;
            numOfMinesPlanted++;
        }
    }
}

int main() {
    int grid[ROWS][COLS] = { 0 };
    int numOfMines = 10;
    srand(time(NULL)); // Seed the random number generator with system clock for truly random values
    plantMines(grid, numOfMines);
    printGrid(grid);
    return 0;
}