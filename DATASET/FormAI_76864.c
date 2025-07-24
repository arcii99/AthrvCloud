//FormAI DATASET v1.0 Category: Sudoku solver ; Style: all-encompassing
#include <stdio.h>

// Helper function to print the grid
void printGrid(int grid[9][9]) {
    printf("-------------------------\n");

    for (int i = 0; i < 9; i++) {
        printf("| ");
        for (int j = 0; j < 9; j++) {
            printf("%d ", grid[i][j]);
            if ((j + 1) % 3 == 0) printf("| ");
        }
        printf("\n");

        if ((i + 1) % 3 == 0) printf("-------------------------\n");
    }
}

// Helper function to check if a given number is present in a row
int checkRow(int grid[9][9], int row, int num) {
    for (int i = 0; i < 9; i++) {
        if (grid[row][i] == num) return 1;
    }
    return 0;
}

// Helper function to check if a given number is present in a column
int checkCol(int grid[9][9], int col, int num) {
    for (int i = 0; i < 9; i++) {
        if (grid[i][col] == num) return 1;
    }
    return 0;
}

// Helper function to check if a given number is present in a 3x3 box
int checkBox(int grid[9][9], int boxRow, int boxCol, int num) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (grid[boxRow + i][boxCol + j] == num) return 1;
        }
    }
    return 0;
}

// Helper function to check if a given number can be placed at a given position
int isValid(int grid[9][9], int row, int col, int num) {
    if (checkRow(grid, row, num)) return 0;
    if (checkCol(grid, col, num)) return 0;
    if (checkBox(grid, row - row % 3, col - col % 3, num)) return 0;
    return 1;
}

// The main recursive function to solve the puzzle
int solve(int grid[9][9], int row, int col) {
    if (row == 9) {
        row = 0;
        if (++col == 9) return 1;
    }

    if (grid[row][col] != 0) return solve(grid, row + 1, col);

    for (int num = 1; num <= 9; num++) {
        if (isValid(grid, row, col, num)) {
            grid[row][col] = num;
            if (solve(grid, row + 1, col)) return 1;
            grid[row][col] = 0;
        }
    }

    return 0;
}

int main() {
    int grid[9][9] = {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}
    };

    printf("Sudoku puzzle:\n");
    printGrid(grid);
    printf("\n");

    if (solve(grid, 0, 0)) {
        printf("Sudoku solution:\n");
        printGrid(grid);
    } else {
        printf("No solution found.\n");
    }

    return 0;
}