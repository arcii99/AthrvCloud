//FormAI DATASET v1.0 Category: Sudoku solver ; Style: random
#include <stdio.h>

// Function to check if the current cell can contain a certain value
int canPlace(int puzzle[][9], int row, int col, int num) {
    // Check if the number exists in the same row
    for (int i = 0; i < 9; i++) {
        if (puzzle[row][i] == num) {
            return 0;
        }
    }

    // Check if the number exists in the same column
    for (int i = 0; i < 9; i++) {
        if (puzzle[i][col] == num) {
            return 0;
        }
    }

    // Check if the number exists in the same 3x3 box
    int boxRow = row - (row % 3);
    int boxCol = col - (col % 3);

    for (int i = boxRow; i < boxRow + 3; i++) {
        for (int j = boxCol; j < boxCol + 3; j++) {
            if (puzzle[i][j] == num) {
                return 0;
            }
        }
    }

    return 1;
}

// Function to solve the Sudoku puzzle
int solveSudoku(int puzzle[][9], int row, int col) {
    // Check if we have reached the end of the puzzle
    if (row == 9) {
        return 1;
    }

    // Check if we have reached the end of the current row
    if (col == 9) {
        return solveSudoku(puzzle, row + 1, 0);
    }

    // Check if the current cell is already filled
    if (puzzle[row][col] != 0) {
        return solveSudoku(puzzle, row, col + 1);
    }

    // Check the possible values for the current cell
    for (int i = 1; i <= 9; i++) {
        if (canPlace(puzzle, row, col, i)) {
            puzzle[row][col] = i;

            if (solveSudoku(puzzle, row, col + 1)) {
                return 1;
            }

            puzzle[row][col] = 0;
        }
    }

    return 0;
}

// Function to print the solved Sudoku puzzle
void printSolution(int puzzle[][9]) {
    printf("Solved Sudoku Puzzle:\n");

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            printf("%d ", puzzle[i][j]);
        }

        printf("\n");
    }
}

// Driver code
int main() {
    int puzzle[9][9] = {
        {8, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 3, 6, 0, 0, 0, 0, 0},
        {0, 7, 0, 0, 9, 0, 2, 0, 0},
        {0, 5, 0, 0, 0, 7, 0, 0, 0},
        {0, 0, 0, 0, 4, 5, 7, 0, 0},
        {0, 0, 0, 1, 0, 0, 0, 3, 0},
        {0, 0, 1, 0, 0, 0, 0, 6, 8},
        {0, 0, 8, 5, 0, 0, 0, 1, 0},
        {0, 9, 0, 0, 0, 0, 4, 0, 0}
    };

    if (solveSudoku(puzzle, 0, 0)) {
        printSolution(puzzle);
    } else {
        printf("Unable to solve the Sudoku puzzle.\n");
    }

    return 0;
}