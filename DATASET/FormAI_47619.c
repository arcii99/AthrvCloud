//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 5
#define COLS 10

// Create Bingo Grid
void createGrid(int grid[][COLS]) {
    int num;
    srand(time(NULL));
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (j == 0) {
                num = rand() % 15 + 1;
            } else if (j == 1) {
                num = rand() % 15 + 16;
            } else if (j == 2) {
                num = rand() % 15 + 31;
            } else if (j == 3) {
                num = rand() % 15 + 46;
            } else if (j == 4) {
                num = rand() % 15 + 61;
            } else if (j == 5) {
                num = rand() % 15 + 76;
            } else if (j == 6) {
                num = rand() % 15 + 91;
            } else if (j == 7) {
                num = rand() % 15 + 106;
            } else if (j == 8) {
                num = rand() % 15 + 121;
            } else if (j == 9) {
                num = rand() % 15 + 136;
            }
            grid[i][j] = num;
        }
    }
}

// Print Bingo Grid
void printGrid(int grid[][COLS]) {
    printf("\nB   I   N   G   O\n");
    for (int i = 0; i < ROWS; i++) {
        printf("-------------------\n");
        for (int j = 0; j < COLS; j++) {
            if (grid[i][j] == -1) {
                printf("| X ");
            } else {
                printf("| %d ", grid[i][j]);
            }
        }
        printf("|\n");
    }
}

// Check if number exists in grid
int exists(int num, int grid[][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (grid[i][j] == num) {
                return 1;
            }
        }
    }
    return 0;
}

// Mark number in grid
void mark(int num, int grid[][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (grid[i][j] == num) {
                grid[i][j] = -1;
            }
        }
    }
}

// Check if grid has a Bingo
int hasBingo(int grid[][COLS]) {
    int count;
    // Check Rows
    for (int i = 0; i < ROWS; i++) {
        count = 0;
        for (int j = 0; j < COLS; j++) {
            if (grid[i][j] == -1) {
                count++;
            }
        }
        if (count == COLS) {
            return 1;
        }
    }
    // Check Columns
    for (int i = 0; i < COLS; i++) {
        count = 0;
        for (int j = 0; j < ROWS; j++) {
            if (grid[j][i] == -1) {
                count++;
            }
        }
        if (count == ROWS) {
            return 1;
        }
    }
    // Check Diagonals
    count = 0;
    for (int i = 0; i < ROWS; i++) {
        if (grid[i][i] == -1) {
            count++;
        }
    }
    if (count == ROWS) {
        return 1;
    }
    count = 0;
    for (int i = 0; i < ROWS; i++) {
        if (grid[i][COLS-1-i] == -1) {
            count++;
        }
    }
    if (count == ROWS) {
        return 1;
    }
    return 0;
}

int main() {
    int grid[ROWS][COLS];
    int call;
    createGrid(grid);
    printGrid(grid);
    while (!hasBingo(grid)) {
        printf("\nEnter the call (1-150): ");
        scanf("%d", &call);
        if (call >= 1 && call <= 150) {
            if (exists(call, grid)) {
                mark(call, grid);
                printGrid(grid);
                if (hasBingo(grid)) {
                    printf("\nBINGO! Congratulations, you won!\n");
                    break;
                }
            } else {
                printf("\nSorry, that number is not in the grid.\n");
            }
        } else {
            printf("\nInvalid call. Please enter a number from 1 to 150.\n");
        }
    }
    return 0;
}