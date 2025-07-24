//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(0)); // seed random number generator

    // game setup
    int upper_limit = 10;
    int num_guesses = 5;
    int target_number = rand() % upper_limit + 1;

    printf("Welcome to the guess the number game!\n");
    printf("You have %d guesses to guess a number between 1 and %d.\n", num_guesses, upper_limit);

    // game loop
    for (int i = 0; i < num_guesses; i++) {
        int guess;

        // prompt user for input
        printf("Guess #%d: ", i+1);
        scanf("%d", &guess);

        // validate input
        if (guess < 1 || guess > upper_limit) {
            printf("Invalid guess. Please enter a number between 1 and %d.\n", upper_limit);
            i--;
            continue;
        }

        // check guess against target number
        if (guess == target_number) {
            printf("Congratulations! You guessed the number in %d guesses!\n", i+1);
            return 0;
        } else if (guess < target_number) {
            printf("Too low!\n");
        } else {
            printf("Too high!\n");
        }
    }

    // game over
    printf("Sorry, you ran out of guesses. The number was %d.\n", target_number);

    return 0;
}