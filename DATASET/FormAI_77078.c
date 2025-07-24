//FormAI DATASET v1.0 Category: Sudoku solver ; Style: ultraprecise
#include<stdio.h>
#define N 9

int isSafe(int grid[N][N], int row, int col, int num){

    int i, j;

    for (i = 0; i < N; i++)
        if (grid[row][i] == num)
            return 0;

    for (j = 0; j < N; j++)
        if (grid[j][col] == num)
            return 0;

    int boxRow = row - row % 3;
    int boxCol = col - col % 3;

    for (i = 0; i < 3; i++)
        for (j = 0; j < 3; j++)
            if (grid[i + boxRow][j + boxCol] == num)
                return 0;

    return 1;
}

int solveSudoku(int grid[N][N]){

    int row, col;
    int flag = 0;

    for (row = 0; row < N; row++){
        for (col = 0; col < N; col++){
            if (grid[row][col] == 0){
                flag = 1;
                break;
            }
        }
        if (flag == 1)
            break;
    }

    if (row == N && col == N)
        return 1;

    int num;

    for (num = 1; num <= 9; num++){
        if (isSafe(grid, row, col, num)){
            grid[row][col] = num;

            if (solveSudoku(grid))
                return 1;

            grid[row][col] = 0;
        }
    }

    return 0;
}

void printGrid(int grid[N][N]){

    int i, j;

    printf("Sudoku solved!\n\n");

    for (i = 0; i < N; i++){
        for (j = 0; j < N; j++)
            printf("%d ", grid[i][j]);
        printf("\n");
    }
}

int main(){

    int grid[N][N] = { { 3, 0, 6, 5, 0, 8, 4, 0, 0 },
                       { 5, 2, 0, 0, 0, 0, 0, 0, 0 },
                       { 0, 8, 7, 0, 0, 0, 0, 3, 1 },
                       { 0, 0, 3, 0, 0, 0, 0, 2, 0 },
                       { 9, 0, 0, 8, 0, 0, 0, 0, 5 },
                       { 0, 5, 0, 0, 4, 0, 0, 0, 0 },
                       { 0, 0, 0, 0, 0, 0, 0, 7, 4 },
                       { 0, 0, 5, 2, 0, 6, 3, 0, 0 },
                       { 0, 0, 0, 0, 0, 0, 0, 0, 0 } };

    if (solveSudoku(grid) == 1)
        printGrid(grid);
    else
        printf("Sudoku cannot be solved!\n");

    return 0;
}