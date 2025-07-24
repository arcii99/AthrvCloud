//FormAI DATASET v1.0 Category: Table Game ; Style: optimized
// This program is a C Table Game, where the user plays against the computer
// The objective of the game is to guess the number that the computer chose between 1 and 100

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int computerNumber, userGuess, tries = 0;
    srand(time(0));  // Seed the random number generator
    computerNumber = rand() % 100 + 1;  // Generate a random number between 1 and 100
    printf("Welcome to the C Table Game!\n");
    printf("Guess the number between 1 and 100!\n");

    do {
        printf("Enter your guess: ");
        scanf("%d", &userGuess);
        tries++;

        // Check if the user's guess is higher, lower, or equal to the computer's number
        if (userGuess > computerNumber) {
            printf("Your guess is too high!\n");
        } else if (userGuess < computerNumber) {
            printf("Your guess is too low!\n");
        } else {
            printf("Congratulations! You guessed the number in %d tries!\n", tries);
        }
    } while (userGuess != computerNumber);

    return 0;
}