//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    // Romantic Bingo Simulator
    printf("Welcome to our Romantic Bingo Simulator!\n");
    printf("Let's play and see if you can win the heart of your crush!\n");

    // Seed the random number generator
    srand(time(NULL));

    // Declare the bingo card
    int bingo[5][5];
    int row, col;

    // Fill the bingo card with random numbers
    for (row = 0; row < 5; row++) {
        for (col = 0; col < 5; col++) {
            if (row == 2 && col == 2) {
                // The center spot is always free
                bingo[row][col] = 0;
            } else {
                // Generate a random number between 1 and 75
                bingo[row][col] = rand() % 75 + 1;
            }
        }
    }

    // Print the bingo card
    printf("Here is your bingo card:\n");
    for (row = 0; row < 5; row++) {
        for (col = 0; col < 5; col++) {
            printf("%2d ", bingo[row][col]);
        }
        printf("\n");
    }

    // Play the game
    int num;
    int calls[75] = {0};
    int callcount = 0;
    int i, j;
    int found;

    while (1) {

        // Generate a random number
        do {
            num = rand() % 75 + 1;
        } while (calls[num - 1] == 1);

        // Mark the number as called
        calls[num - 1] = 1;
        callcount++;

        // Check if the number is on the card
        found = 0;
        for (i = 0; i < 5; i++) {
            for (j = 0; j < 5; j++) {
                if (bingo[i][j] == num) {
                    bingo[i][j] = -1;
                    found = 1;
                }
            }
        }

        // Print the called number and updated bingo card
        printf("\nCalled number: %d\n", num);
        printf("Here is your updated bingo card:\n");
        for (i = 0; i < 5; i++) {
            for (j = 0; j < 5; j++) {
                if (bingo[i][j] < 0) {
                    printf("  ");
                } else {
                    printf("%2d ", bingo[i][j]);
                }
            }
            printf("\n");
        }

        // Check if there is a bingo
        int bingos = 0;

        // Check rows
        for (i = 0; i < 5; i++) {
            found = 1;
            for (j = 0; j < 5; j++) {
                if (bingo[i][j] >= 0) {
                    found = 0;
                }
            }
            if (found) {
                bingos++;
            }
        }

        // Check columns
        for (i = 0; i < 5; i++) {
            found = 1;
            for (j = 0; j < 5; j++) {
                if (bingo[j][i] >= 0) {
                    found = 0;
                }
            }
            if (found) {
                bingos++;
            }
        }

        // Check diagonal
        found = 1;
        for (i = 0; i < 5; i++) {
            if (bingo[i][i] >= 0) {
                found = 0;
            }
        }
        if (found) {
            bingos++;
        }

        found = 1;
        for (i = 0; i < 5; i++) {
            if (bingo[i][4 - i] >= 0) {
                found = 0;
            }
        }
        if (found) {
            bingos++;
        }

        // Check if there is a winner
        if (bingos > 0) {
            printf("\nCongratulations! You won with %d bingos in %d calls!\n", bingos, callcount);
            printf("You have won the heart of your crush!\n");
            break;
        }

        // Ask to continue playing
        printf("\nDo you want to continue playing? (y/n) ");
        char ans;
        scanf(" %c", &ans);
        if (ans == 'n' || ans == 'N') {
            printf("Goodbye!\n");
            break;
        }
    }

    return 0;
}