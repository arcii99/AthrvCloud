//FormAI DATASET v1.0 Category: Sudoku solver ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

// Size of the Sudoku board
#define DIMENSION 9

// The Sudoku board
int sudoku[DIMENSION][DIMENSION];

// Function to print the Sudoku board
void print_board() {
    for (int i = 0; i < DIMENSION; i++) {
        for (int j = 0; j < DIMENSION; j++) {
            printf("%d ", sudoku[i][j]);
        }
        printf("\n");
    }
}

// Function to check if a value can be placed at a given position
bool can_place(int row, int col, int value) {
    // Check the row
    for (int j = 0; j < DIMENSION; j++) {
        if (sudoku[row][j] == value) {
            return false;
        }
    }
    // Check the column
    for (int i = 0; i < DIMENSION; i++) {
        if (sudoku[i][col] == value) {
            return false;
        }
    }
    // Check the subgrid
    int subgrid_row = (row / 3) * 3;
    int subgrid_col = (col / 3) * 3;
    for (int i = subgrid_row; i < subgrid_row + 3; i++) {
        for (int j = subgrid_col; j < subgrid_col + 3; j++) {
            if (sudoku[i][j] == value) {
                return false;
            }
        }
    }
    return true;
}

// Function to generate a random number in a given range
int random_range(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

// Function to solve the Sudoku puzzle
bool solve(int row, int col) {
    if (row == DIMENSION) {
        return true;
    }
    if (col == DIMENSION) {
        return solve(row+1, 0);
    }
    if (sudoku[row][col] != 0) {
        return solve(row, col+1);
    }
    for (int value = 1; value <= 9; value++) {
        if (can_place(row, col, value)) {
            sudoku[row][col] = value;
            if (solve(row, col+1)) {
                return true;
            }
            sudoku[row][col] = 0;
        }
    }
    return false;
}

// Driver function
int main() {
    srand(time(0));
    // Generate a partially filled Sudoku board
    int num_cells = random_range(30, 40);
    for (int i = 0; i < num_cells; i++) {
        int row = random_range(0, 8);
        int col = random_range(0, 8);
        int value = random_range(1, 9);
        if (can_place(row, col, value)) {
            sudoku[row][col] = value;
        }
    }
    // Print the partially filled board
    printf("Partially filled board:\n");
    print_board();
    // Solve the Sudoku puzzle
    if (solve(0, 0)) {
        printf("\nSolution:\n");
        print_board();
    } else {
        printf("\nNo solution!\n");
    }
    return 0;
}