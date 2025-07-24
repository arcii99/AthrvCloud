//FormAI DATASET v1.0 Category: Sudoku solver ; Style: ephemeral
#include <stdio.h>
#include <stdbool.h>

#define SIZE 9

void printBoard(int board[][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

bool rowContains(int board[][SIZE], int row, int num) {
    for (int i = 0; i < SIZE; i++) {
        if (board[row][i] == num) {
            return true;
        }
    }
    return false;
}

bool colContains(int board[][SIZE], int col, int num) {
    for (int i = 0; i < SIZE; i++) {
        if (board[i][col] == num) {
            return true;
        }
    }
    return false;
}

bool boxContains(int board[][SIZE], int boxStartRow, int boxStartCol, int num) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i + boxStartRow][j + boxStartCol] == num) {
                return true;
            }
        }
    }
    return false;
}

bool isSafe(int board[][SIZE], int row, int col, int num) {
    return !rowContains(board, row, num) &&
           !colContains(board, col, num) &&
           !boxContains(board, row - row % 3, col - col % 3, num);
}

bool findEmptySpot(int board[][SIZE], int *row, int *col) {
    for (*row = 0; *row < SIZE; (*row)++) {
        for (*col = 0; *col < SIZE; (*col)++) {
            if (board[*row][*col] == 0) {
                return true;
            }
        }
    }
    return false;
}

bool solveSudoku(int board[][SIZE]) {
    int row, col;
    if (!findEmptySpot(board, &row, &col)) {
        return true;
    }
    for (int num = 1; num <= 9; num++) {
        if (isSafe(board, row, col, num)) {
            board[row][col] = num;
            if (solveSudoku(board)) {
                return true;
            }
            board[row][col] = 0;
        }
    }
    return false;
}

int main() {
    // Board to solve
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

    // Print the unsolved board
    printf("Unsolved Sudoku Board:\n");
    printBoard(board);

    // Solve the Sudoku and print the solved board
    if (solveSudoku(board)) {
        printf("Solved Sudoku Board:\n");
        printBoard(board);
    } else {
        printf("No solution exists for this Sudoku Board\n");
    }

    return 0;
}