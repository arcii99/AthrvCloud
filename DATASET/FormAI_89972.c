//FormAI DATASET v1.0 Category: Sudoku solver ; Style: Dennis Ritchie
#include<stdio.h>

//Function to print the sudoku grid
void printGrid(int grid[9][9]) {
    printf("-------------------\n");
    for(int i=0; i<9; i++) {
        for(int j=0; j<9; j++) {
            printf("%d ", grid[i][j]);
            if(j%3 == 2)
                printf("| ");
        }
        printf("\n");
        if(i%3 == 2)
            printf("-------------------\n");
    }
}

//Function to check if a digit can be placed in a given position
int isPossible(int grid[9][9], int row, int col, int num) {
    //Check if the number already exists in the row or column
    for(int i=0; i<9; i++) {
        if(grid[row][i] == num)
            return 0;
        if(grid[i][col] == num)
            return 0;
    }
    //Check if the number already exists in the 3x3 subgrid
    int subRow = row - (row % 3);
    int subCol = col - (col % 3);
    for(int i=subRow; i<subRow+3; i++) {
        for(int j=subCol; j<subCol+3; j++) {
            if(grid[i][j] == num)
                return 0;
        }
    }
    return 1;
}

//Backtracking based Sudoku solver
int solveSudoku(int grid[9][9]) {
    int row, col, flag=0;
    //Find an unassigned cell
    for(row=0; row<9; row++) {
        for(col=0; col<9; col++) {
            if(grid[row][col] == 0) {
                flag = 1;
                break;
            }
        }
        if(flag == 1)
            break;
    }
    //If no unassigned cell is available, the grid is solved
    if(row == 9 && col == 9)
        return 1;
    //Try placing digits from 1-9 in the unassigned cell
    for(int num=1; num<=9; num++) {
        if(isPossible(grid, row, col, num)) {
            grid[row][col] = num;
            //Check if the grid can be solved with the current assignment
            if(solveSudoku(grid))
                return 1;
            grid[row][col] = 0; //Unassign the cell if this assignment is not valid
        }
    }
    return 0;
}

//Driver function
int main() {
    int grid[9][9] = {{3, 0, 6, 5, 0, 8, 4, 0, 0},
                      {5, 2, 0, 0, 0, 0, 0, 0, 0},
                      {0, 8, 7, 0, 0, 0, 0, 3, 1},
                      {0, 0, 3, 0, 0, 0, 0, 2, 0},
                      {9, 0, 0, 8, 0, 0, 0, 0, 5},
                      {0, 5, 0, 0, 0, 0, 6, 0, 0},
                      {1, 3, 0, 0, 0, 0, 2, 5, 0},
                      {0, 0, 0, 0, 0, 0, 0, 7, 4},
                      {0, 0, 5, 2, 0, 6, 3, 0, 0}};
    printf("Before solving:\n");
    printGrid(grid);
    if(solveSudoku(grid)) {
        printf("After solving:\n");
        printGrid(grid);
    }
    else
        printf("No solution exists.\n");
    return 0;
}