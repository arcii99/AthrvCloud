//FormAI DATASET v1.0 Category: Educational ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));  // Seed rand() with current time

    // Generate random number between 1 and 100
    int secret_number = rand() % 100 + 1;

    int num_guesses = 0;
    int guess = 0;

    printf("Welcome to the Retro Guessing Game!\n");
    printf("I'm thinking of a number between 1 and 100.\n");
    printf("Can you guess what it is?\n");

    while (guess != secret_number) {
        printf("\nEnter your guess: ");
        scanf("%d", &guess);

        if (guess < secret_number) {
            printf("Sorry, your guess is too low. Try again.\n");
        } else if (guess > secret_number) {
            printf("Sorry, your guess is too high. Try again.\n");
        }

        num_guesses++;
    }

    printf("\nCongratulations! You guessed the secret number in %d tries.\n", num_guesses);

    return 0;
}