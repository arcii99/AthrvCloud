//FormAI DATASET v1.0 Category: Game ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int guessedNumber, randomNumber, tries = 0;
    randomNumber = rand() % 100 + 1;

    printf("Welcome to the Guessing Game! ");
    printf("I'm thinking of a number between 1 and 100. ");

    do {
        printf("Enter your guess: ");
        scanf("%d", &guessedNumber);
        tries++;

        if (guessedNumber > randomNumber) {
            printf("Too high! Guess again. ");
        } else if (guessedNumber < randomNumber) {
            printf("Too low! Guess again. ");
        } else {
            printf("Congratulations! You guessed the number in %d tries. ", tries);
        }
    } while (guessedNumber != randomNumber);

    return 0;
}