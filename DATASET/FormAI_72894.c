//FormAI DATASET v1.0 Category: Table Game ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Cheerful C Table Game Example */

int main() {
    srand(time(NULL)); // Seed random number generator
    
    printf("\nWelcome to the Table Game!\n");
    printf("In this game, you will roll two dice and try to reach a table before your opponent.\n");
    printf("Let's get started!\n");
    
    // Set player positions and randomize first turn
    int player1_pos = 0;
    int player2_pos = 0;
    int current_player = rand() % 2 + 1;
    
    // Game loop
    while (player1_pos < 10 && player2_pos < 10) {
        // Display current positions
        printf("\nPlayer 1: Table %d\n", player1_pos);
        printf("Player 2: Table %d\n\n", player2_pos);
        
        // Get roll from current player
        printf("Player %d, press enter to roll the dice!\n", current_player);
        getchar();
        int roll1 = rand() % 6 + 1;
        int roll2 = rand() % 6 + 1;
        printf("You rolled a %d and a %d!\n", roll1, roll2);
        
        // Calculate new position and check for table
        int new_pos = current_player == 1 ? player1_pos + roll1 + roll2 : player2_pos + roll1 + roll2;
        if (new_pos >= 10) {
            printf("You reached the table! Congratulations player %d, you win!\n", current_player);
            return 0;
        } else {
            printf("You moved %d spaces.\n", roll1 + roll2);
            current_player = current_player == 1 ? 2 : 1; // Switch to other player's turn
            if (current_player == 1) {
                player1_pos = new_pos;
            } else {
                player2_pos = new_pos;
            }
        }
    }
    
    // If loop exits, both players have less than 10 spaces
    printf("Unfortunately, no one reached the table this time. Better luck next time!\n");
    return 0;
}