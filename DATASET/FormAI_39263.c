//FormAI DATASET v1.0 Category: Game ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int guess, secretNum, numGuesses = 0;
    srand(time(NULL));
    secretNum = rand() % 101; // generate secret number between 0 and 100

    printf("\nWelcome to Guess the Number Game!\n");
    printf("I have chosen a number between 0 and 100, can you guess it in 7 tries?\n");

    do {
        printf("\nEnter your guess: ");
        scanf("%d", &guess);
        numGuesses++;

        if (guess == secretNum) {
            printf("Congratulations! You guessed the number in %d tries.\n", numGuesses);
            return 0;
        }
        else if (guess < secretNum) {
            printf("Too low! Try again.\n");
        }
        else {
            printf("Too high! Try again.\n");
        }

    } while (numGuesses < 7);

    printf("Sorry! You ran out of guesses. The secret number was %d.\n", secretNum);
    return 0;
}