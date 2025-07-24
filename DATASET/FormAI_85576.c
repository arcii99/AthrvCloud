//FormAI DATASET v1.0 Category: Sudoku solver ; Style: mathematical
#include <stdio.h>

// Function to print the Sudoku board
void printBoard(int board[9][9]) {
    printf("\n+---+---+---+\n");

    for (int i = 0; i < 9; i++) {
        printf("| ");

        for (int j = 0; j < 9; j++) {
            printf("%d ", board[i][j]);

            if (j % 3 == 2) {
                printf("| ");
            }
        }

        if (i % 3 == 2) {
            printf("\n+---+---+---+\n");
        } else {
            printf("\n");
        }
    }
}

// Function to check if a value is valid in the given row and column of the board
int isValid(int board[9][9], int row, int col, int value) {
    // Check row
    for (int i = 0; i < 9; i++) {
        if (board[row][i] == value) {
            return 0;
        }
    }

    // Check column
    for (int i = 0; i < 9; i++) {
        if (board[i][col] == value) {
            return 0;
        }
    }

    // Check 3x3 box
    int box_row = (row / 3) * 3; // Top row of box
    int box_col = (col / 3) * 3; // Left column of box

    for (int i = box_row; i < box_row + 3; i++) {
        for (int j = box_col; j < box_col + 3; j++) {
            if (board[i][j] == value) {
                return 0;
            }
        }
    }

    // Value is valid
    return 1;
}

// Recursive function to solve the Sudoku board
int solveBoard(int board[9][9], int row, int col) {
    // Base case: If we have filled out all the columns, go to the next row
    if (col == 9) {
        row++;
        col = 0;
    }

    // Base case: If we have filled out all the rows, the board is solved
    if (row == 9) {
        return 1;
    }

    // Skip to the next column if this position is already filled
    if (board[row][col] != 0) {
        return solveBoard(board, row, col+1);
    }

    // Try each possible value for this position
    for (int value = 1; value <= 9; value++) {
        // Check if this value is valid
        if (isValid(board, row, col, value)) {
            // Try this value and run the solver recursively
            board[row][col] = value;

            if (solveBoard(board, row, col+1)) {
                // If the rest of the board is solvable with this value, we're done!
                return 1;
            }

            // Undo this choice and try the next possible value
            board[row][col] = 0;
        }
    }

    // None of the values worked, backtrack
    return 0;
}

int main() {
    // Example board to solve
    int board[9][9] = {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}
    };

    printf("Sudoku board to solve:\n");
    printBoard(board);

    // Solve the board
    solveBoard(board, 0, 0);

    printf("\nSolved Sudoku board:\n");
    printBoard(board);

    return 0;
}