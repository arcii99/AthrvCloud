//FormAI DATASET v1.0 Category: Game ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL)); // Initialize random number generator
    
    int targetNumber = rand() % 100 + 1; // Generate a random number between 1 and 100
    int userGuess = 0;
    int numGuesses = 0;
    
    printf("Let's play a game!\n");
    printf("I'm thinking of a number between 1 and 100.\n");
    
    // Loop until user guesses the correct number
    while (userGuess != targetNumber) {
        printf("Enter your guess (between 1 and 100): ");
        scanf("%d", &userGuess);
        numGuesses++;
        
        // Check if guess is too high or too low
        if (userGuess < targetNumber) {
            printf("Too low! Try again.\n");
        } else if (userGuess > targetNumber) {
            printf("Too high! Try again.\n");
        } else {
            printf("Congratulations! You guessed the number in %d guesses.\n", numGuesses);
        }
    }
    
    return 0;
}