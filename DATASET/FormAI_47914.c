//FormAI DATASET v1.0 Category: Table Game ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Welcome message
    printf("Welcome to the C Table Game!\n\n");
    
    // Generate random number between 1 and 100
    srand(time(NULL)); // Seed the random number generator
    int secretNumber = rand() % 100 + 1;
    
    // Game loop
    int guess;
    int numGuesses = 0;
    while (1) {
        printf("Guess a number between 1 and 100: ");
        scanf("%d", &guess);
        numGuesses++;
        
        if (guess < secretNumber) {
            printf("Too low!\n");
        }
        else if (guess > secretNumber) {
            printf("Too high!\n");
        }
        else {
            // Player guessed the number correctly
            printf("Congratulations, you guessed the secret number in %d guesses!\n", numGuesses);
            break;
        }
    }
    
    // End of game
    printf("\nThanks for playing the C Table Game!\n");
    
    return 0;
}