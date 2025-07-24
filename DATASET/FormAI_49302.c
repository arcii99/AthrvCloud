//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    // set the seed for the random number generator
    srand(time(NULL));

    // initialize variables
    int num_guesses = 0;
    int guess, answer;
    char play_again = 'y';

    // welcome message
    printf("\nWelcome to the Guessing Game!\n\n");

    while (play_again == 'y') {
        // generate a random number between 1 and 100
        answer = rand() % 100 + 1;
        printf("I'm thinking of a number between 1 and 100. Can you guess what it is?\n\n");

        while (guess != answer) {
            // prompt the user to guess a number
            printf("Guess a number: ");
            scanf("%d", &guess);
            // increment the number of guesses
            num_guesses++;

            // check if the guess is correct
            if (guess == answer) {
                printf("\nCongratulations! You guessed the number in %d tries.\n", num_guesses);
            } else if (guess < answer) {
                printf("Too low. Try again.\n");
            } else {
                printf("Too high. Try again.\n");
            }
        }

        // ask the user if they want to play again
        printf("Do you want to play again? (y/n): ");
        scanf(" %c", &play_again);

        // reset the number of guesses
        num_guesses = 0;
    }

    printf("\nThanks for playing the Guessing Game! Goodbye.\n");

    return 0;
}