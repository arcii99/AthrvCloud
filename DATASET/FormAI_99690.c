//FormAI DATASET v1.0 Category: Sudoku solver ; Style: energetic
#include <stdio.h>
#define SIZE 9

// Function to print the Sudoku board
void printBoard(int board[][SIZE]) {
    for (int row = 0; row < 9; row++) {
        for (int col = 0; col < 9; col++) {
            printf("%d ", board[row][col]);
            if (col == 2 || col == 5)
                printf("| ");
        }
        printf("\n");
        if (row == 2 || row == 5)
            printf("---------------------\n");
    }
    printf("\n");
}

// Function to check if the number is safe in the given position
int isSafe(int board[][SIZE], int row, int col, int num) {
    for (int i = 0; i < 9; i++) {
        if (board[row][i] == num || board[i][col] == num)
            return 0;
    }

    int subRow = row - row % 3;
    int subCol = col - col % 3;

    for (int i = subRow; i < subRow + 3; i++) {
        for (int j = subCol; j < subCol + 3; j++) {
            if (board[i][j] == num)
                return 0;
        }
    }

    return 1;
}

// Function to solve the Sudoku board using backtracking algorithm
int solveSudoku(int board[][SIZE], int row, int col) {
    if (row == 9) {
        return 1;
    }

    if (col == 9) {
        return solveSudoku(board, row + 1, 0);
    }

    if (board[row][col] != 0) {
        return solveSudoku(board, row, col + 1);
    }

    for (int num = 1; num <= 9; num++) {
        if (isSafe(board, row, col, num)) {
            board[row][col] = num;

            if (solveSudoku(board, row, col + 1)) {
                return 1;
            }

            board[row][col] = 0;
        }
    }

    return 0;
}

int main() {
    int board[SIZE][SIZE] = {
        { 3, 0, 6, 5, 0, 8, 4, 0, 0 },
        { 5, 2, 0, 0, 0, 0, 0, 0, 0 },
        { 0, 8, 7, 0, 0, 0, 0, 3, 1 },
        { 0, 0, 3, 0, 0, 0, 0, 2, 0 },
        { 9, 0, 0, 8, 0, 0, 0, 0, 5 },
        { 0, 5, 0, 0, 0, 0, 6, 0, 0 },
        { 1, 3, 0, 0, 0, 0, 2, 5, 0 },
        { 0, 0, 0, 0, 0, 0, 0, 7, 4 },
        { 0, 0, 5, 2, 0, 6, 3, 0, 0 }
    };

    printBoard(board);
    printf("Solving the Sudoku puzzle...\n");
    if (solveSudoku(board, 0, 0)) {
        printf("Solution:\n");
        printBoard(board);
    } else {
        printf("No solution found\n");
    }

    return 0;
}