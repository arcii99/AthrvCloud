//FormAI DATASET v1.0 Category: Game ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    srand(time(NULL)); // seed the random number generator with the current time
    int secretNumber = rand() % 100 + 1; // generate a random number between 1 and 100
    int guess;
    int guessCount = 0;

    printf("Welcome to the guessing game!\n");
    printf("Try to guess the secret number between 1 and 100.\n");

    do {
        printf("Enter your guess: ");
        scanf("%d", &guess);

        guessCount++;

        if (guess < secretNumber) {
            printf("Too low! Try again.\n");
        } else if (guess > secretNumber) {
            printf("Too high! Try again.\n");
        } else {
            printf("Congratulations! You guessed the secret number in %d tries.\n", guessCount);
        }

    } while (guess != secretNumber);

    return 0;
}