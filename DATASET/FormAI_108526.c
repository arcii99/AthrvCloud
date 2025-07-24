//FormAI DATASET v1.0 Category: Sudoku solver ; Style: multiplayer
#include <stdio.h>

// The board size
#define N 9

// Check if the given row, column and box contain the given number
int isSafe(int board[N][N], int row, int col, int num) {
    int i, j;

    // Check for a number in the row
    for (i = 0; i < N; i++) {
        if (board[row][i] == num) {
            return 0;
        }
    }

    // Check for a number in the column
    for (i = 0; i < N; i++) {
        if (board[i][col] == num) {
            return 0;
        }
    }

    // Check for a number in the box
    int r = row - row % 3;
    int c = col - col % 3;
    for (i = r; i < r + 3; i++) {
        for (j = c; j < c + 3; j++) {
            if (board[i][j] == num) {
                return 0;
            }
        }
    }

    // If the number is not present in the
    // row, column and box, then it is a safe move
    return 1;
}

// Solve the Sudoku using the backtracking algorithm
int solveSudoku(int board[N][N], int row, int col) {
    // If we have reached the end of the Sudoku board,
    // then it is solved
    if (row == N - 1 && col == N) {
        return 1;
    }

    // If we have reached the end of the current row,
    // then move to the next row
    if (col == N) {
        row++;
        col = 0;
    }

    // If the current cell already has a number, then
    // move to the next cell
    if (board[row][col] > 0) {
        return solveSudoku(board, row, col + 1);
    }

    // Try all possible numbers for the current cell
    int num;
    for (num = 1; num <= N; num++) {
        if (isSafe(board, row, col, num)) {
            board[row][col] = num;
            if (solveSudoku(board, row, col + 1)) {
                return 1;
            }
        }
        // If the number doesn't work, then backtrack
        board[row][col] = 0;
    }

    // If no number works, then the Sudoku is unsolvable
    return 0;
}

int main() {
    int board[N][N] = { { 3, 0, 6, 5, 0, 8, 4, 0, 0 },
                        { 5, 2, 0, 0, 0, 0, 0, 0, 0 },
                        { 0, 8, 7, 0, 0, 0, 0, 3, 1 },
                        { 0, 0, 3, 0, 0, 0, 0, 2, 0 },
                        { 9, 0, 0, 8, 0, 0, 0, 0, 5 },
                        { 0, 5, 0, 0, 0, 0, 6, 0, 0 },
                        { 1, 3, 0, 0, 0, 0, 2, 5, 0 },
                        { 0, 0, 0, 0, 0, 0, 0, 7, 4 },
                        { 0, 0, 5, 2, 0, 6, 3, 0, 0 } };
    int i, j;

    if (solveSudoku(board, 0, 0)) {
        for (i = 0; i < N; i++) {
            for (j = 0; j < N; j++) {
                printf("%d ", board[i][j]);
            }
            printf("\n");
        }
    } else {
        printf("Sudoku is unsolvable");
    }
    return 0;
}