//FormAI DATASET v1.0 Category: Sudoku solver ; Style: dynamic
#include <stdio.h>
#include <stdbool.h>

bool rowContains(int row, int num, int board[9][9]) {
    for (int i = 0; i < 9; i++) {
        if (board[row][i] == num) {
            return true;
        }
    }
    return false;
}

bool colContains(int col, int num, int board[9][9]) {
    for (int i = 0; i < 9; i++) {
        if (board[i][col] == num) {
            return true;
        }
    }
    return false;
}

bool boxContains(int row, int col, int num, int board[9][9]) {
    int boxRow = row / 3 * 3;
    int boxCol = col / 3 * 3;
    for (int i = boxRow; i < boxRow + 3; i++) {
        for (int j = boxCol; j < boxCol + 3; j++) {
            if (board[i][j] == num) {
                return true;
            }
        }
    }
    return false;
}

bool isValid(int row, int col, int num, int board[9][9]) {
    return !rowContains(row, num, board) && !colContains(col, num, board) && !boxContains(row, col, num, board);
}

bool findEmpty(int *row, int *col, int board[9][9]) {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (board[i][j] == 0) {
                *row = i;
                *col = j;
                return true;
            }
        }
    }
    return false;
}

bool solve(int board[9][9]) {
    int row, col;
    if (!findEmpty(&row, &col, board)) {
        return true; // board is solved
    }
    for (int num = 1; num <= 9; num++) {
        if (isValid(row, col, num, board)) {
            board[row][col] = num;
            if (solve(board)) {
                return true;
            }
            board[row][col] = 0; // backtrack
        }
    }
    return false; // no solution found
}

void printBoard(int board[9][9]) {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int board[9][9] = {
        {0, 0, 0, 0, 0, 3, 2, 9, 0},
        {8, 0, 1, 0, 0, 7, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 0, 1, 3},
        {5, 0, 8, 0, 0, 0, 0, 0, 4},
        {0, 0, 0, 3, 0, 0, 0, 0, 0},
        {1, 9, 0, 0, 0, 0, 0, 0, 5},
        {0, 0, 0, 0, 2, 1, 0, 7, 0},
        {0, 7, 0, 8, 9, 0, 0, 0, 0},
        {0, 0, 3, 0, 7, 0, 0, 0, 0}
    };
    printf("Initial board:\n");
    printBoard(board);
    if (solve(board)) {
        printf("\nSolution:\n");
        printBoard(board);
    } else {
        printf("\nNo solution found.\n");
    }
    return 0;
}