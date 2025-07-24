//FormAI DATASET v1.0 Category: Game ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int guess, secretNum, tries = 0;
    
    // generate a random number between 1 and 100
    srand(time(NULL));
    secretNum = rand() % 100 + 1;
    
    printf("\nWelcome to the Guessing Game!\n");
    printf("Guess a number between 1 and 100.\n\n");
    
    // keep asking for guesses until the correct number is guessed
    do {
        printf("Enter your guess: ");
        scanf("%d", &guess);
        
        if (guess < secretNum) {
            printf("Too low, try again.\n\n");
            tries++;
        } else if (guess > secretNum) {
            printf("Too high, try again.\n\n");
            tries++;
        } else {
            printf("You guessed it! Congratulations!\n");
            printf("You took %d tries to guess the secret number.\n\n", tries+1);
        }
    } while (guess != secretNum);
    
    return 0;
}