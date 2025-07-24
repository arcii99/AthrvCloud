//FormAI DATASET v1.0 Category: Sudoku solver ; Style: calm
#include <stdio.h>
#define N 9

//function to print the grid
void printGrid(int grid[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
}

//function to check if a number can be placed in a certain cell
int isSafe(int grid[N][N], int row, int col, int num) {
    //check the row
    for (int i = 0; i < N; i++) {
        if (grid[row][i] == num) {
            return 0;
        }
    }
    
    //check the column
    for (int i = 0; i < N; i++) {
        if (grid[i][col] == num) {
            return 0;
        }
    }
    
    //check the box
    int boxRow = row - row % 3;
    int boxCol = col - col % 3;
    for (int i = boxRow; i < boxRow + 3; i++) {
        for (int j = boxCol; j < boxCol + 3; j++) {
            if (grid[i][j] == num) {
                return 0;
            }
        }
    }
    
    return 1;
}

//function to solve the grid
int solveGrid(int grid[N][N], int row, int col) {
    //base case: when all columns and rows are traversed
    if (row == N - 1 && col == N) {
        return 1;
    }
    
    //when a row is fully traversed, move to the next row
    if (col == N) {
        row++;
        col = 0;
    }
    
    //if the cell already contains a number, move to the next cell
    if (grid[row][col] > 0) {
        return solveGrid(grid, row, col + 1);
    }
    
    //try the numbers 1 to 9
    for (int num = 1; num <= 9; num++) {
        if (isSafe(grid, row, col, num)) {
            grid[row][col] = num;
            if (solveGrid(grid, row, col + 1)) {
                return 1;
            }
        }
        //if the number cannot be placed, reset the cell and try the next number
        grid[row][col] = 0;
    }
    
    //no solution found
    return 0;
}

int main() {
    int grid[N][N]={{0,0,6,5,0,8,7,0,0},
                {0,0,0,0,1,0,0,0,0},
                {2,3,0,0,0,0,0,5,4},
                {9,0,0,0,0,0,0,0,3},
                {0,0,0,8,3,7,0,0,0},
                {8,0,0,0,0,0,0,0,7},
                {3,2,0,0,0,0,0,6,1},
                {0,0,0,0,5,0,0,0,0},
                {0,0,5,9,0,6,8,0,0}};
    
    if (solveGrid(grid, 0, 0)) {
        printf("Solution found:\n");
        printGrid(grid);
    }
    else {
        printf("No solution found.\n");
    }

    return 0;
}