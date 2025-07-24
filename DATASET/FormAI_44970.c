//FormAI DATASET v1.0 Category: Table Game ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random number between 1 to 100
int generateRandomNumber() {
    srand(time(NULL));
    return rand() % 100 + 1;
}

int main() {
    int secretNumber, guess, tries = 0;

    // Generate a random number
    secretNumber = generateRandomNumber();

    printf("Welcome to the Guessing Game!\n");
    printf("I'm thinking of a number between 1 and 100. Can you guess it?\n");

    // Loop until the player guesses the correct number
    while (1) {
        // Get input from the player
        printf("Enter your guess: ");
        scanf("%d", &guess);

        tries++;

        // Check if the guess is correct
        if (guess == secretNumber) {
            printf("Congratulations! You have guessed the number in %d tries.\n", tries);
            break;
        }

        // Check if the guess is higher or lower than the secret number
        if (guess < secretNumber) {
            printf("Wrong guess. The number is higher than %d.\n", guess);
        } else {
            printf("Wrong guess. The number is lower than %d.\n", guess);
        }
    }

    return 0;
}