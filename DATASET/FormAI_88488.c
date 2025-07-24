//FormAI DATASET v1.0 Category: Sudoku solver ; Style: romantic
#include <stdio.h>

#define N 9
#define UNASSIGNED 0

int grid[N][N] = { 
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

int isSafe(int row, int col, int num) 
{ 
    for (int i = 0; i < N; i++) {
        if (grid[row][i] == num) return 0; 
        if (grid[i][col] == num) return 0; 
    }

    int r = row - row % 3; 
    int c = col - col % 3; 
    for (int i = r; i < r+3; i++) {
        for (int j = c; j < c+3; j++) {
            if (grid[i][j] == num) return 0; 
        }
    }

    return 1; 
} 

int findEmptyCell(int *row, int *col) 
{ 
    for (*row = 0; *row < N; (*row)++) {
        for (*col = 0; *col < N; (*col)++) {
            if (grid[*row][*col] == UNASSIGNED) return 1; 
        }
    }
    return 0; 
} 

int solveSudoku() 
{ 
    int row, col;
    if (!findEmptyCell(&row, &col)) return 1; 

    for (int num = 1; num <= 9; num++) {
        if (isSafe(row, col, num)) {
            grid[row][col] = num;

            if (solveSudoku()) return 1;

            grid[row][col] = UNASSIGNED; 
        }
    } 

    return 0; 
}

int main() 
{ 
    if (solveSudoku()) {
        printf("Sudoku Solution:\n");
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                printf("%d ", grid[i][j]);
            }
            printf("\n");
        }
    }
    else {
        printf("No solution exists");
    }

    return 0; 
}