//FormAI DATASET v1.0 Category: Sudoku solver ; Style: irregular
#include <stdio.h>

// This solver uses a randomized approach,
// traversing through the rows and columns of the
// Sudoku board one by one, seeking a solution.

void printBoard(int board[9][9]) {
    // Print the Sudoku board in a readable format.
    printf("Sudoku board:\n");
    for (int i = 0; i < 9; i++) {
        if (i % 3 == 0 && i != 0) {
            printf("-------------------\n");
        }
        for (int j = 0; j < 9; j++) {
            if (j % 3 == 0 && j != 0) {
                printf("| ");
            }
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int isValid(int board[9][9], int row, int col, int num) {
    // Check if placing the number 'num' in the given row and column
    // is valid according to the Sudoku rules.
    for (int i = 0; i < 9; i++) {
        // Check the row and column
        if (board[row][i] == num || board[i][col] == num) {
            return 0;
        }
        // Check the 3x3 square
        int squareRow = 3 * (row / 3) + (i / 3);
        int squareCol = 3 * (col / 3) + (i % 3);
        if (board[squareRow][squareCol] == num) {
            return 0;
        }
    }
    return 1;
}

int solve(int board[9][9], int row, int col) {
    // The recursive Sudoku solver. The variable 'row'
    // represents the current row being visited, and 'col'
    // represents the current column.
    if (row == 9) {
        // Base case: the solver has reached the end of the board,
        // meaning the Sudoku has been solved successfully.
        return 1;
    }
    int nextRow = row;
    int nextCol = col + 1;
    if (nextCol == 9) {
        nextRow++;
        nextCol = 0;
    }
    if (board[row][col] != 0) {
        // If the current cell is already filled in, move on to the next one.
        return solve(board, nextRow, nextCol);
    }
    // Otherwise, try out all the numbers from 1 to 9.
    for (int i = 1; i <= 9; i++) {
        if (isValid(board, row, col, i)) {
            // If the current number is valid, place it in the current cell
            // and move on to the next cell.
            board[row][col] = i;
            if (solve(board, nextRow, nextCol)) {
                return 1;
            }
        }
    }
    // If none of the numbers are valid, reset the current cell and return 0 to backtrack.
    board[row][col] = 0;
    return 0;
}

void shuffleArray(int arr[], int n) {
    // Shuffle an array of integers using the Fisher-Yates algorithm.
    for (int i = n - 1; i >= 1; i--) {
        int j = rand() % (i + 1);
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

void generateBoard(int board[9][9]) {
    // Generate a Sudoku board with a randomized solution, using a backtracking algorithm.
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            board[i][j] = 0;
        }
    }
    int nums[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    shuffleArray(nums, 9);
    solve(board, 0, 0);
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (rand() % 2 == 0) {
                int temp = board[i][j];
                board[i][j] = 0;
                int temp2 = solve(board, 0, 0);
                if (temp2 != 1) {
                    board[i][j] = temp;
                }
            }
        }
    }
}

int main() {
    // Create a Sudoku board and solve it.
    int board[9][9];
    generateBoard(board);
    printBoard(board);
    solve(board, 0, 0);
    printf("Solved Sudoku board:\n");
    printBoard(board);
    return 0;
}