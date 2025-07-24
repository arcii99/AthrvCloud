//FormAI DATASET v1.0 Category: Sudoku solver ; Style: peaceful
#include <stdio.h>

void print(int arr[9][9]) {
    int i, j;
    for(i = 0; i < 9; i++) {
        for(j = 0; j < 9; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

int findEmpty(int arr[9][9], int row, int col) {
    int i, j, flag = 0;
    for(i = row; i < 9; i++) {
        for(j = col; j < 9; j++) {
            if(arr[i][j] == 0) {
                flag = 1;
                break;
            }
        }
        if(flag == 1) {
            break;
        }
        col = 0;
    }
    if(flag == 1) {
        return i*10 + j;
    }
    else {
        return -1;
    }
}

int check(int arr[9][9], int row, int col, int num) {
    int i, j, rowStart, colStart;
    for(i = 0; i < 9; i++) {
        if(arr[row][i] == num) {
            return 0;
        }
        if(arr[i][col] == num) {
            return 0;
        }
    }
    rowStart = (row/3)*3;
    colStart = (col/3)*3;
    for(i = rowStart; i < rowStart+3; i++) {
        for(j = colStart; j < colStart+3; j++) {
            if(arr[i][j] == num) {
                return 0;
            }
        }
    }
    return 1;
}

int solve(int arr[9][9], int row, int col) {
    int i, num;
    if(row == 9) {
        return 1;
    }
    if(col == 9) {
        return solve(arr, row+1, 0);
    }
    if(arr[row][col] != 0) {
        return solve(arr, row, col+1);
    }
    for(i = 1; i <= 9; i++) {
        if(check(arr, row, col, i) == 1) {
            arr[row][col] = i;
            if(solve(arr, row, col+1) == 1) {
                return 1;
            }
            arr[row][col] = 0;
        }
    }
    return 0;
}

int main() {
    int i, j, arr[9][9] = { {6, 0, 0, 1, 0, 7, 0, 0, 8},
                            {0, 0, 8, 3, 0, 9, 1, 0, 0},
                            {0, 3, 0, 0, 0, 0, 0, 4, 0},
                            {0, 5, 0, 0, 3, 0, 0, 9, 0},
                            {0, 0, 9, 0, 5, 0, 8, 0, 0},
                            {0, 4, 0, 0, 6, 0, 0, 2, 0},
                            {0, 6, 0, 0, 0, 0, 0, 5, 0},
                            {0, 0, 7, 4, 0, 8, 9, 0, 0},
                            {4, 0, 0, 0, 0, 0, 0, 0, 2} };
    printf("Given Sudoku Puzzle\n");
    print(arr);
    printf("\nSolution of the Puzzle\n");
    if(solve(arr, 0, 0) == 1) {
        print(arr);
    }
    else {
        printf("No Solution Exists!!\n");
    }
    return 0;
}