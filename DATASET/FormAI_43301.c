//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 5
#define COLS 5

int main() {

    // Initiate the bingo card
    int bingo[ROWS][COLS] = {0};

    // Generate random numbers for the card
    srand(time(NULL));
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            int num = (rand() % 15) + 1 + (j * 15);
            // Check for duplicate numbers
            for (int k = 0; k < j; k++) {
                if (num == bingo[i][k]) {
                    num = (rand() % 15) + 1 + (j * 15);
                    k = -1;
                }
            }
            bingo[i][j] = num;
        }
    }

    // Print the bingo card
    printf("Let's play Bingo!\n");
    printf("B  I  N  G  O\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (bingo[i][j] < 10) {
                printf(" ");
            }
            printf("%d ", bingo[i][j]);
        }
        printf("\n");
    }

    // Play the game
    int numbers[75];
    for (int i = 0; i < 75; i++) {
        numbers[i] = i + 1;
    }
    int numCount = 0;
    while (numCount < 75) {
        // Get a random number
        int index = rand() % (75 - numCount);
        int num = numbers[index];
        numbers[index] = numbers[74 - numCount];
        numCount++;
        // Print the number
        printf("The caller says: \"%d!\"\n", num);
        // Check if the number is on the card
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                if (bingo[i][j] == num) {
                    // Mark the number on the card
                    bingo[i][j] = 0;
                    // Check if there's a Bingo
                    int bingoCount = 0;
                    for (int k = 0; k < ROWS; k++) {
                        int sum = 0;
                        for (int l = 0; l < COLS; l++) {
                            sum += bingo[k][l];
                        }
                        if (sum == 0) {
                            bingoCount++;
                        }
                    }
                    for (int k = 0; k < COLS; k++) {
                        int sum = 0;
                        for (int l = 0; l < ROWS; l++) {
                            sum += bingo[l][k];
                        }
                        if (sum == 0) {
                            bingoCount++;
                        }
                    }
                    int sum = 0;
                    for (int k = 0; k < ROWS; k++) {
                        sum += bingo[k][k];
                    }
                    if (sum == 0) {
                        bingoCount++;
                    }
                    sum = 0;
                    for (int k = 0; k < ROWS; k++) {
                        sum += bingo[k][COLS - k - 1];
                    }
                    if (sum == 0) {
                        bingoCount++;
                    }
                    // Print the result
                    if (bingoCount > 0) {
                        printf("BINGO! %d\n", bingoCount);
                        exit(0);
                    }
                }
            }
        }
    }

    // Print the result
    printf("No Bingo!\n");

    return 0;
}