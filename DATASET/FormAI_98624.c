//FormAI DATASET v1.0 Category: Table Game ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Function to generate random numbers between 1-6 (for the dice)
int rollDice() {
    return rand() % 6 + 1; 
}

//Function to calculate the sum of the dice roll
int diceSum(int dice1, int dice2) {
    return dice1 + dice2;
}

int main() {
    srand(time(0)); //Initialize random seed

    int player1Score = 0, player2Score = 0; //Set initial scores for each player
    int player1Turn = 1, player2Turn = 0; //Set which player's turn it is

    while(player1Score < 100 && player2Score < 100) { //Keep playing until one player wins
        printf("-------------------------------------------------------\n");
        printf("Player 1: %d\t\t\tPlayer 2: %d\n", player1Score, player2Score);
        printf("-------------------------------------------------------\n");

        if(player1Turn) { //Player 1's turn
            printf("Player 1's turn:\n\n");
            printf("Press any key to roll the dice...");
            getchar(); //Wait for user input
            int dice1 = rollDice(); //Roll first dice
            printf("First dice: %d\n", dice1);
            int dice2 = rollDice(); //Roll second dice
            printf("Second dice: %d\n", dice2);

            int currentScore = diceSum(dice1, dice2); //Calculate current turn's score
            printf("Current turn's score: %d\n\n", currentScore);

            if(dice1 == dice2) { //Roll again if doubles are rolled
                printf("Player 1 rolled doubles! Roll again.\n");
                player1Score += diceSum(dice1, dice2); //Add to total score
            } else { //End turn
                player1Score += currentScore; //Add to total score
                player1Turn = 0; //Switch to other player's turn
                player2Turn = 1;
            }
        } else { //Player 2's turn
            printf("Player 2's turn:\n\n");
            printf("Press any key to roll the dice...");
            getchar(); //Wait for user input
            int dice1 = rollDice(); //Roll first dice
            printf("First dice: %d\n", dice1);
            int dice2 = rollDice(); //Roll second dice
            printf("Second dice: %d\n", dice2);

            int currentScore = diceSum(dice1, dice2); //Calculate current turn's score
            printf("Current turn's score: %d\n\n", currentScore);

            if(dice1 == dice2) { //Roll again if doubles are rolled
                printf("Player 2 rolled doubles! Roll again.\n");
                player2Score += diceSum(dice1, dice2); //Add to total score
            } else { //End turn
                player2Score += currentScore; //Add to total score
                player1Turn = 1; //Switch to other player's turn
                player2Turn = 0;
            }
        }
    }

    //Print winner
    if(player1Score >= 100) {
        printf("Player 1 wins with a score of %d!", player1Score);
    } else {
        printf("Player 2 wins with a score of %d!", player2Score);
    }

    return 0;
}