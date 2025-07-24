//FormAI DATASET v1.0 Category: Game ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int guess, number, tries = 0;
    srand(time(NULL)); // Initializes the random number generator
    number = rand() % 100; // Generates a random number between 0 and 99

    printf("\nWelcome to the Number Guessing Game!\n");
    printf("\nI have a number between 0 and 99. Can you guess it?\n");

    do {
        printf("\nEnter your guess: ");
        scanf("%d", &guess); // Reads user's guess

        if (guess < number) {
            printf("Too low! Try again.\n");
        } else if (guess > number) {
            printf("Too high! Try again.\n");
        }

        tries++; // Increment the number of tries
    } while (guess != number);

    printf("\nCongratulations! You guessed the number %d in %d tries!\n", number, tries);

    return 0;
}