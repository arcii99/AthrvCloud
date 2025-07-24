//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    srand(time(NULL)); // seed random number generator

    int guessCount = 0;
    int numberToGuess = rand() % 100 + 1; // generate random number between 1 and 100
    int guess = 0;

    printf("Welcome to the Guessing Game! You have three attempts to guess a number between 1 and 100.\n");

    while (guessCount < 3) {

        printf("Guess #%d: ", guessCount + 1);
        scanf("%d", &guess); // allow player to input guess

        if (guess < 1 || guess > 100) {
            printf("Invalid guess. Please enter a number between 1 and 100.\n");
            continue; // restart loop without increasing guessCount
        }

        if (guess == numberToGuess) {
            printf("Congratulations! You guessed the number in %d attempt(s)!\n", guessCount + 1);
            return 0; // end program
        }

        if (guess < numberToGuess) {
            printf("Too low.\n");
        } else {
            printf("Too high.\n");
        }

        guessCount++;
    }

    printf("Sorry, you did not guess the number. The number was %d.\n", numberToGuess);
    return 0;
}