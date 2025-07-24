//FormAI DATASET v1.0 Category: Sudoku solver ; Style: automated
#include <stdio.h>

// Board dimensions
#define BOARD_SIZE 9

// Function to print the Sudoku board
void printBoard(int board[BOARD_SIZE][BOARD_SIZE]) {
    for (int row = 0; row < BOARD_SIZE; row++) {
        for (int col = 0; col < BOARD_SIZE; col++) {
            printf("%d ", board[row][col]);
        }
        printf("\n");
    }
}

// Function to check if a number is valid in a specific position
int isValid(int board[BOARD_SIZE][BOARD_SIZE], int row, int col, int num) {
    // Check horizontally and vertically
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (board[row][i] == num || board[i][col] == num) {
            return 0;
        }
    }
    
    // Check in 3x3 subgrid
    int subgridStartRow = (row / 3) * 3;
    int subgridStartCol = (col / 3) * 3;
    
    for (int i = subgridStartRow; i < subgridStartRow + 3; i++) {
        for (int j = subgridStartCol; j < subgridStartCol + 3; j++) {
            if (board[i][j] == num) {
                return 0;
            }
        }
    }
    
    return 1;
}

// Function to solve the Sudoku board
int solveBoard(int board[BOARD_SIZE][BOARD_SIZE], int row, int col) {
    // Check if we've reached the end of the board
    if (row == BOARD_SIZE) {
        return 1;
    }
    
    // Check if we need to wrap to next row
    if (col == BOARD_SIZE) {
        return solveBoard(board, row + 1, 0);
    }
    
    // Skip over existing cells
    if (board[row][col] != 0) {
        return solveBoard(board, row, col + 1);
    }
    
    // Try all numbers 1-9 in the current cell
    for (int num = 1; num <= 9; num++) {
        if (isValid(board, row, col, num)) {
            board[row][col] = num;
            if (solveBoard(board, row, col + 1)) {
                return 1;
            }
            board[row][col] = 0;
        }
    }
    
    return 0;
}

int main() {
    // Sample board with one solution
    int board[BOARD_SIZE][BOARD_SIZE] = {
        {8, 0, 0, 0, 0, 0, 9, 0, 1},
        {0, 6, 0, 7, 0, 4, 0, 0, 0},
        {0, 0, 2, 0, 0, 0, 0, 4, 0},
        {5, 0, 4, 0, 0, 0, 0, 0, 7},
        {0, 0, 0, 0, 3, 0, 0, 0, 0},
        {6, 0, 0, 0, 0, 0, 2, 0, 4},
        {0, 5, 0, 0, 9, 0, 7, 0, 0},
        {0, 0, 0, 3, 0, 8, 0, 9, 0},
        {7, 0, 3, 0, 0, 0, 0, 0, 5}
    };
    
    // Solve the board
    if (solveBoard(board, 0, 0)) {
        printf("Solved Sudoku board:\n");
        printBoard(board);
    } else {
        printf("Cannot solve Sudoku board.\n");
    }
    
    return 0;
}