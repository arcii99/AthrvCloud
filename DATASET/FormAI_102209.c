//FormAI DATASET v1.0 Category: Sudoku solver ; Style: enthusiastic
#include <stdio.h>
#include <stdbool.h>

// Function to print the Sudoku board 
void printSudoku(int board[][9]) {
    printf("\n -------------------------\n");
    for (int i = 0; i < 9; i++) {
        printf("| ");
        for (int j = 0; j < 9; j++) {
            printf("%d ", board[i][j]);
            if ((j + 1) % 3 == 0)
                printf("| ");
        }
        if ((i + 1) % 3 == 0) 
            printf("\n -------------------------");
        printf("\n");
    }
}

// Function to check if it's safe to place digit in the cell
bool isSafe(int board[][9], int row, int col, int digit) {
    // Check row and column
    for (int i = 0; i < 9; i++)
        if (board[row][i] == digit || board[i][col] == digit)
            return false;

    // Check 3x3 subgrid
    int subRow = row - row % 3;
    int subCol = col - col % 3;
    for (int i = subRow; i < subRow + 3; i++)
        for (int j = subCol; j < subCol + 3; j++)
            if (board[i][j] == digit)
                return false;

    // The digit can be placed here
    return true;
}

// Function to solve Sudoku recursively
bool solveSudoku(int board[][9], int row, int col) {
    //If we've gone through all the rows, the sudoku is solved
    if (row == 9) {
        printSudoku(board);
        return true;
    }
    
    //If we've gone through a row move onto the next row
    if (col == 9) {
        return solveSudoku(board, row + 1, 0);
    }

    //If the spot is not empty, move onto the next spot in the row
    if (board[row][col] != 0) {
        return solveSudoku(board, row, col + 1);
    }

    //Iterating through digits and checking if a valid digit can be placed here
    for (int digit = 1; digit <= 9; digit++) {
        if (isSafe(board, row, col, digit)) {
            board[row][col] = digit;
            if (solveSudoku(board, row, col + 1))
                return true;
            board[row][col] = 0;
        }
    }
    // Backtrack
    return false;
}

int main() {
    int board[9][9] = 
    {
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
    printSudoku(board);
    solveSudoku(board, 0, 0);
    return 0;
}