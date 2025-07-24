//FormAI DATASET v1.0 Category: Math exercise ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int userGuess, randomNumber, count = 0;
    srand(time(0));  // Initialize random number generator
    randomNumber = rand() % 100 + 1;  // Generate a random number between 1 and 100
    
    printf("Welcome to the Guessing Game! Can you guess the secret number?\n");
    do {
        printf("Enter your guess (between 1 and 100): ");
        scanf("%d", &userGuess);
        count++;  // Increment the number of guesses made by user
        
        if (userGuess > randomNumber) {
            printf("Too high! Try again.\n");
        } else if (userGuess < randomNumber) {
            printf("Too low! Try again.\n");
        } else {
            printf("Congratulations! You guessed the secret number in %d tries!\n", count);
            break;  // Exit the loop and end the game
        }
    } while (userGuess != randomNumber);
    
    printf("Thank you for playing the Guessing Game!\n");
    return 0;
}