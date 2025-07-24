//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: Ken Thompson
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <time.h>

int main() {
    srand(time(NULL)); // initialize random seed
    int secretNumber = rand() % 100 + 1; // generate random number between 1 and 100
    int guess;
    int attempts = 0;
    bool gameOver = false;

    printf("Welcome to Guess the Number!\n");
    printf("I have picked a number between 1 and 100, can you guess it?\n\n");

    while (!gameOver) {
        printf("Enter your guess: ");
        scanf("%d", &guess);
        attempts++;

        if (guess == secretNumber) {
            printf("\nCongratulations! You guessed the number in %d attempts.\n", attempts);
            gameOver = true;
        } else if (guess < secretNumber) {
            printf("Too low. Guess again.\n");
        } else {
            printf("Too high. Guess again.\n");
        }
    }

    return 0;
}