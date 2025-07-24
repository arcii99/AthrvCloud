//FormAI DATASET v1.0 Category: Sudoku solver ; Style: thoughtful
#include <stdio.h>
#include <stdbool.h>

#define N 9 // Size of Sudoku board

// Function to print the Sudoku board
void printSudoku(int board[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

// Function to check if a number can be placed in a particular cell
bool isValid(int board[N][N], int row, int col, int num) {
    // Check row
    for (int i = 0; i < N; i++) {
        if (board[row][i] == num) {
            return false;
        }
    }
    // Check column
    for (int i = 0; i < N; i++) {
        if (board[i][col] == num) {
            return false;
        }
    }
    // Check 3x3 sub-grid
    int x = (row / 3) * 3;
    int y = (col / 3) * 3;
    for (int i = x; i < x + 3; i++) {
        for (int j = y; j < y + 3; j++) {
            if (board[i][j] == num) {
                return false;
            }
        }
    }
    return true;
}

// Function to solve the Sudoku puzzle using backtracking
bool solveSudoku(int board[N][N], int row, int col) {
    // If we have reached the last cell, we have solved the puzzle
    if (row == N - 1 && col == N) {
        return true;
    }
    // If we have reached the end of a row, move to the next row
    if (col == N) {
        row++;
        col = 0;
    }
    // If the current cell is already filled, skip it
    if (board[row][col] != 0) {
        return solveSudoku(board, row, col + 1);
    }
    // Try all possible numbers in the current cell
    for (int num = 1; num <= N; num++) {
        if (isValid(board, row, col, num)) {
            board[row][col] = num; // Fill the current cell with the number
            if (solveSudoku(board, row, col + 1)) { // Recurse to the next cell
                return true;
            }
            board[row][col] = 0; // Backtrack
        }
    }
    return false; // No valid number found for the current cell
}

// Driver program
int main() {
    int board[N][N] = {
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
    printf("Sudoku board before solving:\n");
    printSudoku(board);
    printf("\n");
    if (solveSudoku(board, 0, 0)) {
        printf("Sudoku board after solving:\n");
        printSudoku(board);
    } else {
        printf("No solution found.");
    }
    return 0;
}