//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Declare our functions
int roll_die(int sides);
void game_loop();

int main() {
    printf("Welcome to the Medieval Dice Game!\n");
    game_loop(); // Start the game loop
    return 0;
}

void game_loop() {
    // Declare variables
    int player_score = 0;
    int computer_score = 0;
    int round = 1;
    int winner = 0;

    // Seed the random number generator
    srand(time(NULL));

    // Game loop
    while (winner == 0) {
        printf("Round %d\n", round);

        // Player turn
        printf("Your turn:\n");
        int player_roll = roll_die(20);
        printf("You rolled a %d\n", player_roll);
        player_score += player_roll;

        // Computer turn
        printf("Computer's turn:\n");
        int computer_roll = roll_die(20);
        printf("Computer rolled a %d\n", computer_roll);
        computer_score += computer_roll;

        // End of round
        printf("Your score: %d\n", player_score);
        printf("Computer's score: %d\n", computer_score);

        if (player_score >= 50 || computer_score >= 50) {
            winner = (player_score > computer_score) ? 1 : 2;
        }

        round++;
    }

    // Declare winner
    if (winner == 1) {
        printf("You win!\n");
    } else {
        printf("Computer wins!\n");
    }
}

int roll_die(int sides) {
    return (rand() % sides) + 1;
}