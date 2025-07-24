//FormAI DATASET v1.0 Category: Game ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random number
int generateNumber(int min, int max) {
    srand(time(0)); // seed the random number generator
    return rand() % (max - min + 1) + min;
}

int main() {
    int secretNumber, guess, numGuesses = 0;
    secretNumber = generateNumber(1, 100); // generate a secret number between 1 and 100
    printf("Welcome to the Guessing Game!\n");
    printf("I'm thinking of a number between 1 and 100...\n");

    do {
        printf("Enter your guess (1-100): ");
        scanf("%d", &guess);
        numGuesses++;
        if (guess < secretNumber) {
            printf("Too low, try again!\n");
        } else if (guess > secretNumber) {
            printf("Too high, try again!\n");
        } else {
            printf("You guessed it in %d tries, congratulations!\n", numGuesses);
        }
    } while (guess != secretNumber);
    return 0;
}