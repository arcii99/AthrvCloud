//FormAI DATASET v1.0 Category: Table Game ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // initialize variables
    int guess, answer, numGuesses = 0;
    char playAgain = 'y';
    srand(time(0));

    printf("Welcome to the Guessing Game!\n");
    printf("I am going to choose a number between 1 and 100, and you will have to guess it.\n");

    while (playAgain == 'y') {
        // generate random number
        answer = rand() % 100 + 1;

        printf("I've picked a number. What is your guess?\n");
        scanf("%d", &guess);

        while (guess != answer) {
            numGuesses++;
            if (guess < answer) {
                printf("Too low! Guess again.\n");
                scanf("%d", &guess);
            } else {
                printf("Too high! Guess again.\n");
                scanf("%d", &guess);
            }
        }

        printf("Congratulations! You guessed my number in %d guesses!\n", numGuesses);
        printf("Would you like to play again? y/n\n");
        scanf("%s", &playAgain);
        numGuesses = 0;
    }

    printf("Thanks for playing! Goodbye!\n");

    return 0;
}