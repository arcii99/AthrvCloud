//FormAI DATASET v1.0 Category: Sudoku solver ; Style: automated
#include <stdio.h>

#define N 9

int solveSudoku(int grid[N][N], int row, int col);
int isSafe(int grid[N][N], int row, int col, int num);
void printGrid(int grid[N][N]);

int main() {
    int grid[N][N] = {
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

    if (solveSudoku(grid, 0, 0)) {
        printf("Solution:\n");
        printGrid(grid);
    } else {
        printf("No solution exists.");
    }

    return 0;
}

int solveSudoku(int grid[N][N], int row, int col) {
    if (row == N - 1 && col == N) {
        return 1; // If everything is filled.
    }

    if (col == N) {
        row++;
        col = 0;
    }

    if (grid[row][col] > 0) {
        return solveSudoku(grid, row, col + 1);
    }

    for (int num = 1; num <= N; num++) {
        if (isSafe(grid, row, col, num)) {
            grid[row][col] = num;
            if (solveSudoku(grid, row, col + 1)) {
                return 1;
            }
        }
        grid[row][col] = 0;
    }
    return 0;
}

int isSafe(int grid[N][N], int row, int col, int num) {
    for (int x = 0; x < N; x++) {
        if (grid[row][x] == num || grid[x][col] == num) {
            return 0;
        }
    }

    int startRow = row - row % 3;
    int startCol = col - col % 3;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (grid[i + startRow][j + startCol] == num) {
                return 0;
            }
        }
    }
    return 1;
}

void printGrid(int grid[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            printf("%d ", grid[i][j]);
        printf("\n");
    }
}