//FormAI DATASET v1.0 Category: Table Game ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_GUESSES 5  // maximum number of guesses allowed

int main() {
    int secretNumber, guess, guessesLeft = MAX_GUESSES;
    srand(time(NULL));  // initialize random seed

    printf("Welcome to the Guessing Game! \n\n");

    // generate random number between 1 and 100
    secretNumber = rand() % 100 + 1;

    // loop until all guesses used or correct guess made
    while (guessesLeft > 0) {
        printf("You have %d guess(es) left. Enter a number between 1 and 100: ", guessesLeft);
        scanf("%d", &guess);

        // check if guess is within range
        if (guess < 1 || guess > 100) {
            printf("Invalid guess. Please enter a number between 1 and 100. \n");
            continue;
        }

        // decrement number of guesses left
        guessesLeft--;

        // check if guess is correct
        if (guess == secretNumber) {
            printf("Congratulations! You guessed the secret number %d with %d guess(es) left. \n", 
                   secretNumber, guessesLeft);
            break;
        } else if (guess < secretNumber) {
            printf("The secret number is higher than %d. \n", guess);
        } else {
            printf("The secret number is lower than %d. \n", guess);
        }
    }

    // display game over message if all guesses used
    if (guessesLeft == 0) {
        printf("Game over! You have used all %d guesses. The secret number was %d. \n", MAX_GUESSES, secretNumber);
    }

    return 0;
}