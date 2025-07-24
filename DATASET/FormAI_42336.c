//FormAI DATASET v1.0 Category: Game ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Initialize the random number generator
    srand(time(NULL));

    // Declare variables
    int num, guess, tries = 0;

    // Generate random number between 1 - 100
    num = rand() % 100 + 1;

    printf("Welcome to the Guessing Game!\n");
    printf("I am thinking of a number between 1 - 100.\n");

    // Loop until guess is correct
    while (1) {
        printf("Enter your guess: ");
        scanf("%d", &guess);

        tries++;

        if (guess == num) {
            printf("Congratulations! You guessed the number in %d tries.\n", tries);
            break;
        } else if (guess < num) {
            printf("Sorry, your guess is too low. Please try again.\n");
        } else {
            printf("Sorry, your guess is too high. Please try again.\n");
        }
    }

    return 0;
}