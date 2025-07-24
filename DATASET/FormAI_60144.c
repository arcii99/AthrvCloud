//FormAI DATASET v1.0 Category: Game ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Initialize variables
    int playerScore = 0;
    int computerScore = 0;
    int playerChoice, computerChoice;
    srand(time(NULL));
    
    printf("Welcome to the Romeo and Juliet game!\n");
    
    // Loop through 5 rounds
    for(int i = 1; i <= 5; i++) {
        printf("\n\nRound %d\n", i);
        printf("Choose your weapon!\n1. Sword\n2. Dagger\n3. Poison\n");
        scanf("%d", &playerChoice);
        
        // Generate computer choice
        computerChoice = rand() % 3 + 1;
        
        // Determine winner of round
        if(playerChoice == computerChoice) {
            printf("It's a tie! No points awarded.");
        } else if(playerChoice == 1 && computerChoice == 2 || 
                  playerChoice == 2 && computerChoice == 3 || 
                  playerChoice == 3 && computerChoice == 1) {
            printf("You win this round!");
            playerScore++;
        } else {
            printf("The computer wins this round.");
            computerScore++;
        }
    }
    
    // Determine winner of game
    printf("\n\nGame over. Final score:\nYou: %d\nComputer: %d\n", playerScore, computerScore);
    if(playerScore == computerScore) {
        printf("It's a tie!");
    } else if(playerScore > computerScore) {
        printf("Congratulations, you win!");
    } else {
        printf("Sorry, the computer wins.");
    }
    
    return 0;
}