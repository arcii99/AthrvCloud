//FormAI DATASET v1.0 Category: Table Game ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random number between minimum and maximum values
int generateRandomNumber(int min, int max) {
    srand(time(NULL));  // Seed generator
    return (rand() % (max - min + 1)) + min;  // Generate random number
}

int main() {
    // Initialize game variables
    int player1_score = 0;
    int player2_score = 0;
    int rounds = 1;
    int round_winner = 0;

    printf("Welcome to C Table Game!\n");

    // Loop through 5 rounds of the game
    while (rounds <= 5) {
        printf("Round %d:\n", rounds);

        // Player 1 rolls the dice
        int player1_roll = generateRandomNumber(1, 6);
        printf("Player 1 rolls: %d\n", player1_roll);

        // Player 2 rolls the dice
        int player2_roll = generateRandomNumber(1, 6);
        printf("Player 2 rolls: %d\n", player2_roll);

        // Calculate the round winner
        if (player1_roll > player2_roll) {
            round_winner = 1;
            player1_score++;
        } else if (player2_roll > player1_roll) {
            round_winner = 2;
            player2_score++;
        } else {
            round_winner = 0;
        }

        // Display round results
        if (round_winner == 0) {
            printf("Round %d is a tie!\n", rounds);
        } else {
            printf("Player %d wins round %d!\n", round_winner, rounds);
        }

        // Increment round counter
        rounds++;
    }

    // Determine the overall game winner
    if (player1_score > player2_score) {
        printf("Player 1 wins the game with a score of %d to %d!\n", player1_score, player2_score);
    } else if (player2_score > player1_score) {
        printf("Player 2 wins the game with a score of %d to %d!\n", player2_score, player1_score);
    } else {
        printf("The game is a tie with a score of %d to %d!\n", player1_score, player2_score);
    }

    return 0;
}