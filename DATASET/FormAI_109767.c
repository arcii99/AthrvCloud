//FormAI DATASET v1.0 Category: Table Game ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int playerScore = 0, computerScore = 0;
    int playerTurn = 1; // 1 for player's turn, 0 for computer's turn

    srand(time(NULL)); // seed for random number generation

    // Game loop
    while (1) {
        if (playerTurn) {
            printf("Your turn! Enter a number between 1 and 10:\n");
            int playerChoice;
            scanf("%d", &playerChoice);
            while (playerChoice < 1 || playerChoice > 10) { // validate input
                printf("Invalid input. Enter a number between 1 and 10:\n");
                scanf("%d", &playerChoice);
            }
            playerScore += playerChoice;
            printf("Your score: %d\n", playerScore);
            if (playerScore >= 50) {
                printf("Congratulations, you win!\n");
                break;
            }
            playerTurn = 0; // switch to computer's turn
        } else {
            printf("Computer's turn...\n");
            int computerChoice = rand() % 10 + 1; // random number between 1 and 10
            printf("Computer chooses %d\n", computerChoice);
            computerScore += computerChoice;
            printf("Computer's score: %d\n", computerScore);
            if (computerScore >= 50) {
                printf("Sorry, the computer wins!\n");
                break;
            }
            playerTurn = 1; // switch to player's turn
        }
    }
    return 0;
}