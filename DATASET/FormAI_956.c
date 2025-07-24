//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL)); // Initialize the random seed

    int secretNum = rand() % 100 + 1; // Generate a random number between 1 and 100
    int guess;
    int numGuesses = 0;

    printf("Welcome to the Guessing Game! You have 10 attempts to guess the secret number between 1 and 100.\n");

    while(numGuesses < 10) {
        printf("Guess #%d: ", numGuesses + 1);
        scanf("%d", &guess);
        if(guess > secretNum) {
            printf("Too high!\n");
        } else if(guess < secretNum) {
            printf("Too low!\n");
        } else {
            printf("You win! The secret number was %d and you guessed it in %d attempts.\n", secretNum, numGuesses + 1);
            return 0;
        }
        numGuesses++;
    }

    printf("Sorry, you have run out of guesses. The secret number was %d.\n", secretNum);
    return 0;
}