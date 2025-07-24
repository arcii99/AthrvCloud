//FormAI DATASET v1.0 Category: Game ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ROWS 10
#define COLUMNS 10

int grid[ROWS][COLUMNS];

void initialize_grid() {
    for (int row = 0; row < ROWS; row++) {
        for (int col = 0; col < COLUMNS; col++) {
            grid[row][col] = 0;
        }
    }
}

bool is_cell_alive(int row, int col) {
    if (row < 0 || col < 0 || row >= ROWS || col >= COLUMNS) {
        return false;
    }
    return grid[row][col] == 1;
}

int count_live_neighbors(int row, int col) {
    int count = 0;
    for (int r = row - 1; r <= row + 1; r++) {
        for (int c = col - 1; c <= col + 1; c++) {
            if (r == row && c == col) {
                continue;
            }
            if (is_cell_alive(r, c)) {
                count++;
            }
        }
    }
    return count;
}

void update_grid() {
    int new_grid[ROWS][COLUMNS];
    for (int row = 0; row < ROWS; row++) {
        for (int col = 0; col < COLUMNS; col++) {
            int num_live_neighbors = count_live_neighbors(row, col);
            if (is_cell_alive(row, col)) {
                if (num_live_neighbors == 2 || num_live_neighbors == 3) {
                    new_grid[row][col] = 1;
                } else {
                    new_grid[row][col] = 0;
                }
            } else {
                if (num_live_neighbors == 3) {
                    new_grid[row][col] = 1;
                } else {
                    new_grid[row][col] = 0;
                }
            }
        }
    }
    // Copy new grid over to old grid
    for (int row = 0; row < ROWS; row++) {
        for (int col = 0; col < COLUMNS; col++) {
            grid[row][col] = new_grid[row][col];
        }
    }
}

void print_grid() {
    for (int row = 0; row < ROWS; row++) {
        for (int col = 0; col < COLUMNS; col++) {
            if (grid[row][col] == 1) {
                printf("1 ");
            } else {
                printf("0 ");
            }
        }
        printf("\n");
    }
}

int main() {
    initialize_grid();
    // Set up some initial live cells
    grid[4][5] = 1;
    grid[5][5] = 1;
    grid[6][5] = 1;
    grid[3][4] = 1;
    grid[4][6] = 1;

    for (int gen = 0; gen < 5; gen++) {
        printf("Generation %d:\n", gen);
        print_grid();
        update_grid();
    }

    return 0;
}