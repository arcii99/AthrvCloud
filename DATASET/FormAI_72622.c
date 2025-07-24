//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    // Declare variables
    int guess, max_num, attempts = 0, num_to_guess;
    char response;

    // Set the maximum number to guess
    printf("Welcome to the Guessing Game! What is the maximum number you want to guess?\n");
    scanf("%d", &max_num);

    // Generate the number for the user to guess
    srand(time(NULL));
    num_to_guess = rand() % max_num + 1;

    // Ask the user to guess the number
    do {
        printf("Guess a number between 1 and %d: ", max_num);
        scanf("%d", &guess);
        attempts++;

        // Check if the guess is correct
        if (guess == num_to_guess) {
            printf("Congratulations! You guessed the number correctly in %d attempts.\n", attempts);
            return 0;
        }

        // Give the user a hint on whether the guess was too high or too low
        if (guess < num_to_guess) {
            printf("Your guess was too low. Try again? (Y/N): ");
        } else {
            printf("Your guess was too high. Try again? (Y/N): ");
        }

        // Ask the user if they want to continue playing
        scanf(" %c", &response);

    } while (response == 'Y' || response == 'y');

    // User decided to quit the game
    printf("Thanks for playing! The number to guess was %d.\n", num_to_guess);
    return 0;
}