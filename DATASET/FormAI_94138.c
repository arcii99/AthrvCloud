//FormAI DATASET v1.0 Category: Sudoku solver ; Style: careful
#include <stdio.h>

// Function to check if the given number already exists
int usedInRow(int puzzle[9][9], int row, int num) {
    for (int col = 0; col < 9; col++) {
        if (puzzle[row][col] == num) {
            return 1;
        }
    }
    return 0;
}

// Function to check if the given number already exists
int usedInCol(int puzzle[9][9], int col, int num) {
    for (int row = 0; row < 9; row++) {
        if (puzzle[row][col] == num) {
            return 1;
        }
    }
    return 0;
}

// Function to check if the given number already exists
int usedInBox(int puzzle[9][9], int boxStartRow, int boxStartCol, int num) {
    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 3; col++) {
            if (puzzle[row + boxStartRow][col + boxStartCol] == num) {
                return 1;
            }
        }
    }
    return 0;
}

// Function to check if it's safe to add the number to a position
int isSafe(int puzzle[9][9], int row, int col, int num) {
    return !usedInRow(puzzle, row, num) && !usedInCol(puzzle, col, num) && !usedInBox(puzzle, row - row % 3, col - col % 3, num);
}

// Function to display the solved puzzle
void display(int puzzle[9][9]) {
    for (int row = 0; row < 9; row++) {
        for (int col = 0; col < 9; col++) {
            printf("%d ", puzzle[row][col]);
        }
        printf("\n");
    }
}

// Function to solve the Sudoku puzzle
int solve(int puzzle[9][9], int row, int col) {
    if (row == 9 - 1 && col == 9) {
        return 1;
    }

    if (col == 9) {
        row++;
        col = 0;
    }

    if (puzzle[row][col] > 0) {
        return solve(puzzle, row, col + 1);
    }

    for (int num = 1; num <= 9; num++) {
        if (isSafe(puzzle, row, col, num)) {
            puzzle[row][col] = num;

            if (solve(puzzle, row, col + 1)) {
                return 1;
            }
        }
        puzzle[row][col] = 0;
    }
    return 0;
}

// Main function
int main() {
    int puzzle[9][9] = {{0, 5, 3, 0, 6, 0, 4, 0, 0},
                        {0, 0, 0, 1, 0, 3, 6, 0, 5},
                        {0, 6, 2, 4, 0, 5, 9, 0, 1},
                        {8, 0, 0, 0, 1, 0, 0, 4, 0},
                        {0, 0, 4, 0, 0, 0, 7, 0, 0},
                        {0, 1, 0, 0, 2, 0, 0, 0, 3},
                        {1, 0, 7, 3, 0, 2, 8, 5, 0},
                        {2, 0, 0, 0, 0, 9, 0, 0, 0},
                        {0, 0, 5, 0, 8, 0, 0, 3, 0}};

    if (solve(puzzle, 0, 0)) {
        printf("Solved Puzzle:\n");
        display(puzzle);
    } else {
        printf("Solution does not exist.\n");
    }

    return 0;
}