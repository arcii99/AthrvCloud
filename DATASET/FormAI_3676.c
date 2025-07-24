//FormAI DATASET v1.0 Category: Table Game ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int playerScore = 0, computerScore = 0, currentPlayer = 0, currentRound = 1;
    srand(time(NULL)); // initialize random seed
    
    printf("Welcome to the C Table Game!\n\n");
    
    do {
        printf("Round %d:\n\n", currentRound);
        printf("Player score: %d\tComputer score: %d\n", playerScore, computerScore);
        
        currentPlayer = rand() % 2 + 1; // randomly select player 1 or 2
        printf("Player %d's turn.\n", currentPlayer);
        
        int currentRoll = rand() % 6 + 1; // roll a dice with values 1 to 6
        printf("You rolled a %d.\n", currentRoll);
        
        if (currentPlayer == 1) {
            playerScore += currentRoll;
        } else {
            computerScore += currentRoll;
        }
        
        // check if player or computer has won
        if (playerScore >= 50 || computerScore >= 50) {
            printf("Player %d wins!\n", (playerScore >= 50) ? 1 : 2);
            break;
        }
        
        currentRound += 1;
        printf("Press ENTER to continue to the next round.\n");
        getchar(); // pause until user hits ENTER
        system("clear"); // clear console
    } while (1);

    return 0;
}