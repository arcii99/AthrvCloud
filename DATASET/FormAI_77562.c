//FormAI DATASET v1.0 Category: Random ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // seed the random number generator
    srand(time(NULL));

    // declare variables
    int num_guesses = 0;
    int user_guess = -1;
    int secret_num = rand() % 100 + 1;

    // print welcome message
    printf("Welcome to the Number Guessing Game!\n");
    printf("I'm thinking of a number between 1 and 100. Can you guess it?\n");

    // start game loop
    while (user_guess != secret_num) {
        // get user's guess
        printf("Enter your guess: ");
        scanf("%d", &user_guess);

        // check if guess is valid
        if (user_guess < 1 || user_guess > 100) {
            printf("Invalid guess. Please enter a number between 1 and 100.\n");
            continue;
        }

        // update number of guesses
        num_guesses++;

        // check if guess is correct
        if (user_guess == secret_num) {
            printf("Congratulations! You guessed the secret number in %d guesses!\n", num_guesses);
        } else if (user_guess < secret_num) {
            printf("Too low! Try again.\n");
        } else {
            printf("Too high! Try again.\n");
        }
    }

    // print goodbye message
    printf("Thanks for playing!\n");

    return 0;
}