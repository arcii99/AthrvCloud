//FormAI DATASET v1.0 Category: Sudoku solver ; Style: secure
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

bool findEmpty(int board[][SIZE], int * row, int * col) {
    for (*row = 0; *row < SIZE; (*row)++) {
        for (*col = 0; *col < SIZE; (*col)++) {
            if (board[*row][*col] == 0) {
                return true;
            }
        }
    }
    return false;
}

bool checkRow(int board[][SIZE], int row, int num) {
    for (int col = 0; col < SIZE; col++) {
        if (board[row][col] == num) {
            return false;
        }
    }
    return true;
}

bool checkCol(int board[][SIZE], int col, int num) {
    for (int row = 0; row < SIZE; row++) {
        if (board[row][col] == num) {
            return false;
        }
    }
    return true;
}

bool checkBox(int board[][SIZE], int rowStart, int colStart, int num) {
    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 3; col++) {
            if (board[row + rowStart][col + colStart] == num) {
                return false;
            }
        }
    }
    return true;
}

bool isValid(int board[][SIZE], int row, int col, int num) {
    return checkRow(board, row, num) &&
           checkCol(board, col, num) &&
           checkBox(board, row - row % 3, col - col % 3, num);
}

bool solveSudoku(int board[][SIZE]) {
    int row, col;
    if (!findEmpty(board, &row, &col)) {
        // The board is full
        return true;
    }

    for (int num = 1; num <= 9; num++) {
        if (isValid(board, row, col, num)) {
            // Place the number on the board
            board[row][col] = num;

            // Recurse to the next cell
            if (solveSudoku(board)) {
                return true;
            }

            // If we could not find a solution, backtrack
            board[row][col] = 0;
        }
    }

    return false;
}

int main() {
    int board[SIZE][SIZE] = { 
        {0, 0, 0, 0, 0, 0, 3, 0, 0},
        {7, 0, 0, 0, 0, 8, 0, 0, 0},
        {0, 0, 0, 3, 0, 0, 0, 9, 0},
        {0, 9, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 6, 0, 0, 0, 5, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 2, 0, 1, 0, 0, 0, 0},
        {0, 0, 4, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0}
    };

    printf("Original Board:\n");
    printBoard(board);
    printf("\n");
    
    if (solveSudoku(board)) {
        printf("Solved Board:\n");
        printBoard(board);
    } else {
        printf("Could not solve Sudoku\n");
    }
    
    return 0;
}