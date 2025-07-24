//FormAI DATASET v1.0 Category: Sudoku solver ; Style: decentralized
#include <stdio.h>
#include <string.h>

#define SIZE 9

// Function to print the Sudoku board
void printBoard(int sudokuBoard[SIZE][SIZE]) {
    printf("-------------------------\n");
    for (int row = 0; row < SIZE; row++) {
        for (int col = 0; col < SIZE; col++) {
            printf("%d ", sudokuBoard[row][col]);
            if ((col + 1) % 3 == 0) {
                printf("| ");
            }
        }
        printf("\n");
        if ((row + 1) % 3 == 0) {
            printf("-------------------------\n");
        }
    }
}

// Function to check if a number can be placed in a given cell
int isCellSafe(int sudokuBoard[SIZE][SIZE], int row, int col, int num) {
    // Check if number exists in row or column
    for (int i = 0; i < SIZE; i++) {
        if (sudokuBoard[row][i] == num || sudokuBoard[i][col] == num) {
            return 0;
        }
    }

    // Check if number exists in 3x3 box
    int boxRow = (row / 3) * 3;
    int boxCol = (col / 3) * 3;
    for (int i = boxRow; i < boxRow + 3; i++) {
        for (int j = boxCol; j < boxCol + 3; j++) {
            if (sudokuBoard[i][j] == num) {
                return 0;
            }
        }
    }

    // If none of the checks fail, number can be placed
    return 1;
}

// Function to solve the Sudoku puzzle
int solveSudoku(int sudokuBoard[SIZE][SIZE], int row, int col) {
    // Check if we have reached the end of the board
    if (row == SIZE) {
        return 1;
    }

    // Move to the next column if we have filled up the current column
    if (col == SIZE) {
        return solveSudoku(sudokuBoard, row+1, 0);
    }

    // Check if the current cell is already filled
    if (sudokuBoard[row][col] != 0) {
        return solveSudoku(sudokuBoard, row, col+1);
    }

    // Check all possible numbers for current cell
    for (int num = 1; num <= SIZE; num++) {
        if (isCellSafe(sudokuBoard, row, col, num)) {
            sudokuBoard[row][col] = num;
            if (solveSudoku(sudokuBoard, row, col+1)) {
                return 1;
            }
            sudokuBoard[row][col] = 0;
        }
    }

    // If no number can be placed, backtrack
    return 0;
}

int main() {
    // Initialize the Sudoku board
    int sudokuBoard[SIZE][SIZE] = {{3, 0, 6, 5, 0, 8, 4, 0, 0},
                                   {5, 2, 0, 0, 0, 0, 0, 0, 0},
                                   {0, 8, 7, 0, 0, 0, 0, 3, 1},
                                   {0, 0, 3, 0, 0, 0, 0, 2, 0},
                                   {9, 0, 0, 8, 0, 0, 0, 0, 5},
                                   {0, 5, 0, 0, 0, 0, 6, 0, 0},
                                   {1, 3, 0, 0, 0, 0, 2, 5, 0},
                                   {0, 0, 0, 0, 0, 0, 0, 7, 4},
                                   {0, 0, 5, 2, 0, 6, 3, 0, 0}};

    // Print the unsolved Sudoku board
    printf("Sudoku Board:\n");
    printBoard(sudokuBoard);
    
    // Solve the Sudoku puzzle
    if (solveSudoku(sudokuBoard, 0, 0)) {
        // Print the solved Sudoku board
        printf("Solved Sudoku Board:\n");
        printBoard(sudokuBoard);
    } else {
        printf("No solution exists for the given Sudoku board.\n");
    }

    return 0;
}