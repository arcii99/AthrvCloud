//FormAI DATASET v1.0 Category: Sudoku solver ; Style: curious
#include <stdio.h>
#include <stdbool.h>

#define GRID_SIZE 9

int grid[GRID_SIZE][GRID_SIZE] = { //example sudoku grid
    {0, 0, 3, 0, 2, 0, 6, 0, 0},
    {9, 0, 0, 3, 0, 5, 0, 0, 1},
    {0, 0, 1, 8, 0, 6, 4, 0, 0},
    {0, 0, 8, 1, 0, 2, 9, 0, 0},
    {7, 0, 0, 0, 0, 0, 0, 0, 8},
    {0, 0, 6, 7, 0, 8, 2, 0, 0},
    {0, 0, 2, 6, 0, 9, 5, 0, 0},
    {8, 0, 0, 2, 0, 3, 0, 0, 9},
    {0, 0, 5, 0, 1, 0, 3, 0, 0}
};

void printGrid(int arr[GRID_SIZE][GRID_SIZE]) {
    for(int i=0; i<GRID_SIZE; i++) {
        for(int j=0; j<GRID_SIZE; j++) {
            printf("%d ", arr[i][j]);
            if(j%3 == 2) { //add separator between blocks
                printf("| ");
            }
        }
        printf("\n");
        if(i%3 == 2) { //add separator between blocks
            printf("------+-------+------\n");
        }
    }
}

bool isSafe(int arr[GRID_SIZE][GRID_SIZE], int row, int col, int num) {
    //check row
    for(int i=0; i<GRID_SIZE; i++) {
        if(arr[row][i] == num) {
            return false;
        }
    }
    //check column
    for(int i=0; i<GRID_SIZE; i++) {
        if(arr[i][col] == num) {
            return false;
        }
    }
    //check block
    int blockRow = (row/3)*3;
    int blockCol = (col/3)*3;
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            if(arr[blockRow+i][blockCol+j] == num) {
                return false;
            }
        }
    }
    //if all checks passed, number is safe to be placed in cell
    return true;
}

bool solveSudoku(int arr[GRID_SIZE][GRID_SIZE]) {
    int row, col;
    bool foundEmpty = false;
    for(int i=0; i<GRID_SIZE; i++) {
        for(int j=0; j<GRID_SIZE; j++) {
            if(arr[i][j] == 0) { //found empty cell
                row = i;
                col = j;
                foundEmpty = true;
                break;
            }
        }
        if(foundEmpty) {
            break;
        }
    }
    if(!foundEmpty) { //no empty cell, sudoku is solved
        return true;
    }
    for(int i=1; i<=9; i++) { //try every number from 1 to 9
        if(isSafe(arr, row, col, i)) {
            arr[row][col] = i;
            if(solveSudoku(arr)) { //recursive call to solve rest of the grid
                return true;
            }
            arr[row][col] = 0; //backtrack if solution is not possible with this number
        }
    }
    return false; //if no number works, puzzle cannot be solved
}

int main() {
    printf("Original puzzle:\n");
    printGrid(grid);
    
    if(solveSudoku(grid)) {
        printf("\nSolution:\n");
        printGrid(grid);
    } else {
        printf("\nNo solution exists for this puzzle.\n");
    }
    
    return 0;
}