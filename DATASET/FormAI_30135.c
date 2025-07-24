//FormAI DATASET v1.0 Category: Table Game ; Style: ephemeral
/* This program is a unique C Table Game that challenges players to identify the mystery number based on clues provided by the computer. */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int mystery_number, guess, num_guesses = 0;
    srand(time(0));
    mystery_number = rand() % 100 + 1; // generate a random number between 1 and 100

    printf("\nHello there! Welcome to the Mystery Number Game!\n\n");
    printf("I am thinking of a number between 1 and 100. Can you guess what it is?\n\n");

    do {
        printf("Enter your guess: ");
        scanf("%d", &guess);
        num_guesses++;

        if (guess < mystery_number) {
            printf("Too low! Guess higher.\n\n");
        } else if (guess > mystery_number) {
            printf("Too high! Guess lower.\n\n");
        } else {
            printf("\nCongratulations! You guessed the mystery number %d in %d guesses!\n\n", mystery_number, num_guesses);
        }
    } while (guess != mystery_number);

    return 0;
}