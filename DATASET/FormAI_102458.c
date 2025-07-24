//FormAI DATASET v1.0 Category: Sudoku solver ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int grid[9][9]; // initialize the 9x9 grid

// function to print the Sudoku grid
void printGrid() {
    printf("\n\n");
    for(int i = 0; i < 9; i++) {
        if(i % 3 == 0) {
            printf("---+---+---\n"); // prints separator lines for every three rows
        }
        for(int j = 0; j < 9; j++) {
            if(j % 3 == 0) {
                printf("|"); // prints separator lines for every three columns
            }

            if(grid[i][j] == 0) {
                printf(" "); // empty cells are represented by a space
            } else {
                printf("%d", grid[i][j]); // prints the value of the cell
            }
        }
        printf("|\n"); // closes the row
    }
    printf("---+---+---\n"); // prints the footer
}

// function to check if a number can be placed in a specific grid position
bool isSafe(int row, int col, int num) {
    // check if the number is already present in the row
    for(int j = 0; j < 9; j++) {
        if(grid[row][j] == num) {
            return false;
        }
    }

    // check if the number is already present in the column
    for(int i = 0; i < 9; i++) {
        if(grid[i][col] == num) {
            return false;
        }
    }

    // check if the number is already present in the 3x3 grid
    int startRow = row - row % 3;
    int startCol = col - col % 3;

    for(int i = startRow; i < startRow + 3; i++) {
        for(int j = startCol; j < startCol + 3; j++) {
            if(grid[i][j] == num) {
                return false;
            }
        }
    }

    return true;
}

// recursive function to solve Sudoku
bool solveSudoku() {
    int row = -1;
    int col = -1;
    bool isEmpty = true;

    // finds the next empty cell in the grid
    for(int i = 0; i < 9; i++) {
        for(int j = 0; j < 9; j++) {
            if(grid[i][j] == 0) {
                row = i;
                col = j;

                isEmpty = false;
                break;
            }
        }
        if(!isEmpty) {
            break;
        }
    }

    // if no empty cell is found, the grid is solved
    if(isEmpty) {
        return true;
    }

    // tries to place a number in the empty cell
    for(int num = 1; num <= 9; num++) {
        if(isSafe(row, col, num)) {
            grid[row][col] = num; // set the cell's value to the number

            if(solveSudoku()) { // recursively tries to solve the rest of the grid
                return true;
            }

            grid[row][col] = 0; // backtracks by resetting the cell's value to 0
        }
    }

    return false; // returns false if no solution is found
}

int main() {
    // initialize the grid with a post-apocalyptic scenario
    grid[0][2] = 9;
    grid[0][5] = 3;

    grid[1][0] = 5;
    grid[1][1] = 3;
    grid[1][7] = 2;

    grid[2][1] = 8;
    grid[2][4] = 1;
    grid[2][6] = 6;

    grid[3][0] = 4;
    grid[3][3] = 7;
    grid[3][5] = 5;
    grid[3][8] = 3;

    grid[4][1] = 7;
    grid[4][2] = 6;
    grid[4][6] = 9;
    grid[4][7] = 1;

    grid[5][0] = 3;
    grid[5][3] = 1;
    grid[5][5] = 9;
    grid[5][8] = 5;

    grid[6][2] = 2;
    grid[6][4] = 4;
    grid[6][7] = 7;

    grid[7][1] = 9;
    grid[7][7] = 4;
    grid[7][8] = 1;

    grid[8][3] = 8;
    grid[8][6] = 3;

    printf("In a post-apocalyptic world, the only way to survive is by solving Sudoku puzzles.\n");
    printf("You have come across a partially filled grid. Can you solve it?\n");
    printf("Enter the numbers in empty cells (represented by a space):\n");

    printGrid(); // print the initial grid

    if(solveSudoku()) { // solve the Sudoku puzzle
        printf("\n\nCongratulations! You have solved the Sudoku puzzle and survived another day.\n");
        printGrid();
    } else {
        printf("\n\nSorry, there is no solution for this Sudoku puzzle. You will not survive.\n");
    }

    return 0;
}