//FormAI DATASET v1.0 Category: Game ; Style: content
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int numberToGuess, userGuess;
    srand(time(0)); // to seed the random generator with current time
    numberToGuess = rand() % 100 + 1;
    printf("\nWelcome to the Guessing Game!\n");
    printf("I've picked a number between 1 to 100, can you guess it?\n");

    int guessCount = 0;
    do
    {
        printf("\nEnter your guess: ");
        scanf("%d", &userGuess);
        guessCount++;

        if (userGuess == numberToGuess)
        {
            printf("\nCongratulations! You guessed it right in %d attempts!\n", guessCount);
        }
        else if (userGuess > numberToGuess)
        {
            printf("Oops, you guessed too high. Try again.\n");
        }
        else
        {
            printf("Oops, you guessed too low. Try again.\n");
        }
    } while (userGuess != numberToGuess);

    return 0;
}