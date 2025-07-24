//FormAI DATASET v1.0 Category: Sudoku solver ; Style: safe
#include <stdio.h>

void printBoard(int board[9][9]) {
    // Print the board in a readable format 
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            printf("%d ", board[i][j]);
            if ((j + 1) % 3 == 0) {
                printf(" ");
            }
        }
        printf("\n");
        if ((i + 1) % 3 == 0) {
            printf("\n");
        }
    }
}

int checkRow(int board[9][9], int row, int num) {
    // Check if num exists in the row
    for (int i = 0; i < 9; i++) {
        if (board[row][i] == num) {
            return 1;
        }
    }
    return 0;
}

int checkCol(int board[9][9], int col, int num) {
    // Check if num exists in the column 
    for (int i = 0; i < 9; i++) {
        if (board[i][col] == num) {
            return 1;
        }
    }
    return 0;
}

int checkBox(int board[9][9], int row, int col, int num) {
    // Check if num exists in the 3x3 box 
    int boxRow = row - (row % 3);
    int boxCol = col - (col % 3);
    for (int i = boxRow; i < boxRow + 3; i++) {
        for (int j = boxCol; j < boxCol + 3; j++) {
            if (board[i][j] == num) {
                return 1;
            }
        }
    }
    return 0;
}

int solveSudoku(int board[9][9], int row, int col) {
    // Solve the Sudoku using recursion
    int nextRow = row;
    int nextCol = col + 1;
    if (nextCol >= 9) {
        nextRow++;
        nextCol = 0;
    }
    if (row >= 9) {
        return 1;
    }
    if (board[row][col] != 0) {
        return solveSudoku(board, nextRow, nextCol);
    } else {
        for (int num = 1; num <= 9; num++) {
            if (!checkRow(board, row, num) && !checkCol(board, col, num) && !checkBox(board, row, col, num)) {
                board[row][col] = num;
                if (solveSudoku(board, nextRow, nextCol)) {
                    return 1;
                }
                board[row][col] = 0;
            }
        }
        return 0;
    }
}

int main() {
    int board[9][9] = {
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
    printf("Sudoku before solving:\n");
    printBoard(board);
    printf("\nSudoku after solving:\n");
    if (solveSudoku(board, 0, 0)) {
        printBoard(board);
    } else {
        printf("Unable to solve the Sudoku.\n");
    }
    return 0;
}