//FormAI DATASET v1.0 Category: Sudoku solver ; Style: careful
#include <stdio.h>

#define ROWS 9
#define COLUMNS 9

int sudokuPuzzle[ROWS][COLUMNS] = { // This is the input sudoku puzzle.
    {0, 0, 5, 3, 0, 0, 0, 0, 0},
    {8, 0, 0, 0, 0, 0, 0, 2, 0},
    {0, 7, 0, 0, 1, 0, 5, 0, 0},
    {4, 0, 0, 0, 0, 5, 3, 0, 0},
    {0, 1, 0, 0, 7, 0, 0, 0, 6},
    {0, 0, 3, 2, 0, 0, 0, 8, 0},
    {0, 6, 0, 5, 0, 0, 0, 0, 9},
    {0, 0, 4, 0, 0, 0, 0, 3, 0},
    {0, 0, 0, 0, 0, 9, 7, 0, 0}
};

void printSudokuPuzzle() {
    printf("+-----+-----+-----+\n");
    for (int row = 0; row < ROWS; row++) {
        for (int col = 0; col < COLUMNS; col++) {
            printf("|%d", sudokuPuzzle[row][col]);
        }
        printf("|\n");
        if ((row + 1) % 3 == 0) {
            printf("+-----+-----+-----+\n");
        }
    }
}

int canInsertNumberInCell(int number, int row, int col) {
    for (int i = 0; i < COLUMNS; i++) { // Check if the number exists in this row or not.
        if (sudokuPuzzle[row][i] == number) {
            return 0;
        }
    }
    for (int i = 0; i < ROWS; i++) { // Check if the number exists in this column or not.
        if (sudokuPuzzle[i][col] == number) {
            return 0;
        }
    }
    int squareSize = 3;
    int squareRowStart = row - (row % squareSize);
    int squareColStart = col - (col % squareSize);
    for (int i = squareRowStart; i < squareRowStart + squareSize; i++) {
        for (int j = squareColStart; j < squareColStart + squareSize; j++) {
            if (sudokuPuzzle[i][j] == number) { // Check if the number exists in this 3x3 square or not.
                return 0;
            }
        }
    }
    return 1; // If the number doesn't exist in the row/column/square, then we can insert it in this cell.
}

int solveSudokuPuzzle(int row, int col) {
    if (row == ROWS) { // If the entire puzzle is solved, then return success.
        return 1;
    }
    if (col == COLUMNS) { // If the entire current row is solved, then move to the next row.
        return solveSudokuPuzzle(row + 1, 0);
    }
    if (sudokuPuzzle[row][col] != 0) { // If the cell is already filled, then move to the next cell.
        return solveSudokuPuzzle(row, col + 1);
    }
    for (int number = 1; number <= 9; number++) { // Iterate through numbers 1 to 9 and check if we can insert them in the current cell.
        if (canInsertNumberInCell(number, row, col)) {
            sudokuPuzzle[row][col] = number; // If we can insert the number in this cell, then insert it.
            if (solveSudokuPuzzle(row, col + 1)) { // Move to the next cell and continue solving the puzzle.
                return 1; // If the puzzle is successfully solved, then return success.
            }
            sudokuPuzzle[row][col] = 0; // If inserting this number didn't solve the puzzle, then remove it from this cell and try the next number.
        }
    }
    return 0; // If we couldn't find any valid number to insert in this cell, then return failure.
}

int main() {
    printf("Input Sudoku puzzle:\n");
    printSudokuPuzzle();
    printf("\n\nSolving the Sudoku puzzle...\n");
    if (solveSudokuPuzzle(0, 0)) {
        printf("\nSudoku puzzle solved:\n");
        printSudokuPuzzle();
    } else {
        printf("\nFailed to solve the Sudoku puzzle.\n");
    }
    return 0;
}