//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    srand(time(NULL));  // seed for the random number generator

    int secretNum = rand() % 100;  // generate a secret number between 0 and 99
    int guess;
    int numGuesses = 0;

    printf("Welcome to the Guess the Number Game!\n");
    printf("I'm thinking of a number between 0 and 99. Can you guess it?\n");

    do {

        printf("Enter your guess: ");
        scanf("%d", &guess);

        if (guess < secretNum) {
            printf("Too low! Guess higher.\n");
        } else if (guess > secretNum) {
            printf("Too high! Guess lower.\n");
        } else {
            printf("You guessed it! The secret number was %d.\n", secretNum);
        }

        numGuesses++;

    } while (guess != secretNum);

    printf("It took you %d guesses to get the answer!\n", numGuesses);

    return 0;
}