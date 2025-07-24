//FormAI DATASET v1.0 Category: Game ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int guess, tries = 0;
    int max_guesses = 5;
    srand(time(NULL)); // Seed the random number generator
    
    int number = rand() % 100 + 1; // Generate a random number between 1 and 100
      
    printf("Welcome to the Number Guessing Game!\n");
    printf("You have %d tries to guess the number between 1 and 100.\n", max_guesses);
    do {
        printf("Guess #%d: ", tries + 1);
        scanf("%d", &guess); // Read the user's guess
        
        if (guess < number) {
            printf("Too low. Guess higher!\n");
        } else if (guess > number) {
            printf("Too high. Guess lower!\n");
        } else {
            printf("Congratulations! You guessed the number in %d tries.\n", tries + 1);
            return 0;
        }
        tries++;
    } while (tries < max_guesses);

    printf("You did not guess the number. The number was %d.\n", number);
    return 0;
}