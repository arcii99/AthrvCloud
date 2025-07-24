//FormAI DATASET v1.0 Category: Sudoku solver ; Style: high level of detail
#include <stdio.h>
#include <stdbool.h>

#define GRID_SIZE 9

void print_grid(int grid[][GRID_SIZE]) {
    // Print the Sudoku grid
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
}

bool find_empty_spot(int grid[][GRID_SIZE], int *row, int *col) {
    // Find the next empty spot in the grid
    for (*row = 0; *row < GRID_SIZE; (*row)++) {
        for (*col = 0; *col < GRID_SIZE; (*col)++) {
            if (grid[*row][*col] == 0) {
                return true;
            }
        }
    }
    return false;
}

bool is_valid(int grid[][GRID_SIZE], int row, int col, int num) {
    // Check if the given number is valid at the given position
    for (int i = 0; i < GRID_SIZE; i++) {
        if (grid[row][i] == num || grid[i][col] == num) {
            return false;
        }
    }

    int row_start = (row / 3) * 3;
    int col_start = (col / 3) * 3;

    for (int i = row_start; i < row_start + 3; i++) {
        for (int j = col_start; j < col_start + 3; j++) {
            if (grid[i][j] == num) {
                return false;
            }
        }
    }

    return true;
}

bool solve_sudoku(int grid[][GRID_SIZE]) {
    // Recursive function to solve the Sudoku puzzle
    int row, col;

    if (!find_empty_spot(grid, &row, &col)) {
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

int main() {
    int grid[GRID_SIZE][GRID_SIZE] = {
        {0, 0, 0, 0, 0, 3, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 1, 0, 5},
        {8, 0, 0, 0, 0, 1, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 9, 0},
        {0, 0, 0, 4, 0, 0, 0, 1, 6},
        {0, 3, 0, 0, 5, 0, 0, 0, 0},
        {0, 0, 4, 0, 0, 0, 0, 0, 0},
        {1, 0, 0, 6, 0, 0, 5, 0, 0},
        {0, 0, 0, 8, 7, 0, 0, 0, 3}
    };

    printf("Sudoku puzzle:\n");
    print_grid(grid);

    if (solve_sudoku(grid)) {
        printf("Solution:\n");
        print_grid(grid);
    } else {
        printf("No solution found.\n");
    }

    return 0;
}