//FormAI DATASET v1.0 Category: Sudoku solver ; Style: intelligent
#include<stdio.h>
#include<stdlib.h>
#define N 9

int isEmpty(int grid[N][N], int *row, int *col);
int isSafe(int grid[N][N], int row, int col, int num);
int solveSudoku(int grid[N][N]);
void printGrid(int grid[N][N]);

int main(){
    int grid[N][N] = {{0, 0, 5, 3, 0, 0, 0, 0, 0},
                      {8, 0, 0, 0, 0, 0, 0, 2, 0},
                      {0, 7, 0, 0, 1, 0, 5, 0, 0},
                      {4, 0, 0, 0, 0, 5, 3, 0, 0},
                      {0, 1, 0, 0, 7, 0, 0, 0, 6},
                      {0, 0, 3, 2, 0, 0, 0, 8, 0},
                      {0, 6, 0, 5, 0, 0, 0, 0, 9},
                      {0, 0, 4, 0, 0, 0, 0, 3, 0},
                      {0, 0, 0, 0, 0, 9, 7, 0, 0}};
    if (solveSudoku(grid) == 1)
        printGrid(grid);
    else
        printf("No solution exists");

    return 0;
}

int isEmpty(int grid[N][N], int *row, int *col){
    for(*row=0; *row<N; (*row)++)
        for(*col=0; *col<N; (*col)++)
            if(grid[*row][*col] == 0)
                return 1;
    return 0;
}

int isSafe(int grid[N][N], int row, int col, int num){
    int i, j;
    for(i=0; i<N; i++)
        if(grid[row][i] == num)
            return 0;
    for(i=0; i<N; i++)
        if(grid[i][col] == num)
            return 0;
    int startRow = row - row%3, startCol = col - col%3;
    for(i=0; i<3; i++)
        for(j=0; j<3; j++)
            if(grid[i+startRow][j+startCol] == num)
                return 0;
    return 1;
}

int solveSudoku(int grid[N][N]){
    int row, col;
    if(!isEmpty(grid, &row, &col))
        return 1;
    int i;
    for(i=1; i<=9; i++){
        if(isSafe(grid, row, col, i)){
            grid[row][col] = i;
            if(solveSudoku(grid))
                return 1;
            grid[row][col] = 0;
        }
    }
    return 0;
}

void printGrid(int grid[N][N]){
    int i, j;
    printf("\n");
    for(i=0; i<N; i++){
        for(j=0; j<N; j++)
            printf("%d ", grid[i][j]);
            printf("\n");
    }
    printf("\n");
}