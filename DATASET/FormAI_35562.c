//FormAI DATASET v1.0 Category: Sudoku solver ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define BOARD_SIZE 9

// Function to print the Sudoku board
void printBoard(int board[BOARD_SIZE][BOARD_SIZE]) {
    printf("-------------------------\n");
    for(int i=0; i<BOARD_SIZE; i++) {
        for(int j=0; j<BOARD_SIZE; j++) {
            printf(" %d ", board[i][j]);
            if((j+1)%3 == 0)
                printf("|");
        }
        printf("\n");
        if((i+1)%3 == 0)
            printf("-------------------------\n");
    }
}

// Function to check if the number is already present in the row
bool checkRow(int board[BOARD_SIZE][BOARD_SIZE], int row, int num) {
    for(int i=0; i<BOARD_SIZE; i++) {
        if(board[row][i] == num) {
            return false;
        }
    }
    return true;
}

// Function to check if the number is already present in the column
bool checkCol(int board[BOARD_SIZE][BOARD_SIZE], int col, int num) {
    for(int i=0; i<BOARD_SIZE; i++) {
        if(board[i][col] == num) {
            return false;
        }
    }
    return true;
}

// Function to check if the number is already present in the 3x3 sub-grid
bool checkBox(int board[BOARD_SIZE][BOARD_SIZE], int row, int col, int num) {
    int startRow = row - row%3;
    int startCol = col - col%3;
    
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            if(board[startRow+i][startCol+j] == num) {
                return false;
            }
        }
    }
    return true;
}

// Function to check if the number can be placed at the given cell
bool isValid(int board[BOARD_SIZE][BOARD_SIZE], int row, int col, int num) {
    bool rowCheck = checkRow(board, row, num);
    bool colCheck = checkCol(board, col, num);
    bool boxCheck = checkBox(board, row, col, num);
    if(rowCheck && colCheck && boxCheck) {
        return true;
    }
    return false;
}

// Recursive function to solve Sudoku
bool solveSudoku(int board[BOARD_SIZE][BOARD_SIZE], int row, int col) {
    // If we have reached the end of the board, Sudoku is solved.
    if(row == BOARD_SIZE-1 && col == BOARD_SIZE) {
        return true;
    }
    // If we have reached the end of a row, move to the next row.
    if(col == BOARD_SIZE) {
        row++;
        col=0;
    }
    // If the cell is already filled, move to the next column.
    if(board[row][col] != 0) {
        return solveSudoku(board, row, col+1);
    }
    // Try to place numbers from 1 to 9 at the given cell.
    for(int i=1; i<=9; i++) {
        if(isValid(board, row, col, i)) {
            board[row][col] = i;
            if(solveSudoku(board, row, col+1)) {
                return true;
            }
            board[row][col] = 0;
        }
    }
    return false;
}

int main() {
    int board[BOARD_SIZE][BOARD_SIZE] = {
            {9,0,0,1,0,0,0,0,5},
            {0,0,5,0,9,0,2,0,1},
            {8,0,0,0,4,0,0,0,0},
            {0,0,0,0,8,0,0,0,0},
            {0,0,0,7,0,0,0,0,0},
            {0,0,0,0,2,6,0,0,9},
            {2,0,0,3,0,0,0,0,6},
            {0,0,0,2,0,0,9,0,0},
            {0,0,1,9,0,4,5,7,0}
        };
    printf("Sudoku puzzle before solving:\n");
    printBoard(board);
    bool solved = solveSudoku(board, 0, 0);
    if(solved) {
        printf("\nSudoku puzzle after solving:\n");
        printBoard(board);
    } else {
        printf("\nNo solution exists for the given Sudoku puzzle.\n");
    }
    return 0;
}