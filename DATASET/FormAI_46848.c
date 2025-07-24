//FormAI DATASET v1.0 Category: Educational ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// This program generates a random number and asks the user to guess it
int main() {
    int randomNumber, guess, tries = 0;
    
    srand(time(NULL)); // Seed random number generator with current time
    randomNumber = rand() % 50; // Generate random number between 0-49
    
    printf("Welcome to the Guessing Game!\n");
    printf("Guess a number between 0-49: ");
    
    do {
        scanf("%d", &guess);
        tries++;
        
        if (guess > randomNumber) {
            printf("Lower!\n");
        } else if (guess < randomNumber) {
            printf("Higher!\n");
        }
    } while (guess != randomNumber); // Keep looping until user guesses correctly
    
    printf("Congratulations, you guessed the number in %d tries!\n", tries);

    return 0;
}