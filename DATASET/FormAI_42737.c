//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    //initialize variables
    int numGuesses = 0;
    int guess;
    int randomNumber;

    //generate random number
    srand(time(0));
    randomNumber = rand() % 100 + 1;

    //print instructions
    printf("Welcome to the Guessing Game!\n");
    printf("I'm thinking of a number between 1 and 100. Can you guess it?\n");

    //loop until user guesses correctly
    while(1)
    {
        //get user input
        printf("Enter your guess: ");
        scanf("%d", &guess);
        numGuesses++;

        //check if guess is too high, too low, or correct
        if(guess > randomNumber)
        {
            printf("Too high! Try again.\n");
        }
        else if(guess < randomNumber)
        {
            printf("Too low! Try again.\n");
        }
        else
        {
            printf("Congratulations! You guessed the number in %d tries.\n", numGuesses);
            break;
        }
    }

    return 0;
}