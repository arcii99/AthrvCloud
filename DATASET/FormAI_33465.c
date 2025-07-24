//FormAI DATASET v1.0 Category: Game ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    int num, guess, tries = 0;
    srand(time(NULL));
    num = rand() % 100 + 1; //Random number between 1 and 100

    printf("*** Welcome to the Guessing Game ***\n\n");
    printf("Guess a number between 1 and 100:\n");

    do {
        scanf("%d", &guess);
        tries++;

        if (guess > num) {
            printf("Too high!\n");
        } else if (guess < num) {
            printf("Too low!\n");
        } else {
            printf("\nCongratulations! You guessed the number in %d tries!\n", tries);
        }
    } while (guess != num);

    return 0;
}