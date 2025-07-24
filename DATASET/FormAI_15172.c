//FormAI DATASET v1.0 Category: Game ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ATTEMPTS 5

// This function generates a random number between 1 and 100
int generateRandomNumber() {
    srand(time(NULL));
    return rand() % 100 + 1;
}

int main() {
    int numberToGuess = generateRandomNumber();
    int guess, numAttempts = 0;

    printf("\nWelcome to the Number Guessing Game!\n");
    printf("You have %d chances to guess a number between 1 and 100\n\n", MAX_ATTEMPTS);

    do {
        printf("Please enter your guess: ");
        scanf("%d", &guess);

        numAttempts++;

        if (guess == numberToGuess) {
            printf("\nCongratulations! You have guessed the number in %d tries.\n", numAttempts);
            return 0;
        } else if (guess < numberToGuess) {
            printf("Your guess is too low.\n");
        } else {
            printf("Your guess is too high.\n");
        }
    } while (numAttempts < MAX_ATTEMPTS);

    printf("\nGame over! The number was %d.\n", numberToGuess);
    return 0;
}