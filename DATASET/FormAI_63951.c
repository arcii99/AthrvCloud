//FormAI DATASET v1.0 Category: Sudoku solver ; Style: Dennis Ritchie
#include <stdio.h>

#define N 9

int grid[N][N];

/* Function to check if a number can be placed in a particular cell */
int check(int row, int col, int num) {
    int i, j, row_start, col_start;
    
    /* Check row */
    for (i = 0; i < N; i++) {
        if (grid[row][i] == num) {
            return 0;
        }
    }
    
    /* Check column */
    for (i = 0; i < N; i++) {
        if (grid[i][col] == num) {
            return 0;
        }
    }
    
    /* Check square */
    row_start = (row / 3) * 3;
    col_start = (col / 3) * 3;
    for (i = row_start; i < row_start + 3; i++) {
        for (j = col_start; j < col_start + 3; j++) {
            if (grid[i][j] == num) {
                return 0;
            }
        }
    }
    
    return 1;
}

/* Function to solve the Sudoku puzzle */
int solve() {
    int row, col, num;
    
    for (row = 0; row < N; row++) {
        for (col = 0; col < N; col++) {
            if (grid[row][col] == 0) {
                for (num = 1; num <= N; num++) {
                    if (check(row, col, num)) {
                        grid[row][col] = num;
                        if (solve()) {
                            return 1;
                        } else {
                            grid[row][col] = 0;
                        }
                    }
                }
                return 0;
            }
        }
    }
    
    return 1;
}

/* Function to print the Sudoku puzzle */
void print() {
    int row, col;
    
    for (row = 0; row < N; row++) {
        for (col = 0; col < N; col++) {
            printf("%d ", grid[row][col]);
        }
        printf("\n");
    }
}

/* Main function */
int main() {
    int i, j;
    
    /* Input Sudoku puzzle */
    printf("Enter the Sudoku puzzle (use 0 for empty cells):\n");
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            scanf("%d", &grid[i][j]);
        }
    }
    
    /* Solve the puzzle */
    if (solve()) {
        printf("Solution:\n");
        print();
    } else {
        printf("No solution found.\n");
    }
    
    return 0;
}