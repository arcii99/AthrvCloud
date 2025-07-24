//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL)); // seed the random generator

    int targetNum = rand() % 100 + 1; // generate a random number between 1 and 100
    int numGuesses = 0;
    int guess;

    printf("Welcome to the number guessing game!\n");
    printf("I'm thinking of a number between 1 and 100. Can you guess it?\n");

    do {
        printf("Enter your guess: ");
        scanf("%d", &guess);
        numGuesses++;

        if (guess > targetNum) {
            printf("Too high! Guess again.\n");
        } else if (guess < targetNum) {
            printf("Too low! Guess again.\n");
        } else {
            printf("Congratulations! You guessed the number in %d tries.\n", numGuesses);
        }
    } while (guess != targetNum);

    return 0;
}