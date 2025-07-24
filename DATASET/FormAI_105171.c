//FormAI DATASET v1.0 Category: Table Game ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Function to randomly generate a number from 1 to 6
int rollDice(){
    int randNum = rand() % 6 + 1;
    return randNum;
}

//Function to run the game
void playGame(){
    int player1Score = 0, player2Score = 0; //initial scores
    int turn = 1; //player 1 starts the game
    int diceRoll;

    printf("\n--- LET'S PLAY THE C TABLE GAME! ---\n");

    while(player1Score < 50 && player2Score < 50){ //game ends once a player reaches 50 points

        printf("\n*** PLAYER %d'S TURN ***\n", turn);

        if(turn == 1){
            printf("Rolling the dice for Player 1...\n");
            diceRoll = rollDice(); //player 1 rolls the dice
            printf("Player 1 rolled a %d!\n", diceRoll);

            if(diceRoll == 6){ //bonus roll if player rolls a 6
                printf("You rolled a 6! Roll the dice again!\n");
                diceRoll = rollDice();
                printf("Player 1 rolled a %d!\n", diceRoll);
                player1Score += diceRoll;
            }
            else{
                player1Score += diceRoll;
            }

            printf("Player 1's score: %d\n", player1Score);
            turn = 2; //player 2's turn

        }
        else{
            printf("Rolling the dice for Player 2...\n");
            diceRoll = rollDice(); //player 2 rolls the dice
            printf("Player 2 rolled a %d!\n", diceRoll);

            if(diceRoll == 6){ //bonus roll if player rolls a 6
                printf("You rolled a 6! Roll the dice again!\n");
                diceRoll = rollDice();
                printf("Player 2 rolled a %d!\n", diceRoll);
                player2Score += diceRoll;
            }
            else{
                player2Score += diceRoll;
            }

            printf("Player 2's score: %d\n", player2Score);
            turn = 1; //player 1's turn

        }

    }

    //declare winner
    if(player1Score >= 50){
        printf("\nPlayer 1 wins! Congratulations!\n");
    }
    else{
        printf("\nPlayer 2 wins! Congratulations!\n");
    }

}

int main(){

    srand(time(NULL)); //seed for random number generation

    printf("--- WELCOME TO THE C TABLE GAME ---\n");
    printf("Instructions: Each player rolls the dice once per turn. If you roll a 6, you get to roll again! The first player who reaches a score of 50 wins the game!\n");

    char response;
    do{
        playGame();

        printf("\nDo you want to play again? (Y/N): ");
        scanf("%c", &response);
        getchar(); //clear input buffer

    }while(toupper(response) == 'Y');

    printf("\nThank you for playing the C Table Game! Goodbye!\n");

    return 0;
}