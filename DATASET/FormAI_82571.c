//FormAI DATASET v1.0 Category: Sudoku solver ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define SIZE 9

struct Cell {
    int row;
    int col;
};

struct Cell getEmptyCell(int board[SIZE][SIZE]) {
    struct Cell emptyCell = {-1, -1};
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] == 0) {
                emptyCell.row = i;
                emptyCell.col = j;
                return emptyCell;
            }
        }
    }
    return emptyCell;
}

bool isValid(int board[SIZE][SIZE], int row, int col, int num) {
    // Check row
    for (int i = 0; i < SIZE; i++) {
        if (board[row][i] == num) {
            return false;
        }
    }

    // Check column
    for (int i = 0; i < SIZE; i++) {
        if (board[i][col] == num) {
            return false;
        }
    }

    // Check 3x3 box
    int boxRow = row - row % 3;
    int boxCol = col - col % 3;
    for (int i = boxRow; i < boxRow + 3; i++) {
        for (int j = boxCol; j < boxCol + 3; j++) {
            if (board[i][j] == num) {
                return false;
            }
        }
    }

    // Valid if no conflicts found
    return true;
}

bool solveSudoku(int board[SIZE][SIZE]) {
    struct Cell emptyCell = getEmptyCell(board);
    if (emptyCell.row == -1) {
        return true;  // Board is solved
    }

    int row = emptyCell.row;
    int col = emptyCell.col;
    for (int num = 1; num <= 9; num++) {
        if (isValid(board, row, col, num)) {
            board[row][col] = num;
            if (solveSudoku(board)) {
                return true;  // This path led to a solution
            }
            board[row][col] = 0;  // Backtrack if no solution found
        }
    }

    return false;  // No solution found
}

void printBoard(int board[SIZE][SIZE]) {
    printf("Sudoku Board:\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int board[SIZE][SIZE] = {
        {0, 0, 0, 0, 0, 0, 2, 0, 0},
        {0, 8, 0, 0, 0, 7, 0, 9, 0},
        {6, 0, 2, 0, 0, 0, 5, 0, 0},
        {0, 7, 0, 0, 6, 0, 0, 0, 0},
        {0, 0, 0, 9, 0, 1, 0, 0, 0},
        {0, 0, 0, 0, 2, 0, 0, 4, 0},
        {0, 0, 5, 0, 0, 0, 6, 0, 3},
        {0, 9, 0, 4, 0, 0, 0, 7, 0},
        {0, 0, 6, 0, 0, 0, 0, 0, 0}
    };

    printf("Before solving:\n");
    printBoard(board);

    if (solveSudoku(board)) {
        printf("Solution found:\n");
        printBoard(board);
    } else {
        printf("No solution found\n");
    }

    return 0;
}