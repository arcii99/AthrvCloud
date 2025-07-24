//FormAI DATASET v1.0 Category: Random ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main () {

    srand(time(0)); // initialize random seed based on current time

    int random_number = rand() % 100; // generate a random number between 0 and 99
    int guess = -1;
    int attempts_remaining = 10;

    printf("Welcome to the Guessing Game!\n");
    printf("You have %d attempts to guess the number between 0 and 99.\n", attempts_remaining);

    while (guess != random_number && attempts_remaining > 0) {
        printf("Guess a number: ");
        scanf("%d", &guess);

        if (guess < random_number) {
            printf("Too low! ");
        } else if (guess > random_number) {
            printf("Too high! ");
        }

        attempts_remaining--;
        printf("You have %d attempts remaining.\n", attempts_remaining);

        if (attempts_remaining == 0) {
            printf("Sorry, you are out of attempts!\n");
        }
    }

    if (guess == random_number) {
        printf("Congratulations! You guessed the number %d!\n", random_number);
    }

    return 0;
}