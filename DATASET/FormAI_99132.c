//FormAI DATASET v1.0 Category: Random ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int randomNum, guess, tries = 0;

    // seed the random number generator
    srand((unsigned int) time(NULL));

    // get a random number between 1 and 100
    randomNum = rand() % 100 + 1;

    printf("\nWelcome to the Number Guessing Game!\n");
    printf("I'm thinking of a number between 1 and 100. Can you guess it?\n\n");

    do {
        printf("Enter your guess: ");
        scanf("%d", &guess);
        tries++;

        if (guess > randomNum) {
            printf("Too high, try again.\n");
        } else if (guess < randomNum) {
            printf("Too low, try again.\n");
        } else {
            printf("\nCongratulations! You guessed it in %d tries!\n", tries);
        }
    } while (guess != randomNum);

    return 0;
}