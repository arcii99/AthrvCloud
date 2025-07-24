//FormAI DATASET v1.0 Category: Game of Life ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 20
#define COLS 40

int gen = 0; // number of generations

// function to display the grid
void displayGrid(int grid[][COLS]) {
    printf("Generation: %d\n\n", gen);
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (grid[i][j] == 1) printf("*");
            else printf(" ");
        }
        printf("\n");
    }
    printf("\n");
}

// function to count live neighbours for a cell
int countLiveNeighbours(int grid[][COLS], int row, int col) {
    int count = 0;
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            int r = (row+i+ROWS) % ROWS;
            int c = (col+j+COLS) % COLS;
            if (grid[r][c] == 1 && !(i == 0 && j == 0)) count++;
        }
    }
    return count;
}

// function to update the grid
void updateGrid(int grid[][COLS]) {
    int newGrid[ROWS][COLS] = {0};
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            int neighbours = countLiveNeighbours(grid, i, j);
            if (grid[i][j] == 1) {
                if (neighbours < 2 || neighbours > 3) newGrid[i][j] = 0;
                else newGrid[i][j] = 1;
            }
            else {
                if (neighbours == 3) newGrid[i][j] = 1;
            }
        }
    }
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            grid[i][j] = newGrid[i][j];
        }
    }
    gen++;
}

// function to randomly populate the grid
void randomPopulate(int grid[][COLS]) {
    srand(time(NULL));
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            grid[i][j] = rand() % 2;
        }
    }
}

int main() {
    int grid[ROWS][COLS] = {0};
    randomPopulate(grid);
    displayGrid(grid);
    while (gen < 100) {
        updateGrid(grid);
        displayGrid(grid);
    }
    return 0;
}