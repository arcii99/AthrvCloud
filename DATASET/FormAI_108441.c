//FormAI DATASET v1.0 Category: Sudoku solver ; Style: happy
#include <stdio.h>

// Function to check if the number is valid
int checkNumber(int arr[9][9], int row, int col, int n) {
    int i, j;
    // Check if the number is present in the row or column
    for (i = 0; i < 9; i++) {
        if (arr[row][i] == n || arr[i][col] == n)
            return 0;
    }
    // Check if the number is present in the 3x3 box
    int box_row = row - row % 3;
    int box_col = col - col % 3;
    for (i = box_row; i < box_row + 3; i++)
        for (j = box_col; j < box_col + 3; j++)
            if (arr[i][j] == n)
                return 0;
    return 1;
}

// Function to solve the Sudoku
int solveSudoku(int arr[9][9], int row, int col) {
    // If we have reached the last column of the last row, we have solved the Sudoku
    if (row == 8 && col == 9) {
        return 1;
    }
    // If we have reached the last column of a row, move to the next row
    if (col == 9) {
        row++;
        col = 0;
    }
    // If the current cell is already filled, move to the next cell
    if (arr[row][col] != 0) {
        return solveSudoku(arr, row, col + 1);
    }
    // Try each number from 1 to 9
    int n;
    for (n = 1; n <= 9; n++) {
        // Check if the number is valid
        if (checkNumber(arr, row, col, n)) {
            arr[row][col] = n;
            // Try to solve the Sudoku recursively
            if (solveSudoku(arr, row, col + 1)) {
                return 1;
            }
        }
    }
    // If none of the numbers work, backtrack and try a different number
    arr[row][col] = 0;
    return 0;
}

// Main function
int main() {
    // Creating a Sudoku board to solve
    int arr[9][9] = {
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

    // Print the original Sudoku board
    printf("Original Sudoku Board:\n");
    int i, j;
    for (i = 0; i < 9; i++) {
        for (j = 0; j < 9; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    // If the Sudoku is solved, print the solved board
    if (solveSudoku(arr, 0, 0)) {
        printf("\nSolved Sudoku Board:\n");
        for (i = 0; i < 9; i++) {
            for (j = 0; j < 9; j++) {
                printf("%d ", arr[i][j]);
            }
            printf("\n");
        }
    } else {
        printf("\nSorry, we could not solve the Sudoku!\n");
    }
    return 0;
}