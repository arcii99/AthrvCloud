//FormAI DATASET v1.0 Category: Math exercise ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUMBERS 1000
#define MAX_GUESSES 10

int main() {
    int number, guess, guessesLeft = MAX_GUESSES;;

    srand(time(NULL)); // Setting seed for random number generator
    number = rand() % MAX_NUMBERS + 1; // Generating number between 1 and 1000
    printf("I'm thinking of a number between 1 and 1000!\n");

    while (guessesLeft > 0) {
        printf("You have %d guesses left - enter your guess: ", guessesLeft);
        scanf("%d", &guess);
        getchar(); // Clearing input buffer

        if (guess < number) {
            printf("Your guess is too low!\n");
        } else if (guess > number) {
            printf("Your guess is too high!\n");
        } else {
            printf("Congratulations, you guessed the number!\n");
            break;
        }

        guessesLeft--;
    }

    if (guessesLeft == 0) {
        printf("Sorry, you ran out of guesses. The number was %d.\n", number);
    }

    return 0; // Program done running
}