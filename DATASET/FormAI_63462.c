//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int guess, number_of_attempts = 0;
    time_t t;
    srand((unsigned) time(&t));
    int number_to_guess = rand() % 100 + 1;

    printf("Welcome to the Guessing Game!\n");
    printf("You have 7 attempts to guess a number between 1 and 100.\n");

    do
    {
        printf("Enter your guess: ");
        scanf("%d", &guess);
        number_of_attempts++;

        if (guess < number_to_guess)
        {
            printf("Too low! Guess again.\n");
        }
        else if (guess > number_to_guess)
        {
            printf("Too high! Guess again.\n");
        }
    } while (guess != number_to_guess && number_of_attempts < 7);

    if (guess == number_to_guess)
    {
        printf("Congratulations! You guessed the number in %d attempts!\n", number_of_attempts);
    }
    else if (number_of_attempts == 7)
    {
        printf("Sorry, you have run out of attempts. The number was %d.\n", number_to_guess);
    }

    return 0;
}