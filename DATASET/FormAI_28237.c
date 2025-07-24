//FormAI DATASET v1.0 Category: Table Game ; Style: visionary
#include <stdio.h>
#include <stdlib.h>

int main() {

    // Introduction
    printf("Welcome to the visionary table game!\n");
    printf("In this game, you will compete against the computer to reach the end of the table.\n");
    printf("Each player starts at position 0 and takes turns rolling a die to move further down the table.\n");
    printf("The player that reaches the end of the table first, wins the game!\n");
    printf("Do you have what it takes to be a visionary?\n\n");

    // Variables
    int player_pos = 0;
    int comp_pos = 0;
    int player_roll = 0;
    int comp_roll = 0;
    int turn = 1; // 1 for player, 2 for computer

    // Game loop
    while (player_pos < 100 && comp_pos < 100) { // Game ends at position 100

        // Player turn
        if (turn == 1) {
            printf("Player's turn:\n");
            printf("Rolling die...\n");
            player_roll = rand() % 6 + 1; // Roll die (random number between 1 and 6)
            printf("You rolled a %d!\n", player_roll);
            player_pos += player_roll; // Move player's position
            printf("Player's position: %d\n", player_pos);
            turn = 2; // Switch turn to computer
        }

        // Computer turn
        else if (turn == 2) {
            printf("Computer's turn:\n");
            printf("Rolling die...\n");
            comp_roll = rand() % 6 + 1; // Roll die (random number between 1 and 6)
            printf("The computer rolled a %d!\n", comp_roll);
            comp_pos += comp_roll; // Move computer's position
            printf("Computer's position: %d\n", comp_pos);
            turn = 1; // Switch turn to player
        }

        // If player or computer reaches the end of the table
        if (player_pos >= 100) {
            printf("\nCongratulations! You reached the end of the table first!\n");
        }
        else if (comp_pos >= 100) {
            printf("\nSorry, the computer reached the end of the table first. Better luck next time!\n");
        }
    }

    return 0;
}