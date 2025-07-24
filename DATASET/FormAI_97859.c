//FormAI DATASET v1.0 Category: Game ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int guess, number, num_guesses = 0;

    // seed the random number generator
    srand(time(NULL));

    // generate a random number between 1 and 100
    number = rand() % 100 + 1;

    printf("I am thinking of a number between 1 and 100. Can you guess what it is?\n");

    do {
        printf("Enter your guess: ");
        scanf("%d", &guess);
        num_guesses++;

        if (guess > number) {
            printf("Too high!\n");
        } else if (guess < number) {
            printf("Too low!\n");
        }

    } while (guess != number);

    printf("Congratulations! You guessed the number %d in %d tries!\n", number, num_guesses);

    return 0;
}