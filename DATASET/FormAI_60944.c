//FormAI DATASET v1.0 Category: Game ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int num = rand() % 100 + 1;
    int guess, tries = 0;

    printf("Welcome to the Number Guessing Game!\n");
    printf("I am thinking of a number between 1 and 100.\n");

    do {
        printf("Guess a number: ");
        scanf("%d", &guess);
        tries++;

        if (guess > num) {
            printf("Too high! Guess again.\n");
        } else if (guess < num) {
            printf("Too low! Guess again.\n");
        } else {
            printf("Congratulations! You guessed the number in %d tries.\n", tries);
        }
    } while (guess != num);

    return 0;
}