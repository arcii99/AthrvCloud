//FormAI DATASET v1.0 Category: Sudoku solver ; Style: single-threaded
#include <stdio.h>
#include <stdbool.h>

#define SIZE 9

bool isRowValid(int board[][SIZE], int row, int num) {
    for(int i = 0; i < SIZE; i++) {
        if(board[row][i] == num) {
            return false;
        }
    }
    return true;
}

bool isColValid(int board[][SIZE], int col, int num) {
    for(int i = 0; i < SIZE; i++) {
        if(board[i][col] == num) {
            return false;
        }
    }
    return true;
}

bool isBoxValid(int board[][SIZE], int startRow, int startCol, int num) {
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            if(board[startRow+i][startCol+j] == num) {
                return false;
            }
        }
    }
    return true;
}

bool isValid(int board[][SIZE], int row, int col, int num) {
    return isRowValid(board, row, num) &&
           isColValid(board, col, num) &&
           isBoxValid(board, row-row%3, col-col%3, num);
}

bool findUnassigned(int board[][SIZE], int *rowPtr, int *colPtr) {
    for(int i = 0; i < SIZE; i++) {
        for(int j = 0; j < SIZE; j++) {
            if(board[i][j] == 0) {
                *rowPtr = i;
                *colPtr = j;
                return true;
            }
        }
    }
    return false;
}

bool solveSudoku(int board[][SIZE]) {
    int row, col;
    if(!findUnassigned(board, &row, &col)) {
        return true; // the sudoku is solved!
    }
    for(int i = 1; i <= SIZE; i++) {
        if(isValid(board, row, col, i)) {
            board[row][col] = i;
            if(solveSudoku(board)) {
                return true;
            }
            board[row][col] = 0; // undo the change
        }
    }
    return false;
}

void printBoard(int board[][SIZE]) {
    for(int i = 0; i < SIZE; i++) {
        for(int j = 0; j < SIZE; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int board[SIZE][SIZE] = {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}
    };

    if(solveSudoku(board)) {
        printBoard(board);
    } else {
        printf("No solution found.\n");
    }

    return 0;
}