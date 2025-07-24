//FormAI DATASET v1.0 Category: Table Game ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    printf("WELCOME TO THE TABLE GAME\n\n");

    /* Set up variables */
    int player1_score = 0;
    int player2_score = 0;
    int max_score = 50;

    srand(time(NULL)); // Seed random number generator

    /* Start game */
    while (player1_score < max_score && player2_score < max_score) {
        /* Player 1 turn */
        printf("Player 1's turn\n");
        int roll1 = rand() % 6 + 1; // Roll the die
        player1_score += roll1;
        printf("Player 1 rolled a %d, current score: %d\n", roll1, player1_score);

        /* Player 2 turn */
        printf("Player 2's turn\n");
        int roll2 = rand() % 6 + 1; // Roll the die
        player2_score += roll2;
        printf("Player 2 rolled a %d, current score: %d\n", roll2, player2_score);

        printf("\n");
    }

    /* Determine winner */
    if (player1_score >= max_score && player1_score > player2_score) {
        printf("Player 1 wins!");
    } else if (player2_score >= max_score && player2_score > player1_score) {
        printf("Player 2 wins!");
    } else {
        printf("It's a tie!");
    }

    return 0;
}