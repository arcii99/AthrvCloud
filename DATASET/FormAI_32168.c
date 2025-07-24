//FormAI DATASET v1.0 Category: Game ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random number between min and max
int randNum(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

int main() {
    srand(time(NULL)); // Initializing the random number generator

    printf("--------------------\n");
    printf("Welcome to Guess Game!\n");
    printf("--------------------\n");

    int numToGuess = randNum(1, 100); // Generating a random number between 1 and 100
    int guess = 0;
    int attempts = 0;

    printf("\nI am thinking of a number between 1 and 100.\n");

    while (guess != numToGuess) {
        printf("\nEnter your guess: ");
        scanf("%d", &guess);

        // Validating the user input
        if (guess < 1 || guess > 100) {
            printf("Invalid guess. Please enter a number between 1 and 100.\n");
            continue;
        }

        attempts++;

        // Checking if the guess is correct
        if (guess == numToGuess) {
            printf("Congratulations! You guessed the number in %d attempts.\n", attempts);
        } else {
            // Providing hint if the guess is incorrect
            if (guess < numToGuess) {
                printf("Too low! Guess again.\n");
            } else {
                printf("Too high! Guess again.\n");
            }
        }
    }

    return 0;
}