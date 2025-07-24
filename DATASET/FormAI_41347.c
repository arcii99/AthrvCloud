//FormAI DATASET v1.0 Category: Sudoku solver ; Style: rigorous
#include <stdio.h>
#include <stdbool.h>

#define SIZE 9

// Function to print the solved Sudoku board
void displayBoard(int board[][SIZE]) {
    printf("======= SUDOKU BOARD =======\n\n");

    for (int row = 0; row < SIZE; row++) {
        for (int col = 0; col < SIZE; col++) {
            printf("%d ", board[row][col]);
        }
        printf("\n");
    }

    printf("\n\n");
}

// Function to check if the number can be placed at the given cell
bool canPlace(int board[][SIZE], int row, int col, int num) {
    // Check whether the number already exists in the same row or column
    for (int i = 0; i < SIZE; i++) {
        if (board[row][i] == num || board[i][col] == num) {
            return false;
        }
    }

    // Check whether the number already exists in the same 3x3 subgrid
    int subgridRow = row - row % 3;
    int subgridCol = col - col % 3;

    for (int i = subgridRow; i < subgridRow + 3; i++) {
        for (int j = subgridCol; j < subgridCol + 3; j++) {
            if (board[i][j] == num) {
                return false;
            }
        }
    }

    // If the number is not found, then it can be placed at the given cell
    return true;
}

// Function to solve the Sudoku board
bool solveBoard(int board[][SIZE], int row, int col) {
    // If all the cells are checked, Sudoku is solved
    if (row == SIZE) {
        return true;
    }

    // If a column is completely checked, move to the next row
    if (col == SIZE) {
        return solveBoard(board, row + 1, 0);
    }

    // If the cell is already filled, move to the next cell
    if (board[row][col] != 0) {
        return solveBoard(board, row, col + 1);
    }

    // Try all the numbers from 1 to 9 at the current cell
    for (int num = 1; num <= 9; num++) {
        if (canPlace(board, row, col, num)) {
            // Check if the number can be placed at the current cell
            board[row][col] = num;

            // Move to the next cell
            if (solveBoard(board, row, col + 1)) {
                return true;
            }

            // Backtrack if the current placement is not correct
            board[row][col] = 0;
        }
    }

    // If no number from 1 to 9 can be placed at the current cell, Sudoku is unsolvable
    return false;
}

int main() {
    int sudokuBoard[SIZE][SIZE] = {
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

    // Display the unsolved Sudoku board
    printf("======= UNSOLVED SUDOKU BOARD =======\n\n");

    displayBoard(sudokuBoard);

    // Solve the Sudoku board
    if (solveBoard(sudokuBoard, 0, 0)) {
        // Display the solved Sudoku board
        printf("======= SOLVED SUDOKU BOARD =======\n\n");

        displayBoard(sudokuBoard);
    } else {
        printf("The Sudoku board cannot be solved.\n");
    }

    return 0;
}