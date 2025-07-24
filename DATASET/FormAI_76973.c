//FormAI DATASET v1.0 Category: Game ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL)); // Set the seed for the rand() function to the current time
    int target_number = rand() % 100 + 1; // Generate a random number between 1 and 100
    int guess, num_guesses = 0; // Declare variables for the user's guess and the number of guesses made

    printf("Welcome to the Number Guessing Game!\n");
    printf("I'm thinking of a number between 1 and 100. Can you guess it?\n");

    do {
        printf("Enter your guess: ");
        scanf("%d", &guess); // Get the user's guess
        num_guesses++; // Increment the number of guesses made

        if (guess < target_number) {
            printf("Too low! Guess higher.\n");
        } else if (guess > target_number) {
            printf("Too high! Guess lower.\n");
        } else {
            printf("Congratulations! You guessed the number in %d tries.\n", num_guesses);
        }
    } while (guess != target_number);

    return 0;
}