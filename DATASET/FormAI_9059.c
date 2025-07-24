//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL)); // initialize random seed

    int num = rand() % 100 + 1; // generate random number between 1 and 100
    int guess, tries = 0;

    printf("Welcome to the guessing game!\n");
    printf("Guess a number between 1 and 100.\n");

    do {
        printf("Enter your guess: ");
        scanf("%d", &guess);
        tries++;

        if (guess > num) {
            printf("Too high! Guess again.\n");
        } else if (guess < num) {
            printf("Too low! Guess again.\n");
        }
    } while (guess != num);

    printf("Congratulations, you guessed the number in %d tries!\n", tries);

    return 0;
}