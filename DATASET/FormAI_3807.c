//FormAI DATASET v1.0 Category: Game ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int num_guesses = 0;
    int guess;
    int play_again = 1;

    srand(time(NULL)); // Seeds the random number generator based on the current time

    while (play_again) {
        int number_to_guess = rand() % 100; // Generates a random number between 0 and 99 to guess
        printf("Guess a number between 0 and 99\n");

        while (1) {
            printf("Enter your guess: ");
            scanf("%d", &guess);
            num_guesses++;

            if (guess < number_to_guess) {
                printf("Too low. Guess again.\n");
            } else if (guess > number_to_guess) {
                printf("Too high. Guess again.\n");
            } else {
                printf("Congratulations! You guessed the number in %d tries.\n", num_guesses);
                break;
            }
        }

        // Ask the user if they want to play again
        printf("Play again? (0 for no, 1 for yes): ");
        scanf("%d", &play_again);
        num_guesses = 0;
    }

    return 0;
}