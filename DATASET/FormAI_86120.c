//FormAI DATASET v1.0 Category: Game ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>  // for generating random numbers

// function to generate random number
int generateRandomNumber(int maxNumber) {
    srand(time(NULL));  // seed the random number generator
    return rand() % maxNumber + 1;  // return random number between 1 to maxNumber inclusive
}

int main() {
    printf("Welcome to the Guessing Game!\n\n");

    int maxNumber = 20;  // maximum number to guess
    int randomNumber = generateRandomNumber(maxNumber);  // call function to generate random number

    int guess;
    int numGuesses = 0;

    do {
        printf("Guess a number between 1 and %d: ", maxNumber);
        scanf("%d", &guess);
        numGuesses++;

        if (guess > randomNumber) {
            printf("Too high. Try again.\n");
        } else if (guess < randomNumber) {
            printf("Too low. Try again.\n");
        }

    } while (guess != randomNumber);

    printf("\nCongratulations! You guessed the number in %d guesses.", numGuesses);

    return 0;
}