//FormAI DATASET v1.0 Category: Table Game ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    // Initialize game variables
    int playerScore = 0;
    int computerScore = 0;
    int roundNumber = 1;
    srand(time(NULL));

    // Display game instructions
    printf("Welcome to Visionary Table Game!\n");
    printf("The goal of the game is to score as many points as possible in each round.\n");
    printf("The player and computer will roll two dice each, and the highest total score wins the round.\n");
    printf("The game consists of three rounds, and the player with the highest total score at the end wins!\n");

    // Begin game loop
    while (roundNumber <= 3){
        printf("\n--- ROUND %d ---\n", roundNumber);

        // Player's turn
        printf("Press enter to roll the dice...");
        getchar();
        int playerDice1 = rand() % 6 + 1;
        int playerDice2 = rand() % 6 + 1;
        int playerTotalScore = playerDice1 + playerDice2;
        printf("You rolled a %d and a %d, for a total of %d points!\n", playerDice1, playerDice2, playerTotalScore);

        // Computer's turn
        printf("Now it's the computer's turn...\n");
        int computerDice1 = rand() % 6 + 1;
        int computerDice2 = rand() % 6 + 1;
        int computerTotalScore = computerDice1 + computerDice2;
        printf("The computer rolled a %d and a %d, for a total of %d points!\n", computerDice1, computerDice2, computerTotalScore);

        // Determine round winner
        if(playerTotalScore > computerTotalScore){
            printf("Congratulations! You have won round %d!\n", roundNumber);
            playerScore++;
        }
        else if(playerTotalScore < computerTotalScore){
            printf("Sorry, the computer has won round %d...\n", roundNumber);
            computerScore++;
        }
        else{
            printf("It's a tie! No one wins round %d.\n", roundNumber);
        }

        // Display round scores
        printf("Scores after round %d: You: %d / Computer: %d\n", roundNumber, playerScore, computerScore);

        // End of round
        roundNumber++;
    }

    // Determine game winner
    printf("\n--- GAME OVER ---\n");

    if(playerScore > computerScore){
        printf("Congratulations, you have won the game with a score of %d to %d!\n", playerScore, computerScore);
    }
    else if(playerScore < computerScore){
        printf("Sorry, the computer has won the game with a score of %d to %d.\n", computerScore, playerScore);
    }
    else{
        printf("It's a tie game with a score of %d to %d.\n", playerScore, computerScore);
    }

    return 0;
}