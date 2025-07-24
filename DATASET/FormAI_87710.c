//FormAI DATASET v1.0 Category: Sudoku solver ; Style: multivariable
#include <stdio.h>

// function to print the sudoku board
void printBoard(int board[][9]) {
    for(int i=0; i<9; i++) {
        for(int j=0; j<9; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

// function to check if cell can be filled with given number
int isSafe(int board[][9], int row, int col, int num) {
    // check row
    for(int i=0; i<9; i++) {
        if(board[row][i] == num) {
            return 0;
        }
    }
    // check column
    for(int i=0; i<9; i++) {
        if(board[i][col] == num) {
            return 0;
        }
    }
    // check subgrid
    int subRow = row - row%3;
    int subCol = col - col%3;
    for(int i=subRow; i<subRow+3; i++) {
        for(int j=subCol; j<subCol+3; j++) {
            if(board[i][j] == num) {
                return 0;
            }
        }
    }
    return 1;
}

// function to solve the sudoku board using backtracking
int solveSudoku(int board[][9], int row, int col) {
    // check if all cells have been filled
    if(row == 9) {
        return 1;
    }
    // check if current cell is empty
    if(board[row][col] != 0) {
        if(col == 8) {
            return solveSudoku(board, row+1, 0);
        } else {
            return solveSudoku(board, row, col+1);
        }
    }
    // try to fill current cell with numbers 1-9
    for(int i=1; i<=9; i++) {
        // check if number is safe to be filled in current cell
        if(isSafe(board, row, col, i)) {
            board[row][col] = i;
            // recursively try to solve the board
            if(col == 8) {
                if(solveSudoku(board, row+1, 0)) {
                    return 1;
                }
            } else {
                if(solveSudoku(board, row, col+1)) {
                    return 1;
                }
            }
            // if the current number does not lead to a solution, backtrack
            board[row][col] = 0;
        }
    }
    return 0;
}

int main() {
    int sudokuBoard[9][9] = {{0,0,5,3,0,0,0,0,0},
                            {8,0,0,0,0,0,0,2,0},
                            {0,7,0,0,1,0,5,0,0},
                            {4,0,0,0,0,5,3,0,0},
                            {0,1,0,0,7,0,0,0,6},
                            {0,0,3,2,0,0,0,8,0},
                            {0,6,0,5,0,0,0,0,9},
                            {0,0,4,0,0,0,0,3,0},
                            {0,0,0,0,0,9,7,0,0}};

    // print the unsolved board
    printf("Unsolved board:\n");
    printBoard(sudokuBoard);

    // solve the board
    if(solveSudoku(sudokuBoard, 0, 0)) {
        // print the solved board
        printf("Solved board:\n");
        printBoard(sudokuBoard);
    } else {
        printf("No solution found.");
    }

    return 0;
}