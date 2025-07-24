//FormAI DATASET v1.0 Category: Sudoku solver ; Style: satisfied
#include <stdio.h>
#include <stdbool.h>

//Size of the Sudoku Grid
#define SIZE 9

//Function to print the solved Sudoku grid
void printGrid(int grid[SIZE][SIZE]) {
    printf("\n\nSudoku Solved:\n");
    for(int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++)
            printf(" %d ", grid[i][j]);
        printf("\n");
    }
}

//Function to check if the given number is safe to put in a cell or not.
bool isSafe(int grid[SIZE][SIZE], int row, int col, int num) {
    //Check if the given number exists in same row
    for(int i = 0; i < SIZE; i++)
        if(grid[row][i] == num)
            return false;
    
    //Check if the given number exists in same column
    for(int i = 0; i < SIZE; i++)
        if(grid[i][col] == num)
            return false;
    
    //Check if the given number exists in the same 3x3 subgrid
    int subgridStartRow = row - row % 3;
    int subgridStartCol = col - col % 3;
    for(int i = subgridStartRow; i < subgridStartRow + 3; i++)
        for(int j = subgridStartCol; j < subgridStartCol + 3; j++)
            if(grid[i][j] == num)
                return false;
    
    return true;
}

//Function to solve the Sudoku grid
bool solveSudoku(int grid[SIZE][SIZE]) {
    int row, col;
    bool isEmpty = false;

    //Check if any cell is empty to put number
    for(row = 0; row < SIZE; row++) {
        for(col = 0; col < SIZE; col++) {
            if(grid[row][col] == 0) {
                isEmpty = true;
                break;
            }
        }
        if(isEmpty)
            break;
    }

    //If all cells are filled then return true
    if(!isEmpty) {
        return true;
    }

    //Try to fill numbers from 1 to 9 in empty cell
    for(int num = 1; num <= 9; num++) {
        if(isSafe(grid, row, col, num)) {
            grid[row][col] = num;
            
            //Recurse to fill next cell
            if(solveSudoku(grid))
                return true;
            
            //If unable to fill next cell then backtrack to previous cell
            grid[row][col] = 0;
        }
    }

    return false;
}

int main() {
    int grid[SIZE][SIZE] = {
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

    if (solveSudoku(grid))
        printGrid(grid);
    else
        printf("No solution exists.");
    return 0;
}