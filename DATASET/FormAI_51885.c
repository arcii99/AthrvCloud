//FormAI DATASET v1.0 Category: Funny ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define MAX_ATTEMPTS 5

int main() {
    // Set up variables
    srand(time(NULL));
    int secret_number = rand() % 100;
    int guess, attempts_left = MAX_ATTEMPTS;
    bool game_over = false;

    // Start game loop
    while (!game_over) {
        // Check for end conditions
        if (attempts_left == 0) {
            printf("Out of attempts! The secret number was %d.\n", secret_number);
            game_over = true;
            continue;
        }
        printf("You have %d attempts left.\n", attempts_left);
        printf("Guess a number between 0 and 99: ");
        scanf("%d", &guess);

        // Check for correct guess
        if (guess == secret_number) {
            printf("You guessed it! The secret number was %d.\n", secret_number);
            game_over = true;
        }

        // Check for incorrect guess
        else {
            attempts_left--;
            if (guess < secret_number) {
                printf("Too low! ");
            }
            else {
                printf("Too high! ");
            }
            printf("Guess again.\n");
        }
    }
    return 0;
}