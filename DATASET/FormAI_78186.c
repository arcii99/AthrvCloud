//FormAI DATASET v1.0 Category: Table Game ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PLAYERS 5
#define MAX_SCORE 50

int main(void) {
    srand(time(NULL)); // Set the random seed

    int num_players;
    printf("Enter the number of players (max %d): ", MAX_PLAYERS);
    scanf("%d", &num_players);

    if(num_players > MAX_PLAYERS) {
        printf("Error: Maximum number of players is %d.\n", MAX_PLAYERS);
        return 1;
    }

    int player_scores[MAX_PLAYERS]; // Array to store player scores
    for(int i = 0; i < num_players; i++) {
        player_scores[i] = 0; // Initialize scores to zero
    }

    printf("Starting game...\n");
    while(1) { // Loop until a player reaches the maximum score
        printf("\nCurrent scores:\n");
        for(int i = 0; i < num_players; i++) {
            printf("Player %d: %d\n", i+1, player_scores[i]);
        }

        int player_turn; // The current player's turn
        for(player_turn = 0; player_turn < num_players; player_turn++) {
            printf("It's Player %d's turn. Press enter to roll.", player_turn+1);
            getchar(); // Wait for the player to press enter
            int roll = rand() % 6 + 1; // Generate a random number between 1 and 6
            printf("You rolled a %d.\n", roll);
            player_scores[player_turn] += roll;
            if(player_scores[player_turn] >= MAX_SCORE) { // Game over
                printf("Player %d wins!\n", player_turn+1);
                return 0;
            }
        }
    }
}