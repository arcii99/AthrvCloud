//FormAI DATASET v1.0 Category: Game ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(0)); // Seed for random number generator
    int num = rand() % 100 + 1; // Generate random number from 1 to 100
    int guess, tries = 0;

    printf("\n\nWelcome to the Guessing Game!\n");
    printf("Enter a number between 1 and 100 to guess the secret number.\n");

    do {
        printf("Guess #%d: ", tries+1);
        scanf("%d", &guess);

        if (guess > num) {
            printf("Too high! Try again.\n");
            tries++;
        } else if (guess < num) {
            printf("Too low! Try again.\n");
            tries++;
        } else {
            printf("Congratulations! You guessed the secret number in %d tries!\n", tries+1);
        }
    } while (guess != num);

    return 0;
}