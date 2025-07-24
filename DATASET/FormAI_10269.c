//FormAI DATASET v1.0 Category: Game ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int num, guess, tries = 0;
    srand(time(0));
    num = rand() % 100 + 1;
    printf("\nWelcome to the Guessing Game!\n");
    printf("I'm thinking of a number between 1 and 100.\n");
    printf("Can you guess it?\n\n");

    do {
        printf("Enter your guess: ");
        scanf("%d", &guess);
        tries++;

        if (guess > num) {
            printf("Too high! Try again.\n");
        }
        else if (guess < num) {
            printf("Too low! Try again.\n");
        }
        else {
            printf("\nCongratulations! You guessed the number in %d tries!\n", tries);
        }
    } while (guess != num);

    return 0;
}