//FormAI DATASET v1.0 Category: Sudoku solver ; Style: portable
#include <stdio.h>

void printSudoku(int sudoku[9][9]) {
    // Helper function to print sudoku board
    printf("+---+---+---+\n");
    for(int i=0; i<9; i++) {
        printf("|");
        for(int j=0; j<9; j++) {
            printf("%d", sudoku[i][j]);
            if((j+1)%3 == 0){
                printf("|");
            } else {
                printf(" ");
            }
        }
        printf("\n");
        if((i+1)%3 == 0) {
            printf("+---+---+---+\n");
        }
    }
}

int isSafe(int sudoku[9][9], int row, int col, int num) {
    // Helper function to check if placement is valid in the row, column, and box
    // Returns 1 if safe, 0 otherwise

    // Check row
    for(int i=0; i<9; i++) {
        if(sudoku[row][i] == num) {
            return 0;
        }
    }

    // Check column
    for(int i=0; i<9; i++) {
        if(sudoku[i][col] == num) {
            return 0;
        }
    }

    // Check box
    int boxRow = row - (row % 3);
    int boxCol = col - (col % 3);
    for(int i=boxRow; i<boxRow+3; i++) {
        for(int j=boxCol; j<boxCol+3; j++) {
            if(sudoku[i][j] == num) {
                return 0;
            }
        }
    }

    // Placement is safe
    return 1;
}

int solveSudoku(int sudoku[9][9]) {
    // Recursive function to solve sudoku using backtracking
    // Returns 1 if solved, 0 otherwise

    int row = -1;
    int col = -1;
    int isFull = 1;

    // Find next empty cell
    for(int i=0; i<9; i++) {
        for(int j=0; j<9; j++) {
            if(sudoku[i][j] == 0) {
                row = i;
                col = j;
                isFull = 0;
                break;
            }
        }
        if(!isFull) {
            break;
        }
    }

    // If sudoku board is full, we are done
    if(isFull) {
        return 1;
    }

    // Try each number from 1 to 9 in the cell
    for(int num=1; num<=9; num++) {
        if(isSafe(sudoku, row, col, num)) {
            sudoku[row][col] = num;

            // Recursively try to solve the rest of the board
            if(solveSudoku(sudoku)) {
                return 1;
            }

            // If we can't solve the rest of the board with this number, backtrack
            sudoku[row][col] = 0;
        }
    }

    // Sudoku has no solution
    return 0;
}

int main() {

    // Example unsolved sudoku board
    int sudoku[9][9] = {
        {0, 5, 0, 0, 0, 0, 2, 0, 0},
        {8, 0, 0, 0, 0, 2, 0, 0, 0},
        {0, 0, 0, 5, 6, 0, 0, 7, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 3},
        {0, 0, 0, 0, 9, 0, 6, 0, 0},
        {4, 2, 0, 0, 0, 3, 0, 0, 0},
        {0, 0, 0, 0, 8, 0, 0, 0, 9},
        {0, 0, 1, 9, 0, 0, 4, 0, 0},
        {0, 0, 0, 0, 5, 0, 0, 0, 0}
    };

    printf("Unsolved sudoku board:\n");
    printSudoku(sudoku);

    // Solve sudoku board
    if(solveSudoku(sudoku)) {
        printf("\nSolved sudoku board:\n");
        printSudoku(sudoku);
    } else {
        printf("\nSudoku board has no solution.\n");
    }

    return 0;
}