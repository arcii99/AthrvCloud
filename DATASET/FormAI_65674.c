//FormAI DATASET v1.0 Category: Table Game ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    // Set up random number generator
    srand(time(NULL));
    
    // Initialize game variables
    int numPlayers = 2;
    int maxScore = 50;
    int currentPlayer = 0;
    int totalScore = 0;
    int rollScore = 0;
    int die1, die2;
    
    // Main game loop
    while(totalScore < maxScore){
        // Output current player and total score
        printf("Player %d, your total score is %d\n", currentPlayer+1, totalScore);
        
        // Prompt current player to roll dice
        printf("Press enter to roll the dice\n");
        getchar();
        
        // Roll dice and calculate roll score
        die1 = rand() % 6 + 1;
        die2 = rand() % 6 + 1;
        rollScore = die1 + die2;
        printf("You rolled %d + %d = %d\n", die1, die2, rollScore);
        
        // Check for doubles
        if(die1 == die2){
            printf("DOUBLES! Roll again!\n");
            die1 = rand() % 6 + 1;
            die2 = rand() % 6 + 1;
            rollScore += die1 + die2;
            printf("You rolled %d + %d = %d\n", die1, die2, rollScore);
        }
        
        // Update total score and check for win
        totalScore += rollScore;
        if(totalScore >= maxScore){
            printf("Player %d wins with a score of %d!\n", currentPlayer+1, totalScore);
            break;
        }
        
        // Switch to next player
        currentPlayer++;
        if(currentPlayer == numPlayers){
            currentPlayer = 0;
        }
    }
    
    return 0;
}