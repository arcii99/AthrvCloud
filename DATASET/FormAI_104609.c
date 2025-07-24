//FormAI DATASET v1.0 Category: Sudoku solver ; Style: innovative
#include <stdbool.h>
#include <stdio.h>
#define UNASSIGNED 0
#define N 9

int grid[N][N] = { { 3, 0, 6, 5, 0, 8, 4, 0, 0 },
                   { 5, 2, 0, 0, 0, 0, 0, 0, 0 },
                   { 0, 8, 7, 0, 0, 0, 0, 3, 1 },
                   { 0, 0, 3, 0, 0, 0, 0, 2, 0 },
                   { 9, 0, 0, 8, 0, 0, 0, 0, 5 },
                   { 0, 5, 0, 0, 0, 0, 6, 0, 0 },
                   { 1, 3, 0, 0, 0, 0, 2, 5, 0 },
                   { 0, 0, 0, 0, 0, 0, 0, 7, 4 },
                   { 0, 0, 5, 2, 0, 6, 3, 0, 0 } };

void printGrid() {
    for (int row = 0; row < N; row++) {
        for (int col = 0; col < N; col++)
            printf("%d ", grid[row][col]);
        printf("\n");
    }
}

bool usedInRow(int row, int num) {
    for (int col = 0; col < N; col++)
        if (grid[row][col] == num)
            return true;
    return false;
}

bool usedInCol(int col, int num) {
    for (int row = 0; row < N; row++)
        if (grid[row][col] == num)
            return true;
    return false;
}

bool usedInBox(int boxStartRow, int boxStartCol, int num) {
    for (int row = 0; row < 3; row++)
        for (int col = 0; col < 3; col++)
            if (grid[row + boxStartRow][col + boxStartCol] == num)
                return true;
    return false;
}

bool isSafe(int row, int col, int num) {
    return !usedInRow(row, num) && !usedInCol(col, num) &&
           !usedInBox(row - row % 3, col - col % 3, num) &&
           grid[row][col] == UNASSIGNED;
}

bool findUnassignedLocation(int* row, int* col) {
    for (*row = 0; *row < N; (*row)++)
        for (*col = 0; *col < N; (*col)++)
            if (grid[*row][*col] == UNASSIGNED)
                return true;
    return false;
}

bool solveSudoku() {
    int row, col;
    if (!findUnassignedLocation(&row, &col))
        return true;
    for (int num = 1; num <= 9; num++) {
        if (isSafe(row, col, num)) {
            grid[row][col] = num;

            if (solveSudoku())
                return true;

            grid[row][col] = UNASSIGNED;
        }
    }
    return false;
}

int main() {
    if (solveSudoku())
        printGrid();
    else
        printf("No solution exists");
    return 0;
}