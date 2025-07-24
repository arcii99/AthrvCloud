//FormAI DATASET v1.0 Category: Sudoku solver ; Style: careful
#include <stdio.h>

// Define the size of the Sudoku board
#define SIZE 9

// Function to check if a particular number is valid for a given position on the board
int is_valid(int board[SIZE][SIZE], int row, int col, int num) {
    // Check the row for conflicts
    for (int i = 0; i < SIZE; i++) {
        if (board[row][i] == num) {
            return 0;
        }
    }
    // Check the column for conflicts
    for (int i = 0; i < SIZE; i++) {
        if (board[i][col] == num) {
            return 0;
        }
    }
    // Check the 3x3 sub-grid for conflicts
    int sub_row = (row / 3) * 3;
    int sub_col = (col / 3) * 3;
    for (int i = sub_row; i < sub_row + 3; i++) {
        for (int j = sub_col; j < sub_col + 3; j++) {
            if (board[i][j] == num) {
                return 0;
            }
        }
    }
    // If there are no conflicts, the number is valid for the position
    return 1;
}

// Function to recursively solve the Sudoku board
int solve_board(int board[SIZE][SIZE], int row, int col) {
    // If we have reached the end of the board, the Sudoku is solved
    if (row == SIZE) {
        return 1;
    }
    // If we have reached the end of the row, move to the next row
    if (col == SIZE) {
        return solve_board(board, row + 1, 0);
    }
    // If the current position is already filled in, move to the next position
    if (board[row][col] != 0) {
        return solve_board(board, row, col + 1);
    }
    // Try numbers 1-9 in the current position and recursively solve the new board
    for (int num = 1; num <= 9; num++) {
        if (is_valid(board, row, col, num)) {
            board[row][col] = num;
            if (solve_board(board, row, col + 1)) {
                return 1;
            }
            board[row][col] = 0; // backtrack
        }
    }
    // If no number is valid for the current position, the Sudoku is unsolvable
    return 0;
}

// Function to print the Sudoku board to the screen
void print_board(int board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%2d ", board[i][j]);
        }
        printf("\n");
    }
}

int main() {
    // Define the Sudoku board
    int board[SIZE][SIZE] = {
        {0, 0, 0, 7, 0, 0, 0, 0, 9},
        {0, 0, 5, 0, 3, 0, 0, 0, 0},
        {0, 2, 0, 0, 0, 6, 0, 0, 0},
        {0, 0, 4, 0, 0, 0, 0, 2, 0},
        {5, 0, 0, 0, 0, 0, 7, 0, 0},
        {0, 0, 0, 4, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 2, 0, 0, 3},
        {0, 4, 0, 0, 0, 0, 5, 1, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 4}
    };
    // Print the unsolved Sudoku board
    printf("Unsolved Sudoku:\n");
    print_board(board);
    // Solve the Sudoku board
    if (solve_board(board, 0, 0)) {
        // Print the solved Sudoku board
        printf("\nSolved Sudoku:\n");
        print_board(board);
    } else {
        printf("\nUnsolvable Sudoku!\n");
    }
    return 0;
}