//FormAI DATASET v1.0 Category: Sudoku solver ; Style: enthusiastic
#include <stdio.h>
#include <stdbool.h>

#define GRIDSIZE 9

bool is_available(int grid[GRIDSIZE][GRIDSIZE], int row, int col, int num) {
    int i, j;

    //check if the number already exists in the row
    for (i = 0; i < GRIDSIZE; i++)
        if (grid[row][i] == num)
            return false;

    //check if the number already exists in the column
    for (i = 0; i < GRIDSIZE; i++)
        if (grid[i][col] == num)
            return false;

    //check if the number already exists in the box
    int startRow = row - row % 3;
    int startCol = col - col % 3;
    for (i = 0; i < 3; i++)
        for (j = 0; j < 3; j++)
            if (grid[i + startRow][j + startCol] == num)
                return false;

    return true;
}

bool solve_sudoku(int grid[GRIDSIZE][GRIDSIZE]) {
    int row, col, num;

    for (row = 0; row < GRIDSIZE; row++) {
        for (col = 0; col < GRIDSIZE; col++) {
            if (grid[row][col] == 0) { //unfilled cell
                for (num = 1; num <= GRIDSIZE; num++) {
                    if (is_available(grid, row, col, num)) {
                        grid[row][col] = num;

                        if (solve_sudoku(grid))
                            return true;

                        grid[row][col] = 0; //backtrack
                    }
                }
                
                //all numbers have been tried. Backtrack
                return false;
            }
        }
    }

    //sudoku has been solved
    return true;
}

int main() {
    int grid[GRIDSIZE][GRIDSIZE] = {
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

    if (solve_sudoku(grid)) { //if it returns true
        for (int i = 0; i < GRIDSIZE; i++) {
            for (int j = 0; j < GRIDSIZE; j++)
                printf("%d ", grid[i][j]);
            printf("\n");
        }
    } else {
        printf("Sudoku cannot be solved.\n");
    }

    return 0;
}