//FormAI DATASET v1.0 Category: Math exercise ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int answer, guess, attempts = 0;
    srand(time(0)); // Random seed generator
    
    // Generate random number between 1 and 100
    answer = rand() % 100 + 1;
    
    printf("I am thinking of a number between 1 and 100. Can you guess it?\n");
    
    // Loop until user guesses the correct number
    while (1) {
        printf("Enter your guess: ");
        scanf("%d", &guess);
        
        // Check if guess is correct
        if (guess == answer) {
            printf("Congratulations! You guessed the number in %d tries.\n", attempts);
            break;
        }
        
        // Provide hint based on whether guess is greater or less than answer
        if (guess > answer) {
            printf("Your guess is too high. Try again.\n");
        } else {
            printf("Your guess is too low. Try again.\n");
        }
        
        attempts++; // Increment the number of attempts     
    }
    
    return 0;
}