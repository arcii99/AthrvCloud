//FormAI DATASET v1.0 Category: Game ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));  // seed random number generator

    int target = rand() % 100;  // pick a random number between 0 and 99
    int guess, num_guesses = 0;

    printf("Welcome to the guess the number game!\n\n");

    do {
        printf("Enter your guess (between 0 and 99): ");
        scanf("%d", &guess);
        num_guesses++;

        if (guess < target) {
            printf("Too low! Try again.\n");
        } else if (guess > target) {
            printf("Too high! Try again.\n");
        }
    } while (guess != target);

    printf("\nCongratulations, you guessed the number in %d tries!\n", num_guesses);
    printf("Thanks for playing.\n");

    return 0;
}