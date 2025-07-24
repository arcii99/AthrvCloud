//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int bingo_card[5][5];
    int i, j, number, found, win;

    // Generate random numbers and fill in the bingo card
    srand(time(NULL));
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            bingo_card[i][j] = rand() % 99 + 1;
        }
    }

    printf("Welcome to the Bingo simulator!\n");
    printf("Here is your Bingo card:\n\n");

    // Print the bingo card with the random numbers
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            if (i == 2 && j == 2) {
                printf(" F ");
            } else {
                printf("%2d ", bingo_card[i][j]);
            }
        }
        printf("\n");
    }

    printf("\nLet's start the game!\n");

    // Keep playing until someone wins
    win = 0;
    while (!win) {
        // Generate a random number between 1 and 99
        number = rand() % 99 + 1;
        printf("\nNext number: %d\n", number);

        // Search for the number on the bingo card
        found = 0;
        for (i = 0; i < 5; i++) {
            for (j = 0; j < 5; j++) {
                if (bingo_card[i][j] == number) {
                    found = 1;
                    bingo_card[i][j] = 0; // Mark the number as found on the card
                }
            }
        }

        // Check if someone has won
        // Rows
        for (i = 0; i < 5; i++) {
            if (bingo_card[i][0] == 0 && bingo_card[i][1] == 0 && bingo_card[i][2] == 0 && bingo_card[i][3] == 0 && bingo_card[i][4] == 0) {
                printf("Bingo! Row %d.\n", i+1);
                win = 1;
            }
        }
        // Columns
        for (j = 0; j < 5; j++) {
            if (bingo_card[0][j] == 0 && bingo_card[1][j] == 0 && bingo_card[2][j] == 0 && bingo_card[3][j] == 0 && bingo_card[4][j] == 0) {
                printf("Bingo! Column %d.\n", j+1);
                win = 1;
            }
        }
        // Diagonals
        if (bingo_card[0][0] == 0 && bingo_card[1][1] == 0 && bingo_card[2][2] == 0 && bingo_card[3][3] == 0 && bingo_card[4][4] == 0) {
            printf("Bingo! Diagonal.\n");
            win = 1;
        }
        if (bingo_card[0][4] == 0 && bingo_card[1][3] == 0 && bingo_card[2][2] == 0 && bingo_card[3][1] == 0 && bingo_card[4][0] == 0) {
            printf("Bingo! Diagonal.\n");
            win = 1;
        }
    }

    printf("Congratulations, you won!\n");

    return 0;
}