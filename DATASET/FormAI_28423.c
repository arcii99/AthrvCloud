//FormAI DATASET v1.0 Category: Sudoku solver ; Style: realistic
#include <stdio.h>
#include <stdbool.h>
#define SIZE 9

bool checkRow(int puzzle[SIZE][SIZE], int row, int num) {
    for(int i=0; i<SIZE; i++) {
        if(puzzle[row][i] == num) {
            return false;
        }
    }
    return true;
}

bool checkColumn(int puzzle[SIZE][SIZE], int col, int num) {
    for(int i=0; i<SIZE; i++) {
        if(puzzle[i][col] == num) {
            return false;
        }
    }
    return true;
}

bool checkBox(int puzzle[SIZE][SIZE], int row, int col, int num) {
    int boxRow = row - (row % 3);
    int boxCol = col - (col % 3);
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            if(puzzle[i+boxRow][j+boxCol] == num) {
                return false;
            }
        }
    }
    return true;
}

bool isValid(int puzzle[SIZE][SIZE], int row, int col, int num) {
    if(checkRow(puzzle, row, num) && checkColumn(puzzle, col, num) && checkBox(puzzle, row, col, num)) {
        return true;
    } else {
        return false;
    }
}

bool findUnassigned(int puzzle[SIZE][SIZE], int* row, int* col) {
    for(*row=0; *row<SIZE; (*row)++) {
        for(*col=0; *col<SIZE; (*col)++) {
            if(puzzle[*row][*col] == 0) {
                return true;
            }
        }
    }
    return false;
}

bool solvePuzzle(int puzzle[SIZE][SIZE]) {
    int row, col;
    if(!findUnassigned(puzzle, &row, &col)) {
        return true;
    }
    for(int i=1; i<=SIZE; i++) {
        if(isValid(puzzle, row, col, i)) {
            puzzle[row][col] = i;
            if(solvePuzzle(puzzle)) {
                return true;
            }
            puzzle[row][col] = 0;
        }
    }
    return false;
}

void printPuzzle(int puzzle[SIZE][SIZE]) {
    printf("Sudoku Puzzle:\n");
    for(int i=0; i<SIZE; i++) {
        for(int j=0; j<SIZE; j++) {
            printf("%d ", puzzle[i][j]);
        }
        printf("\n");
    }
    printf("----------------\n");
}

int main() {
    int puzzle[SIZE][SIZE] = {{1, 0, 7, 3, 0, 0, 0, 0, 0},
                              {9, 0, 0, 0, 0, 7, 0, 0, 3},
                              {0, 0, 8, 0, 4, 6, 0, 0, 0},
                              {2, 3, 0, 5, 0, 0, 0, 6, 0},
                              {0, 8, 0, 0, 3, 0, 0, 0, 1},
                              {7, 0, 0, 0, 6, 0, 0, 0, 0},
                              {6, 0, 0, 0, 8, 3, 0, 0, 0},
                              {0, 0, 0, 2, 0, 0, 8, 9, 0},
                              {0, 0, 0, 9, 0, 0, 0, 0, 0}};

    printPuzzle(puzzle);
    if(solvePuzzle(puzzle)) {
        printf("Solved Puzzle:\n");
        printPuzzle(puzzle);
    } else {
        printf("Error: Puzzle could not be solved\n");
    }
    return 0;
}