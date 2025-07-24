//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int i, guess, n, max_guesses;
    int secret_number;
    printf("Welcome to the Number Guessing Game!\n");

    // Set the range of numbers to guess
    printf("Enter the range of numbers to guess (max): ");
    scanf("%d", &n);

    // Set the maximum number of guesses
    printf("Enter the maximum number of guesses: ");
    scanf("%d", &max_guesses);

    // Generate a random secret number
    srand(time(NULL));
    secret_number = rand() % n + 1;

    // Loop through the guesses
    for (i = 1; i <= max_guesses; i++) {
        printf("Guess #%d: ", i);
        scanf("%d", &guess);

        // Check if the guess is correct
        if (guess == secret_number) {
            printf("Congratulations! You guessed the secret number in %d guesses!\n", i);
            return 0;
        } 

        // Check if the guess is too high or too low
        else if (guess > secret_number) {
            printf("Try again! Your guess is too high.\n");
        } else {
            printf("Try again! Your guess is too low.\n");
        }
    }

    // Print the secret number if the player loses
    printf("Sorry, you ran out of guesses! The secret number was %d.\n", secret_number);

    return 0;
}