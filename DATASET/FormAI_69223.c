//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL)); // Set seed for random number generation

    // Initialize game variables
    int random_num = rand() % 100 + 1; // Generate random number between 1 and 100
    int guess, num_guesses = 0;
    char play_again = 'y';

    // Game loop
    while (play_again == 'y') {
        printf("Guess a number between 1 and 100: ");
        scanf("%d", &guess);

        if (guess == random_num) { // If user guesses correctly
            printf("Congratulations! You guessed the number in %d attempts!\n", num_guesses);
        }
        else if (guess < random_num) { // If user's guess is too low
            printf("Too low! Guess again.\n");
            num_guesses++;
        }
        else { // If user's guess is too high
            printf("Too high! Guess again.\n");
            num_guesses++;
        }

        // Ask user if they want to play again
        printf("Do you want to play again? (y/n): ");
        scanf(" %c", &play_again);
        num_guesses = 0; // Reset number of guesses for new game
        random_num = rand() % 100 + 1; // Generate new random number for new game
    }

    printf("Thanks for playing!\n");
    return 0;
}