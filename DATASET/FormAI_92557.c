//FormAI DATASET v1.0 Category: Sudoku solver ; Style: protected
#include <stdio.h>

// Function prototypes
void printSudoku(int sudoku[9][9]);
int checkRow(int row, int num, int sudoku[9][9]);
int checkColumn(int col, int num, int sudoku[9][9]);
int checkSubgrid(int startRow, int startCol, int num, int sudoku[9][9]);
int findEmptyCell(int sudoku[9][9], int *row, int *col);
int solveSudoku(int sudoku[9][9]);

int main() {
    // Example sudoku puzzle
    int sudoku[9][9] = {     {3, 0, 6, 5, 0, 8, 4, 0, 0},
                             {5, 2, 0, 0, 0, 0, 0, 0, 0},
                             {0, 8, 7, 0, 0, 0, 0, 3, 1},
                             {0, 0, 3, 0, 0, 0, 0, 2, 0},
                             {9, 0, 0, 8, 0, 0, 0, 0, 5},
                             {0, 5, 0, 0, 7, 0, 0, 0, 0},
                             {1, 3, 0, 0, 0, 0, 0, 0, 0},
                             {0, 0, 0, 0, 4, 0, 2, 0, 0},
                             {0, 0, 0, 0, 0, 0, 0, 0, 0} };

    // Print the sudoku puzzle
    printf("Sudoku puzzle:\n\n");
    printSudoku(sudoku);
    printf("\n");

    // Solve the sudoku puzzle
    if (solveSudoku(sudoku)) {
        printf("Solution:\n\n");
        printSudoku(sudoku);
        printf("\n");
    } else {
        printf("No solution found.\n");
    }

    return 0;
}

void printSudoku(int sudoku[9][9]) {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            printf("%d ", sudoku[i][j]);
        }
        printf("\n");
    }
}

int checkRow(int row, int num, int sudoku[9][9]) {
    for (int col = 0; col < 9; col++) {
        if (sudoku[row][col] == num) {
            return 0;
        }
    }
    return 1;
}

int checkColumn(int col, int num, int sudoku[9][9]) {
    for (int row = 0; row < 9; row++) {
        if (sudoku[row][col] == num) {
            return 0;
        }
    }
    return 1;
}

int checkSubgrid(int startRow, int startCol, int num, int sudoku[9][9]) {
    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 3; col++) {
            if (sudoku[row + startRow][col + startCol] == num) {
                return 0;
            }
        }
    }
    return 1;
}

int findEmptyCell(int sudoku[9][9], int *row, int *col) {
    for  (*row = 0; *row < 9; (*row)++) {
        for (*col = 0; *col < 9; (*col)++) {
            if (sudoku[*row][*col] == 0) {
                return 1;
            }
        }
    }
    return 0;
}

int solveSudoku(int sudoku[9][9]) {
    int row, col;
    if (!findEmptyCell(sudoku, &row, &col)) {
        return 1;
    }
    for (int num = 1; num <= 9; num++) {
        if (checkRow(row, num, sudoku) && checkColumn(col, num, sudoku) && checkSubgrid(row - row % 3, col - col % 3, num, sudoku)) {
            sudoku[row][col] = num;
            if (solveSudoku(sudoku)) {
                return 1;
            }
            sudoku[row][col] = 0;
        }
    }
    return 0;
}