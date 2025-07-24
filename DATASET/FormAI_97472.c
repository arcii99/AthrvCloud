//FormAI DATASET v1.0 Category: Random ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int num, guess, tries = 0;
    srand(time(0)); // Seed for random number generator
    num = rand() % 100 + 1; // Generate a random number between 1 and 100

    printf("Welcome to the Number Guessing Game!\n");
    printf("I am thinking of a number between 1 and 100.\n");
    printf("You have 10 tries to guess the number.\n");

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
            return 0;
        }

        if (tries == 10) {
            printf("Sorry, you have run out of tries. The number was %d.\n", num);
            return 0;
        }
    } while (1);
}