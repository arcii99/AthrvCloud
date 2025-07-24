//FormAI DATASET v1.0 Category: Game ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random number between min and max (inclusive)
int getRandomNumber(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

int main() {
    int guess, number, num_guesses = 0, max_guesses;
    srand(time(NULL));

    // Get user input for max number of guesses
    printf("Enter the maximum number of guesses: ");
    scanf("%d", &max_guesses);

    // Generate random number between 1 and 100 (inclusive)
    number = getRandomNumber(1, 100);

    // Loop until all guesses are used or the correct number is guessed
    while (num_guesses < max_guesses) {
        // Get user input for guess
        printf("Guess a number between 1 and 100: ");
        scanf("%d", &guess);
        num_guesses++;

        // Check if guess is too high, too low, or correct
        if (guess < number) {
            printf("Too low! Guess again.\n");
        } else if (guess > number) {
            printf("Too high! Guess again.\n");
        } else {
            printf("Congratulations! You guessed the correct number in %d guesses.\n", num_guesses);
            return 0;
        }
    }

    // If the loop has ended, the user has run out of guesses
    printf("Sorry, you have run out of guesses. The correct number was %d.\n", number);
    return 0;
}