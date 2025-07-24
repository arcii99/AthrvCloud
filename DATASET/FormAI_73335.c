//FormAI DATASET v1.0 Category: Sudoku solver ; Style: introspective
#include <stdio.h>
#include <stdbool.h>

#define SIZE 9

// Function to print the Sudoku grid
void printGrid(int grid[SIZE][SIZE]){
    int i, j;
    printf("The Sudoku grid is:\n\n");
    for (i = 0; i < SIZE; i++){
        for (j = 0; j < SIZE; j++){
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
    printf("\n\n");
}

// Function to check if a number is already present in the row
bool usedInRow(int grid[SIZE][SIZE], int row, int num){
    int i;
    for (i = 0; i < SIZE; i++){
        if (grid[row][i] == num){
            return true;
        }
    }
    return false;
}

// Function to check if a number is already present in the column
bool usedInCol(int grid[SIZE][SIZE], int col, int num){
    int i;
    for (i = 0; i < SIZE; i++){
        if (grid[i][col] == num){
            return true;
        }
    }
    return false;
}

// Function to check if a number is already present in the 3x3 box
bool usedInBox(int grid[SIZE][SIZE], int boxStartRow, int boxStartCol, int num){
    int i, j;
    for (i = 0; i < 3; i++){
        for (j = 0; j < 3; j++){
            if (grid[i + boxStartRow][j + boxStartCol] == num){
                return true;
            }
        }
    }
    return false;
}

// Function to check if it is safe to put the number in the given coordinate
bool isSafe(int grid[SIZE][SIZE], int row, int col, int num){
    return (!usedInRow(grid, row, num) &&
            !usedInCol(grid, col, num) &&
            !usedInBox(grid, row - row % 3, col - col % 3, num));
}

// Function to find the next empty block coordinates (if present)
bool findEmpty(int grid[SIZE][SIZE], int* row, int* col){
    for (*row = 0; *row < SIZE; (*row)++){
        for (*col = 0; *col < SIZE; (*col)++){
            if (grid[*row][*col] == 0){
                return true;
            }
        }
    }
    return false;
}

// The main solving function using recursive backtracking
bool solveSudoku(int grid[SIZE][SIZE]){
    int row, col;
    if (!findEmpty(grid, &row, &col)){
        return true; // The Sudoku puzzle is already solved
    }
    int num;
    for (num = 1; num <= 9; num++){
        if (isSafe(grid, row, col, num)){
            grid[row][col] = num;
            if (solveSudoku(grid)){ // Call the function recursively
                return true;
            }
            grid[row][col] = 0; // Reset the block and try again
        }
    }
    return false; // We cannot solve this Sudoku puzzle
}

int main(void){
    int grid1[SIZE][SIZE] = {
        {0, 0, 0, 6, 0, 0, 4, 0, 0},
        {7, 0, 0, 0, 0, 3, 6, 0, 0},
        {0, 0, 0, 0, 9, 1, 0, 8, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 5, 0, 1, 8, 0, 0, 0, 3},
        {0, 0, 0, 3, 0, 6, 0, 4, 5},
        {0, 4, 0, 2, 0, 0, 0, 6, 0},
        {9, 0, 3, 0, 0, 0, 0, 0, 0},
        {0, 2, 0, 0, 0, 0, 1, 0, 0}
    };
    
    int grid2[SIZE][SIZE] = {
        {3, 0, 0, 9, 0, 4, 5, 0, 1},
        {0, 9, 0, 0, 7, 0, 0, 0, 0},
        {0, 0, 1, 0, 0, 0, 0, 0, 9},
        {0, 0, 3, 0, 6, 0, 0, 0, 0},
        {0, 0, 9, 0, 0, 1, 0, 0, 0},
        {0, 4, 0, 0, 0, 0, 3, 9, 8},
        {0, 0, 0, 4, 1, 0, 0, 5, 6},
        {0, 5, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 2, 0, 0, 9, 0, 0}
    };

    printf("Sudoku solver program\n\n");
    
    // Solve the first grid
    printGrid(grid1);
    if (solveSudoku(grid1)){
        printf("The Sudoku puzzle is solved!\n");
        printGrid(grid1);
    } else {
        printf("There is no solution for this Sudoku puzzle.\n");
    }
    
    // Solve the second grid
    printGrid(grid2);
    if (solveSudoku(grid2)){
        printf("The Sudoku puzzle is solved!\n");
        printGrid(grid2);
    } else {
        printf("There is no solution for this Sudoku puzzle.\n");
    }
    
    return 0;
}