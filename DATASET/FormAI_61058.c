//FormAI DATASET v1.0 Category: Table Game ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int player_score = 0;
    int computer_score = 0;
    int round = 1;
    printf("Welcome to the C Table Game!\n\n");

    while (round <= 10) {
        // player's turn
        printf("Round %d:\n", round);
        printf("Player's turn: ");
        int player_choice = rand() % 6 + 1;
        player_score += player_choice;
        printf("%d\n", player_choice);

        // computer's turn
        printf("Computer's turn: ");
        int computer_choice = rand() % 6 + 1;
        computer_score += computer_choice;
        printf("%d\n", computer_choice);

        // display scores
        printf("Current score:\n");
        printf("Player: %d\n", player_score);
        printf("Computer: %d\n\n", computer_score);

        round++;
    }

    // determine winner
    if (player_score > computer_score) {
        printf("Congratulations! You won with a score of %d.\n", player_score);
    } else if (computer_score > player_score) {
        printf("Sorry, the computer won with a score of %d.\n", computer_score);
    } else {
        printf("It's a tie!\n");
    }

    return 0;
}