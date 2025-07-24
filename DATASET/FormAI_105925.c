//FormAI DATASET v1.0 Category: Sudoku solver ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define SIZE 9
#define BLOCK_SIZE 3

bool is_valid(int grid[SIZE][SIZE], int row, int col, int num) {
    int box_row = row - row % BLOCK_SIZE;
    int box_col = col - col % BLOCK_SIZE;

    for (int i = 0; i < SIZE; i++) {
        if (grid[row][i] == num || grid[i][col] == num) {
            return false;
        }
    }

    for (int i = box_row; i < box_row + BLOCK_SIZE; i++) {
        for (int j = box_col; j < box_col + BLOCK_SIZE; j++) {
            if (grid[i][j] == num) {
                return false;
            }
        }
    }

    return true;
}

bool sudoku_solver(int grid[SIZE][SIZE], int row, int col) {
    if (col == SIZE) {
        col = 0;
        row++;

        if (row == SIZE) {
            return true;
        }
    }

    if (grid[row][col] != 0) {
        return sudoku_solver(grid, row, col + 1);
    }

    for (int i = 1; i <= SIZE; i++) {
        if (is_valid(grid, row, col, i)) {
            grid[row][col] = i;

            if (sudoku_solver(grid, row, col + 1)) {
                return true;
            }

            grid[row][col] = 0;
        }
    }

    return false;
}

void print_grid(int grid[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int grid[SIZE][SIZE] = { 
        {0, 0, 0, 5, 0, 9, 7, 2, 0},
        {0, 7, 0, 0, 0, 0, 0, 8, 0},
        {5, 0, 8, 0, 0, 6, 0, 0, 4},
        {1, 4, 0, 0, 5, 0, 8, 0, 0},
        {0, 0, 0, 2, 0, 8, 0, 0, 0},
        {0, 0, 2, 0, 4, 0, 0, 3, 5},
        {9, 0, 0, 7, 0, 0, 3, 0, 1},
        {0, 2, 0, 0, 0, 0, 0, 7, 0},
        {0, 6, 7, 3, 0, 4, 0, 0, 0}
    };

    if (sudoku_solver(grid, 0, 0)) {
        printf("Solution:\n");
        print_grid(grid);
    } else {
        printf("No solution found.\n");
    }

    return 0;
}