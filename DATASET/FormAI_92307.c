//FormAI DATASET v1.0 Category: Game ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_GUESSES 5
#define MAX_NUM 100

int main()
{
    int number_to_guess, guess, num_guesses = 0;

    // Set the seed for the random number generator
    srand(time(NULL));

    // Generate a random number between 1 and MAX_NUM
    number_to_guess = rand() % MAX_NUM + 1;

    printf("Welcome to the Number Guessing Game!\n");
    printf("I'm thinking of a number between 1 and %d.\n", MAX_NUM);

    // Allow the user to make up to MAX_GUESSES guesses
    while (num_guesses < MAX_GUESSES) {
        printf("Guess #%d: ", num_guesses + 1);
        scanf("%d", &guess);

        // Check if the guess is correct
        if (guess == number_to_guess) {
            printf("Congratulations! You guessed the number in %d guesses.\n", num_guesses + 1);
            return 0;
        } else if (guess < number_to_guess) {
            printf("Sorry, your guess is too low.\n");
        } else {
            printf("Sorry, your guess is too high.\n");
        }

        num_guesses++;
    }

    printf("Sorry, you ran out of guesses. The number I was thinking of was %d.\n", number_to_guess);

    return 0;
}