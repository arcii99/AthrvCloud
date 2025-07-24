//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 5
#define COLUMNS 5

void printGrid(int grid[ROWS][COLUMNS], int numCount[76]);
void generateNumber(int num, int numCount[76]);
int bingoCheck(int grid[ROWS][COLUMNS]);

int main() {
    int grid[ROWS][COLUMNS] = {{0}};
    int numCount[76] = {0};
    int numCountIndex = 75;
    int num;

    srand(time(0));  // Seed random number generator

    printf("\nWelcome to Bingo Simulator!\n\n");

    // Generate Bingo grid
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLUMNS; j++) {
            if ((i == 2 && j == 2) || (j == 1 && i > 0)) {
                grid[i][j] = 0;  // Place free space in center and second column
            } else {
                while (1) {
                    num = rand() % 75 + 1;  // Generate random number between 1 and 75
                    if (numCount[num] == 0) {  // Check if number has been generated before
                        generateNumber(num, numCount);  // Add number to bingo card
                        grid[i][j] = num;
                        break;
                    }
                }
            }
        }
    }

    printf("BINGO grid has been generated!\n");
    printGrid(grid, numCount);

    while (1) {
        printf("\nGenerating next number...\n");
        num = rand() % 75 + 1;  // Generate random number between 1 and 75
        printf("The number is: %d\n", num);
        generateNumber(num, numCount);  // Mark number off bingo card
        printGrid(grid, numCount);

        if (bingoCheck(grid) == 1) {  // Check if bingo has been achieved
            printf("\nBINGO! You have won!\n");
            break;
        }

        if (--numCountIndex < 0) {  // Check if all numbers have been called
            printf("\nGame over! No BINGO achieved.\n");
            break;
        }
    }

    return 0;
}

void printGrid(int grid[ROWS][COLUMNS], int numCount[76]) {
    printf("\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLUMNS; j++) {
            if (grid[i][j] == 0) {
                printf("|%2s|", " ");
            } else {
                printf("|%2d|", grid[i][j]);
            }
        }
        printf("\n");
    }

    printf("\nNumbers called:");
    for (int i = 1; i < 76; i++) {
        if (numCount[i] == 1) {
            printf(" %d", i);
        }
    }
    printf("\n");
}

void generateNumber(int num, int numCount[76]) {
    numCount[num] = 1;
}

int bingoCheck(int grid[ROWS][COLUMNS]) {
    int i, j, count;

    // Check rows
    for (i = 0; i < ROWS; i++) {
        count = 0;
        for (j = 0; j < COLUMNS; j++) {
            if (grid[i][j] == 0) {
                count++;
            }
        }
        if (count == COLUMNS) {  // BINGO achieved
            return 1;
        }
    }

    // Check columns
    for (j = 0; j < COLUMNS; j++) {
        count = 0;
        for (i = 0; i < ROWS; i++) {
            if (grid[i][j] == 0) {
                count++;
            }
        }
        if (count == ROWS) {  // BINGO achieved
            return 1;
        }
    }

    // Check diagonals
    count = 0;
    for (i = 0; i < ROWS; i++) {
        if (grid[i][i] == 0) {
            count++;
        }
    }
    if (count == ROWS) {  // BINGO achieved
        return 1;
    }
    count = 0;
    for (i = 0; i < ROWS; i++) {
        if (grid[i][ROWS - 1 - i] == 0) {
            count++;
        }
    }
    if (count == ROWS) {  // BINGO achieved
        return 1;
    }

    return 0;  // No BINGO achieved yet
}