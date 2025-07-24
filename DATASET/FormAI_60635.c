//FormAI DATASET v1.0 Category: Table Game ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
Introspective C Table Game:
A game program written by an AI chatbot to test the player's luck and strategic thinking. 
*/

int main() {
    srand(time(NULL)); //initialize random seed

    //Game variables
    int playerScore = 0;
    int computerScore = 0;
    int currentPlayer = 1; //1 means it's the player's turn, 2 means it's the computer's turn
    int turnsPlayed = 0;

    printf("Welcome to the Introspective C Table Game!\n");
    printf("You will compete against the computer to score points by rolling a die.\n");
    printf("The game will continue for 10 turns. The player with the highest score at the end wins!\n");

    //Game loop
    while(turnsPlayed < 10) {
        int roll = rand() % 6 + 1; //generate a random number between 1 and 6 for the die roll

        //Print turn information
        printf("\nTurn %d\n", turnsPlayed + 1);
        printf("Player %d rolled a %d\n", currentPlayer, roll);

        //Update scores
        if(currentPlayer == 1) {
            playerScore += roll;
            currentPlayer = 2;
        } else {
            computerScore += roll;
            currentPlayer = 1;
        }

        turnsPlayed++; //increment turn counter
    }

    //Print final results
    printf("\nFinal Score:\n");
    printf("Player 1: %d\n", playerScore);
    printf("Computer: %d\n", computerScore);

    //Determine winner
    if(playerScore > computerScore) {
        printf("Congratulations! You win!\n");
    } else if(computerScore > playerScore) {
        printf("Sorry, the computer wins. Better luck next time!\n");
    } else {
        printf("It's a tie! Nice try!\n");
    }

    return 0; //indicate successful program execution
}