//FormAI DATASET v1.0 Category: Sudoku solver ; Style: medieval
#include <stdio.h>
#include <stdbool.h>

#define N 9

void printBoard(int board[][N]) {
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            printf("%3d", board[i][j]);
        }
        printf("\n");
    }
}

bool isPossible(int board[][N], int row, int column, int value) {
    for(int i = 0; i < N; i++) {
        if(board[row][i] == value || board[i][column] == value) {
            return false;
        }
    }
    int rowStart = (row / 3) * 3;
    int columnStart = (column / 3) * 3;

    for(int i = rowStart; i < rowStart + 3; i++) {
        for(int j = columnStart; j < columnStart + 3; j++) {
            if(board[i][j] == value) {
                return false;
            }
        }
    }
    return true;
}

bool solveSudoku(int board[][N]) {
    int row = -1;
    int col = -1;
    bool isEmpty = false;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if(board[i][j] == 0) {
                row = i;
                col = j;
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

    for(int i = 1; i <= 9; i++) {
        if(isPossible(board, row, col, i)) {
            board[row][col] = i;
            if(solveSudoku(board)) {
                return true;
            }
            board[row][col] = 0;
        }
    }
    return false;
}

int main() {
    int board[N][N] = { { 3, 0, 6, 5, 0, 8, 4, 0, 0 },
                        { 5, 2, 0, 0, 0, 0, 0, 0, 0 },
                        { 0, 8, 7, 0, 0, 0, 0, 3, 1 },
                        { 0, 0, 3, 0, 0, 0, 0, 2, 0 },
                        { 9, 0, 0, 8, 0, 0, 0, 0, 5 },
                        { 0, 5, 0, 0, 0, 0, 6, 0, 0 },
                        { 1, 3, 0, 0, 0, 0, 2, 5, 0 },
                        { 0, 0, 0, 0, 0, 0, 0, 7, 4 },
                        { 0, 0, 5, 2, 0, 6, 3, 0, 0 } };
    if(solveSudoku(board)) {
        printBoard(board);
    } else {
        printf("No solution exists.");
    }
    return 0;
}