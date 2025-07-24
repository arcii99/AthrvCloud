//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 5
#define COLS 5
#define MAX_NUM 25

int main()
{
    int card[ROWS][COLS];
    int called[MAX_NUM];

    srand(time(NULL));

    // Initialize card with random numbers
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            int num = rand() % MAX_NUM + 1;
            // Check if number already exists on the card
            while (1) {
                int flag = 0;
                for (int k = 0; k < j; k++) {
                    if (card[i][k] == num) {
                        flag = 1;
                        break;
                    }
                }
                if (!flag) break;
                num = rand() % MAX_NUM + 1;
            }
            card[i][j] = num;
        }
    }

    // Initialize called array to all zeros
    for (int i = 0; i < MAX_NUM; i++) {
        called[i] = 0;
    }

    // Print out the card
    printf("B    I    N    G    O\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%-4d ", card[i][j]);
        }
        printf("\n");
    }

    // Keep track of how many numbers have been called
    int num_called = 0;

    // Keep track of whether or not there is a winner
    int winner = 0;

    // Keep calling numbers until someone wins or all numbers are called
    while (num_called < MAX_NUM && !winner) {
        // Generate random number between 1 and MAX_NUM
        int num = rand() % MAX_NUM + 1;
        // Check if number has already been called
        if (called[num - 1]) {
            continue;
        }
        called[num - 1] = 1;
        num_called++;
        // Check if number is on the card
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                if (card[i][j] == num) { // Number is on the card
                    // Mark the number as called on the card
                    card[i][j] = -1;
                    // Check if there is a bingo
                    int bingo = 1;
                    for (int k = 0; k < ROWS; k++) {
                        int row_bingo = 1;
                        int col_bingo = 1;
                        for (int l = 0; l < COLS; l++) {
                            if (card[k][l] != -1) {
                                row_bingo = 0;
                            }
                            if (card[l][k] != -1) {
                                col_bingo = 0;
                            }
                        }
                        if (row_bingo || col_bingo) {
                            winner = 1;
                            break;
                        }
                    }
                    if (winner) {
                        break;
                    }
                }
            }
            if (winner) {
                break;
            }
        }
        printf("Number called: %d\n", num);
    }

    // Print out the final state of the card
    printf("B    I    N    G    O\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (card[i][j] == -1) {
                printf("X    ");
            } else {
                printf("%-4d ", card[i][j]);
            }
        }
        printf("\n");
    }

    if (winner) {
        printf("BINGO!\n");
    } else {
        printf("No winner :(\n");
    }

    return 0;
}