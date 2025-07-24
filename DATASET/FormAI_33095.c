//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate random number within a range
int get_random_number(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

int main() {
    int guess, answer, attempts = 0;
    char play_again = 'y';

    srand(time(NULL)); // Seed the random number generator with current time

    printf("Welcome to the Number Guessing Game!\n");

    while (play_again == 'y') {
        answer = get_random_number(1, 100); // Generate a random number between 1 and 100
        printf("\nI'm thinking of a number between 1 and 100. Can you guess what it is?\n");

        while (1) {
            printf("Enter your guess: ");
            scanf("%d", &guess);

            attempts++;

            if (guess == answer) {
                printf("Congratulations! You guessed it in %d attempts!\n", attempts);
                break;
            } else if (guess < answer) {
                printf("Too low. Try again.\n");
            } else {
                printf("Too high. Try again.\n");
            }
        }

        printf("Would you like to play again? (y/n) ");
        scanf(" %c", &play_again);

        attempts = 0; // Reset attempts counter for new game
    }

    printf("Thanks for playing! Goodbye.\n");

    return 0;
}