//FormAI DATASET v1.0 Category: Sudoku solver ; Style: scalable
#include <stdio.h>

void displayBoard(int board[9][9]) {
    for (int i = 0; i < 9; i++) {
        if (i % 3 == 0 && i != 0) {
            printf("- - - - - - - - - - -\n");
        }
        for (int j = 0; j < 9; j++) {
            if (j % 3 == 0 && j != 0) {
                printf("|");
            }
            printf(" %d ", board[i][j]);
        }
        printf("\n");
    }
}

int findEmpty(int board[9][9], int* row, int* col) {
    for (*row = 0; *row < 9; (*row)++) {
        for (*col = 0; *col < 9; (*col)++) {
            if (board[*row][*col] == 0) {
                return 1;
            }
        }
    }
    return 0;
}

int isValid(int board[9][9], int row, int col, int num) {
    for (int i = 0; i < 9; i++) {
        if (board[row][i] == num || board[i][col] == num) {
            return 0;
        }
    }
    int boxRow = row - (row % 3);
    int boxCol = col - (col % 3);
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[boxRow + i][boxCol + j] == num) {
                return 0;
            }
        }
    }
    return 1;
}

int solveBoard(int board[9][9]) {
    int row, col;
    if (!findEmpty(board, &row, &col)) {
        return 1;
    }
    for (int num = 1; num < 10; num++) {
        if (isValid(board, row, col, num)) {
            board[row][col] = num;
            if (solveBoard(board)) {
                return 1;
            }
            board[row][col] = 0;
        }
    }
    return 0;
}

int main() {
    int board[9][9] = {{7, 8, 0, 4, 0, 0, 1, 2, 0},
                       {6, 0, 0, 0, 7, 5, 0, 0, 9},
                       {0, 0, 0, 6, 0, 1, 0, 7, 8},
                       {0, 0, 7, 0, 4, 0, 2, 6, 0},
                       {0, 0, 1, 0, 5, 0, 9, 3, 0},
                       {9, 0, 4, 0, 6, 0, 0, 0, 5},
                       {0, 7, 0, 3, 0, 0, 0, 1, 2},
                       {1, 2, 0, 0, 0, 7, 4, 0, 0},
                       {0, 4, 9, 2, 0, 6, 0, 0, 7}};
    displayBoard(board);
    printf("\n\n");
    if (solveBoard(board)) {
        displayBoard(board);
    }
    else {
        printf("Unsolvable board\n");
    }
    return 0;
}