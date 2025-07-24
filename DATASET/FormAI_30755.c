//FormAI DATASET v1.0 Category: Game ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int min = 1;
    int max = 100;
    int guess;
    int numGuesses = 0;
    char playAgain = 'y';

    srand(time(NULL));

    printf("Guess a number between %d and %d\n", min, max);

    while (playAgain == 'y') {
        int numberToGuess = rand() % (max - min + 1) + min;

        do {
            printf("Enter your guess: ");
            scanf("%d", &guess);
            numGuesses++;

            if (guess < numberToGuess) {
                printf("Too low!\n");
            } else if (guess > numberToGuess) {
                printf("Too high!\n");
            } else {
                printf("Congratulations! You guessed the number in %d tries!\n", numGuesses);
            }
        } while (guess != numberToGuess);

        numGuesses = 0;
        printf("Do you want to play again? (y/n): ");
        scanf(" %c", &playAgain);
    }

    printf("Thanks for playing!\n");

    return 0;
}