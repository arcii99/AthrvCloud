//FormAI DATASET v1.0 Category: Sudoku solver ; Style: future-proof
#include <stdio.h>
#include <stdbool.h>

#define N 9

int grid[N][N] = {  // Example Sudoku puzzle
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

bool search_empty_location(int *row, int *col) {
    for (*row = 0; *row < N; (*row)++) {
        for (*col = 0; *col < N; (*col)++) {
            if (grid[*row][*col] == 0) {
                return true;
            }
        }
    }
    return false;
}

bool is_safe(int row, int col, int num) {
    // Check the row
    for (int c = 0; c < N; ++c) {
        if (grid[row][c] == num) {
            return false;
        }
    }
    // Check the column
    for (int r = 0; r < N; ++r) {
        if (grid[r][col] == num) {
            return false;
        }
    }
    // Check the 3x3 box
    int box_row = row - row % 3;
    int box_col = col - col % 3;
    for (int r = box_row; r < box_row + 3; ++r) {
        for (int c = box_col; c < box_col + 3; ++c) {
            if (grid[r][c] == num) {
                return false;
            }
        }
    }
    return true;
}

void print_grid() {
    for (int r = 0; r < N; ++r) {
        for (int c = 0; c < N; ++c) {
            printf("%d ", grid[r][c]);
        }
        printf("\n");
    }
}

bool solve_sudoku() {
    int row, col;
    if (!search_empty_location(&row, &col)) {
        return true;  // Puzzle solved
    }
    // Try values 1 to 9 in empty location
    for (int num = 1; num <= 9; ++num) {
        if (is_safe(row, col, num)) {
            grid[row][col] = num;
            if (solve_sudoku()) {
                return true; // Stop searching if a solution found 
            }
            grid[row][col] = 0; // Backtrack: unassign last assigned value
        }
    }
    return false;  // No solution found for the current configuration
}

int main() {
    if (solve_sudoku()) {
        print_grid();
    } else {
        printf("No solution exists for this Sudoku puzzle.\n");
    }
    return 0;
}