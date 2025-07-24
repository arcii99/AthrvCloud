//FormAI DATASET v1.0 Category: Game ; Style: happy
// Welcome to the Happy Game
// This game will bring joy and happiness to your life!

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int guess, secretNum, numGuesses = 0;
    srand(time(0)); // seed random number generator
    secretNum = rand() % 100 + 1; // generate a random number between 1 and 100

    printf("Welcome to the Happy Game!\n");
    printf("Guess the secret number between 1 and 100 to win!\n");

    do {
        printf("Enter your guess (1-100): ");
        scanf("%d", &guess);
        numGuesses++;

        if (guess > secretNum) {
            printf("Too high! Guess again.\n");
        } else if (guess < secretNum) {
            printf("Too low! Guess again.\n");
        } else {
            printf("Congratulations! You guessed the secret number in %d tries!\n", numGuesses);
        }

    } while (guess != secretNum);

    printf("Thank you for playing the Happy Game!\n");

    return 0;
}