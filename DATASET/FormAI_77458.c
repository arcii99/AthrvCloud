//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    // Initialize variables
    int numberToGuess = 0, userGuess = 0, numGuesses = 0;
    srand(time(NULL)); // Seed random number generator with current time
    numberToGuess = rand() % 100; // Generate random number between 0 and 100

    // Game loop
    while (1) {
        printf("\nEnter your guess (0-100): ");
        scanf("%d", &userGuess);
        numGuesses++;

        if (userGuess < numberToGuess) {
            printf("Too low!\n");
        } else if (userGuess > numberToGuess) {
            printf("Too high!\n");
        } else {
            // User guessed the number, end the game
            printf("Congratulations! You guessed the number in %d tries.\n", numGuesses);
            printf("Play again? (Y/N): ");

            char playAgain;
            scanf("%s", &playAgain);

            if (playAgain == 'Y' || playAgain == 'y') {
                // Reset game
                numberToGuess = rand() % 100;
                numGuesses = 0;
            } else {
                printf("Thanks for playing!\n");
                break;
            }
        }
    }

    return 0;
}