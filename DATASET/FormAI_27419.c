//FormAI DATASET v1.0 Category: Funny ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    // Seed random number generator with current time
    srand(time(0));

    // Generate a random number between 1 and 100
    int secretNumber = rand() % 100 + 1;

    // Initialize user's guess and guess count
    int guess = 0;
    int numGuesses = 0;

    // Loop until user guesses secret number or runs out of guesses
    while (guess != secretNumber && numGuesses < 10) {
        // Prompt user for guess
        printf("Guess a number between 1 and 100: ");
        scanf("%d", &guess);

        // Increment guess count
        numGuesses++;

        // Check if user's guess is correct, too high, or too low
        if (guess == secretNumber) {
            printf("Congratulations! You guessed the number in %d guesses.\n", numGuesses);
        } else if (guess < secretNumber) {
            printf("Too low! ");
        } else {
            printf("Too high! ");
        }

        // Give the user a hint
        if (secretNumber % 2 == 0) {
            printf("The secret number is even.\n");
        } else {
            printf("The secret number is odd.\n");
        }
    }

    // Check if user ran out of guesses
    if (numGuesses == 10) {
        printf("You ran out of guesses! The secret number was %d.\n", secretNumber);
    }

    return 0;
}