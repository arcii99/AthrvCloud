//FormAI DATASET v1.0 Category: Sudoku solver ; Style: recursive
#include <stdio.h>
#include <stdbool.h>

// Function to print the Sudoku board
void printBoard(int board[9][9]) {
    printf("===================\n");
    for(int row = 0; row < 9; row++) {
        for(int col = 0; col < 9; col++) {
            printf("%d ", board[row][col]);
            if(col == 2 || col == 5) {
                printf("| ");
            }
        }
        printf("\n");
        if(row == 2 || row == 5) {
            printf("-------------------\n");
        }
    }
    printf("===================\n");
}

// Function to check if the number can be placed in the given position
bool isValid(int board[9][9], int row, int col, int num) {
    // Check row and column
    for(int i = 0; i < 9; i++) {
        if(board[row][i] == num || board[i][col] == num) {
            return false;
        }
    }
    // Check 3x3 box
    int boxRow = row - (row % 3);
    int boxCol = col - (col % 3);
    for(int i = boxRow; i < boxRow + 3; i++) {
        for(int j = boxCol; j < boxCol + 3; j++) {
            if(board[i][j] == num) {
                return false;
            }
        }
    }
    return true;
}

// Recursive function to solve the Sudoku puzzle
bool solveSudoku(int board[9][9], int row, int col) {
    // Base case: if we have reached the 9th row, the entire board has been solved
    if(row == 9) {
        return true;
    }
    // If we have reached the last column in the current row, move to first column of next row
    if(col == 9) {
        return solveSudoku(board, row + 1, 0);
    }
    // If there is a number present at the current position, move to next column
    if(board[row][col] != 0) {
        return solveSudoku(board, row, col + 1);
    }
    // Try all numbers from 1 to 9
    for(int num = 1; num <= 9; num++) {
        if(isValid(board, row, col, num)) {
            board[row][col] = num;
            // If the puzzle is solved with the current number, return true
            if(solveSudoku(board, row, col + 1)) {
                return true;
            }
            // If the puzzle is not solved with the current number, undo the change and try the next number
            board[row][col] = 0;
        }
    }
    // If no numbers work, backtrack to previous cell
    return false;
}

int main() {
    // Example Sudoku board to solve
    int board[9][9] = {{5, 3, 0, 0, 7, 0, 0, 0, 0},
                       {6, 0, 0, 1, 9, 5, 0, 0, 0},
                       {0, 9, 8, 0, 0, 0, 0, 6, 0},
                       {8, 0, 0, 0, 6, 0, 0, 0, 3},
                       {4, 0, 0, 8, 0, 3, 0, 0, 1},
                       {7, 0, 0, 0, 2, 0, 0, 0, 6},
                       {0, 6, 0, 0, 0, 0, 2, 8, 0},
                       {0, 0, 0, 4, 1, 9, 0, 0, 5},
                       {0, 0, 0, 0, 8, 0, 0, 7, 9}};
    
    // Print the initial Sudoku board
    printf("Initial board:\n");
    printBoard(board);
    
    // Solve the Sudoku board recursively
    if(solveSudoku(board, 0, 0)) {
        printf("Solution found!\n");
        printBoard(board);
    } else {
        printf("Unable to find a solution.\n");
    }
    
    return 0;
}