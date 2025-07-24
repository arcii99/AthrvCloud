//FormAI DATASET v1.0 Category: Table Game ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int numToGuess, guess, minRange = 1, maxRange = 100, numPlayers, currentPlayer = 1;

    // Ask for number of players
    printf("Enter number of players: ");
    scanf("%d", &numPlayers);

    // Generate random number to guess
    srand(time(NULL));
    numToGuess = rand() % 100 + 1;

    // Loop until someone guesses the correct number
    do {
        printf("Player %d's turn.\n", currentPlayer);
        printf("Guess a number between %d and %d: ", minRange, maxRange);
        scanf("%d", &guess);

        if (guess < numToGuess) {
            printf("Too low\n");
            minRange = guess + 1;
        } else if (guess > numToGuess) {
            printf("Too high\n");
            maxRange = guess - 1;
        } else {
            printf("Player %d wins!\n", currentPlayer);
            break;
        }

        // Move on to the next player
        currentPlayer++;
        if (currentPlayer > numPlayers) {
            currentPlayer = 1;
        }
    } while (1);

    return 0;
}