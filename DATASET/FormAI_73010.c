//FormAI DATASET v1.0 Category: Sudoku solver ; Style: inquisitive
#include <stdio.h>

// Define the size of the Sudoku board (9x9)
#define SIZE 9

// Function to print the Sudoku board
void printBoard(int board[SIZE][SIZE]) {
    for (int row = 0; row < SIZE; row++) {
        for (int col = 0; col < SIZE; col++) {
            printf("%d ", board[row][col]);
        }
        printf("\n");
    }
}

// Function to check if a number is already present in a row
int inRow(int board[SIZE][SIZE], int row, int num) {
    for (int col = 0; col < SIZE; col++) {
        if (board[row][col] == num) {
            return 1;
        }
    }
    return 0;
}

// Function to check if a number is already present in a column
int inCol(int board[SIZE][SIZE], int col, int num) {
    for (int row = 0; row < SIZE; row++) {
        if (board[row][col] == num) {
            return 1;
        }
    }
    return 0;
}

// Function to check if a number is already present in a box
int inBox(int board[SIZE][SIZE], int startRow, int startCol, int num) {
    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 3; col++) {
            if (board[row+startRow][col+startCol] == num) {
                return 1;
            }
        }
    }
    return 0;
}

// Function to check if a number is valid at a particular cell
int isValid(int board[SIZE][SIZE], int row, int col, int num) {
    return !inRow(board, row, num) &&
           !inCol(board, col, num) &&
           !inBox(board, row - row%3, col - col%3, num);
}

// Function to solve the Sudoku board
int solveSudoku(int board[SIZE][SIZE], int row, int col) {
    if (row == SIZE) {
        return 1;
    }
    if (col == SIZE) {
        return solveSudoku(board, row+1, 0);
    }
    if (board[row][col] != 0) {
        return solveSudoku(board, row, col+1);
    }
    for (int num = 1; num <= 9; num++) {
        if (isValid(board, row, col, num)) {
            board[row][col] = num;
            if (solveSudoku(board, row, col+1)) {
                return 1;
            }
            board[row][col] = 0;
        }
    }
    return 0;
}

int main() {
    // Define the Sudoku board (0 denotes empty cells)
    int board[SIZE][SIZE] = {{5, 3, 0, 0, 7, 0, 0, 0, 0},
                             {6, 0, 0, 1, 9, 5, 0, 0, 0},
                             {0, 9, 8, 0, 0, 0, 0, 6, 0},
                             {8, 0, 0, 0, 6, 0, 0, 0, 3},
                             {4, 0, 0, 8, 0, 3, 0, 0, 1},
                             {7, 0, 0, 0, 2, 0, 0, 0, 6},
                             {0, 6, 0, 0, 0, 0, 2, 8, 0},
                             {0, 0, 0, 4, 1, 9, 0, 0, 5},
                             {0, 0, 0, 0, 8, 0, 0, 7, 9}};
    
    printf("Before solving:\n");
    printBoard(board);
    
    if (solveSudoku(board, 0, 0)) {
        printf("\nAfter solving:\n");
        printBoard(board);
    } else {
        printf("\nNo solution found!\n");
    }
    
    return 0;
}