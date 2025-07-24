//FormAI DATASET v1.0 Category: Table Game ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int random_number, guess, num_guesses = 0;
    
    srand(time(0)); // Seed the random number generator with the current time
    
    random_number = rand() % 100 + 1; // Generate a random number between 1 and 100
    
    printf("Welcome to the number guessing game!\n");
    printf("I'm thinking of a number between 1 and 100. Can you guess it?\n");
    
    do {
        printf("Guess a number: ");
        scanf("%d", &guess); // Read in the user's guess
        
        num_guesses++; // Increment the number of guesses
        
        if (guess < random_number) {
            printf("Too low! Guess higher.\n");
        } else if (guess > random_number) {
            printf("Too high! Guess lower.\n");
        } else {
            printf("Congratulations! You got it in %d guesses.\n", num_guesses);
        }
    } while (guess != random_number);
    
    return 0;
}