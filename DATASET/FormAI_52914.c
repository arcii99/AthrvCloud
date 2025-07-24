//FormAI DATASET v1.0 Category: Game ; Style: excited
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

// Function to generate a random number between min and max
int generateRandomNumber(int min, int max) {
    srand(time(NULL));
    int randomNumber = (rand() % (max - min + 1)) + min;
    return randomNumber;
}

int main() {
    printf("Welcome to the amazing guessing game!");
    printf("\n\n");

    // Define the upper and lower limits for the random number
    int min = 1;
    int max = 100;
    int randomNumber = generateRandomNumber(min, max);

    // Initialize the number of guesses to 0
    int numberOfGuesses = 0;

    // Loop until the player guesses the correct number
    while (1) {
        int guess;
        printf("Guess a number between %d and %d: ", min, max);
        scanf("%d", &guess);

        // Increase the number of guesses by one
        numberOfGuesses++;

        // Check if the guess is correct
        if (guess == randomNumber) {
            printf("\nCongratulations, you guessed the number!\n");
            printf("It took you %d guesses.\n", numberOfGuesses);
            break;
        } else if (guess < randomNumber) {
            printf("\nYour guess is too low, try again.\n");
        } else if (guess > randomNumber) {
            printf("\nYour guess is too high, try again.\n");
        }
    }

    return 0;
}