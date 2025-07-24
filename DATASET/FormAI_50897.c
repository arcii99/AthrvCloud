//FormAI DATASET v1.0 Category: Game ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int input, guess, tries = 0;
    srand(time(NULL)); // Seed for random number generator
    guess = rand() % 100 + 1; // Generate a random number between 1 and 100

    printf("Welcome to the Guessing Game!\n");
    printf("I am thinking of a number between 1 and 100.\n");
    printf("Can you guess it in less than 10 tries?\n\n");

    do {
        printf("Enter your guess: ");
        scanf("%d", &input);
        tries++;

        if (input == guess) {
            printf("\nCongratulations! You guessed my number in %d tries!\n", tries);
            return 0; // End the program
        } else if (input < guess) {
            printf("Too low. Try again.\n");
        } else {
            printf("Too high. Try again.\n");
        }
    } while (tries < 10); // Allow up to 10 guesses

    // If the user couldn't guess the number in 10 tries
    printf("\nSorry, you couldn't guess my number in 10 tries.\n");
    printf("My number was %d.\n", guess);
    return 0;
}