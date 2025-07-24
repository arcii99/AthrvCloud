//FormAI DATASET v1.0 Category: Sudoku solver ; Style: energetic
#include <stdio.h>
#define N 9

// function to check if the number is valid or not
int is_valid(int grid[N][N], int row, int col, int num)
{
    // check in the same row
    for(int i=0; i<N; i++) {
        if(grid[row][i] == num) {
            return 0;
        }
    }

    // check in the same column
    for(int i=0; i<N; i++) {
        if(grid[i][col] == num) {
            return 0;
        }
    }

    // check in the same 3x3 grid
    int start_row = (row/3)*3;
    int start_col = (col/3)*3;

    for(int i=start_row; i<start_row+3; i++) {
        for(int j=start_col; j<start_col+3; j++) {
            if(grid[i][j] == num) {
                return 0;
            }
        }
    }

    return 1;
}

// function to solve the sudoku puzzle
int solve_sudoku(int grid[N][N], int row, int col)
{
    // if we have solved all the cells
    if(row == N-1 && col == N) {
        return 1;
    }

    // if we have reached the end of the row
    if(col == N) {
        row++;
        col = 0;
    }

    // if the cell is already filled
    if(grid[row][col] != 0) {
        return solve_sudoku(grid, row, col+1);
    }

    // try all possible numbers from 1 to 9
    for(int num=1; num<=9; num++) {
        if(is_valid(grid, row, col, num)) {
            grid[row][col] = num;
            
            if(solve_sudoku(grid, row, col+1)) {
                return 1;
            }
            
            grid[row][col] = 0;
        }
    }
    
    return 0;
}

int main()
{
    int grid[N][N] = {{0, 0, 0, 0, 2, 0, 0, 5, 0},
                      {0, 0, 0, 0, 0, 8, 0, 0, 0},
                      {7, 0, 0, 0, 0, 0, 0, 9, 0},
                      {0, 0, 0, 0, 0, 0, 0, 0, 4},
                      {0, 0, 3, 2, 4, 0, 0, 0, 5},
                      {0, 4, 0, 0, 0, 0, 0, 0, 0},
                      {0, 7, 8, 0, 0, 0, 0, 1, 0},
                      {0, 0, 0, 9, 0, 0, 0, 0, 0},
                      {0, 9, 0, 0, 0, 6, 0, 0, 0}};

    printf("Sudoku puzzle to be solved:\n\n");
    
    // print the initial sudoku puzzle
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
    
    // solve the sudoku puzzle
    if(solve_sudoku(grid, 0, 0)) {
        printf("\n\nSudoku puzzle solved:\n\n");
        
        // print the solved sudoku puzzle
        for(int i=0; i<N; i++) {
            for(int j=0; j<N; j++) {
                printf("%d ", grid[i][j]);
            }
            printf("\n");
        }
    }
    else {
        printf("\n\nNo solution exists.\n");
    }

    return 0;
}