//FormAI DATASET v1.0 Category: Sudoku solver ; Style: safe
#include <stdio.h>

#define N 9

/* Check if the number can be placed in the given position in the sudoku grid */
int isValid(int grid[N][N], int row, int col, int num) {
    for (int i = 0; i < N; i++) {
        if (grid[row][i] == num || grid[i][col] == num) {
            /* If the number already exists in the same row or column */
            return 0;
        }
    }
    
    /* Check in the same 3x3 box */
    int x = row - row % 3;
    int y = col - col % 3;
    for (int i = x; i < x + 3; i++) {
        for (int j = y; j < y + 3; j++) {
            if (grid[i][j] == num) {
                return 0;
            }
        }
    }
    
    return 1;
}

/* Solve the sudoku grid */
int solveSudoku(int grid[N][N]) {
    int row, col, flag = 0;
    for (row = 0; row < N; row++) {
        for (col = 0; col < N; col++) {
            if (grid[row][col] == 0) { /* Check for empty cell */
                flag = 1;
                break;
            }
        }
        if (flag) {
            break;
        }
    }
    if (!flag) {
        return 1; /* Solution found */
    }
    
    /* Try placing numbers in the empty cell */
    for (int num = 1; num <= 9; num++) {
        if (isValid(grid, row, col, num)) {
            grid[row][col] = num;
            
            if (solveSudoku(grid)) {
                return 1;
            }
            
            grid[row][col] = 0; /* Backtrack */
        }
    }
    
    return 0; /* No solution found */
}

/* Print the sudoku grid */
void printSudoku(int grid[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int grid[N][N] = {{0, 0, 0, 2, 6, 0, 7, 0, 1},
                      {6, 8, 0, 0, 7, 0, 0, 9, 0},
                      {1, 9, 0, 0, 0, 4, 5, 0, 0},
                      {8, 2, 0, 1, 0, 0, 0, 4, 0},
                      {0, 0, 4, 6, 0, 2, 9, 0, 0},
                      {0, 5, 0, 0, 0, 3, 0, 2, 8},
                      {0, 0, 9, 3, 0, 0, 0, 7, 4},
                      {0, 4, 0, 0, 5, 0, 0, 3, 6},
                      {7, 0, 3, 0, 1, 8, 0, 0, 0}};
    
    printf("Sudoku puzzle:\n");
    printSudoku(grid);
    
    if (solveSudoku(grid)) {
        printf("\nSudoku solution:\n");
        printSudoku(grid);
    } else {
        printf("\nNo solution found.\n");
    }
    
    return 0;
}