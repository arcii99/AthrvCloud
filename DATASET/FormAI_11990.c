//FormAI DATASET v1.0 Category: Sudoku solver ; Style: high level of detail
#include <stdio.h>
#include <stdbool.h>

#define SIZE 9

void printBoard(int board[][SIZE]) {
    printf("+-----+-----+-----+\n");
    for(int i = 0; i < SIZE; i++) {
        printf("| ");
        for(int j = 0; j < SIZE; j++) {
            printf("%d ", board[i][j]);
            if((j+1) % 3 == 0) printf("| ");
        }
        printf("\n");
        if((i+1) % 3 == 0) printf("+-----+-----+-----+\n");
    }
}

bool rowContains(int board[][SIZE], int row, int num) {
    for(int i = 0; i < SIZE; i++) {
        if(board[row][i] == num) return true;
    }
    return false;
}

bool colContains(int board[][SIZE], int col, int num) {
    for(int i = 0; i < SIZE; i++) {
        if(board[i][col] == num) return true;
    }
    return false;
}

bool boxContains(int board[][SIZE], int row, int col, int num) {
    int rIndex = (row / 3) * 3;
    int cIndex = (col / 3) * 3;
    for(int i = rIndex; i < rIndex + 3; i++) {
        for(int j = cIndex; j < cIndex + 3; j++) {
            if(board[i][j] == num) return true;
        }
    }
    return false;
}

bool canPlaceNum(int board[][SIZE], int row, int col, int num) {
    if(rowContains(board, row, num)) return false;
    if(colContains(board, col, num)) return false;
    if(boxContains(board, row, col, num)) return false;
    return true;
}

bool findEmptyCell(int board[][SIZE], int *row, int *col) {
    for(int i = 0; i < SIZE; i++) {
        for(int j = 0; j < SIZE; j++) {
            if(board[i][j] == 0) {
                *row = i;
                *col = j;
                return true;
            }
        }
    }
    return false;
}

bool solveSudoku(int board[][SIZE]) {
    int row, col;
    if(!findEmptyCell(board, &row, &col)) return true; // board is solved

    for(int num = 1; num <= SIZE; num++) {
        if(canPlaceNum(board, row, col, num)) {
            board[row][col] = num;
            if(solveSudoku(board)) return true;
            board[row][col] = 0; // backtrack
        }
    }

    return false;
}

int main() {
    int board[SIZE][SIZE] = {{0, 0, 0, 6, 0, 3, 0, 0, 0},
                             {0, 0, 0, 0, 0, 0, 8, 0, 0},
                             {0, 4, 0, 7, 0, 0, 6, 0, 0},
                             {0, 9, 0, 8, 0, 0, 4, 3, 0},
                             {8, 1, 0, 0, 9, 0, 0, 0, 6},
                             {0, 3, 0, 0, 7, 0, 0, 0, 0},
                             {0, 0, 5, 0, 0, 4, 0, 0, 0},
                             {0, 0, 0, 0, 0, 0, 0, 0, 8},
                             {0, 0, 0, 0, 0, 0, 0, 9, 7}};

    printf("The initial board:\n");
    printBoard(board);
    solveSudoku(board);
    printf("\nThe solved board:\n");
    printBoard(board);
    return 0;
}