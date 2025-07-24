//FormAI DATASET v1.0 Category: Random ; Style: bold
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int num, guess, tries = 0;
    
    srand(time(0)); // Seed random number generator with current time
    
    num = rand() % 100 + 1; // Generate a random number between 1 and 100
    
    printf("\nWelcome to the Random Number Guessing Game!\n\n");
    printf("I have randomly generated a number between 1 and 100, try to guess it\n");
    
    do {
        printf("\nEnter your guess: ");
        scanf("%d", &guess);
        tries++; 
        
        if (guess > num) {
            printf("\nSorry, but your guess is too high. Try again\n");
        } else if (guess < num) {
            printf("\nSorry, but your guess is too low. Try again\n");
        } else {
            printf("\nCongratulations! You guessed the number %d in %d tries\n", num, tries);
        }
        
    } while (guess != num);
    
    return 0;
}