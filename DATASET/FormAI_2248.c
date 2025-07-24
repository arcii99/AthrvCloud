//FormAI DATASET v1.0 Category: Sudoku solver ; Style: calm
#include <stdio.h>
#include <stdbool.h>

#define SIZE 9

bool find_unassigned(int grid[SIZE][SIZE], int* row, int* col) {
    for (*row = 0; *row < SIZE; (*row)++) {
        for (*col = 0; *col < SIZE; (*col)++) {
            if (grid[*row][*col] == 0) {
                return true;
            }
        }
    }
    return false;
}

bool used_in_row(int grid[SIZE][SIZE], int row, int num) {
    for (int col = 0; col < SIZE; col++) {
        if (grid[row][col] == num) {
            return true;
        }
    }
    return false;
}

bool used_in_col(int grid[SIZE][SIZE], int col, int num) {
    for (int row = 0; row < SIZE; row++) {
        if (grid[row][col] == num) {
            return true;
        }
    }
    return false;
}

bool used_in_box(int grid[SIZE][SIZE], int box_start_row, int box_start_col, int num) {
    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 3; col++) {
            if (grid[row + box_start_row][col + box_start_col] == num) {
                return true;
            }
        }
    }
    return false;
}

bool is_valid_num(int grid[SIZE][SIZE], int row, int col, int num) {
    return !used_in_row(grid, row, num) &&
           !used_in_col(grid, col, num) &&
           !used_in_box(grid, row - row % 3, col - col % 3, num);
}

bool solve_sudoku(int grid[SIZE][SIZE]) {
    int row, col;

    if (!find_unassigned(grid, &row, &col)) {
        return true;
    }

    for (int num = 1; num <= 9; num++) {
        if (is_valid_num(grid, row, col, num)) {
            grid[row][col] = num;
            if (solve_sudoku(grid)) {
                return true;
            }
            grid[row][col] = 0;
        }
    }

    return false;
}

void print_grid(int grid[SIZE][SIZE]) {
    printf("\n");
    for (int row = 0; row < SIZE; row++) {
        for (int col = 0; col < SIZE; col++) {
            printf("%d ", grid[row][col]);
            if ((col + 1) % 3 == 0 && col != 8) {
                printf("| ");
            }
        }
        printf("\n");
        if ((row + 1) % 3 == 0 && row != 8) {
            printf("-------------------\n");
        }
    }
    printf("\n");
}

int main() {
    int grid[SIZE][SIZE] = {
        {8, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 3, 6, 0, 0, 0, 0, 0},
        {0, 7, 0, 0, 9, 0, 2, 0, 0},
        {0, 5, 0, 0, 0, 7, 0, 0, 0},
        {0, 0, 0, 0, 4, 5, 7, 0, 0},
        {0, 0, 0, 1, 0, 0, 0, 3, 0},
        {0, 0, 1, 0, 0, 0, 0, 6, 8},
        {0, 0, 8, 5, 0, 0, 0, 1, 0},
        {0, 9, 0, 0, 0, 0, 4, 0, 0}
    };

    printf("Given Sudoku Puzzle:\n");
    print_grid(grid);

    if (solve_sudoku(grid)) {
        printf("Solution:\n");
        print_grid(grid);
    } else {
        printf("No solution exists.");
    }

    return 0;
}