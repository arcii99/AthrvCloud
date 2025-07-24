//FormAI DATASET v1.0 Category: Game ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int secretNum, guess, numGuesses = 0;
    
    // Generate random number between 1 and 100
    srand(time(NULL));
    secretNum = rand() % 100 + 1;
    
    printf("The secret number has been generated. Try to guess it!\n");
    
    do {
        printf("Enter your guess (1-100): ");
        scanf("%d", &guess);
        
        // Check if guess is within bounds
        if (guess < 1 || guess > 100) {
            printf("Invalid guess. Please enter a number between 1 and 100.\n");
            continue; // Restart loop
        }
        
        numGuesses++;
        
        if (guess > secretNum) {
            printf("Too high. Guess again.\n");
        } else if (guess < secretNum) {
            printf("Too low. Guess again.\n");
        } else {
            printf("Congratulations! You guessed the number in %d tries.\n", numGuesses);
        }
    } while (guess != secretNum);
    
    return 0;
}