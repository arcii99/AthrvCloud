//FormAI DATASET v1.0 Category: Game ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(0)); // Seed the random number generator with the current time
    int secret_number = rand() % 100 + 1; // Generate a secret number between 1 and 100
    int attempts = 0; // Keep track of how many attempts the player has made
    int guess = 0; // Initialize the player's guess variable
    
    printf("Welcome to the Guessing Game! You have 10 attempts to guess the secret number between 1 and 100.\n");
    
    do {
        printf("Enter your guess: ");
        scanf("%d", &guess); // Get the player's guess from the input
        
        if (guess < secret_number) {
            printf("Your guess is too low!\n");
        } else if (guess > secret_number) {
            printf("Your guess is too high!\n");
        }
        
        attempts++; // Increment the number of attempts the player has made
        
    } while (guess != secret_number && attempts < 10); // Keep playing until the player guesses correctly or runs out of attempts
    
    if (guess == secret_number) {
        printf("Congratulations, you guessed correctly in %d attempts!\n", attempts);
    } else {
        printf("Sorry, you didn't manage to guess the secret number in time. The secret number was %d.\n", secret_number);
    }
    
    return 0;
}