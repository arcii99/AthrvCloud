//FormAI DATASET v1.0 Category: Table Game ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Function to roll the dice
int rollDice() {
    int diceValue = rand() % 6 + 1;
    return diceValue;
}

//Function to print the board
void printBoard(int player1, int player2) {
    printf("\n");
    printf("Player 1: ");
    for(int i=1; i<=30; i++) {
        if(i == player1) {
            printf("X");
        }
        else {
            printf("-");
        }
    }
    printf("\n");
    printf("Player 2: ");
    for(int i=1; i<=30; i++) {
        if(i == player2) {
            printf("O");
        }
        else {
            printf("-");
        }
    }
    printf("\n");
}

int main() {

    //Variables to store the position of players on the board
    int player1 = 1;
    int player2 = 1;

    //Variable to store the value of dice
    int diceValue;

    //Variable to store the turn of the player
    int turn = 1;

    //Seed the random number generator
    srand(time(NULL));

    //Game loop
    while(1) {

        //Print the board
        printBoard(player1, player2);

        //Roll the dice
        diceValue = rollDice();

        //If turn is of Player 1
        if(turn == 1) {
            printf("Player 1 rolled %d\n", diceValue);
            player1 += diceValue;
            if(player1 > 30) {
                player1 = 30;
            }
            turn = 2;
        }
        //If turn is of Player 2
        else {
            printf("Player 2 rolled %d\n", diceValue);
            player2 += diceValue;
            if(player2 > 30) {
                player2 = 30;
            }
            turn = 1;
        }

        //Check if any player has won
        if(player1 == 30) {
            printf("Congratulations! Player 1 has won the game.\n");
            break;
        }
        else if(player2 == 30) {
            printf("Congratulations! Player 2 has won the game.\n");
            break;
        }
    }

    return 0;
}