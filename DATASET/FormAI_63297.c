//FormAI DATASET v1.0 Category: Sudoku solver ; Style: shocked
#include <stdio.h>

// Define board size as a constant
#define size 9

// Function to print the board
void print_board(int board[size][size]) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

// Function to check if a value is safe in a cell
int is_safe(int board[size][size], int row, int col, int num) {
    // Check row and column
    for (int i = 0; i < size; i++) {
        if (board[row][i] == num || board[i][col] == num) {
            return 0;
        }
    }
    // Check sub-grid
    int sub_row = row - row % 3;
    int sub_col = col - col % 3;
    for (int i = sub_row; i < sub_row + 3; i++) {
        for (int j = sub_col; j < sub_col + 3; j++) {
            if (board[i][j] == num) {
                return 0;
            }
        }
    }
    return 1;
}

// Function to solve the Sudoku puzzle
int solve_sudoku(int board[size][size], int row, int col) {
    // Base case: all cells are filled
    if (row == size) {
        return 1;
    }
    // Move to next row if current row is filled
    if (col == size) {
        row++;
        col = 0;
    }
    // Skip already filled cells
    if (board[row][col] != 0) {
        return solve_sudoku(board, row, col+1);
    }
    // Try possible values in the cell
    for (int num = 1; num <= size; num++) {
        if (is_safe(board, row, col, num)) {
            board[row][col] = num;
            if (solve_sudoku(board, row, col+1)) {
                return 1;
            }
            board[row][col] = 0; // backtrack
        }
    }
    return 0;
}

int main() {
    int board[size][size] = {
        {0, 0, 5, 3, 0, 0, 0, 0, 0},
        {8, 0, 0, 0, 0, 0, 0, 2, 0},
        {0, 7, 0, 0, 1, 0, 5, 0, 0},
        {4, 0, 0, 0, 0, 5, 3, 0, 0},
        {0, 1, 0, 0, 7, 0, 0, 0, 6},
        {0, 0, 3, 2, 0, 0, 0, 8, 0},
        {0, 6, 0, 5, 0, 0, 0, 0, 9},
        {0, 0, 4, 0, 0, 0, 0, 3, 0},
        {0, 0, 0, 0, 0, 9, 7, 0, 0}
    };
    if (solve_sudoku(board, 0, 0)) {
        printf("Solved Sudoku: \n");
        print_board(board);
    } else {
        printf("No solution exists.\n");
    }
    return 0;
}