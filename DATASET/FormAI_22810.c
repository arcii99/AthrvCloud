//FormAI DATASET v1.0 Category: Sudoku solver ; Style: calm
#include <stdio.h>
#include <stdbool.h>
#define N 9 // Sudoku grid size

void printGrid(int grid[N][N]){
    // Function to print the solved Sudoku grid
    printf("\n");
    for(int row=0; row<N; row++){
        for(int col=0; col<N; col++)
            printf("%d ", grid[row][col]);
        printf("\n");
    }
}

bool findEmptyCell(int grid[N][N], int *row, int *col){
    // Function to find an empty cell in the Sudoku grid
    for(*row=0; *row<N; (*row)++){
        for(*col=0; *col<N; (*col)++){
            if(grid[*row][*col] == 0)
                return true;
        }
    }
    return false;
}

bool isSafe(int grid[N][N], int row, int col, int num){
    // Function to check if a number can be placed in a cell
    for(int i=0; i<N; i++){
        if(grid[row][i] == num)
            return false;
        if(grid[i][col] == num)
            return false;
        if(grid[(row-row%3)+(i/3)][(col-col%3)+(i%3)] == num)
            return false;
    }
    return true;
}

bool solveSudoku(int grid[N][N]){
    // Function to solve the Sudoku grid using backtracking
    int row, col;
    if(!findEmptyCell(grid, &row, &col))
        return true;
    for(int num=1; num<=9; num++){
        if(isSafe(grid, row, col, num)){
            grid[row][col] = num;
            if(solveSudoku(grid))
                return true;
            grid[row][col] = 0;
        }
    }
    return false;
}

int main(){
    int grid[N][N] = {{3, 0, 6, 5, 0, 8, 4, 0, 0},
                      {5, 2, 0, 0, 0, 0, 0, 0, 0},
                      {0, 8, 7, 0, 0, 0, 0, 3, 1},
                      {0, 0, 3, 0, 0, 0, 0, 2, 0},
                      {9, 0, 0, 8, 0, 0, 0, 0, 5},
                      {0, 5, 0, 0, 0, 0, 6, 0, 0},
                      {1, 3, 0, 0, 0, 0, 2, 5, 0},
                      {0, 0, 0, 0, 0, 0, 0, 7, 4},
                      {0, 0, 5, 2, 0, 6, 3, 0, 0}};
    if(solveSudoku(grid))
        printGrid(grid);
    else
        printf("\nNo solution exists\n");
    return 0;
}