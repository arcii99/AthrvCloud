//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    // Welcome message for the player
    printf("Welcome to Guess the Number game!\n");
    printf("I'm thinking of a number between 1 and 100.\n");
    printf("Can you guess what it is?\n\n");

    // Generating a random number between 1 and 100
    srand(time(NULL));
    int secretNumber = rand() % 100 + 1;

    // Declaring variables for player's guesses and guess count
    int guess, numGuesses = 0;

    // Loop for player's guesses
    while (1)
    {
        printf("Enter your guess: ");
        scanf("%d", &guess);

        // Counting player's guesses
        numGuesses++;

        // Checking if player's guess is correct, too low, or too high
        if (guess == secretNumber)
        {
            printf("Congratulations! You guessed the number in %d tries.\n", numGuesses);
            break;
        }
        else if (guess < secretNumber)
        {
            printf("Too low! Try again.\n");
        }
        else
        {
            printf("Too high! Try again.\n");
        }
    }

    return 0;
}