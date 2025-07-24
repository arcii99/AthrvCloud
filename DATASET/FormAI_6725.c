//FormAI DATASET v1.0 Category: Table Game ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int guess;
    int secretNumber;

    srand(time(0));
    secretNumber = rand() % 100 + 1;

    printf("Welcome to the Guessing Game!\n");
    printf("I'm thinking of a number between 1 and 100. You have to guess it.\n");

    do {
        printf("Enter your guess: ");
        scanf("%d", &guess);

        if (guess < secretNumber) {
            printf("Too low. Try again.\n");
        } else if (guess > secretNumber) {
            printf("Too high. Try again.\n");
        } else {
            printf("Congratulations! You guessed it!\n");
        }
    } while(guess != secretNumber);

    printf("Thanks for playing!\n");
    return 0;
}