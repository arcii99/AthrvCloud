//FormAI DATASET v1.0 Category: Educational ; Style: relaxed
/* This program will generate a random number and let the user guess the number
   until the correct one is found. */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int randomNumber, guess, tries = 0;

    // Set the random seed for the random number generator
    srand(time(0));
    
    // Generate a random number between 1 and 100
    randomNumber = rand() % 100 + 1;

    printf("Welcome to the Number Guessing Game!\n");
    printf("I am thinking of a number between 1 and 100, can you guess it?\n\n");

    do
    {
        printf("Enter your guess: ");
        scanf("%d", &guess);

        // Check if the guess is too high or too low
        if (guess > randomNumber)
        {
            printf("Your guess is too high! Try again.\n\n");
            tries++;
        }
        else if (guess < randomNumber)
        {
            printf("Your guess is too low! Try again.\n\n");
            tries++;
        }
        else
        {
            printf("Congratulations! You guessed the correct number in %d tries!\n", tries+1);
        }

    } while (guess != randomNumber);

    return 0;
}