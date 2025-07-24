//FormAI DATASET v1.0 Category: Game ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* A simple guessing game in C */

int main() {
    int numToGuess, guess, attempts = 0;
    srand(time(NULL)); // seed random number generator
    numToGuess = rand() % 100; // generate random number between 0 and 99
    printf("Welcome to the guessing game! Can you guess my number?\n");

    while (1) { // loop until user guesses the correct number
        attempts++;
        printf("Enter your guess (between 0 and 99): ");
        scanf("%d", &guess);
        if (guess == numToGuess) {
            printf("Congratulations! You guessed my number in %d attempts.\n", attempts);
            break;
        }
        else if (guess < numToGuess) {
            printf("Your guess is too low. Try again!\n");
        }
        else {
            printf("Your guess is too high. Try again!\n");
        }
    }
    return 0;
}