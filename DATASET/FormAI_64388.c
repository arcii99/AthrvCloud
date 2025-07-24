//FormAI DATASET v1.0 Category: Game of Life ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 25
#define COLS 50
#define GENERATIONS 50

int grid[ROWS][COLS];
int grid_temp[ROWS][COLS];

/* Initialize the grid randomly */
void initializeGrid() {
    srand(time(NULL));
    for (int i=0; i<ROWS; i++) {
        for (int j=0; j<COLS; j++) {
            grid[i][j] = rand() % 2;
        }
    }
}

/* Print the current state of the grid */
void printGrid() {
    printf("\n");
    for (int i=0; i<ROWS; i++) {
        for (int j=0; j<COLS; j++) {
            if (grid[i][j] == 1) {
                printf("* ");
            } else {
                printf("- ");
            }
        }
        printf("\n");
    }
}

/* Get the number of neighbors for a given cell */
int getNeighbors(int i, int j) {
    int neighbors = 0;
    int row, col;
    for (int x=-1; x<=1; x++) {
        for (int y=-1; y<=1; y++) {
            row = (i + x + ROWS) % ROWS;
            col = (j + y + COLS) % COLS;
            if (grid[row][col] == 1) {
                neighbors++;
            }
        }
    }
    neighbors -= grid[i][j];
    return neighbors;
}

/* Update the grid according to the rules of the Game of Life */
void updateGrid() {
    int neighbors;
    for (int i=0; i<ROWS; i++) {
        for (int j=0; j<COLS; j++) {
            neighbors = getNeighbors(i, j);
            if (grid[i][j] == 1) {
                if (neighbors < 2 || neighbors > 3) {
                    grid_temp[i][j] = 0;
                } else {
                    grid_temp[i][j] = 1;
                }
            } else {
                if (neighbors == 3) {
                    grid_temp[i][j] = 1;
                } else {
                    grid_temp[i][j] = 0;
                }
            }
        }
    }
    for (int i=0; i<ROWS; i++) {
        for (int j=0; j<COLS; j++) {
            grid[i][j] = grid_temp[i][j];
        }
    }
}

int main() {
    initializeGrid();
    for (int gen=1; gen<=GENERATIONS; gen++) {
        printf("Generation %d:", gen);
        printGrid();
        updateGrid();
    }
    return 0;
}