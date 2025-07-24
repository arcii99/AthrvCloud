//FormAI DATASET v1.0 Category: Game ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* This program is a guessing game where the user tries to guess a randomly generated number */
int main() {
    int randomNumber, guess, attempts=0; // define variables needed for game
    srand(time(0)); // initialize random seed

    randomNumber = rand() % 101; // generate random number between 0 and 100
    
    printf("Welcome to the guessing game!\n");
    printf("Try to guess the random number between 0 and 100. You have 10 attempts.\n");

    do {
        printf("Enter your guess: ");
        scanf("%d", &guess); // read user input

        if (guess < randomNumber) {
            printf("Too low. Try again.\n");
        } else if (guess > randomNumber) {
            printf("Too high. Try again.\n");
        }

        attempts++;
    } while (attempts < 10 && guess != randomNumber);

    if (guess == randomNumber) {
        printf("Congratulations! You guessed the number in %d attempts.\n", attempts);
    } else {
        printf("Sorry, you didn't guess the number. It was %d.\n", randomNumber);
    }

    return 0;
}