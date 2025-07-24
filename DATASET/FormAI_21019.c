//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: Claude Shannon
/* A Claude Shannon style C Terminal Based Game */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int guess, number, count = 0;
    srand (time(NULL)); //Random seed based on time

    number = rand() % 100 + 1; //random number between 1 and 100
    printf("I am thinking of a number between 1 and 100\n");

    do {
        printf("Guess the number: ");
        scanf("%d", &guess);
        count++;

        if (guess > number) {
            printf("Lower!\n");
        }
        else if (guess < number) {
            printf("Higher!\n");
        }
        else {
            printf("You guessed it in %d tries!\n", count);
        }
    } while (guess != number);

    return 0;
}