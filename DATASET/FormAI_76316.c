//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Game variables
    int number, guess, attempts = 0;
    char playAgain = 'y';

    // Seed random number generator
    srand(time(NULL));

    printf("Welcome to the Number Guessing Game!\n");
    printf("I'm thinking of a number between 1 and 100.\n");

    while (playAgain == 'y') {
        // Generate random number
        number = rand() % 100 + 1;

        // Reset attempts counter
        attempts = 0;

        // Loop until correct guess is made
        while (1) {
            printf("Guess the number: ");
            scanf("%d", &guess);
            attempts++;

            if (guess == number) {
                printf("Congratulations, you guessed the number in %d attempts!\n", attempts);
                break;
            } else if (guess < number) {
                printf("Higher...\n");
            } else {
                printf("Lower...\n");
            }
        }

        // Ask to play again
        printf("Do you want to play again? (y/n): ");
        scanf(" %c", &playAgain);
    }

    printf("Thanks for playing! Goodbye.\n");

    return 0;
}