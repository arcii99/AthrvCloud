//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 5
#define COLS 5
#define MAX_NUMBER 75

int main() {
    int i, j, k;
    int card[ROWS][COLS] = { 0 };
    int number[MAX_NUMBER] = { 0 };
    int call_count = 0;
    int remaining = ROWS * COLS;

    // Initialize random number generator
    srand(time(NULL));

    // Generate list of numbers
    for (i = 0; i < MAX_NUMBER; i++) {
        number[i] = i + 1;
    }

    // Shuffle numbers
    for (i = 0; i < MAX_NUMBER; i++) {
        j = rand() % MAX_NUMBER;
        k = number[i];
        number[i] = number[j];
        number[j] = k;
    }

    // Generate bingo card
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            if (j == 2 && i == 2) {
                card[i][j] = 0;
            } else {
                card[i][j] = number[i * COLS + j];
            }
        }
    }

    // Display bingo card
    printf("B I N G O\n");
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            if (card[i][j] == 0) {
                printf("  ");
            } else {
                printf("%2d", card[i][j]);
            }
            if (j < COLS - 1) {
                printf(" ");
            }
        }
        printf("\n");
    }

    // Play game
    while (remaining > 0) {
        // Prompt user to press enter to call next number
        printf("Press enter to call next number...");
        getchar();

        // Call next number
        int next_number = number[call_count++];
        printf("Number called: %d\n", next_number);

        // Mark number on card if exists
        for (i = 0; i < ROWS; i++) {
            for (j = 0; j < COLS; j++) {
                if (card[i][j] == next_number) {
                    card[i][j] = 0;
                    remaining--;
                }
            }
        }

        // Display updated card
        printf("Current card:\n");
        for (i = 0; i < ROWS; i++) {
            for (j = 0; j < COLS; j++) {
                if (card[i][j] == 0) {
                    printf("  ");
                } else {
                    printf("%2d", card[i][j]);
                }
                if (j < COLS - 1) {
                    printf(" ");
                }
            }
            printf("\n");
        }

        // Check if bingo is achieved
        if (card[0][0] == 0 && card[0][1] == 0 && card[0][2] == 0 && card[0][3] == 0 && card[0][4] == 0) {
            printf("BINGO!\n");
            break;
        }
        if (card[1][0] == 0 && card[1][1] == 0 && card[1][2] == 0 && card[1][3] == 0 && card[1][4] == 0) {
            printf("BINGO!\n");
            break;
        }
        if (card[2][0] == 0 && card[2][1] == 0 && card[2][3] == 0 && card[2][4] == 0) {
            printf("BINGO!\n");
            break;
        }
        if (card[3][0] == 0 && card[3][1] == 0 && card[3][2] == 0 && card[3][3] == 0 && card[3][4] == 0) {
            printf("BINGO!\n");
            break;
        }
        if (card[4][0] == 0 && card[4][1] == 0 && card[4][2] == 0 && card[4][3] == 0 && card[4][4] == 0) {
            printf("BINGO!\n");
            break;
        }
    }

    // End game
    printf("Game over.\n");

    return 0;
}