//FormAI DATASET v1.0 Category: Sudoku solver ; Style: configurable
#include <stdio.h>

#define N 9 // size of the Sudoku board

// function to print the Sudoku board
void printBoard(int board[N][N]) {
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

// function to check if a value can be placed at a particular position in the board
int isSafe(int board[N][N], int row, int col, int val) {
    // check if the value is already present in the same row or column
    for(int i = 0; i < N; i++) {
        if(board[row][i] == val || board[i][col] == val) {
            return 0;
        }
    }
    
    // check if the value is already present in the same 3x3 grid
    int gridRow = row - (row % 3);
    int gridCol = col - (col % 3);
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            if(board[gridRow + i][gridCol + j] == val) {
                return 0;
            }
        }
    }
    
    return 1;
}

// function to solve the Sudoku board recursively
int solveSudoku(int board[N][N], int row, int col) {
    // check if we have reached the end of the board
    if(row == N) {
        return 1;
    }
    
    // check if we have reached the end of the row
    if(col == N) {
        return solveSudoku(board, row+1, 0);
    }
    
    // check if the current cell is already filled
    if(board[row][col] != 0) {
        return solveSudoku(board, row, col+1);
    }
    
    // try all possible values for the current cell
    for(int val = 1; val <= 9; val++) {
        if(isSafe(board, row, col, val)) {
            board[row][col] = val;
            if(solveSudoku(board, row, col+1)) {
                return 1;
            }
            board[row][col] = 0; // backtrack
        }
    }
    
    return 0;
}

// main function
int main() {
    int board[N][N] = {
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
    
    printf("Sudoku board before solving:\n");
    printBoard(board);
    
    if(solveSudoku(board, 0, 0)) {
        printf("\nSudoku board after solving:\n");
        printBoard(board);
    }
    else {
        printf("\nSolution not possible!\n");
    }
    
    return 0;
}