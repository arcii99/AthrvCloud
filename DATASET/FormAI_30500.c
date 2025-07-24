//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Initializing the game
    srand(time(NULL));
    int target = rand() % 100;
    int guess, num_guesses = 0;

    printf("Welcome to the Guessing Game! I am thinking of a number between 0 and 100.\n");

    // Loop until the player guesses the number
    while (1) {
        printf("Enter your guess: ");
        scanf("%d", &guess);

        num_guesses++;

        if (guess == target) {
            printf("Congratulations! You guessed the number in %d guesses.\n", num_guesses);
            return 0;
        } else if (guess < target) {
            printf("Too low! Try again.\n");
        } else { // guess > target
            printf("Too high! Try again.\n");
        }
    }
}