//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL)); // Initialize random seed

    int guess = 0;
    int number = rand() % 100 + 1;
    int tries = 0;

    printf("*** Welcome to the Number Guessing Game! ***\n");
    printf("I am thinking of a number between 1-100. You have 7 tries to guess it.\n");

    while (guess != number && tries < 7) {
        printf("Enter your guess: ");
        scanf("%d", &guess);

        if (guess > number) {
            printf("Too high! Guess lower.\n");
        } else if (guess < number) {
            printf("Too low! Guess higher.\n");
        } else {
            printf("Congratulations! You guessed the number in %d tries.\n", tries);
        }

        tries++;
    }

    if (guess != number) {
        printf("Game over! You failed to guess the number.\n");
        printf("The number was %d. Better luck next time!\n", number);
    }

    return 0;
}