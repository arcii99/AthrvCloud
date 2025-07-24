//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_GUESSES 5 // maximum number of guesses allowed for the player

int main() {
    // generate a random number between 1 and 100
    srand(time(NULL)); // initialize the random seed
    int secretNumber = rand() % 100 + 1;

    printf("Welcome to the Guessing Game!\n");
    printf("You have %d guesses to find the secret number.\n", MAX_GUESSES);

    // loop until the player runs out of guesses or finds the secret number
    int numGuesses = 0;
    while (numGuesses < MAX_GUESSES) {
        printf("Enter a guess: ");
        int guess;
        scanf("%d", &guess);

        numGuesses++; // increment the number of guesses

        if (guess < secretNumber) {
            printf("Too low!\n");
        } else if (guess > secretNumber) {
            printf("Too high!\n");
        } else {
            printf("Congratulations! You guessed the secret number in %d guesses!\n", numGuesses);
            return 0; // exit the program
        }
    }

    // if we get here, the player ran out of guesses
    printf("You ran out of guesses. The secret number was %d. Better luck next time!\n", secretNumber);
    return 0;
}