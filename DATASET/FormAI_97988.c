//FormAI DATASET v1.0 Category: Sudoku solver ; Style: ultraprecise
#include <stdio.h>

// Define the size of the Sudoku board
#define SIZE 9

// Helper function to print the Sudoku board
void printBoard(int board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

// Helper function to check if a number can be placed in a certain cell
int isSafe(int board[SIZE][SIZE], int row, int col, int num) {
    // Check the row and column for the same number
    for (int i = 0; i < SIZE; i++) {
        if (board[row][i] == num || board[i][col] == num) {
            return 0;
        }
    }

    // Check the box for the same number
    int boxRow = row - row % 3;
    int boxCol = col - col % 3;
    for (int i = boxRow; i < boxRow + 3; i++) {
        for (int j = boxCol; j < boxCol + 3; j++) {
            if (board[i][j] == num) {
                return 0;
            }
        }
    }

    // If the number is safe to place, return 1
    return 1;
}

// Recursive function to solve the Sudoku board
int solveSudoku(int board[SIZE][SIZE], int row, int col) {
    // If we have reached the end of the board, return 1 to indicate success
    if (row == SIZE - 1 && col == SIZE) {
        return 1;
    }

    // If we have reached the end of a row, move to the next row and reset the column
    if (col == SIZE) {
        row++;
        col = 0;
    }

    // If the current cell is not empty, move to the next cell
    if (board[row][col] != 0) {
        return solveSudoku(board, row, col + 1);
    }

    // Try placing a number in the current cell
    for (int num = 1; num <= SIZE; num++) {
        // If the number is safe to place, place it and move to the next cell
        if (isSafe(board, row, col, num)) {
            board[row][col] = num;

            // Recursively solve the rest of the board
            if (solveSudoku(board, row, col + 1)) {
                return 1;
            }
        }

        // If the number cannot be placed, reset the cell and try the next number
        board[row][col] = 0;
    }

    // If no number can be placed, return 0 to indicate failure
    return 0;
}

int main() {
    int board[SIZE][SIZE] = {
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

    printf("Original board:\n");
    printBoard(board);

    if (solveSudoku(board, 0, 0)) {
        printf("Solved board:\n");
        printBoard(board);
    } else {
        printf("No solution exists.\n");
    }

    return 0;
}