//FormAI DATASET v1.0 Category: Sudoku solver ; Style: multiplayer
#include <stdio.h>
#define GRID_SIZE 9

int grid[GRID_SIZE][GRID_SIZE] = {
    {5, 3, 0, 0, 7, 0, 0, 0, 0},
    {6, 0, 0, 1, 9, 5, 0, 0, 0},
    {0, 9, 8, 0, 0, 0, 0, 6, 0},
    {8, 0, 0, 0, 6, 0, 0, 0, 3},
    {4, 0, 0, 8, 0, 3, 0, 0, 1},
    {7, 0, 0, 0, 2, 0, 0, 0, 6},
    {0, 6, 0, 0, 0, 0, 2, 8, 0},
    {0, 0, 0, 4, 1, 9, 0, 0, 5},
    {0, 0, 0, 0, 8, 0, 0, 7, 9}
};

void print_grid() {
    int row, col;
    for (row = 0; row < GRID_SIZE; row++) {
        for (col = 0; col < GRID_SIZE; col++) {
            printf("%d ", grid[row][col]);
        }
        printf("\n");
    }
}

int is_valid(int row, int col, int num) {
    // Check if num is unique in row
    for (int i = 0; i < GRID_SIZE; i++) {
        if (grid[row][i] == num) {
            return 0;
        }
    }
    // Check if num is unique in column
    for (int i = 0; i < GRID_SIZE; i++) {
        if (grid[i][col] == num) {
            return 0;
        }
    }
    // Check if num is unique in 3x3 square
    int square_row = (row / 3) * 3;
    int square_col = (col / 3) * 3;
    for (int i = square_row; i < square_row + 3; i++) {
        for (int j = square_col; j < square_col + 3; j++) {
            if (grid[i][j] == num) {
                return 0;
            }
        }
    }
    return 1; // num is valid
}

int is_grid_full() {
    int row, col;
    for (row = 0; row < GRID_SIZE; row++) {
        for (col = 0; col < GRID_SIZE; col++) {
            if (grid[row][col] == 0) {
                return 0; // grid is not full
            }
        }
    }
    return 1; // grid is full
}

int solve(int row, int col) {
    if (is_grid_full()) {
        return 1;
    }
    if (grid[row][col] != 0) {
        if (col == GRID_SIZE - 1) {
            if (solve(row + 1, 0)) {
                return 1;
            }
        } else {
            if (solve(row, col + 1)) {
                return 1;
            }
        }
    } else {
        for (int num = 1; num <= GRID_SIZE; num++) {
            if (is_valid(row, col, num)) {
                grid[row][col] = num;
                if (col == GRID_SIZE - 1) {
                    if (solve(row + 1, 0)) {
                        return 1;
                    }
                } else {
                    if (solve(row, col + 1)) {
                        return 1;
                    }
                }
                grid[row][col] = 0;
            }
        }
    }
    return 0; // no solution found
}

int main() {
    printf("Initial Sudoku grid:\n");
    print_grid();

    if (solve(0, 0)) {
        printf("\nSolved Sudoku grid:\n");
        print_grid();
    } else {
        printf("\nNo solution found\n");
    }

    return 0;
}