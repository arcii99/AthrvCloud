//FormAI DATASET v1.0 Category: Game ; Style: complex
#include <stdio.h>
#include <stdlib.h>


/**
 * A simple game where the user must guess a random number between 1-100
 */


int main(void) {
    const int max = 100;   // max number to generate
    const int min = 1;     // min number to generate
    const int attempts = 5; // number of attempts the user gets
    
    int secret_number = rand() % (max - min + 1) + min; // generate secret number
    int guess; // user's guess
    
    printf("Welcome to Guess the Number!\n\n");
    printf("I am thinking of a number between %d and %d.\n", min, max);
    printf("You have %d attempts to guess the number.\n", attempts);
    
    
    for (int i = 1; i <= attempts; i++) { // loop through attempts
        
        printf("\nEnter your guess: ");
        scanf("%d", &guess);
        
        if (guess == secret_number) { // if user guesses correctly
            printf("\nCongratulations! You guessed the number in %d attempt(s)!\n", i);
            return 0; // exit program
        } else if (guess < secret_number) { // if user's guess is too low
            printf("Your guess is too low. ");
        } else { // if user's guess is too high
            printf("Your guess is too high. ");
        }
        
        printf("You have %d attempt(s) left.\n", attempts - i);
        
    }
    
    printf("\nSorry, you have run out of attempts. The number was %d.\n", secret_number);
    
    return 0; // exit program
}