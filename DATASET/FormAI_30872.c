//FormAI DATASET v1.0 Category: Table Game ; Style: paranoid
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int player_rolls[2];
    int opponent_rolls[2];
    int player_score = 0;
    int opponent_score = 0;

    printf("Welcome to the Paranoid Table Game!\n");

    bool player_turn = true;

    while (true) { 
        if (player_turn) { 
            printf("Player's turn...\n");
            printf("Press ENTER to roll the dice.\n");
            getchar(); // Wait for the ENTER key to be pressed
            player_rolls[0] = rand() % 6 + 1;
            player_rolls[1] = rand() % 6 + 1;
            printf("You rolled: %d and %d\n", player_rolls[0], player_rolls[1]);

            if (player_rolls[0] == player_rolls[1]) {
                printf("You rolled doubles! Roll again!\n");
                player_rolls[0] = rand() % 6 + 1;
                printf("You rolled: %d\n", player_rolls[0]);
                printf("Your new total is: %d\n", player_score += player_rolls[0]);
            }
            else {
                printf("Your total is: %d\n", player_score += player_rolls[0] + player_rolls[1]);
            }

            if (player_score >= 21) {
                printf("You win!\n");
                break;
            }
        }
        else { 
            printf("Opponent's turn...\n");
            opponent_rolls[0] = rand() % 6 + 1;
            opponent_rolls[1] = rand() % 6 + 1;
            printf("Opponent rolled: %d and %d\n", opponent_rolls[0], opponent_rolls[1]);

            if (opponent_rolls[0] == opponent_rolls[1]) {
                printf("Opponent rolled doubles! Roll again!\n");
                opponent_rolls[0] = rand() % 6 + 1;
                printf("Opponent rolled: %d\n", opponent_rolls[0]);
                printf("Opponent's new total is: %d\n", opponent_score += opponent_rolls[0]);
            }
            else {
                printf("Opponent's total is: %d\n", opponent_score += opponent_rolls[0] + opponent_rolls[1]);
            }

            if (opponent_score >= 21) {
                printf("Opponent wins!\n");
                break;
            }
        }

        player_turn = !player_turn; // Switch turns
    }

    return 0;
}