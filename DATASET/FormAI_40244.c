//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int numberToGuess, guess, numberOfGuesses = 0;
    srand(time(0));
    numberToGuess = rand() % 100 + 1; // Generate random number between 1-100

    printf("\n\n\tWelcome to the Number Guessing Game!");
    printf("\n\n\tI'm thinking of a number between 1 and 100.");
    printf("\n\n\tCan you guess what it is?\n");

    do{
        printf("\nEnter your guess: ");
        scanf("%d",&guess);
        numberOfGuesses++;

        if(guess > numberToGuess)
        {
            printf("Too high! Try again.\n");
        }
        else if(guess < numberToGuess)
        {
            printf("Too low! Try again.\n");
        }
        else
        {
            printf("\nCongratulations! You guessed it in %d attempts!\n",numberOfGuesses);
        }
    }while(guess != numberToGuess);

    return 0;
}