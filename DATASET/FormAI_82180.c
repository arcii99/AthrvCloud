//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 5
#define COLS 5

int main() {
    int bingo[ROWS][COLS];
    int drawn[ROWS * COLS];
    int row, col, i, j, count, num;

    // Generate Bingo card
    for (row = 0; row < ROWS; row++) {
        for (col = 0; col < COLS; col++) {
            // Generate random number between 1 and 15 for the first column
            if (col == 0) {
                num = rand() % 15 + 1;
            }
            // Generate random number between 16 and 30 for the second column
            else if (col == 1) {
                num = rand() % 15 + 16;
            }
            // Generate random number between 31 and 45 for the third column
            else if (col == 2) {
                num = rand() % 15 + 31;
            }
            // Generate random number between 46 and 60 for the fourth column
            else if (col == 3) {
                num = rand() % 15 + 46;
            }
            // Generate random number between 61 and 75 for the fifth column
            else {
                num = rand() % 15 + 61;
            }
            // Check if num has already been generated in current column
            for (i = 0; i < row; i++) {
                if (num == bingo[i][col]) {
                    num = 0;
                    break;
                }
            }
            // If num hasn't been generated in current column, add it to the bingo card
            bingo[row][col] = num;
        }
    }

    // Print out Bingo card
    printf("B   I   N   G   O\n");
    for (row = 0; row < ROWS; row++) {
        for (col = 0; col < COLS; col++) {
            if (bingo[row][col] < 10) {
                printf(" ");
            }
            printf("%d   ", bingo[row][col]);
        }
        printf("\n");
    }

    // Draw numbers until there's a Bingo
    srand(time(NULL));
    count = 0;
    while (1) {
        // Generate a random number between 1 and 75
        num = rand() % 75 + 1;
        // Check if num has already been drawn
        for (i = 0; i < count; i++) {
            if (num == drawn[i]) {
                num = 0;
                break;
            }
        }
        // If num hasn't been drawn yet, add it to drawn array and check if it's on the bingo card
        if (num != 0) {
            drawn[count] = num;
            count++;
            printf("Number drawn: %d\n", num);
            for (row = 0; row < ROWS; row++) {
                for (col = 0; col < COLS; col++) {
                    if (bingo[row][col] == num) {
                        bingo[row][col] = 0;
                        for (j = 0; j < COLS; j++) {
                            if (bingo[row][j] != 0) {
                                break;
                            }
                            if (j == COLS - 1) {
                                printf("Bingo! Row %d!\n", row + 1);
                                return 0;
                            }
                        }
                        for (j = 0; j < ROWS; j++) {
                            if (bingo[j][col] != 0) {
                                break;
                            }
                            if (j == ROWS - 1) {
                                printf("Bingo! Col %d!\n", col + 1);
                                return 0;
                            }
                        }
                        if (row == col) {
                            for (j = 0; j < ROWS; j++) {
                                if (bingo[j][j] != 0) {
                                    break;
                                }
                                if (j == ROWS - 1) {
                                    printf("Bingo! Diagonal!\n");
                                    return 0;
                                }
                            }
                        }
                        if (row == ROWS - col - 1) {
                            for (j = 0; j < ROWS; j++) {
                                if (bingo[j][ROWS - j - 1] != 0) {
                                    break;
                                }
                                if (j == ROWS - 1) {
                                    printf("Bingo! Diagonal!\n");
                                    return 0;
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    return 0;
}