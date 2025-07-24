//FormAI DATASET v1.0 Category: Table Game ; Style: single-threaded
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Declare variables
    int player1_score = 0;
    int player2_score = 0;
    int dice_roll;
    bool player1_turn = true;

    // Seed the random number generator
    srand(time(NULL));

    // Generate dice rolls and add to player scores until one player reaches 50
    while (player1_score < 50 && player2_score < 50) {
        // Roll the dice
        dice_roll = rand() % 6 + 1;
        printf("Dice Roll: %d\n", dice_roll);

        // Add the dice roll to the current player's score
        if (player1_turn) {
            printf("Player 1's turn\n");
            player1_score += dice_roll;
            printf("Player 1's score: %d\n", player1_score);
        } else {
            printf("Player 2's turn\n");
            player2_score += dice_roll;
            printf("Player 2's score: %d\n", player2_score);
        }

        // Switch turns
        player1_turn = !player1_turn;
        printf("\n");
    }

    // Determine the winner
    printf("===== GAME OVER =====\n");
    if (player1_score >= 50) {
        printf("Player 1 wins!\n");
    } else {
        printf("Player 2 wins!\n");
    }

    return 0;
}