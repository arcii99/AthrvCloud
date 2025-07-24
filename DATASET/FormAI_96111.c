//FormAI DATASET v1.0 Category: Sudoku solver ; Style: invasive
#include <stdio.h>
#define N 9

int grid[N][N] = {
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
    for (int row = 0; row < N; row++) {
        for (int col = 0; col < N; col++) {
            printf("%d ", grid[row][col]);
        }
        printf("\n");
    }
}

int is_valid(int row, int col, int num) {
    // Check the row
    for (int i = 0; i < N; i++) {
        if (grid[row][i] == num) {
            return 0;
        }
    }

    // Check the column
    for (int i = 0; i < N; i++) {
        if (grid[i][col] == num) {
            return 0;
        }
    }

    // Check the box
    int box_row = row - row % 3;
    int box_col = col - col % 3;
    for (int i = box_row; i < box_row + 3; i++) {
        for (int j = box_col; j < box_col + 3; j++) {
            if (grid[i][j] == num) {
                return 0;
            }
        }
    }

    return 1;
}

int solve_sudoku(int row, int col) {
    // If all rows and columns have been covered, print the grid
    if (row == N && col == 0) {
        print_grid();
        return 1;
    }

    // If column has been fully covered, go to the next row
    if (col == N) {
        row++;
        col = 0;
    }

    // If the cell is already filled, go to the next cell
    if (grid[row][col] > 0) {
        return solve_sudoku(row, col + 1);
    }

    // Try all numbers from 1 to 9
    for (int num = 1; num <= N; num++) {
        if (is_valid(row, col, num)) {
            grid[row][col] = num;
            if (solve_sudoku(row, col + 1)) {
                return 1;
            }
            grid[row][col] = 0; // Backtrack
        }
    }

    return 0;
}

int main() {
    printf("Input Sudoku:\n");
    print_grid();
    printf("\nSolving Sudoku...\n\n");
    solve_sudoku(0, 0);
    return 0;
}