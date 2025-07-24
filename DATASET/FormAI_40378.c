//FormAI DATASET v1.0 Category: Sudoku solver ; Style: enthusiastic
#include <stdio.h>
#include <stdbool.h>

#define N 9 

bool findEmptySpace(int sudoku[N][N], int* row, int* col);
bool isPossible(int sudoku[N][N], int row, int col, int num);
bool solveSudoku(int sudoku[N][N]);
void printSudoku(int sudoku[N][N]);

int main() {
    int sudoku[N][N] = {
        {0, 8, 0, 0, 0, 9, 7, 4, 3},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {7, 0, 2, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 5, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 2, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 7, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 5, 0, 0, 0, 0, 0}
    };
    
    printf("Sudoku puzzle:\n");
    printSudoku(sudoku);
    
    solveSudoku(sudoku);
    
    printf("\nSolved Sudoku puzzle:\n");
    printSudoku(sudoku);
    
    return 0;
}

bool findEmptySpace(int sudoku[N][N], int* row, int* col) {
    for (*row = 0; *row < N; (*row)++) {
        for (*col = 0; *col < N; (*col)++) {
            if (sudoku[*row][*col] == 0) {
                return true;
            }
        }
    }
    return false;
}

bool isPossible(int sudoku[N][N], int row, int col, int num) {
    for (int i = 0; i < N; i++) {
        if (sudoku[row][i] == num) {
            return false;
        }
        if (sudoku[i][col] == num) {
            return false;
        }
        if (sudoku[row - row % 3 + i / 3][col - col % 3 + i % 3] == num) {
            return false;
        }
    }
    return true;
}

bool solveSudoku(int sudoku[N][N]) {
    int row, col;
    if (!findEmptySpace(sudoku, &row, &col)) {
        return true;
    }
    
    for (int num = 1; num <= 9; num++) {
        if (isPossible(sudoku, row, col, num)) {
            sudoku[row][col] = num;
            if (solveSudoku(sudoku)) {
                return true;
            }
            sudoku[row][col] = 0;
        }
    }
    return false;
}

void printSudoku(int sudoku[N][N]) {
    for (int i = 0; i < N; i++) {
        if (i % 3 == 0 && i != 0) {
            printf("---------------------\n");
        }
        for (int j = 0; j < N; j++) {
            if (j % 3 == 0 && j != 0) {
                printf("| ");
            }
            printf("%d ", sudoku[i][j]);
        }
        printf("\n");
    }
}