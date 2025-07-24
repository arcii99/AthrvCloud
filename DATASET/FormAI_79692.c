//FormAI DATASET v1.0 Category: Sudoku solver ; Style: shocked
#include <stdio.h>

// Define board size
#define N 9

// Function to print the Sudoku board
void printBoard(int board[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

// Function to check if the number is safe to place
int isSafe(int board[N][N], int row, int col, int num) {
    // Check row
    for (int i = 0; i < N; i++) {
        if (board[row][i] == num) {
            return 0;
        }
    }

    // Check column
    for (int i = 0; i < N; i++) {
        if (board[i][col] == num) {
            return 0;
        }
    }

    // Check 3x3 subgrid
    int subgridRow = row - row % 3;
    int subgridCol = col - col % 3;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[subgridRow + i][subgridCol + j] == num) {
                return 0;
            }
        }
    }

    // Number is safe to place if all checks pass
    return 1;
}

// Recursive function to solve the Sudoku puzzle
int solveSudoku(int board[N][N], int row, int col) {
    // If we are at the last row and column, the Sudoku is solved
    if (row == N - 1 && col == N) {
        return 1;
    }

    // If we reach the end of a row, move to the next row
    if (col == N) {
        row++;
        col = 0;
    }

    // Check if the current position is already filled
    if (board[row][col] > 0) {
        return solveSudoku(board, row, col + 1);
    }

    // Try each possible number from 1 to 9
    for (int num = 1; num <= 9; num++) {
        // Check if the number is safe to place
        if (isSafe(board, row, col, num)) {
            // Place the number
            board[row][col] = num;

            // Recursive call to solve the next position
            if (solveSudoku(board, row, col + 1)) {
                return 1;
            }
        }

        // If the current number is not safe to place or the Sudoku cannot be solved with this number, backtrack, and try the next number
        board[row][col] = 0;
    }

    return 0;
}

int main() {
    // Define the initial Sudoku board
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

    printf("Initial Sudoku board:\n");
    printBoard(board);

    // Solve the Sudoku puzzle
    if (solveSudoku(board, 0, 0)) {
        printf("\nSolved Sudoku board:\n");
        printBoard(board);
    } else {
        printf("\nUnable to solve Sudoku board.\n");
    }

    return 0;
}