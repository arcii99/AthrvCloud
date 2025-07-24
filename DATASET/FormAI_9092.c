//FormAI DATASET v1.0 Category: Dice Roller ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int roll_dice() {
    // This function generates a random number between 1 and 6
    return rand() % 6 + 1;
}

int main() {
    srand(time(NULL)); // Initialize random numbers using system time

    int player1_score = 0, player2_score = 0;
    int current_roll, player_turn = 1;

    printf("Welcome to the Dice Roller game!\n");

    while (player1_score < 100 && player2_score < 100) { // Game ends when one player reaches a score of 100 or above
        printf("Player %i's turn\n", player_turn);
        printf("Press ENTER to roll the dice\n");
        getchar(); // Wait for player to press enter

        current_roll = roll_dice(); // Roll the dice
        printf("You rolled a %i!\n", current_roll);

        if (current_roll == 1) { // Player rolled a 1, switch turn
            printf("Sorry, you lose all points for this turn.\n");
            if (player_turn == 1) {
                player1_score = 0;
                player_turn = 2;
            } else {
                player2_score = 0;
                player_turn = 1;
            }
        } else { // Player rolled a number between 2 and 6
            printf("Would you like to roll again (y/n)?\n");
            char choice = getchar();
            getchar(); // Consume newline character
            while (choice == 'y') { // Player can keep rolling until they choose to stop or roll a 1
                current_roll = roll_dice();
                printf("You rolled a %i!\n", current_roll);
                if (current_roll == 1) {
                    printf("Sorry, you lose all points for this turn.\n");
                    if (player_turn == 1) {
                        player1_score = 0;
                        player_turn = 2;
                    } else {
                        player2_score = 0;
                        player_turn = 1;
                    }
                    break;
                } else {
                    printf("Would you like to roll again (y/n)?\n");
                    choice = getchar();
                    getchar(); // Consume newline character
                }
            }
            if (player_turn == 1) {
                player1_score += current_roll;
                player_turn = 2;
            } else {
                player2_score += current_roll;
                player_turn = 1;
            }
        }
        printf("Player 1's score: %i\n", player1_score);
        printf("Player 2's score: %i\n", player2_score);
    }
    if (player1_score >= 100) { // Player 1 wins
        printf("Congratulations Player 1, you win!\n");
    } else { // Player 2 wins
        printf("Congratulations Player 2, you win!\n");
    }
    return 0;
}