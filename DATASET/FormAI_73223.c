//FormAI DATASET v1.0 Category: Game ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(0)); //seed random number generator with current time

    int secretNumber = rand() % 100 + 1; //generate a random number between 1-100
    int guess;
    int attempts = 1;

    printf("Welcome to the Guessing Game!\n");
    printf("I'm thinking of a number between 1 and 100. Can you guess it?\n");

    do {
        printf("Enter your guess: ");
        scanf("%d", &guess);
        printf("You guessed: %d\n", guess);

        if (guess > secretNumber) {
            printf("Too high! Try again.\n");
        } else if (guess < secretNumber) {
            printf("Too low! Try again.\n");
        } else {
            printf("Congrats! You guessed it in %d attempts.\n", attempts);
            break;
        }
        attempts++;
    } while (guess != secretNumber);

    return 0;
}