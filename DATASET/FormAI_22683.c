//FormAI DATASET v1.0 Category: Sudoku solver ; Style: funny
#include <stdio.h>

// Define the Sudoku dimensions
#define N 9

// Function to print Sudoku grid
void printGrid(int grid[N][N]) {
    printf("Solving the Suduko puzzle, hang in there...\n\n");
    int i,j;
    for (i=0; i<N; i++) {
        for (j=0; j<N; j++)
            printf("%d ", grid[i][j]);
        printf("\n");
    }
}

// Function to check if a cell is safe to place a number
int isSafe(int grid[N][N], int row, int col, int num) {
    int i, j;

    // Check the row for the same number
    for (i=0; i<N; i++)
        if (grid[row][i] == num)
            return 0;

    // Check the column for the same number
    for (i=0; i<N; i++)
        if (grid[i][col] == num)
            return 0;

    // Check the box for the same number
    int boxRow = row - row % 3;
    int boxCol = col - col % 3;
    for (i=0; i<3; i++)
        for (j=0; j<3; j++)
            if (grid[i+boxRow][j+boxCol] == num)
                return 0;

    return 1;
}

// Function to solve Sudoku puzzle
int solveSudoku(int grid[N][N]) {
    int row, col;

    // If all cells are filled, return 1 (puzzle solved)
    for (row=0; row<N; row++)
        for (col=0; col<N; col++)
            if (grid[row][col] == 0)
                goto start;

    // Puzzle is solved
    return 1;

    // Start from the first empty cell
    start:
    for (row=0; row<N; row++) {
        for (col=0; col<N; col++) {

            // If cell is empty, try placing numbers
            if (grid[row][col] == 0) {

                // Try from 1 to 9
                int num;
                for (num=1; num<=9; num++) {

                    // Check if number is safe to place
                    if (isSafe(grid, row, col, num)) {

                        // Place the number, and try to solve the puzzle
                        grid[row][col] = num;

                        if (solveSudoku(grid))
                            return 1;

                        // Solution is not possible, remove the number and try again
                        grid[row][col] = 0;
                    }
                }

                // Nothing has worked, return 0
                return 0;
            }
        }
    }
    return 1;
}

int main() {
    int grid[N][N] = {{0, 0, 0, 0, 0, 0, 5, 0, 0},
                      {0, 9, 0, 5, 4, 0, 0, 0, 8},
                      {0, 4, 0, 0, 6, 0, 0, 9, 0},
                      {0, 0, 0, 0, 0, 0, 9, 0, 0},
                      {3, 0, 7, 6, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0, 0, 0, 0},
                      {1, 3, 0, 0, 0, 0, 0, 7, 0},
                      {0, 0, 0, 3, 0, 7, 0, 0, 4},
                      {0, 0, 0, 0, 0, 0, 0, 8, 0}};

    // Print the initial grid
    printGrid(grid);

    // Try to solve the Sudoku puzzle
    if (solveSudoku(grid) == 1) {
        printf("\nDone! Here is the solved Sudoku puzzle:\n\n");
        printGrid(grid);
    }
    else {
        printf("\nSorry, I couldn't solve the Sudoku puzzle :(\n");
    }

    return 0;
}