//FormAI DATASET v1.0 Category: Game ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int secret_num, guess, num_guesses = 0;
    time_t t;

    // Intializes random number generator
    srand((unsigned) time(&t));

    // Generates a random number between 1 and 100
    secret_num = rand() % 100 + 1;

    printf("Welcome to the guessing game! \n\n");

    do {
        num_guesses++;

        // Prompts user for guess
        printf("Guess a number between 1 and 100: ");
        scanf("%d", &guess);

        // Compares guess to secret number
        if (guess == secret_num) {
            printf("\nCongratulations! You guessed the secret number in %d tries.", num_guesses);
        } else if (guess < secret_num) {
            printf("\nSorry, your guess is too low. Try again.\n");
        } else {
            printf("\nSorry, your guess is too high. Try again.\n");
        }

    } while (guess != secret_num);

    return 0;
}