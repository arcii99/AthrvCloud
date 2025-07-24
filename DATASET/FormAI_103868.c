//FormAI DATASET v1.0 Category: Sudoku solver ; Style: beginner-friendly
#include <stdio.h>

// Function to check if it's legal to assign the given number at given (row, col) index
int isSafe(int board[9][9], int row, int col, int num) {
    // check if the given number is already present in the given row OR column OR box
    for (int i = 0; i < 9; i++)
        if (board[row][i] == num || board[i][col] == num || board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == num)
            return 0;
    return 1;
}

// Function to solve the given sudoku board using backtracking algorithm
int solveSudoku(int board[9][9]) {
    int row, col, flag = 0;
    // Find an unassigned cell in the sudoku board, if it's not present then the board is solved
    for (row = 0; row < 9; row++) {
        for (col = 0; col < 9; col++) {
            if (board[row][col] == 0) {
                flag = 1;
                break;
            }
        }
        if (flag) break;
    }
    // If all cells are assigned, the sudoku board is solved
    if (!flag) return 1;
    // Try assigning numbers from 1 to 9 into the unassigned cell
    for (int num = 1; num <= 9; num++) {
        // If it is safe to assign the given number at given (row, col) index
        if (isSafe(board, row, col, num)) {
            // assign the number and recursively check for remaining cells
            board[row][col] = num;
            if (solveSudoku(board))
                return 1;
            // reset the cell if the assigned number doesn't lead to the solution
            board[row][col] = 0;
        }
    }
    return 0;
}

// Function to print the solved sudoku board
void printSudoku(int board[9][9]) {
    for (int row = 0; row < 9; row++) {
        for (int col = 0; col < 9; col++) {
            printf("%d ", board[row][col]);
            if (col == 2 || col == 5) printf("| "); // add vertical separator after every 3rd and 6th column
        }
        printf("\n");
        if (row == 2 || row == 5) printf("---------------------\n"); // add horizontal separator after every 3rd and 6th row
    }
}

int main() {
    int board[9][9] = {
            {9, 0, 7, 4, 8, 0, 0, 0, 1}, 
            {6, 0, 0, 0, 0, 0, 0, 2, 0},
            {0, 0, 0, 0, 0, 5, 0, 6, 0},
            {0, 0, 0, 0, 0, 0, 4, 0, 0},
            {4, 2, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 1, 8, 0, 0, 0, 0, 5},
            {0, 0, 0, 3, 2, 0, 7, 4, 0},
            {0, 4, 0, 0, 1, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 5, 0, 0}
    };
    if (solveSudoku(board))
        printSudoku(board);
    else
        printf("No solution exists for the given sudoku board\n");
    return 0;
}