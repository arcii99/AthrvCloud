//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Set up the game
    int num_guesses = 0;
    int target_num = rand() % 100 + 1; // Random number between 1 and 100
    int guessed_num;

    // Start the game loop
    while (1) {
        // Get user input
        printf("Guess a number between 1 and 100: ");
        scanf("%d", &guessed_num);

        // Invalid input
        if (guessed_num < 1 || guessed_num > 100) {
            printf("Invalid input.\n");
            continue;
        }

        // Compare guessed number to target number
        num_guesses++;
        if (guessed_num == target_num) {
            printf("You win!\n");
            printf("Number of guesses: %d\n", num_guesses);
            break;
        } else if (guessed_num < target_num) {
            printf("Too low! Guess again.\n");
        } else {
            printf("Too high! Guess again.\n");
        }
    }

    return 0;
}