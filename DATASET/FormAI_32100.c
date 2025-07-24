//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int secretNum, guess, numGuesses = 0;
    srand(time(0)); // seed rand() with time
    secretNum = rand() % 100 + 1; // generate random number between 1-100

    printf("========================\n");
    printf("Welcome to Guess the Number Game\n");
    printf("========================\n\n");

    do {
        printf("Enter a guess between 1-100: ");
        scanf("%d", &guess);
        numGuesses++;

        if(guess > secretNum)
        {
            printf("Too high. Guess again.\n\n");
        }
        else if(guess < secretNum)
        {
            printf("Too low. Guess again.\n\n");
        }
        else
        {
            printf("\nCongratulations! You guessed the secret number in %d guesses.\n", numGuesses);
        }
    } while(guess != secretNum);

    return 0;
}