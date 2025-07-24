//FormAI DATASET v1.0 Category: Table Game ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL)); // Initialize random seed
    
    // Generate random number from 1 to 100
    int secret_number = rand() % 100 + 1;
    
    printf("Guess the secret number between 1 and 100!\n");
    
    int guess = 0;
    int guess_count = 0;
    
    // Loop until the player correctly guesses the number
    while (guess != secret_number) {
        printf("Enter your guess: ");
        scanf("%d", &guess);
        guess_count++;
        
        // Check if the guess is too high, too low, or correct
        if (guess > secret_number) {
            printf("Too high! Try again.\n");
        } else if (guess < secret_number) {
            printf("Too low! Try again.\n");
        } else {
            printf("Congratulations! You guessed the secret number in %d tries.\n", guess_count);
        }
    }
    
    return 0;
}