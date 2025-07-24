//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random number between min and max (inclusive)
int generateRandomNumber(int min, int max) {
    static int initialized = 0;
    if (!initialized) {
        srand(time(NULL));
        initialized = 1;
    }
    return rand() % (max + 1 - min) + min;
}

int main() {
    int secretNumber = generateRandomNumber(1, 100);  // Generate a random number between 1 and 100 (inclusive)
    int guess;
    int numGuesses = 0;
    int maxGuesses = 10;

    printf("*** Welcome to Guess the Number! ***\n\n");
    printf("You have %d guesses to guess the secret number (between 1 and 100).\n\n", maxGuesses);

    // Loop until the player guesses the correct number or runs out of guesses
    while (numGuesses < maxGuesses) {
        printf("Guess #%d: ", numGuesses + 1);
        scanf("%d", &guess);

        if (guess == secretNumber) {
            printf("\nCongratulations! You guessed the secret number (%d) in %d guesses!\n", secretNumber, numGuesses + 1);
            return 0;
        } else if (guess < secretNumber) {
            printf("Too low. Try again.\n\n");
        } else {
            printf("Too high. Try again.\n\n");
        }

        numGuesses++;
    }

    // The player has run out of guesses
    printf("\nSorry, you ran out of guesses. The secret number was %d.\n", secretNumber);
    return 0;
}