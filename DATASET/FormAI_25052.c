//FormAI DATASET v1.0 Category: Table Game ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int player_score = 0, computer_score = 0;
    int round_number = 1;
    srand(time(0)); // set seed for random number generation
    
    printf("--------------------------------------------------\n");
    printf("-------------------- C TABLE GAME -----------------\n");
    printf("--------------------------------------------------\n\n");
    printf("Instructions: \n");
    printf("Roll a 6-sided die. If the number rolled is odd,\n");
    printf("add it to your score. If it's even, subtract it.\n");
    printf("The first player to reach 50 points wins!\n\n");
    
    while (player_score < 50 && computer_score < 50) {
        printf("--------------------------------------------------\n");
        printf("Round %d: \n", round_number);
        printf("Current Scores: You - %d   Computer - %d\n", player_score, computer_score);
        
        // player's turn
        printf("\nIt's your turn! Press enter to roll the die.");
        getchar(); // wait for input
        int player_roll = rand() % 6 + 1;
        printf("You rolled a %d!\n", player_roll);
        if (player_roll % 2 == 0) {
            player_score -= player_roll;
            printf("Oops! That's even. You lose %d points.\n", player_roll);
        } else {
            player_score += player_roll;
            printf("Nice! That's odd. You gain %d points.\n", player_roll);
        }
        
        if (player_score >= 50) { // check if player won
            printf("\nCongratulations! You won the game!\n");
            break;
        }
        
        // computer's turn
        printf("\nNow it's the computer's turn. Press enter to continue.");
        getchar(); // wait for input
        int computer_roll = rand() % 6 + 1;
        printf("The computer rolled a %d!\n", computer_roll);
        if (computer_roll % 2 == 0) {
            computer_score -= computer_roll;
            printf("Oops! That's even. The computer loses %d points.\n", computer_roll);
        } else {
            computer_score += computer_roll;
            printf("Nice! That's odd. The computer gains %d points.\n", computer_roll);
        }
        
        if (computer_score >= 50) { // check if computer won
            printf("\nSorry, the computer won the game. Better luck next time!\n");
            break;
        }
        
        round_number++; // go to next round
    }
    
    printf("\nThanks for playing the C Table Game!\n");
    printf("--------------------------------------------------\n");
    return 0;
}