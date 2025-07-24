//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    int guess; // User guess
    int number; // Randomly generated number
    int tries = 1; // Number of tries
    int maxTries = 5; // Maximum number of tries allowed

    // Generate random number between 1 and 100
    srand(time(NULL));
    number = rand() % 100 + 1;

    printf("\nWelcome to the Guessing Game!\n");
    printf("I'm thinking of a number between 1 and 100.\n");
    printf("You have %d tries to guess it.\n", maxTries);

    // Loop until user runs out of tries or guesses correctly
    while (tries <= maxTries) {
        printf("\nEnter your guess: ");
        scanf("%d", &guess);

        // User guessed correctly
        if (guess == number) {
            printf("\nCongratulations! You guessed the number in %d tries!\n", tries);
            return 0;
        }
        // User's guess was too high
        else if (guess > number) {
            printf("\nSorry, your guess was too high. You have %d tries left.\n", maxTries - tries);
        }
        // User's guess was too low
        else {
            printf("\nSorry, your guess was too low. You have %d tries left.\n", maxTries - tries);
        }

        tries++;
    }

    // User ran out of tries
    printf("\nSorry, you ran out of tries. The number was %d.\n", number);
    return 0;
}