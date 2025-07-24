//FormAI DATASET v1.0 Category: Game ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to get a random number between min and max
int getRandomNumber(int min, int max) {
    srand(time(NULL));  // Seed random number generator
    return rand() % (max - min + 1) + min;
}

int main() {
    int guessCount = 0;
    int guess;
    const int MAX_GUESSES = 5;
    int randomNumber = getRandomNumber(1, 100);

    printf("Welcome to the Guessing Game!\n");
    printf("I'm thinking of a number between 1 and 100. You have %d guesses to get it right.\n", MAX_GUESSES);

    do {
        printf("Enter your guess: ");
        scanf("%d", &guess);
        guessCount++;

        if (guess < randomNumber) {
            printf("Too low! Try again.\n");
        } else if (guess > randomNumber) {
            printf("Too high! Try again.\n");
        }
    } while (guess != randomNumber && guessCount < MAX_GUESSES);

    if (guess == randomNumber) {
        printf("Congratulations! You guessed the number in %d tries.\n", guessCount);
    } else {
        printf("Sorry, you didn't guess the number. The number was %d.\n", randomNumber);
    }

    return 0;
}