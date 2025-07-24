//FormAI DATASET v1.0 Category: Table Game ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int min = 1, max = 100, guess = 0, num_guesses = 0, secret_number;
    srand(time(NULL)); // initialize random seed
    secret_number = rand() % (max - min + 1) + min; // generate random secret number

    printf("Welcome to the Guessing Game!\n");
    printf("I am thinking of a number between %d and %d. Can you guess it?\n", min, max);

    // loop until the user guesses correctly
    while(guess != secret_number) {
        printf("Guess #%d: ", num_guesses + 1);
        scanf("%d", &guess);

        // check if the guess is within range
        if(guess < min || guess > max) {
            printf("Invalid guess. Please enter a number between %d and %d.\n", min, max);
            continue; // skip to next iteration of loop
        }

        // check if the guess is too low or too high
        if(guess < secret_number) {
            printf("Too low. Guess again.\n");
        } else if (guess > secret_number) {
            printf("Too high. Guess again.\n");
        }

        num_guesses++; // increment number of guesses
    }

    printf("Congratulations! You guessed the number in %d guesses.\n", num_guesses);
    return 0;
}