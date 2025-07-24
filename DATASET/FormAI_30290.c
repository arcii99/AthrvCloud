//FormAI DATASET v1.0 Category: Sudoku solver ; Style: futuristic
#include <stdio.h>
#include <stdbool.h>

// Define the dimensions of the Sudoku board
#define N 9

// Function to print the Sudoku board
void printBoard(int board[][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

// Function to check whether a number can be placed in a particular cell
bool canPlace(int board[][N], int row, int col, int num) {
    // Check if the number is already present in the same row
    for (int i = 0; i < N; i++) {
        if (board[row][i] == num) {
            return false;
        }
    }
    // Check if the number is already present in the same column
    for (int i = 0; i < N; i++) {
        if (board[i][col] == num) {
            return false;
        }
    }
    // Check if the number is already present in the same 3x3 subgrid
    int subgridRow = row - row % 3;
    int subgridCol = col - col % 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[subgridRow + i][subgridCol + j] == num) {
                return false;
            }
        }
    }
    return true;
}

// Function to solve the Sudoku board using backtracking
bool solveSudoku(int board[][N], int row, int col) {
    // Check if we have reached the end of the board
    if (row == N - 1 && col == N) {
        return true;
    }
    // Check if we have reached the end of the row
    if (col == N) {
        row++;
        col = 0;
    }
    // Check if the current cell already contains a number
    if (board[row][col] != 0) {
        return solveSudoku(board, row, col + 1);
    }
    // Try placing numbers in the current cell
    for (int num = 1; num <= N; num++) {
        if (canPlace(board, row, col, num)) {
            board[row][col] = num;
            if (solveSudoku(board, row, col + 1)) {
                return true;
            }
            board[row][col] = 0;
        }
    }
    return false;
}

int main() {
    // Define the Sudoku board
    int board[N][N] = {
        {0, 0, 0, 0, 0, 0, 6, 8, 0},
        {0, 0, 0, 0, 7, 3, 0, 0, 9},
        {3, 0, 9, 0, 0, 0, 0, 4, 5},
        {4, 9, 0, 0, 0, 0, 0, 0, 0},
        {8, 0, 3, 0, 5, 0, 9, 0, 2},
        {0, 0, 0, 0, 0, 0, 0, 3, 6},
        {9, 6, 0, 0, 0, 0, 3, 0, 8},
        {7, 0, 0, 6, 8, 0, 0, 0, 0},
        {0, 2, 8, 0, 0, 0, 0, 0, 0}
    };
    // Print the initial board
    printf("Initial Sudoku board:\n");
    printBoard(board);
    // Solve the Sudoku board
    if (solveSudoku(board, 0, 0)) {
        // Print the solution
        printf("Solved Sudoku board:\n");
        printBoard(board);
    }
    else {
        printf("No solution found.\n");
    }
    return 0;
}