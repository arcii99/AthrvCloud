//FormAI DATASET v1.0 Category: Sudoku solver ; Style: immersive
#include <stdio.h>

// Size of the Sudoku grid
#define N 9

// Helper function to check whether a value can be placed in a cell
int is_valid(int board[N][N], int row, int col, int num) {
    // Check row
    for (int c = 0; c < N; c++) {
        if (board[row][c] == num) {
            return 0;
        }
    }
    // Check column
    for (int r = 0; r < N; r++) {
        if (board[r][col] == num) {
            return 0;
        }
    }
    // Check 3x3 square
    int sqr_row = row - row % 3;
    int sqr_col = col - col % 3;
    for (int r = sqr_row; r < sqr_row + 3; r++) {
        for (int c = sqr_col; c < sqr_col + 3; c++) {
            if (board[r][c] == num) {
                return 0;
            }
        }
    }
    return 1;
}

// Helper function to print the Sudoku grid
void print_board(int board[N][N]) {
    for (int r = 0; r < N; r++) {
        for (int c = 0; c < N; c++) {
            printf("%d ", board[r][c]);
        }
        printf("\n");
    }
}

// Main recursive function to solve the Sudoku grid
int solve_board(int board[N][N], int row, int col) {
    // Check if we reached the end of the grid
    if (row == N) {
        return 1;
    }
    // Check if we reached the end of the row
    if (col == N) {
        return solve_board(board, row + 1, 0);
    }
    // Check if the cell is already filled
    if (board[row][col] != 0) {
        return solve_board(board, row, col + 1);
    }
    // Try filling the cell with different numbers
    for (int num = 1; num <= 9; num++) {
        if (is_valid(board, row, col, num)) {
            board[row][col] = num;
            if (solve_board(board, row, col + 1)) {
                return 1;
            }
            board[row][col] = 0;
        }
    }
    return 0; // Backtrack
}

// Example usage
int main() {
    int board[N][N] = {
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
    if (solve_board(board, 0, 0)) {
        printf("Solution:\n");
        print_board(board);
    } else {
        printf("No solution.\n");
    }
    return 0;
}