//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(0)); // seed the random number generator
    int secretNumber = rand() % 100 + 1; // generate a random number between 1 and 100
    int guess, tries = 0;

    printf("Welcome to Paranoid Number Guessing Game\n");
    printf("You have only five chances to guess the secret number between 1 and 100\n");

    while (tries < 5) {
        printf("Guess #%d: ", tries + 1);
        scanf("%d", &guess);

        if (guess < secretNumber) {
            printf("Too low! Try again\n");
            tries++;
        } else if (guess > secretNumber) {
            printf("Too high! Try again\n");
            tries++;
        } else {
            printf("Congratulations! You guessed the secret number in %d tries\n", tries + 1);
            return 0;
        }
    }

    printf("You have failed to guess the secret number\n");
    printf("The secret number was %d\n", secretNumber);

    return 0;
}