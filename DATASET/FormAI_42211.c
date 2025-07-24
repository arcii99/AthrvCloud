//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    srand(time(NULL)); // Initializing random seed
    int secret_num = rand() % 100 + 1; // Generating random number between 1 and 100
    int guess = 0; // Initializing guess variable
    int num_guesses = 0; // Initializing number of guesses variable

    printf("Welcome to the Guessing Game!\n\n");
    printf("I am thinking of a number between 1 and 100. Can you guess what it is?\n\n");

    // Loop until user guesses the correct number
    while (guess != secret_num) {
        printf("Enter your guess: ");
        scanf("%d", &guess);
        num_guesses++;

        if (guess < secret_num) {
            printf("That's too low. Guess again.\n\n");
        } else if (guess > secret_num) {
            printf("That's too high. Guess again.\n\n");
        } else {
            printf("Congratulations, you guessed the correct number in %d guesses!\n\n", num_guesses);
        }
    }

    return 0;
}