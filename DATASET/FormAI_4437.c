//FormAI DATASET v1.0 Category: Game of Life ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 20
#define COLS 40
#define GENERATIONS 50

void printGrid(int grid[ROWS][COLS]) {
    system("clear"); // clears the console
    for (int row = 0; row < ROWS; row++) {
        for (int col = 0; col < COLS; col++) {
            printf("%c", (grid[row][col]) ? '#' : ' '); // prints the grid
        }
        printf("\n");
    }
}

int countNeighbours(int row, int col, int grid[ROWS][COLS]) {
    int count = 0;
    for (int r = row - 1; r <= row + 1; r++) {
        for (int c = col - 1; c <= col + 1; c++) {
            if (r == row && c == col) {
                continue;
            }
            count += grid[(r + ROWS) % ROWS][(c + COLS) % COLS];
        }
    }
    return count;
}

void generateNextGeneration(int grid[ROWS][COLS]) {
    int nextGeneration[ROWS][COLS];
    for (int row = 0; row < ROWS; row++) {
        for (int col = 0; col < COLS; col++) {
            int neighbours = countNeighbours(row, col, grid);
            nextGeneration[row][col] = grid[row][col];
            if (neighbours < 2 || neighbours > 3) {
                nextGeneration[row][col] = 0;
            } else if (neighbours == 3) {
                nextGeneration[row][col] = 1;
            }
        }
    }
    for (int row = 0; row < ROWS; row++) {
        for (int col = 0; col < COLS; col++) {
            grid[row][col] = nextGeneration[row][col];
        }
    }
}

int main() {
    srand(time(0));
    int grid[ROWS][COLS] = {0};
    for (int row = 0; row < ROWS; row++) {
        for (int col = 0; col < COLS; col++) {
            grid[row][col] = (rand() % 2 == 0) ? 1 : 0; // randomly initializes the grid
        }
    }
    for (int i = 0; i < GENERATIONS; i++) {
        printGrid(grid); // prints the current grid
        generateNextGeneration(grid); // generates the next generation
    }
    return 0;
}