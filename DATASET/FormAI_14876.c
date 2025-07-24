//FormAI DATASET v1.0 Category: Game ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    // Declare variables for the game
    int guess, num, num_guesses = 0;
    srand(time(0));
    num = rand() % 100 + 1; // Generate a random number between 1 and 100

    // Display welcome message
    printf("Welcome to the Guessing Game! Can you guess the number I'm thinking of between 1 and 100?\n");

    while (guess != num) {
        printf("Enter your guess: ");
        scanf("%d", &guess);
        num_guesses++;

        if (guess < num) { // If the guess is too low
            printf("Your guess is too low! Try again.\n");
        }
        else if (guess > num) { // If the guess is too high
            printf("Your guess is too high! Try again.\n");
        }
        else { // If the guess is correct
            printf("Congratulations! You guessed the correct number in %d tries.\n", num_guesses);
        }
    }
    return 0;
}