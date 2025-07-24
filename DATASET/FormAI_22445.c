//FormAI DATASET v1.0 Category: Table Game ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Function to roll the dice
int rollDice() {
    return (rand() % 6) + 1; //Generate a random number between 1 and 6
}

int main() {
    //Initialize variables
    int player1 = 0;
    int player2 = 0;
    int rollNum = 1;

    srand(time(NULL)); //Set random seed

    //Loop until a player reaches 100
    while (player1 < 100 && player2 < 100) {
        //Player 1 turn
        printf("Roll #%d:\n", rollNum);
        printf("Player 1, press enter to roll the dice.\n");
        getchar(); //Wait for player input
        int roll = rollDice();
        printf("You rolled a %d!\n", roll);
        player1 += roll;
        printf("Your total score is now %d.\n", player1);
        printf("----------------------------\n");
        if (player1 >= 100) {
            printf("Player 1 wins!");
            break;
        }

        //Player 2 turn
        printf("Roll #%d:\n", rollNum);
        printf("Player 2, press enter to roll the dice.\n");
        getchar(); //Wait for player input
        roll = rollDice();
        printf("You rolled a %d!\n", roll);
        player2 += roll;
        printf("Your total score is now %d.\n", player2);
        printf("----------------------------\n");
        if (player2 >= 100) {
            printf("Player 2 wins!");
            break;
        }

        rollNum++; //Increment roll number
    }

    return 0;
}