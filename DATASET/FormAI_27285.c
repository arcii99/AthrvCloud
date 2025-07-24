//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(0)); //initialize random seed

    int number = rand() % 100 + 1; //generate random number between 1 and 100
    int guess, tries = 0; //initialize variables for user's guess and number of tries

    printf("Welcome to the Guessing Game!\n\n");

    do
    {
        printf("Guess a number between 1 and 100: ");
        scanf("%d", &guess);
        tries++; //increment number of tries

        if (guess > number)
        {
            printf("Too high! Try again\n\n");
        }
        else if (guess < number)
        {
            printf("Too low! Try again\n\n");
        }
        else
        {
            printf("Congratulations! You guessed the number in %d tries!\n\n", tries);
        }

    } while (guess != number); //repeat until the user guesses correctly

    printf("Thanks for playing! Have a great day!\n");

    return 0;
}