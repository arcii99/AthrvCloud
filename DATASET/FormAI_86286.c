//FormAI DATASET v1.0 Category: Game ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int guess, number_of_guesses = 0, number_to_guess;
    srand(time(0)); // seed for random number generator
    number_to_guess = rand() % 100 + 1; // generates a random number between 1 and 100

    printf("Welcome to the Guessing Game!\n");
    printf("Guess the number between 1 and 100\n");

    do
    {
        printf("Enter your guess: ");
        scanf("%d", &guess);
        number_of_guesses++;

        if (guess > number_to_guess)
        {
            printf("Too high, try again!\n");
        }
        else if (guess < number_to_guess)
        {
            printf("Too low, try again!\n");
        }
        else
        {
            printf("Congratulations, you guessed the number in %d attempts!\n", number_of_guesses);
        }
    } while (guess != number_to_guess);

    return 0;
}