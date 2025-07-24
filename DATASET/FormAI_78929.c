//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: introspective
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10
#define COLS 10

// Define a struct to hold cell information
typedef struct {
    bool open;
    bool connected;
} Cell;

// Initialize all cells as closed
void initCells(Cell cells[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            cells[i][j].open = false;
            cells[i][j].connected = false;
        }
    }
}

// Open a random cell in the top row
void openTopCell(Cell cells[ROWS][COLS]) {
    int col = rand() % COLS;
    cells[0][col].open = true;
}

// Connect open cells together
void connectCells(Cell cells[ROWS][COLS], int row, int col) {
    // Check neighboring cells to see if they are open
    if (row > 0 && cells[row-1][col].open) {
        cells[row][col].connected = true;
        cells[row-1][col].connected = true;
    }
    if (row < ROWS-1 && cells[row+1][col].open) {
        cells[row][col].connected = true;
        cells[row+1][col].connected = true;
    }
    if (col > 0 && cells[row][col-1].open) {
        cells[row][col].connected = true;
        cells[row][col-1].connected = true;
    }
    if (col < COLS-1 && cells[row][col+1].open) {
        cells[row][col].connected = true;
        cells[row][col+1].connected = true;
    }
}

// Check if bottom row has any connected cells
bool percolates(Cell cells[ROWS][COLS]) {
    for (int i = 0; i < COLS; i++) {
        if (cells[ROWS-1][i].connected) {
            return true;
        }
    }
    return false;
}

// Print the current state of the grid
void printGrid(Cell cells[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (cells[i][j].open) {
                printf(" ");
            } else {
                printf("X");
            }
        }
        printf("\n");
    }
}

int main() {
    // Set the random seed based on current time
    srand(time(NULL));

    Cell cells[ROWS][COLS];

    // Initialize all cells as closed
    initCells(cells);

    // Open a random cell in the top row
    openTopCell(cells);

    // Continuously open cells and connect them until the grid percolates
    while (!percolates(cells)) {
        // Choose a random open cell
        int row, col;
        do {
            row = rand() % ROWS;
            col = rand() % COLS;
        } while (!cells[row][col].open);

        // Open a neighboring closed cell
        if (row > 0 && !cells[row-1][col].open) {
            cells[row-1][col].open = true;
            connectCells(cells, row-1, col);
        } else if (row < ROWS-1 && !cells[row+1][col].open) {
            cells[row+1][col].open = true;
            connectCells(cells, row+1, col);
        } else if (col > 0 && !cells[row][col-1].open) {
            cells[row][col-1].open = true;
            connectCells(cells, row, col-1);
        } else if (col < COLS-1 && !cells[row][col+1].open) {
            cells[row][col+1].open = true;
            connectCells(cells, row, col+1);
        }
    }

    // Print the final state of the grid
    printGrid(cells);

    return 0;
}