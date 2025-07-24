//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL)); // Seed the random number generator
    int secretNumber = rand() % 100 + 1; // Generate a random number between 1 and 100
    int guess = 0;
    int numGuesses = 0;

    printf("I'm thinking of a number between 1 and 100. Can you guess what it is?\n");

    while (guess != secretNumber)
    {
        printf("Enter your guess: ");
        scanf("%d", &guess);
        numGuesses++;

        if (guess < secretNumber)
        {
            printf("Too low!\n");
        }
        else if (guess > secretNumber)
        {
            printf("Too high!\n");
        }
        else
        {
            printf("Congratulations! You guessed the number in %d guesses.\n", numGuesses);
        }
    }

    return 0;
}