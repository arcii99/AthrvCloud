//FormAI DATASET v1.0 Category: Sudoku solver ; Style: cheerful
#include <stdio.h>

#define GRID_SIZE 9

void printGrid(char grid[][GRID_SIZE]) {
    printf("================\n");
    for (int i = 0; i < GRID_SIZE; i++) {
        printf("|");
        for (int j = 0; j < GRID_SIZE; j++) {
            printf(" %c ", grid[i][j]);
            if (j % 3 == 2) {
                printf("|");
            }
        }
        printf("\n");
        if (i % 3 == 2) {
            printf("================\n");
        }
    }
    printf("\n");
}

int findUnassigned(char grid[][GRID_SIZE], int* row, int* col) {
    for (*row = 0; *row < GRID_SIZE; (*row)++) {
        for (*col = 0; *col < GRID_SIZE; (*col)++) {
            if (grid[*row][*col] == '0') {
                return 1;
            }
        }
    }
    return 0;
}

int isSafe(char grid[][GRID_SIZE], int row, int col, int num) {
    for (int i = 0; i < GRID_SIZE; i++) {
        if (grid[row][i] == num + '0' || grid[i][col] == num + '0') {
            return 0;
        }
    }

    int boxRow = row - row % 3;
    int boxCol = col - col % 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (grid[i + boxRow][j + boxCol] == num + '0') {
                return 0;
            }
        }
    }
    return 1;
}

int solveSudoku(char grid[][GRID_SIZE]) {
    int row;
    int col;
    if (!findUnassigned(grid, &row, &col)) {
        return 1;
    }

    for (int i = 1; i <= 9; i++) {
        if (isSafe(grid, row, col, i)) {
            grid[row][col] = i + '0';
            if (solveSudoku(grid)) {
                return 1;
            }
            grid[row][col] = '0';
        }
    }
    return 0;
}

int main() {
    printf("Welcome to the cheerful Sudoku solver!\n\n");

    char grid[GRID_SIZE][GRID_SIZE] = {
        {'5', '3', '0', '0', '7', '0', '0', '0', '0'},
        {'6', '0', '0', '1', '9', '5', '0', '0', '0'},
        {'0', '9', '8', '0', '0', '0', '0', '6', '0'},
        {'8', '0', '0', '0', '6', '0', '0', '0', '3'},
        {'4', '0', '0', '8', '0', '3', '0', '0', '1'},
        {'7', '0', '0', '0', '2', '0', '0', '0', '6'},
        {'0', '6', '0', '0', '0', '0', '2', '8', '0'},
        {'0', '0', '0', '4', '1', '9', '0', '0', '5'},
        {'0', '0', '0', '0', '8', '0', '0', '7', '9'}
    };

    printf("Initial Grid:\n");
    printGrid(grid);

    if (solveSudoku(grid)) {
        printf("Grid Solved:\n");
        printGrid(grid);
    } else {
        printf("No solution exists for the given grid!\n");
    }

    return 0;
}