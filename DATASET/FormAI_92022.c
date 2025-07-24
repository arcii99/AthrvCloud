//FormAI DATASET v1.0 Category: Game ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int guess, num, tries = 0;
    srand(time(NULL));
    num = rand() % 100 + 1;

    printf("Welcome to the Guessing Game!\n");
    printf("I have a number between 1 and 100, can you guess what it is?\n");

    do {
        printf("Enter your guess: ");
        scanf("%d", &guess);
        tries++;

        if (guess > num) {
            printf("Too high! Try again.\n");
        } else if (guess < num) {
            printf("Too low! Try again.\n");
        } else {
            printf("Congratulations! You guessed my number in %d tries!\n", tries);
            break;
        }
    } while (guess != num);

    return 0;
}