//FormAI DATASET v1.0 Category: Sudoku solver ; Style: secure
#include<stdio.h> 

#define N 9 

int found_blank(int grid[N][N], int *row, int *col) 
{ 
    for (*row = 0; *row < N; (*row)++) {
        for (*col = 0; *col < N; (*col)++) { 
            if (grid[*row][*col] == 0) {
                return 1; 
            } 
        }
    }
    return 0; 
} 

int is_safe(int grid[N][N], int row, int col, int num) 
{ 
    int i, j; 

    //check row and column
    for (i = 0; i < N; i++) {
        if (grid[row][i] == num || grid[i][col] == num) {
            return 0; 
        }
    }

    //check sub-grid
    int row_start = (row/3) * 3; 
    int col_start = (col/3) * 3; 
    for (i = row_start; i < row_start + 3; i++) {
        for (j = col_start; j < col_start + 3; j++) {
            if (grid[i][j] == num) {
                return 0; 
            }
        }
    }
    return 1; 
} 

int solve_sudoku(int grid[N][N]) 
{ 
    int row, col; 

    if (!found_blank(grid, &row, &col)) {
        return 1; 
    }

    int num; 
    for (num = 1; num <= N; num++) { 

        if (is_safe(grid, row, col, num) == 1) { 

            grid[row][col] = num; 

            if (solve_sudoku(grid) == 1) {
                return 1; 
            }

            grid[row][col] = 0; 
        } 
    } 
    return 0; 
} 

void print_grid(int grid[N][N]) 
{ 
    int i, j;
    printf("\n\nSolution: \n");
    for (i = 0; i < N; i++) { 
        for (j = 0; j < N; j++) {
            printf("%d ", grid[i][j]); 
        }
        printf("\n"); 
    } 
} 

int main() 
{ 
    int grid[N][N] = {{3, 0, 6, 5, 0, 8, 4, 0, 0}, 
                      {5, 2, 0, 0, 0, 0, 0, 0, 0}, 
                      {0, 8, 7, 0, 0, 0, 0, 3, 1}, 
                      {0, 0, 3, 0, 0, 0, 0, 2, 0}, 
                      {9, 0, 0, 8, 0, 0, 0, 0, 5}, 
                      {0, 5, 0, 0, 0, 0, 6, 0, 0}, 
                      {1, 3, 0, 0, 0, 0, 0, 0, 0}, 
                      {0, 0, 0, 0, 4, 0, 0, 0, 0}, 
                      {0, 0, 0, 0, 0, 0, 0, 0, 0}}; 

    if (solve_sudoku(grid) == 1) {
        print_grid(grid); 
    } 
    else {
        printf("No solution exists for the given Sudoku puzzle.\n"); 
    }

    return 0; 
}