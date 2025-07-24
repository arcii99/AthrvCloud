//FormAI DATASET v1.0 Category: Sudoku solver ; Style: scalable
#include <stdio.h>

#define ROWS 9
#define COLS 9

int grid[ROWS][COLS] = {
    {0,3,0,0,0,0,0,7,0},
    {1,9,0,0,0,0,0,0,0},
    {0,8,0,5,0,2,0,0,0},
    {0,0,0,0,3,0,6,0,0},
    {4,0,6,8,0,0,0,2,0},
    {0,0,0,0,9,0,0,0,5},
    {0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,6,9,0,0},
    {0,0,0,0,0,0,0,0,0}
};

void printGrid() {
    for(int r = 0; r < ROWS; r++) {
        for(int c = 0; c < COLS; c++)
            printf("%d ", grid[r][c]);
        printf("\n");
    }
    printf("\n");
}

int findEmpty(int* row, int* col) {
    for(int r = 0; r < ROWS; r++)
        for(int c = 0; c < COLS; c++)
            if(grid[r][c] == 0) {
                *row = r;
                *col = c;
                return 1;
            }
    return 0;
}

int isValid(int num, int row, int col) {
    for(int i = 0; i < 9; i++) {
        if(grid[row][i] == num)
            return 0;
        if(grid[i][col] == num)
            return 0;
    }
    int boxRow = row - (row % 3);
    int boxCol = col - (col % 3);
    for(int r = boxRow; r < boxRow + 3; r++)
        for(int c = boxCol; c < boxCol + 3; c++)
            if(grid[r][c] == num)
                return 0;
    return 1;
}

int solve() {
    int row, col;
    if(!findEmpty(&row, &col))
        return 1;
    for(int num = 1; num <= 9; num++) {
        if(isValid(num, row, col)) {
            grid[row][col] = num;
            if(solve())
                return 1;
            grid[row][col] = 0;
        }
    }
    return 0;
}

int main() {
    printf("Original Grid: \n");
    printGrid();
    printf("Solved Grid: \n");
    if(solve())
        printGrid();
    else
        printf("No Solution Exists \n");
    return 0;
}