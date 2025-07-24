//FormAI DATASET v1.0 Category: Game ; Style: bold
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_GUESSES 7

int main() {
    srand(time(NULL));
    int num = rand() % 100 + 1;
    int guess, tries = 0;

    printf("*** Welcome to the Guessing Game! ***\n\n");
    printf("Guess a number between 1 and 100. You have %d tries.\n\n", MAX_GUESSES);

    do {
        printf("Enter your guess: ");
        scanf("%d", &guess);
        tries++;

        if (guess < num) {
            printf("Too low! Try again.\n\n");
        } else if (guess > num) {
            printf("Too high! Try again.\n\n");
        } else {
            printf("Congrats! You got it in %d tries.\n", tries);
            return 0;
        }
    } while (tries < MAX_GUESSES);

    printf("Sorry, you ran out of tries! The number was %d.\n", num);
    return 0;
}