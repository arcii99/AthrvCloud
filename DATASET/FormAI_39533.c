//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 5
#define COLS 5
#define MAX_NUM 75

int main() {
    int i, j, k, num, bingo;
    int card[ROWS][COLS];

    // Initialize the card with zeros
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            card[i][j] = 0;
        }
    }

    // Seed the random number generator
    srand(time(0));

    // Generate random numbers and add them to the card
    for (k = 1; k <= MAX_NUM; k++) {
        // Generate a random number between 1 and 75
        num = rand() % 75 + 1;

        // Check if the number is already on the card
        bingo = 0;
        for (i = 0; i < ROWS; i++) {
            for (j = 0; j < COLS; j++) {
                if (card[i][j] == num) {
                    bingo = 1;
                }
            }
        }

        // If the number is not already on the card, add it
        if (!bingo) {
            // Find an empty spot on the card
            do {
                i = rand() % ROWS;
                j = rand() % COLS;
            } while (card[i][j] != 0);

            // Add the number to the card
            card[i][j] = num;
        }
    }

    // Print the card
    printf("B  I  N  G  O\n");
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            if (card[i][j] == 0) {
                printf("   ");
            } else {
                printf("%2d ", card[i][j]);
            }
        }
        printf("\n");
    }

    return 0;
}