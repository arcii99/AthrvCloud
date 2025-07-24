//FormAI DATASET v1.0 Category: Game ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Initialize random number generator
    srand(time(NULL));

    // Declare variables
    int num_guesses = 0;
    int guess = -1;
    int target = rand() % 100 + 1; // Random number between 1 and 100

    // Print instructions
    printf("Guess a number between 1 and 100\n");

    // Start game
    while (1) {
        // Get user guess
        printf("Enter your guess: ");
        scanf("%d", &guess);
        num_guesses++;

        // Check if guess is correct
        if (guess == target) {
            printf("Congratulations, you guessed the number in %d guesses!\n", num_guesses);
            break;
        }

        // Check if guess is too high or too low
        if (guess < target) {
            printf("Too low, try again\n");
        } else {
            printf("Too high, try again\n");
        }
    }

    return 0;
}