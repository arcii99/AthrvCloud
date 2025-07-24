//FormAI DATASET v1.0 Category: Sudoku solver ; Style: careful
#include <stdio.h>

#define UNASSIGNED 0

int isSafe(int grid[9][9], int row, int col, int num) {
    // checks if number `num` can be placed in position (row, col) in `grid`
    for (int i = 0; i < 9; i++) {
        if (grid[row][i] == num || grid[i][col] == num)
            return 0;   // number already present in row or column
    }

    // checks if number is already present in 3x3 sub-grid
    int startRow = row - row % 3;
    int startCol = col - col % 3;

    for (int i = startRow; i < startRow + 3; i++)
        for (int j = startCol; j < startCol + 3; j++)
            if (grid[i][j] == num)
                return 0;   // number already present in sub-grid

    return 1;   // number can be placed in position
}

int findUnassignedLocation(int grid[9][9], int* row, int* col) {
    // searches grid for an unassigned location, returns 0 if none found
    // modifies row and col pointers to hold coordinates of unassigned location if found
    for (*row = 0; *row < 9; (*row)++)
        for (*col = 0; *col < 9; (*col)++)
            if (grid[*row][*col] == UNASSIGNED)
                return 1;

    return 0;   // no unassigned locations found
}

int solveSudoku(int grid[9][9]) {
    int row, col;

    if (!findUnassignedLocation(grid, &row, &col))
        return 1;   // all locations have been assigned, puzzle solved

    // try each number from 1 to 9 in unassigned location
    for (int i = 1; i <= 9; i++) {
        if (isSafe(grid, row, col, i)) {
            grid[row][col] = i;

            if (solveSudoku(grid))    // recursively solve sub-grid
                return 1;

            grid[row][col] = UNASSIGNED;    // backtrack
        }
    }

    return 0;   // puzzle unsolvable
}

void printGrid(int grid[9][9]) {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++)
            printf("%d ", grid[i][j]);

        printf("\n");
    }
}

int main() {
    int grid[9][9] = {   // insert puzzle to be solved here
        {0, 0, 0, 0, 9, 4, 3, 0, 0},
        {0, 0, 0, 0, 0, 5, 0, 0, 1},
        {4, 0, 0, 3, 0, 0, 2, 9, 0},
        {0, 0, 4, 0, 0, 0, 0, 0, 0},
        {0, 3, 9, 0, 0, 0, 1, 5, 0},
        {0, 0, 0, 0, 0, 0, 9, 0, 4},
        {0, 5, 3, 0, 0, 6, 0, 0, 7},
        {2, 0, 0, 7, 0, 0, 0, 0, 0},
        {0, 0, 1, 8, 3, 0, 0, 0, 0}
    };

    if (solveSudoku(grid)) {
        printf("Solution:\n");
        printGrid(grid);
    } else {
        printf("Puzzle unsolvable...\n");
    }

    return 0;
}