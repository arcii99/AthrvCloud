//FormAI DATASET v1.0 Category: Sudoku solver ; Style: multiplayer
#include <stdio.h>
#include <stdbool.h>

#define SIZE 9
#define SUBGRID_SIZE 3

// Function to print the Sudoku board
void printBoard(int board[][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

// Function to check if a number is a valid entry in a given cell
bool isValid(int board[][SIZE], int row, int col, int num) {
    // Check if the number appears in the same row
    for (int j = 0; j < SIZE; j++) {
        if (board[row][j] == num) {
            return false;
        }
    }

    // Check if the number appears in the same column
    for (int i = 0; i < SIZE; i++) {
        if (board[i][col] == num) {
            return false;
        }
    }

    // Check if the number appears in the same 3x3 subgrid
    int subRow = (row / SUBGRID_SIZE) * SUBGRID_SIZE;
    int subCol = (col / SUBGRID_SIZE) * SUBGRID_SIZE;
    for (int i = subRow; i < subRow + SUBGRID_SIZE; i++) {
        for (int j = subCol; j < subCol + SUBGRID_SIZE; j++) {
            if (board[i][j] == num) {
                return false;
            }
        }
    }

    // If the number passes all the checks, it is valid
    return true;
}

// Function to find the next empty cell on the Sudoku board
bool findEmpty(int board[][SIZE], int *row, int *col) {
    for (*row = 0; *row < SIZE; (*row)++) {
        for (*col = 0; *col < SIZE; (*col)++) {
            if (board[*row][*col] == 0) {
                return true;
            }
        }
    }
    return false;
}

// Function to solve the Sudoku board using backtracking
bool solveSudoku(int board[][SIZE]) {
    int row, col;

    // Find the next empty cell
    if (!findEmpty(board, &row, &col)) {
        return true; // If the board is full, it's already solved
    }

    // Try each number from 1 to 9 in the empty cell
    for (int num = 1; num <= SIZE; num++) {
        if (isValid(board, row, col, num)) {
            board[row][col] = num; // Tentatively fill the cell with the number

            // Recursively try to solve the Sudoku board
            if (solveSudoku(board)) {
                return true; // If a solution is found, return true
            }

            board[row][col] = 0; // If no solution found, backtrack and try the next number
        }
    }

    return false; // If no valid number works, the board is unsolvable
}

int main() {
    int board[SIZE][SIZE] = {{0, 3, 0, 0, 5, 0, 0, 4, 0},
                             {0, 0, 7, 3, 0, 0, 5, 0, 2},
                             {0, 0, 0, 0, 0, 7, 0, 0, 0},
                             {0, 0, 1, 5, 0, 0, 0, 0, 0},
                             {6, 0, 0, 0, 3, 0, 0, 0, 8},
                             {0, 0, 0, 0, 0, 9, 4, 0, 0},
                             {0, 0, 0, 2, 0, 0, 0, 0, 0},
                             {9, 0, 2, 0, 0, 1, 7, 0, 0},
                             {0, 8, 0, 0, 7, 0, 0, 1, 0}};

    // Solve the board
    if (solveSudoku(board)) {
        // Print the solution
        printf("Solution:\n");
        printBoard(board);
    } else {
        printf("No solution found.\n");
    }

    return 0;
}