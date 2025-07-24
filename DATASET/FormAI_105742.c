//FormAI DATASET v1.0 Category: Sudoku solver ; Style: portable
#include <stdio.h>
#include <stdbool.h>

#define GRID_SIZE 9

bool is_valid(int grid[GRID_SIZE][GRID_SIZE], int row, int col, int num) {
    // check row
    for (int c = 0; c < GRID_SIZE; c++) {
        if (grid[row][c] == num) {
            return false;
        }
    }
    // check column
    for (int r = 0; r < GRID_SIZE; r++) {
        if (grid[r][col] == num) {
            return false;
        }
    }
    // check 3x3 box
    int box_row = row - row % 3;
    int box_col = col - col % 3;
    for (int r = 0; r < 3; r++) {
        for (int c = 0; c < 3; c++) {
            if (grid[box_row + r][box_col + c] == num) {
                return false;
            }
        }
    }
    return true;
}

bool find_unassigned_location(int grid[GRID_SIZE][GRID_SIZE], int* row, int* col) {
    for (*row = 0; *row < GRID_SIZE; (*row)++) {
        for (*col = 0; *col < GRID_SIZE; (*col)++) {
            if (grid[*row][*col] == 0) {
                return true;
            }
        }
    }
    return false;
}

bool solve_sudoku(int grid[GRID_SIZE][GRID_SIZE]) {
    int row, col;
    if (!find_unassigned_location(grid, &row, &col)) {
        return true;
    }
    for (int num = 1; num <= 9; num++) {
        if (is_valid(grid, row, col, num)) {
            grid[row][col] = num;
            if (solve_sudoku(grid)) {
                return true;
            }
            grid[row][col] = 0;
        }
    }
    return false;
}

void print_grid(int grid[GRID_SIZE][GRID_SIZE]) {
    printf("-------------------------\n");
    for (int i = 0; i < GRID_SIZE; i++) {
        printf("| ");
        for (int j = 0; j < GRID_SIZE; j++) {
            printf("%d ", grid[i][j]);
            if ((j + 1) % 3 == 0) {
                printf("| ");
            }
        }
        printf("\n");
        if ((i + 1) % 3 == 0) {
            printf("-------------------------\n");
        }
    }
}

int main() {
    int grid[GRID_SIZE][GRID_SIZE] = {
        {0, 0, 0, 8, 0, 0, 0, 0, 9},
        {0, 0, 0, 0, 0, 0, 7, 2, 0},
        {0, 1, 0, 0, 0, 3, 0, 0, 0},
        {0, 5, 0, 1, 0, 0, 0, 4, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 3, 0, 0, 0, 7, 0, 5, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 5},
        {0, 4, 3, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0}
    };
    printf("Input Grid:\n");
    print_grid(grid);
    if (solve_sudoku(grid)) {
        printf("Solution:\n");
        print_grid(grid);
    } else {
        printf("No solution exists!\n");
    }
    return 0;
}