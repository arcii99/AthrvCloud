//FormAI DATASET v1.0 Category: Game ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Seed the random number generator
    srand(time(NULL));
    
    // Choose a random number between 1 and 100
    int answer = rand() % 100 + 1;
    
    // Keep track of the number of attempts
    int attempts = 0;
    
    // Ask the user to guess the number
    printf("I'm thinking of a number between 1 and 100. Can you guess it?\n");
    printf("Enter your guess: ");
    int guess;
    scanf("%d", &guess);
    
    // While the user's guess is incorrect
    while (guess != answer) {
        // Increment the number of attempts
        attempts++;
        
        // Print a message based on whether the guess is too high or too low
        if (guess > answer) {
            printf("Your guess is too high. Try again.\n");
        } else {
            printf("Your guess is too low. Try again.\n");
        }
        
        // Ask the user to guess again
        printf("Enter your guess: ");
        scanf("%d", &guess);
    }
    
    // If the user's guess is correct, congratulate them and print the number of attempts
    printf("Congratulations, you guessed the number in %d attempts!\n", attempts);
    
    // Return 0 to indicate success
    return 0;
}