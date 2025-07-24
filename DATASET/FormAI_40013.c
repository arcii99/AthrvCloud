//FormAI DATASET v1.0 Category: Game ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL)); // seed random number generator

    printf("Welcome to the Guessing Game!\n");

    int secret_number = rand() % 100 + 1; // generate a random number between 1 and 100
    int guess = 0;
    int num_guesses = 0;

    while (guess != secret_number) {
        printf("Guess a number between 1 and 100: ");
        scanf("%d", &guess);
        num_guesses++;

        if (guess < secret_number) {
            printf("Too low! Try again.\n");
        } else if (guess > secret_number) {
            printf("Too high! Try again.\n");
        } else {
            printf("Congratulations, you guessed the secret number in %d guesses!\n", num_guesses);
        }
    }

    return 0;
}