//FormAI DATASET v1.0 Category: Table Game ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Initialize random seed
    srand(time(NULL));
    
    // Declare variables
    int player1_score = 0, player2_score = 0, current_player = 1, dice_roll = 0, choice = 0;
    
    // Game loop
    while (player1_score < 100 && player2_score < 100) {
        printf("Current scores:\nPlayer 1: %d\nPlayer 2: %d\n", player1_score, player2_score);
        printf("Player %d's turn:\n", current_player);
        
        // Roll dice and add score
        dice_roll = rand() % 6 + 1;
        printf("You rolled a %d!\n", dice_roll);
        
        if (dice_roll == 1) {
            printf("You rolled a 1 and lost all your points!\n");
            if (current_player == 1) player1_score = 0;
            else player2_score = 0;
            current_player = current_player == 1 ? 2 : 1;
            continue;
        }
        
        printf("Would you like to:\n1. Add the roll to your score\n2. Pass the turn to the other player\n");
        scanf("%d", &choice);
        
        if (choice == 1) {
            if (current_player == 1) player1_score += dice_roll;
            else player2_score += dice_roll;
        }
        
        current_player = current_player == 1 ? 2 : 1;
    }
    
    // Check winner
    if (player1_score >= 100) printf("Player 1 wins!\n");
    else printf("Player 2 wins!\n");
    
    return 0;
}