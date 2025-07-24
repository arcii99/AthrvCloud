//FormAI DATASET v1.0 Category: Memory Game ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 4
#define COLS 4

void printGrid(int grid[][COLS], int rows, int cols, int revealed[][COLS]) {
    printf(" ");
    for (int i = 0; i < cols; i++) {
        printf(" %2d", i + 1);
    }
    printf("\n");

    for (int i = 0; i < rows; i++) {
        printf("%2d", i + 1);
        for (int j = 0; j < cols; j++) {
            if (revealed[i][j]) {
                printf(" %2d", grid[i][j]);
            } else {
                printf("  X");
            }
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL)); // seed random number generator
    int grid[ROWS][COLS];
    int revealed[ROWS][COLS] = {};
    int numPairs = ROWS * COLS / 2;

    int numGenerated = 0;
    int row, col;
    while (numGenerated < numPairs) {
        // generate random coordinates (row and col)
        row = rand() % ROWS;
        col = rand() % COLS;

        // if this coordinate hasn't been generated yet, generate a pair and mark them as generated
        if (grid[row][col] == 0) {
            int value = rand() % numPairs + 1;
            grid[row][col] = value;
            grid[ROWS-1-row][COLS-1-col] = value;
            numGenerated++;
        }
    }

    printf("Welcome to the Memory Game!\n");
    printf("Match all pairs of numbers to win.\n");
    printf("===============================\n");

    int numRevealed = 0;
    int firstRow, firstCol, secondRow, secondCol;
    while (1) {
        printGrid(grid, ROWS, COLS, revealed);

        // ask player to input two coordinates
        printf("Enter the row and column of the first number: ");
        scanf("%d%d", &row, &col);
        firstRow = row - 1;
        firstCol = col - 1;
        while (revealed[firstRow][firstCol]) {
            printf("You already revealed that number. Choose another one: ");
            scanf("%d%d", &row, &col);
            firstRow = row - 1;
            firstCol = col - 1;
        }
        revealed[firstRow][firstCol] = 1;

        printf("Enter the row and column of the second number: ");
        scanf("%d%d", &row, &col);
        secondRow = row - 1;
        secondCol = col - 1;
        while (revealed[secondRow][secondCol]) {
            printf("You already revealed that number. Choose another one: ");
            scanf("%d%d", &row, &col);
            secondRow = row - 1;
            secondCol = col - 1;
        }
        revealed[secondRow][secondCol] = 1;

        // check if these two numbers match
        if (grid[firstRow][firstCol] == grid[secondRow][secondCol]) {
            numRevealed += 2;
            if (numRevealed == ROWS * COLS) {
                printf("Congratulations! You won the Memory Game!\n");
                return 0;
            }
            printf("Congratulations! You found a pair of %d's!\n", grid[firstRow][firstCol]);
        } else {
            printf("Sorry! Those numbers don't match. Try again.\n");
            revealed[firstRow][firstCol] = 0;
            revealed[secondRow][secondCol] = 0;
        }
    }

    return 0;
}