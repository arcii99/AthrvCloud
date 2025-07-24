//FormAI DATASET v1.0 Category: Sudoku solver ; Style: beginner-friendly
#include <stdio.h>

int checkRow(int row, int num, int puzzle[][9]) {
    for (int col = 0; col < 9; col++) {
        if (puzzle[row][col] == num) {
            return 0;
        }
    }
    return 1;
}

int checkCol(int col, int num, int puzzle[][9]) {
    for (int row = 0; row < 9; row++) {
        if (puzzle[row][col] == num) {
            return 0;
        }
    }
    return 1;
}

int checkBox(int startRow, int startCol, int num, int puzzle[][9]) {
    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 3; col++) {
            if (puzzle[row+startRow][col+startCol] == num) {
                return 0;
            }
        }
    }
    return 1;
}

void printPuzzle(int puzzle[][9]) {
    for (int row = 0; row < 9; row++) {
        for (int col = 0; col < 9; col++) {
            printf("%2d",puzzle[row][col]);
            if (col == 2 || col == 5) {
                printf(" ");
            }
        }
        printf("\n");
        if (row == 2 || row == 5) {
            printf("\n");
        }
    }
}

int solve(int puzzle[][9]) {
    int row, col, num;
    for (row = 0; row < 9; row++) {
        for (col = 0; col < 9; col++) {
            if (puzzle[row][col] == 0) {
                for (num = 1; num <= 9; num++) {
                    if (checkRow(row, num, puzzle) && checkCol(col, num, puzzle) && checkBox(row-row%3, col-col%3, num, puzzle)) {
                        puzzle[row][col] = num;
                        if (solve(puzzle))
                            return 1;
                        puzzle[row][col] = 0;
                    }
                }
                return 0;
            }
        }
    }
    return 1;
}

int main() {
    int puzzle[9][9] = {{0, 0, 0, 9, 0, 0, 0, 5, 0},
                        {7, 0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 9, 0, 0, 8, 0, 0, 0, 0},
                        {0, 0, 0, 7, 0, 5, 0, 0, 0},
                        {1, 0, 7, 0, 0, 0, 4, 0, 0},
                        {0, 0, 4, 0, 3, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 7, 0, 0, 0},
                        {0, 5, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0, 0}};

    printf("Puzzle before solving:\n");
    printPuzzle(puzzle);

    if (solve(puzzle)) {
        printf("Puzzle solved:\n");
        printPuzzle(puzzle);
    } else {
        printf("Unable to solve puzzle");
    }

    return 0;
}