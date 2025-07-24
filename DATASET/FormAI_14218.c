//FormAI DATASET v1.0 Category: Game ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    
    // Initialize Variables
    int n, guess, attempts = 0;
    srand(time(0));
    n = rand() % 100 + 1;
    
    // User Input
    printf("Guess the number (1 - 100): ");
    do {
        scanf("%d", &guess);
        attempts++;
        
        // Check if Guess is Correct
        if (guess > n) {
            printf("Too High\n");
        } else if (guess < n) {
            printf("Too Low\n");
        } else {
            printf("\nCongratulations! You Guessed the Number in %d Attempts\n", attempts);
        }
    } while(guess != n);
    
    return 0;
}