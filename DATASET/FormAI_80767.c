//FormAI DATASET v1.0 Category: Sudoku solver ; Style: minimalist
#include <stdio.h>
#include <stdbool.h>

bool is_possible(int grid[9][9], int row, int col, int num) {
    for (int i = 0; i < 9; i++) {
        if (grid[row][i] == num || grid[i][col] == num) {
            return false;
        }
    }

    int start_row = row - row % 3;
    int start_col = col - col % 3;
    for (int i = start_row; i < start_row + 3; i++) {
        for (int j = start_col; j < start_col + 3; j++) {
            if (grid[i][j] == num) {
                return false;
            }
        }
    }

    return true;
}

bool find_unassigned(int grid[9][9], int *row, int *col) {
    for (*row = 0; *row < 9; (*row)++) {
        for (*col = 0; *col < 9; (*col)++) {
            if (grid[*row][*col] == 0) {
                return true;
            }
        }
    }

    return false;
}

bool solve_sudoku(int grid[9][9]) {
    int row, col;
    if (!find_unassigned(grid, &row, &col)) {
        return true;
    }

    for (int num = 1; num <= 9; num++) {
        if (is_possible(grid, row, col, num)) {
            grid[row][col] = num;
            if (solve_sudoku(grid)) {
                return true;
            }
            grid[row][col] = 0;
        }
    }

    return false;
}

void print_grid(int grid[9][9]) {
    for (int row = 0; row < 9; row++) {
        for (int col = 0; col < 9; col++) {
            printf("%d ", grid[row][col]);
        }
        printf("\n");
    }
}

int main() {
    int grid[9][9] = {
        {3, 0, 6, 5, 0, 8, 4, 0, 0},
        {5, 2, 0, 0, 0, 0, 0, 0, 0},
        {0, 8, 7, 0, 0, 0, 0, 3, 1},
        {0, 0, 3, 0, 0, 0, 0, 2, 0},
        {9, 0, 0, 8, 0, 0, 0, 0, 5},
        {0, 5, 0, 0, 0, 0, 6, 0, 0},
        {1, 3, 0, 0, 0, 0, 2, 5, 0},
        {0, 0, 0, 0, 0, 0, 0, 7, 4},
        {0, 0, 5, 2, 0, 6, 3, 0, 0}
    };

    if (solve_sudoku(grid)) {
        print_grid(grid);
    } else {
        printf("Unable to solve Sudoku");
    }

    return 0;
}