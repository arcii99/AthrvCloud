//FormAI DATASET v1.0 Category: Table Game ; Style: artistic
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
    int player1Score = 0, player2Score = 0, tempScore = 0, diceRoll, turn = 1;

    // Seed the random number generator
    srand(time(NULL));

    printf("Welcome to the Roll the Dice game!\n");

    // Loop for 10 rounds
    for (int i = 1; i <= 10; i++){
        printf("\nRound %d:\n", i);

        // Loop for each player's turn
        while (turn <= 2){

            // Player 1's turn
            if (turn == 1){
                printf("Player 1's turn\n");
                printf("Press enter to roll the dice");
                getchar();

                // Roll the dice
                diceRoll = rand() % 6 + 1;
                printf("You rolled a %d\n", diceRoll);

                // Check if player gets additional turn
                if (diceRoll == 6){
                    printf("You get an additional turn.\n");
                }
                else{
                    player1Score += tempScore + diceRoll;
                    printf("Your score is now %d\n", player1Score);

                    // Reset temporary score
                    tempScore = 0;
                }
            }
            // Player 2's turn
            else{
                printf("Player 2's turn\n");
                printf("Press enter to roll the dice");
                getchar();

                // Roll the dice
                diceRoll = rand() % 6 + 1;
                printf("You rolled a %d\n", diceRoll);

                // Check if player gets additional turn
                if (diceRoll == 6){
                    printf("You get an additional turn.\n");
                }
                else{
                    player2Score += tempScore + diceRoll;
                    printf("Your score is now %d\n", player2Score);

                    // Reset temporary score
                    tempScore = 0;
                }
            }

            // Check if player wins
            if (player1Score >= 100){
                printf("Player 1 wins!");
                return 0;
            }
            else if (player2Score >= 100){
                printf("Player 2 wins!");
                return 0;
            }

            // Check if player gets another turn
            if (diceRoll == 6){
                tempScore += diceRoll;
            }
            else{
                turn++;
            }
        }

        // Switch turn to next player
        if (turn == 3){
            turn = 1;
        }
    }

    // After 10 rounds, determine winner
    if (player1Score > player2Score){
        printf("Player 1 wins!");
    }
    else if (player2Score > player1Score){
        printf("Player 2 wins!");
    }
    else{
        printf("Tie game!");
    }

    return 0;
}