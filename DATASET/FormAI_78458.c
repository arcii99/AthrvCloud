//FormAI DATASET v1.0 Category: Table Game ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void clearScreen() {
    system("clear"); // For Unix-based systems
    // system("cls"); // For Windows-based systems
}

int main() {
    srand(time(NULL)); // Initialize random seed with current time

    int playerScore = 0;
    int computerScore = 0;
    int roundNumber = 1;

    printf("Welcome to the Table Game!\n\n");
    printf("Instructions:\n");
    printf("1. Each round, both player and computer will roll two dice.\n");
    printf("2. The player with the higher total score will win the round.\n");
    printf("3. If the scores are tied, the round will be a draw.\n");
    printf("4. The game will continue until one player has won three rounds.\n\n");

    while (playerScore < 3 && computerScore < 3) {
        printf("Round %d:\n", roundNumber);

        // Player roll
        int playerDie1 = rand() % 6 + 1;
        int playerDie2 = rand() % 6 + 1;
        int playerTotal = playerDie1 + playerDie2;
        printf("You rolled a %d and a %d, for a total of %d.\n", playerDie1, playerDie2, playerTotal);

        // Computer roll
        int computerDie1 = rand() % 6 + 1;
        int computerDie2 = rand() % 6 + 1;
        int computerTotal = computerDie1 + computerDie2;
        printf("The computer rolled a %d and a %d, for a total of %d.\n", computerDie1, computerDie2, computerTotal);

        // Determine winner of round
        if (playerTotal > computerTotal) {
            playerScore++;
            printf("You won the round!\n");
        } else if (computerTotal > playerTotal) {
            computerScore++;
            printf("The computer won the round.\n");
        } else {
            printf("The round was a draw.\n");
        }

        printf("You have won %d rounds and the computer has won %d rounds.\n\n", playerScore, computerScore);

        roundNumber++;

        // Pause for a moment before clearing the screen for the next round
        printf("Press enter to start the next round.");
        getchar();
        clearScreen();
    }

    // Determine winner of game
    if (playerScore > computerScore) {
        printf("Congratulations, you won the game!");
    } else {
        printf("Sorry, you lost the game.");
    }

    return 0;
}