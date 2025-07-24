//FormAI DATASET v1.0 Category: Dice Roller ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int rollDice(); // Declare function for rolling the dice

int main() {
    int player1 = 0, player2 = 0; // Variables for storing scores
    srand(time(NULL)); // Seed random number generator
    printf("Welcome to the Dice Roller game!\n");
    printf("Player 1, it's your turn to roll the dice!\n");
    player1 += rollDice(); // Roll dice and add result to player1 score
    printf("Player 1, your score is %d\n", player1);
    printf("Player 2, it's your turn to roll the dice!\n");
    player2 += rollDice(); // Roll dice and add result to player2 score
    printf("Player 2, your score is %d\n", player2);
    printf("Let's play another round!\n");
    printf("Player 1, it's your turn to roll the dice!\n");
    player1 += rollDice(); // Roll dice and add result to player1 score
    printf("Player 1, your score is now %d\n", player1);
    printf("Player 2, it's your turn to roll the dice!\n");
    player2 += rollDice(); // Roll dice and add result to player2 score
    printf("Player 2, your score is now %d\n", player2);
    printf("The game is over!\n");
    if (player1 > player2) {
        printf("Congratulations Player 1, you win!\n");
    } else if (player2 > player1) {
        printf("Congratulations Player 2, you win!\n");
    } else {
        printf("It's a tie!\n");
    }
    return 0; // End program
}

int rollDice() {
    int result = rand() % 6 + 1; // Generate random number between 1 and 6
    printf("You rolled a %d!\n", result);
    return result;
}