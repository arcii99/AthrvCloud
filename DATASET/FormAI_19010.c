//FormAI DATASET v1.0 Category: Game ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));     // Initialize seed for random number generation
    int secretNumber = rand() % 50 + 1;     // Generate secret number between 1 and 50
    int guesses = 0;        // Initialize number of guesses to 0
    int guess;              // Declare variable to store user's guesses
    
    printf("Welcome to the Guessing Game! See if you can guess the secret number between 1 and 50...\n\n");
    
    do {
        printf("Enter your guess: ");
        scanf("%d", &guess);
        guesses++;          // Increment number of guesses
        
        if (guess < secretNumber) {
            printf("Too low, try again!\n");
        } else if (guess > secretNumber) {
            printf("Too high, try again!\n");
        } else {
            printf("\nCongratulations! You've guessed the secret number in %d guesses!\n", guesses);
        }
    } while (guess != secretNumber);
    
    return 0;
}