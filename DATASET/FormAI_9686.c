//FormAI DATASET v1.0 Category: Game ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 5
#define COLS 10

int main() {
    int nums[ROWS][COLS];
    int row, col, num;
    int total = 0;
    srand(time(NULL)); // Initialize random seed

    // Initialize array with random numbers and print
    printf("Initial array:\n");
    for (row = 0; row < ROWS; row++) {
        for (col = 0; col < COLS; col++) {
            num = rand() % 100; // Get random number between 0-99
            nums[row][col] = num;
            printf("%d ", num);
        }
        printf("\n");
    }

    // Sum each row and print
    printf("\nRow totals:\n");
    for (row = 0; row < ROWS; row++) {
        total = 0;
        for (col = 0; col < COLS; col++) {
            total += nums[row][col];
        }
        printf("Row %d: %d\n", row+1, total);
    }

    // Sum each column and print
    printf("\nColumn totals:\n");
    for (col = 0; col < COLS; col++) {
        total = 0;
        for (row = 0; row < ROWS; row++) {
            total += nums[row][col];
        }
        printf("Col %d: %d\n", col+1, total);
    }

    return 0;
}