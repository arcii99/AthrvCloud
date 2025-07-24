//FormAI DATASET v1.0 Category: Game ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    printf("Wow! This program is amazing!\n");
    printf("It's a number guessing game!\n");
    printf("I'm thinking of a number between 1 and 100...\n");

    srand(time(NULL)); // seed to make the game unpredictable
    int number = rand() % 100 + 1; // generate a random number between 1-100

    int guess;
    int tries = 0;
    do {
        printf("Enter your guess: ");
        scanf("%d", &guess);
        tries++;

        if (guess < number) {
            printf("Your guess is too low!\n");
        } else if (guess > number) {
            printf("Your guess is too high!\n");
        } else {
            printf("Congratulations! You guessed the number in %d tries!\n", tries);
        }

    } while (guess != number);

    printf("Thanks for playing my game!\n");
    return 0;
}