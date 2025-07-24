//FormAI DATASET v1.0 Category: Game ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random number between 1 and 100
int generateRandomNumber() {
    srand(time(NULL)); // Seed the random number generator
    return (rand() % 100) + 1;
}

int main() {
    int secretNumber = generateRandomNumber(); // Generate the random number
    int guess, numGuesses = 0; // Initialize variables for the guess and number of guesses

    // Loop until the user correctly guesses the number
    while (1) {
        printf("Guess the secret number (between 1 and 100): ");
        scanf("%d", &guess); // Read in the user's guess
        numGuesses++; // Increment the number of guesses

        if (guess == secretNumber) {
            printf("Congratulations, you guessed the secret number in %d guesses!\n", numGuesses);
            break; // Exit the loop
        } else if (guess < secretNumber) {
            printf("Too low! Try again.\n");
        } else {
            printf("Too high! Try again.\n");
        }
    }

    return 0;
}