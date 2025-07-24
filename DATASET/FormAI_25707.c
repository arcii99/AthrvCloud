//FormAI DATASET v1.0 Category: Game ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random number between min and max (inclusive)
int generateRandomNumber(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

int main() {
    srand(time(NULL)); // Seed the random number generator with the current time

    // Set up the game
    const int MIN_NUMBER = 1;
    const int MAX_NUMBER = 100;
    int targetNumber = generateRandomNumber(MIN_NUMBER, MAX_NUMBER);
    int guessCount = 0;
    int guess;

    printf("Welcome to the Number Guessing Game!\n");
    printf("I'm thinking of a number between %d and %d. Can you guess it?\n", MIN_NUMBER, MAX_NUMBER);

    // Loop until the player guesses the correct number
    while (1) {
        printf("Guess #%d: ", guessCount + 1);
        scanf("%d", &guess);

        // Check if the guess is too low or too high
        if (guess < targetNumber) {
            printf("Too low. Guess again.\n");
        } else if (guess > targetNumber) {
            printf("Too high. Guess again.\n");
        } else {
            printf("You got it! The number was %d. It took you %d guesses.\n", targetNumber, guessCount + 1);
            break;
        }

        guessCount++;
    }

    return 0;
}