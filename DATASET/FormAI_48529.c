//FormAI DATASET v1.0 Category: Sudoku solver ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>

#define ROWS 9
#define COLS 9
#define UNASSIGNED 0

void printBoard(int board[ROWS][COLS]) {
    printf("+-----+-----+-----+\n");
    for (int i = 0; i < ROWS; i++) {
        printf("|");
        for (int j = 0; j < COLS; j++) {
            printf("%d ", board[i][j]);
            if ((j+1)%3 == 0) printf("| ");
        }
        printf("\n");
        if ((i+1)%3 == 0) printf("+-----+-----+-----+\n");
    }
}

int isValid(int board[ROWS][COLS], int row, int col, int num) {
    for (int i = 0; i < ROWS; i++) {
        if (board[i][col] == num) return 0;
        if (board[row][i] == num) return 0;
    }
    int boxRow = (row/3)*3;
    int boxCol = (col/3)*3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[boxRow+i][boxCol+j] == num) return 0;
        }
    }
    return 1;
}

int solveSudoku(int board[ROWS][COLS]) {
    int row, col;
    int solved = 1;
    for (row = 0; row < ROWS; row++) {
        for (col = 0; col < COLS; col++) {
            if (board[row][col] == UNASSIGNED) {
                solved = 0;
                break;
            }
        }
        if (!solved) break;
    }
    if (solved) return 1;
    for (int num = 1; num <= 9; num++) {
        if (isValid(board, row, col, num)) {
            board[row][col] = num;
            if (solveSudoku(board)) return 1;
            board[row][col] = UNASSIGNED;
        }
    }
    return 0;
}

int main() {
    int board[ROWS][COLS] = {{0,0,0,4,0,0,0,0,2},
                             {0,7,0,5,1,0,0,0,0},
                             {0,0,0,0,0,9,0,0,0},
                             {0,8,0,0,9,7,0,0,0},
                             {0,4,0,0,0,0,0,8,0},
                             {0,0,0,6,2,0,0,3,0},
                             {0,0,0,1,0,0,0,0,0},
                             {0,0,0,0,0,0,7,0,0},
                             {0,0,6,0,0,5,0,0,0}};
    printf("Original Board:\n");
    printBoard(board);
    if (solveSudoku(board) == 1) {
        printf("\nSolved Board:\n");
        printBoard(board);
    }
    else {
        printf("No solution exists for the given Sudoku board.\n");
    }
    return 0;
}