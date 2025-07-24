//FormAI DATASET v1.0 Category: Table Game ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int guess, number, tries = 0;

    srand(time(NULL));
    number = rand() % 100 + 1;

    printf("Welcome to the Guessing Game!\n");
    printf("I'm thinking of a number between 1 and 100.\n");
    printf("Can you guess what it is?\n");

    do {
        printf("Enter your guess (1-100): ");
        scanf("%d", &guess);
        tries++;

        if (guess < number) {
            printf("Too low! Try again.\n");
        } else if (guess > number) {
            printf("Too high! Try again.\n");
        } else {
            printf("Congratulations! You guessed the number in %d tries.\n", tries);
        }

    } while (guess != number);

    return 0;
}