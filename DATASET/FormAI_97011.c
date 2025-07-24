//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Constants
#define MAX_ATTEMPTS 5 // number of attempts for the player
#define MAX_NUMBER 100 // maximum random number
#define MIN_NUMBER 1 // minimum random number

int main() {
    int randomNumber, guess, attemptsLeft;

    // Generate random number
    srand(time(NULL)); // seed the random number generator with the current time
    randomNumber = rand() % (MAX_NUMBER - MIN_NUMBER + 1) + MIN_NUMBER;

    // Print instructions
    printf("Guess the number between %d and %d in %d attempts!\n", MIN_NUMBER, MAX_NUMBER, MAX_ATTEMPTS);

    // Loop through the number of attempts
    for(attemptsLeft = MAX_ATTEMPTS; attemptsLeft >= 1; attemptsLeft--) {
        printf("Attempts left: %d\n", attemptsLeft);
        printf("Guess the number: ");
        scanf("%d", &guess);

        // Check if the guess is correct
        if(guess == randomNumber) {
            printf("Congratulations! You guessed the number in %d attempts!\n", MAX_ATTEMPTS - attemptsLeft + 1);
            return 0;
        }
        else if(guess < randomNumber) {
            printf("Too low!\n");
        }
        else {
            printf("Too high!\n");
        }
    }

    // Player has run out of attempts
    printf("You have run out of attempts! The number was %d.\n", randomNumber);
    return 0;
}