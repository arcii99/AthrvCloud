//FormAI DATASET v1.0 Category: Sudoku solver ; Style: relaxed
#include <stdio.h>
#include <stdbool.h>

// Sudoku board
int board[9][9] = {{0, 0, 0, 0, 0, 0, 0, 0, 0},
                   {0, 0, 0, 0, 0, 0, 0, 0, 0},
                   {0, 0, 0, 0, 0, 0, 0, 0, 0},
                   {0, 0, 0, 0, 0, 0, 0, 0, 0},
                   {0, 0, 0, 0, 0, 0, 0, 0, 0},
                   {0, 0, 0, 0, 0, 0, 0, 0, 0},
                   {0, 0, 0, 0, 0, 0, 0, 0, 0},
                   {0, 0, 0, 0, 0, 0, 0, 0, 0},
                   {0, 0, 0, 0, 0, 0, 0, 0, 0}};

// Function to check if a number is already present in the row
bool checkRow(int row, int num) {
    for(int col=0; col<9; col++) {
        if(board[row][col] == num) {
            return true;
        }
    }
    return false;
}

// Function to check if a number is already present in the column
bool checkCol(int col, int num) {
    for(int row=0; row<9; row++) {
        if(board[row][col] == num) {
            return true;
        }
    }
    return false;
}

// Function to check if a number is already present in the 3x3 box
bool checkBox(int row, int col, int num) {
    int r = row - (row % 3);
    int c = col - (col % 3);
    for(int i=r; i<r+3; i++) {
        for(int j=c; j<c+3; j++) {
            if(board[i][j] == num) {
                return true;
            }
        }
    }
    return false;
}

// Function to check if it is safe to place a number in a particular cell
bool isSafe(int row, int col, int num) {
    return !checkRow(row, num) && !checkCol(col, num) && !checkBox(row, col, num);
}

// Function to solve the Sudoku puzzle using backtracking
bool solveSudoku() {
    int row, col;
    bool isEmpty = false;
    for(row=0; row<9; row++) {
        for(col=0; col<9; col++) {
            if(board[row][col] == 0) {
                isEmpty = true;
                break;
            }
        }
        if(isEmpty) {
            break;
        }
    }
    if(!isEmpty) {
        return true;
    }
    for(int num=1; num<=9; num++) {
        if(isSafe(row, col, num)) {
            board[row][col] = num;
            if(solveSudoku()) {
                return true;
            }
            board[row][col] = 0;
        }
    }
    return false;
}

// Function to print the Sudoku board
void printBoard() {
    for(int row=0; row<9; row++) {
        for(int col=0; col<9; col++) {
            printf("%d ", board[row][col]);
        }
        printf("\n");
    }
}

// Main function
int main() {
    // Enter the Sudoku board values here
    board[0][0] = 5;
    board[0][3] = 3;
    board[0][4] = 7;
    board[1][1] = 6;
    board[1][2] = 1;
    board[1][5] = 9;
    board[2][1] = 9;
    board[2][2] = 8;
    board[2][7] = 6;
    board[3][0] = 8;
    board[3][4] = 4;
    board[3][8] = 5;
    board[4][3] = 1;
    board[4][5] = 6;
    board[5][0] = 7;
    board[5][4] = 2;
    board[5][8] = 9;
    board[6][1] = 5;
    board[6][6] = 9;
    board[6][7] = 3;
    board[7][3] = 2;
    board[7][4] = 8;
    board[7][7] = 1;
    board[8][4] = 3;
    board[8][5] = 1;
    board[8][8] = 4;
    if(solveSudoku()) {
        printf("Sudoku puzzle solved!\n");
        printBoard();
    } else {
        printf("Unable to solve the Sudoku puzzle!\n");
    }
    return 0;
}