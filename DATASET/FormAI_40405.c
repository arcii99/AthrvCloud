//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL)); //initialize random seed

    int secretNumber = rand() % 100 + 1; //generate random number between 1 and 100
    int guess, numGuesses = 0;

    printf("Welcome to the guessing game! You have 5 attempts to guess the secret number.\n");

    do
    {
        printf("Enter your guess: ");
        scanf("%d", &guess);
        numGuesses++;

        if (guess < secretNumber)
        {
            printf("Too low! Guess again.\n");
        }
        else if (guess > secretNumber)
        {
            printf("Too high! Guess again.\n");
        }
        else
        {
            printf("Congratulations, you guessed the secret number in %d guesses!\n", numGuesses);
            return 0;
        }

    } while (numGuesses < 5);

    printf("Sorry, you've run out of guesses. The secret number was %d. Better luck next time!\n", secretNumber);

    return 0;
}