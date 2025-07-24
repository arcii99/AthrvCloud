//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int num, guess, tries = 0;
    srand(time(0)); // random number generator
    num = rand() % 100 + 1; // generating random number between 1 and 100
    printf("\nWelcome to the Guess the Number game!\n");
    printf("You have to guess a number between 1 and 100.\n");
    printf("You have only 5 tries.\n\n");

    do {
        printf("Guess the number: ");
        scanf("%d", &guess);
        tries++;

        if (guess > num) {
            printf("Guess lower.\n");
        } else if (guess < num) {
            printf("Guess higher.\n");
        } else {
            printf("\nCongratulations! You guessed the number in %d tries.\n", tries);
            break;
        }
    } while (tries < 5); // for 5 tries

    if (tries >= 5) {
        printf("\nSorry! You failed to guess the number in 5 tries.\n");
        printf("The number was %d.\n", num);
    }

    return 0;
}