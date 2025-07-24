//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 5
#define COLS 5
#define MAX_NUM 75

void printCard(int card[][COLS]) {
    // Print the card
    printf("\n------- BINGO CARD -------\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (card[i][j] == 0) {
                printf("|  X  ");
            } else {
                printf("| %2d  ", card[i][j]);
            }
        }
        printf("|\n");
    }
    printf("--------------------------\n");
}

int main() {
    srand(time(0)); // Seed the random number generator with the current time

    int card[ROWS][COLS] = {0}; // Initialize the bingo card with 0s

    // Generate the numbers for the card
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (i == 2 && j == 2) { // Middle of the card is always free
                continue;
            }
            int num = rand() % MAX_NUM + 1; // Generate a random number between 1 and 75
            // Check if the number is already on the card
            for (int k = 0; k < ROWS; k++) {
                for (int l = 0; l < COLS; l++) {
                    if (card[k][l] == num) {
                        num = rand() % MAX_NUM + 1; // If the number is already on the card, generate a new random number
                    }
                }
            }
            card[i][j] = num; // Assign the number to the card
        }
    }

    // Print the initial card
    printCard(card);

    // Play the game
    int numCount = 0;
    while (numCount < MAX_NUM) {
        // Generate a random number between 1 and 75
        int num = rand() % MAX_NUM + 1;
        numCount++;

        // Check if the number is on the card
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                if (card[i][j] == num) {
                    card[i][j] = 0; // If the number is on the card, mark it as found
                    printf("Number found: %d\n", num);
                }
            }
        }

        // Check for a bingo
        int bingo = 0;
        // Check rows
        for (int i = 0; i < ROWS; i++) {
            int rowSum = 0;
            for (int j = 0; j < COLS; j++) {
                rowSum += card[i][j];
            }
            if (rowSum == 0) {
                printf("BINGO! Row %d\n", i + 1);
                bingo = 1;
                break;
            }
        }
        if (bingo) {
            break;
        }
        // Check columns
        for (int j = 0; j < COLS; j++) {
            int colSum = 0;
            for (int i = 0; i < ROWS; i++) {
                colSum += card[i][j];
            }
            if (colSum == 0) {
                printf("BINGO! Column %d\n", j + 1);
                bingo = 1;
                break;
            }
        }
        if (bingo) {
            break;
        }
        // Check diagonal
        int diag1Sum = 0;
        int diag2Sum = 0;
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                if (i == j) {
                    diag1Sum += card[i][j];
                }
                if (i + j == ROWS - 1) {
                    diag2Sum += card[i][j];
                }
            }
        }
        if (diag1Sum == 0) {
            printf("BINGO! Diagonal 1\n");
            bingo = 1;
            break;
        }
        if (diag2Sum == 0) {
            printf("BINGO! Diagonal 2\n");
            bingo = 1;
            break;
        }
    }

    // Print the final card
    printCard(card);

    return 0;
}