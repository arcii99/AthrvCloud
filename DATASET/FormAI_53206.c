//FormAI DATASET v1.0 Category: Table Game ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// function to generate a random number between 1 and 6 (inclusive)
int rollDice() {
    int num = rand() % 6 + 1;
    printf("You rolled a %d!\n", num);
    return num;
}

int main() {
    int playerScore = 0;
    int computerScore = 0;
    
    srand(time(NULL)); // seed the random number generator
    
    printf("Let's play a game of C Table!\n");
    printf("You will take turns rolling a dice and adding the number to your score.\n");
    printf("The first player to reach a score of 50 wins!\n");
    
    while (playerScore < 50 && computerScore < 50) {
        printf("\nYour turn:\n");
        int playerRoll = rollDice();
        playerScore += playerRoll;
        printf("Your score: %d\n", playerScore);
        
        // check if the player has won
        if (playerScore >= 50) {
            printf("\nCongratulations, you won with a score of %d!\n", playerScore);
            break;
        }
        
        printf("\nComputer's turn:\n");
        int computerRoll = rollDice();
        computerScore += computerRoll;
        printf("Computer's score: %d\n", computerScore);
        
        // check if the computer has won
        if (computerScore >= 50) {
            printf("\nSorry, the computer won with a score of %d.\n", computerScore);
            break;
        }
    }
    
    return 0;
}