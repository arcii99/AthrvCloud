//FormAI DATASET v1.0 Category: Game ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int guess, number_of_guesses = 0, number_to_guess;
    srand(time(0));
    number_to_guess = rand() % 100 + 1;

    printf("\nWelcome to the Number Guessing Game!\n");
    printf("\nI'm thinking of a number between 1 and 100.");
    printf("\nCan you guess it?\n");

    do
    {
        printf("\nEnter your guess: ");
        scanf("%d", &guess);
        number_of_guesses++;

        if (guess < number_to_guess)
        {
            printf("Sorry, your guess is too low.\n");
        }
        else if (guess > number_to_guess)
        {
            printf("Sorry, your guess is too high.\n");
        }

    } while (guess != number_to_guess);

    printf("\nCongratulations! You guessed the number in %d tries.\n", number_of_guesses);

    return 0;
}