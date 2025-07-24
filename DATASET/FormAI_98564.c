//FormAI DATASET v1.0 Category: Game ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Let's play a game of guessing a number between 1 and 100

int main()
{
    int randomNumber, guess, numGuesses = 0;
    char playAgain = 'y';

    // Keep playing until player decides to quit
    while (playAgain == 'y')
    {
        // Generate a random number between 1 and 100
        srand(time(NULL)); // Seed the random number generator
        randomNumber = rand() % 100 + 1;

        printf("I am thinking of a number between 1 and 100. Can you guess what it is?\n");

        // Keep guessing until player gets the right number
        do
        {
            scanf("%d", &guess);
            numGuesses++;

            if (guess < randomNumber)
            {
                printf("Too low! Guess again.\n");
            }
            else if (guess > randomNumber)
            {
                printf("Too high! Guess again.\n");
            }
            else
            {
                printf("Congratulations! You guessed the number in %d guesses.\n", numGuesses);
            }
        } while (guess != randomNumber);

        // Ask if player wants to play again
        printf("Do you want to play again? (y/n) ");
        scanf(" %c", &playAgain);
        numGuesses = 0; // Reset guess counter for new game
    }

    return 0;
}