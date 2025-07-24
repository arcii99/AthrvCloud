//FormAI DATASET v1.0 Category: Game ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* This program is a game where the user must guess a randomly generated number between 1 and 100 */

int main() {
    int guess, num, count = 0;

    srand(time(0)); /* Seed the random number generator */
    num = rand() % 100 + 1; /* Generate a random number */

    printf("Welcome to the guessing game! Can you guess the number I'm thinking of?\n");

    do {
        printf("Enter your guess: ");
        scanf("%d", &guess);
        count++;

        if (guess > num) {
            printf("Too high! Try again.\n");
        } else if (guess < num) {
            printf("Too low! Try again.\n");
        } else {
            printf("Congratulations! You guessed the number in %d attempts.\n", count);
        }
    } while (guess != num);

    return 0;
}