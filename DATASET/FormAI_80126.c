//FormAI DATASET v1.0 Category: Game ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    int guess, number, tries = 0;
    srand(time(0)); // seed the random number generator
    number = rand() % 100 + 1; // generate a random number between 1 and 100

    printf("\nWelcome to the Guessing Game!\n");
    printf("\nYou have to guess a number between 1 and 100.\n");
    
    do {
        printf("\nEnter your guess: ");
        scanf("%d", &guess);
        tries++;

        if (guess > number) {
            printf("Lower!");
        } else if (guess < number) {
            printf("Higher!");
        } else {
            printf("\nCongratulations! You guessed it in %d tries.", tries);
        }
    } while (guess != number);

    return 0;
}