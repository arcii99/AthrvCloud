//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    int num, guess, tries = 0;
    srand(time(0));
    num = rand() % 100 + 1; //generating a random number between 1 and 100

    printf("Welcome to the Guessing Game!\n");
    printf("I'm thinking of a number between 1 and 100.\n");
    printf("You have to guess the number in minimum attempts.\n\n");

    do {
        printf("Guess the number: ");
        scanf("%d", &guess);
        tries++;

        if (guess > num) {
            printf("Too high! Try again.\n\n");
        } else if (guess < num) {
            printf("Too low! Try again.\n\n");
        } else {
            printf("\nCongratulations! You guessed the number in %d attempts.\n", tries);
        }
    } while (guess != num);

    return 0;
}