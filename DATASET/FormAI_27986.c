//FormAI DATASET v1.0 Category: Game ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    // Initialize random seed
    srand(time(0));
    
    // Declare variables
    int number, guess, attempts = 0;
    
    // Generate random number between 1 and 100
    number = rand() % 100 + 1;
    
    // Welcome message
    printf("Welcome to the Guessing Game!\n");
    
    // Loop until correct guess is made
    do {
        // Get user guess
        printf("Enter a number between 1 and 100: ");
        scanf("%d", &guess);
        
        // Check if user guess is within range
        if(guess < 1 || guess > 100) {
            printf("Invalid guess. Try again.\n");
            continue;
        }
        
        // Increment number of attempts
        attempts++;
        
        // Check if guess is correct
        if(guess == number) {
            printf("Congratulations! You guessed the number in %d attempts.\n", attempts);
        } else if(guess > number) {
            printf("Too high. Try again.\n");
        } else {
            printf("Too low. Try again.\n");
        }
    } while(guess != number);
    
    // Exit program
    return 0;
}