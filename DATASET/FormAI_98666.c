//FormAI DATASET v1.0 Category: Table Game ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int player1_score = 0, player2_score = 0, rounds;
    printf("Welcome to the Table Game!\n\n");
    srand(time(NULL));
    printf("Enter the number of rounds you want to play: ");
    
    // taking the input for number of rounds to be played
    scanf("%d", &rounds);
    printf("\n");

    for (int i = 1; i <= rounds; i++) {
        printf("Round %d\n", i);
        printf("Player 1's turn: ");
        // generating a random number between 1 and 6 for player 1
        int roll1 = rand() % 6 + 1;
        printf("%d\n", roll1);
        printf("Player 2's turn: ");
        // generating a random number between 1 and 6 for player 2
        int roll2 = rand() % 6 + 1;
        printf("%d\n", roll2);
        printf("\n");
        
        if (roll1 > roll2) {
            printf("Player 1 wins the round!\n");
            player1_score++;
        } else if (roll2 > roll1) {
            printf("Player 2 wins the round!\n");
            player2_score++;
        } else {
            printf("It's a tie!\n");
        }
        
        printf("Current score: \nPlayer 1: %d\nPlayer 2: %d\n\n", player1_score, player2_score);
    }
    
    if (player1_score > player2_score) {
        printf("Player 1 wins the game!\n");
    } else if (player2_score > player1_score) {
        printf("Player 2 wins the game!\n");
    } else {
        printf("The game is tied!\n");
    }
    
    return 0;
}